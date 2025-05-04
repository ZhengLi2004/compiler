#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"
#include "symbol_table.h"
#include "type.h"

// 调试级别控制
int debug_level = 2;  // 可调整为 0-3，3 输出最详细信息

#define DEBUG(level, fmt, ...) \
    if (debug_level >= level) fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)

// 前向声明
Type* get_expression_type(ASTNode *expr, SymbolTable *table);
int type_compatible(Type *lhs, Type *rhs);
Type* get_type_from_declaration_specifiers(ASTNode *spec);
Type* parse_declarator(ASTNode *declr, Type *base_type);
int is_valid_type(Type *type);
int is_variable_redeclared(SymbolTable *table, const char *name);
void handle_function_parameters(ASTNode *func, SymbolTable *table);
Type* get_function_return_type(SymbolTable *table);
int is_in_loop(SymbolTable *table);
int node_is_arithmetic(ASTNode *node);
int node_is_comparison(ASTNode *node);

int node_is_arithmetic(ASTNode *node) {
    return node->type == AST_BINOP && 
           (strchr("+-*/%", node->bin.op) != NULL);
}

int node_is_comparison(ASTNode *node) {
    return node->type == AST_BINOP && 
           (strchr("=><!", node->bin.op) != NULL || 
            node->bin.op == 'e' || node->bin.op == '!' ||
            node->bin.op == 'l' || node->bin.op == 'g');
}

// 打印符号表调试信息
void symbol_table_print_debug(SymbolTable *table, int level) {
    if (debug_level < level) return;
    symbol_table_print(table,stdout);
}

void error_report(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
}

static void build_symbol_table_recursive(ASTNode *node, SymbolTable *table) {
    DEBUG(1, "Entering build_symbol_table_recursive (type: %d)", node ? node->type : -1);
    if (!node) {
        error_report("Node is NULL. Exiting.");
        return;
    }

    switch (node->type) {
        case AST_TRANSLATION_UNIT:
        case AST_EXTERNAL_DECL:
            DEBUG(1, "Processing AST_TRANSLATION_UNIT/EXTERNAL_DECL (count: %d)", node->seq.count);
            for (int i = 0; i < node->seq.count; ++i) {
                DEBUG(2, "Processing seq[%d] (type: %d)", i, node->seq.list[i]->type);
                build_symbol_table_recursive(node->seq.list[i], table);
            }
            break;

        case AST_DECLARATION: {
            DEBUG(1, "Processing AST_DECLARATION (specs count: %d)", node->declaration.scount);
            Type *base_type = get_type_from_declaration_specifiers(node->declaration.specs[0]);
            DEBUG(2, "Base type: %s", base_type ? base_type->basic : "NULL");

            for (int i = 0; i < node->declaration.icount; ++i) {
                ASTNode *init_decl = node->declaration.inits[i];
                DEBUG(3, "Processing init_decl[%d] (type: %d)", i, init_decl->type);
                if (init_decl->type == AST_INIT_DECL) {
                    ASTNode *declr = init_decl->id.declr;
                    ASTNode *var_node = declr;

                    // 提取变量名（处理数组/指针类型）
                    while (var_node->type == AST_ARRAY_TYPE || var_node->type == AST_POINTER_TYPE) {
                        if (var_node->type == AST_ARRAY_TYPE) {
                            var_node = var_node->at.base;
                        } else {
                            var_node = var_node->ptr_to;
                        }
                    }

                    if (var_node->type != AST_VAR) {
                        error_report("Invalid declarator - not a variable");
                        continue;
                    }

                    DEBUG(3, "Declaring variable: %s", var_node->varname);
                    Type *type = parse_declarator(declr, base_type);
                    DEBUG(3, "Parsed type for %s: %s", var_node->varname, type ? type->basic : "NULL");

                    if (!type) continue;

                    if (!is_valid_type(type)) {
                        error_report("Invalid type for variable '%s'", var_node->varname);
                        type_free(type);
                        continue;
                    }

                    if (is_variable_redeclared(table, var_node->varname)) {
                        error_report("Variable '%s' already declared", var_node->varname);
                        type_free(type);
                        continue;
                    }

                    Symbol *sym = malloc(sizeof(Symbol));
                    sym->name = strdup(var_node->varname);
                    sym->type = type;
                    sym->scope_depth = table->scope_depth;
                    sym->is_constant = 0;
                    sym->is_parameter = 0;
                    sym->ast_node = init_decl;

                    symbol_table_add(table, sym);
                    DEBUG(2, "Added symbol: %s (type: %s)", sym->name, sym->type->basic);
                }
            }
            symbol_table_print_debug(table, 2);
            break;
        }

        case AST_FUNC_TYPE: {
            DEBUG(1, "Processing AST_FUNC_TYPE (function name: %s)", node->ft.name ? node->ft.name : "anonymous");
        
            // 1. 创建函数返回类型
            Type *return_type = get_type_from_declaration_specifiers(node->ft.ret_type);
        
            // 2. 创建参数类型数组
            Type **param_types = NULL;
            int param_count = 0;
        
            if (node->ft.params && node->ft.params->type == AST_PARAM_LIST) {
                for (int i = 0; i < node->ft.params->pl.pcount; ++i) {
                    ASTNode *param = node->ft.params->pl.params[i];
                    if (param->type == AST_PARAM) {
                        Type *param_type = get_type_from_declaration_specifiers(param->param.dspecs[0]);
                        if (param->param.declr && param->param.declr->type == AST_VAR) {
                            param_types = realloc(param_types, (param_count + 1) * sizeof(Type*));
                            param_types[param_count++] = parse_declarator(param->param.declr, param_type);
                        }
                    }
                }
            }
        
            // 3. 创建函数类型
            Type *func_type = type_function(return_type, param_types, param_count);
        
            // 4. 创建函数符号并添加到全局作用域（Scope 0）
            if (node->ft.name) {
                Symbol *sym = malloc(sizeof(Symbol));
                sym->name = strdup(node->ft.name);
                sym->type = func_type;
                sym->scope_depth = table->scope_depth; // 应为 0（全局作用域）
                sym->is_constant = 0;
                sym->is_parameter = 0;
                sym->ast_node = node;
        
                symbol_table_add(table, sym);
                DEBUG(2, "Added function: %s (type: %s)", sym->name, sym->type->basic);
            }
        
            // 5. 进入函数体作用域（Scope 1）
            DEBUG(2, "Entering function scope (depth: %d)", table->scope_depth + 1);
            symbol_table_enter_scope(table);
            symbol_table_print_debug(table, 2);
        
            // 6. 处理参数（添加到函数作用域）
            if (node->ft.params && node->ft.params->type == AST_PARAM_LIST) {
                for (int i = 0; i < node->ft.params->pl.pcount; ++i) {
                    ASTNode *param = node->ft.params->pl.params[i];
                    if (param->type == AST_PARAM && param->param.declr && param->param.declr->type == AST_VAR) {
                        Symbol *param_sym = malloc(sizeof(Symbol));
                        param_sym->name = strdup(param->param.declr->varname);
                        param_sym->type = param_types[i];
                        param_sym->scope_depth = table->scope_depth; // 应为 1（函数作用域）
                        param_sym->is_constant = 0;
                        param_sym->is_parameter = 1;
                        param_sym->ast_node = param->param.declr;
        
                        symbol_table_add(table, param_sym);
                        DEBUG(2, "Added parameter: %s (type: %s)", param_sym->name, param_sym->type->basic);
                    }
                }
            }
        
            // 7. 处理函数体
            if (node->ft.body) {
                DEBUG(2, "Processing function body");
                build_symbol_table_recursive(node->ft.body, table);
            }
        
            // 8. 离开函数作用域
            symbol_table_leave_scope(table);
            DEBUG(2, "Leaving function scope (depth: %d)", table->scope_depth);
            symbol_table_print_debug(table, 2);
            break;
        }

        case AST_COMPOUND_STMT:
            DEBUG(1, "Processing AST_COMPOUND_STMT (count: %d)", node->seq.count);
            DEBUG(2, "Entering new scope (depth: %d)", table->scope_depth + 1);
            symbol_table_enter_scope(table);
            symbol_table_print_debug(table, 2);

            for (int i = 0; i < node->seq.count; ++i) {
                DEBUG(3, "Processing compound stmt[%d] (type: %d)", i, node->seq.list[i]->type);
                build_symbol_table_recursive(node->seq.list[i], table);
            }

            DEBUG(2, "Leaving scope (depth: %d)", table->scope_depth);
            symbol_table_leave_scope(table);
            symbol_table_print_debug(table, 2);
            break;

        case AST_VAR: {
            DEBUG(2, "Processing AST_VAR: %s", node->varname);
            Symbol *sym = symbol_table_lookup(table, node->varname);
            if (!sym) {
                error_report("Undefined variable '%s'", node->varname);
            }
            break;
        }

        case AST_ASSIGN: {
            DEBUG(2, "Processing assignment to %s", node->assign.l->varname);
            build_symbol_table_recursive(node->assign.l, table);
            build_symbol_table_recursive(node->assign.r, table);

            Type *lhs_type = get_expression_type(node->assign.l, table);
            Type *rhs_type = get_expression_type(node->assign.r, table);
            DEBUG(3, "Assignment types: %s = %s", lhs_type ? lhs_type->basic : "NULL", rhs_type ? rhs_type->basic : "NULL");

            if (!type_compatible(lhs_type, rhs_type)) {
                error_report("Type mismatch in assignment to '%s'", node->assign.l->varname);
            }
            break;
        }

        case AST_BINOP: {
            DEBUG(2, "Processing binary op: %c", node->bin.op);
            build_symbol_table_recursive(node->bin.lhs, table);
            build_symbol_table_recursive(node->bin.rhs, table);

            Type *lhs_type = get_expression_type(node->bin.lhs, table);
            Type *rhs_type = get_expression_type(node->bin.rhs, table);
            DEBUG(3, "Binary op types: %s %c %s", lhs_type ? lhs_type->basic : "NULL", node->bin.op, rhs_type ? rhs_type->basic : "NULL");

            if ((node->bin.op == '+' || node->bin.op == '-' || node->bin.op == '*' || node->bin.op == '/') &&
                (!lhs_type || !rhs_type || lhs_type->kind != TYPE_BASIC || rhs_type->kind != TYPE_BASIC)) {
                error_report("Arithmetic operation requires scalar types");
            }

            if ((node->bin.op == '==' || node->bin.op == '!=' || node->bin.op == '<' || node->bin.op == '>') &&
                (!type_compatible(lhs_type, rhs_type))) {
                error_report("Comparison requires compatible types");
            }
            break;
        }

        case AST_CALL: {
            DEBUG(2, "Processing function call: %s", node->call.fname);
            Symbol *func = symbol_table_lookup(table, node->call.fname);
            if (!func || func->type->kind != TYPE_FUNCTION) {
                error_report("Undefined or non-function symbol '%s'", node->call.fname);
                break;
            }

            Type *func_type = func->type;
            DEBUG(2, "Function '%s' has %d parameters", node->call.fname, func_type->function.param_count);
            if (node->call.argc != func_type->function.param_count) {
                error_report("Argument count mismatch in call to '%s'", node->call.fname);
                break;
            }

            for (int i = 0; i < node->call.argc; ++i) {
                Type *expected = func_type->function.param_types[i];
                Type *actual = get_expression_type(node->call.args[i], table);
                DEBUG(3, "Arg[%d] type check: expected %s, got %s", i, expected->basic, actual ? actual->basic : "NULL");
                if (!type_compatible(expected, actual)) {
                    error_report("Argument type mismatch in call to '%s' at position %d", node->call.fname, i);
                }
            }
            break;
        }

        case AST_RETURN: {
            DEBUG(2, "Processing return statement");
            if (node->expr) {
                build_symbol_table_recursive(node->expr, table);
            }

            Type *func_return_type = get_function_return_type(table);
            Type *return_type = node->expr ? get_expression_type(node->expr, table) : NULL;
            DEBUG(3, "Return types: expected %s, got %s", 
                func_return_type ? func_return_type->basic : "void",
                return_type ? return_type->basic : "void");

            if (!func_return_type && node->expr) {
                DEBUG(1, "Return statement outside function");
            } else if (func_return_type && func_return_type->kind == TYPE_BASIC && 
                      strcmp(func_return_type->basic, "void") == 0 && node->expr) {
                DEBUG(1, "Return value from void function");
            } else if (func_return_type && node->expr && !type_compatible(func_return_type, return_type)) {
                error_report("Return type mismatch");
            }
            break;
        }

        case AST_IF: {
            DEBUG(2, "Processing if statement");
            build_symbol_table_recursive(node->sif.cond, table);
            build_symbol_table_recursive(node->sif.then_s, table);
            if (node->sif.else_s) {
                build_symbol_table_recursive(node->sif.else_s, table);
            }

            Type *cond_type = get_expression_type(node->sif.cond, table);
            DEBUG(3, "If condition type: %s", cond_type ? cond_type->basic : "NULL");
            if (cond_type && cond_type->kind != TYPE_BASIC) {
                error_report("If condition must be a scalar type");
            }
            break;
        }

        case AST_WHILE:
        case AST_DO_WHILE:
        case AST_FOR: {
            DEBUG(2, "Processing loop statement (type: %d)", node->type);
            ASTNode *cond = node->type == AST_DO_WHILE ? node->sdw.cond :
                           (node->type == AST_FOR ? node->sf.cond : node->sw.cond);
            ASTNode *body = node->type == AST_DO_WHILE ? node->sdw.body :
                           (node->type == AST_FOR ? node->sf.body : node->sw.body);

            build_symbol_table_recursive(cond, table);
            build_symbol_table_recursive(body, table);

            Type *cond_type = get_expression_type(cond, table);
            DEBUG(3, "Loop condition type: %s", cond_type ? cond_type->basic : "NULL");
            if (cond_type && cond_type->kind != TYPE_BASIC) {
                error_report("Loop condition must be a scalar type");
            }
            break;
        }

        case AST_BREAK:
        case AST_CONTINUE: {
            DEBUG(2, "Processing %s statement", node->type == AST_BREAK ? "break" : "continue");
            if (!is_in_loop(table)) {
                error_report("'%s' statement outside loop", node->type == AST_BREAK ? "break" : "continue");
            }
            break;
        }

        case AST_EXPR_STMT:
            DEBUG(2, "Processing expression statement");
            if (node->expr) {
                build_symbol_table_recursive(node->expr, table);
            }
            break;

        case AST_INIT_LIST:
            DEBUG(1, "Processing AST_INIT_LIST (count: %d)", node->seq.count);
            for (int i = 0; i < node->seq.count; ++i) {
                build_symbol_table_recursive(node->seq.list[i], table);
            }
            break;

        case AST_DESIGNATION:
            DEBUG(1, "Processing AST_DESIGNATION (count: %d)", node->des);
            for (int i = 0; i < node->des; ++i) {
                build_symbol_table_recursive(node->des[i], table);
            }
            break;

        default:
            error_report("Ignoring unhandled node type: %d", node->type);
            break;
    }

    DEBUG(1, "Exiting build_symbol_table_recursive (type: %d)", node->type);
}

// 以下为辅助函数的简化实现（需根据实际代码补充完整）
Type* get_expression_type(ASTNode *expr, SymbolTable *table) {
    if (!expr) return NULL;
    switch (expr->type) {
        case AST_VAR: {
            Symbol *sym = symbol_table_lookup(table, expr->varname);
            return sym ? sym->type : NULL;
        }
        case AST_INT: return type_basic("int");
        case AST_DOUBLE: return type_basic("double");
        case AST_ASSIGN: return get_expression_type(expr->assign.l, table);
        case AST_CALL: {
            Symbol *func = symbol_table_lookup(table, expr->call.fname);
            return func && func->type->kind == TYPE_FUNCTION ? func->type->function.return_type : NULL;
        }
        case AST_BINOP: {
            Type *lhs = get_expression_type(expr->bin.lhs, table);
            Type *rhs = get_expression_type(expr->bin.rhs, table);

            // 算术运算型
            if (node_is_arithmetic(expr)) {
                if (lhs && rhs) {
                    if (strcmp(lhs->basic, "double") == 0 || 
                        strcmp(rhs->basic, "double") == 0) {
                        return type_basic("double");
                    }
                    return type_basic("int");
                }
            }   
            
            // 比较运算返回int类型
            if (node_is_comparison(expr)) {
                return type_basic("int");
            }

            return NULL;
        }
        default: return NULL;
    }
}

int type_compatible(Type *lhs, Type *rhs) {
    if (!lhs || !rhs) return 0;
    if (lhs == rhs) return 1;
    if (lhs->kind != rhs->kind) return 0;
    switch (lhs->kind) {
        case TYPE_BASIC: return strcmp(lhs->basic, rhs->basic) == 0;
        case TYPE_POINTER: return type_compatible(lhs->pointer.base, rhs->pointer.base);
        case TYPE_ARRAY: return lhs->array.size == rhs->array.size && 
                                 type_compatible(lhs->array.base, rhs->array.base);
        case TYPE_FUNCTION: return type_compatible(lhs->function.return_type, rhs->function.return_type) &&
                                 lhs->function.param_count == rhs->function.param_count;
        default: return 0;
    }
}

Type* get_type_from_declaration_specifiers(ASTNode* spec_node) {
    if (!spec_node) {
        return type_basic("int");
    }
    switch (spec_node->type) {
        case AST_DECL_SPEC: {
            for (int i = 0; i < spec_node->ds.scount; ++i) {
                ASTNode* spec = spec_node->ds.specs[i];
                if (spec->type == AST_TYPE_NAME) {
                    const char* name = spec->str;
                    if (strcmp(name, "int") == 0) return type_basic("int");
                    if (strcmp(name, "double") == 0) return type_basic("double");
                    if (strcmp(name, "void") == 0) return type_basic("void");
                }
            }
            // 默认返回 int 类型
            return type_basic("anon");
        }

        case AST_VAR:
            // 变量名本身不包含类型信息，但可以尝试从上下文获取，或返回默认类型
            return type_basic("anon");

        case AST_TYPE_NAME:
            // 直接提取类型名
            if (strcmp(spec_node->str, "int") == 0) return type_basic("int");
            if (strcmp(spec_node->str, "double") == 0) return type_basic("double");
            if (strcmp(spec_node->str, "void") == 0) return type_basic("void");
            return type_basic("anon");

        default:
            // 其他情况返回默认类型 int
            return type_basic("anon");
    }
}

Type* parse_declarator(ASTNode* node, Type* base_type) {
    if (!node) return base_type;

    switch (node->type) {
        case AST_POINTER_TYPE:
            return type_pointer(parse_declarator(node->ptr_to, base_type));
        case AST_ARRAY_TYPE:
            {
                int size = -1;
                if (node->at.size && node->at.size->type == AST_INT) {
                    size = node->at.size->intval;
                }
                Type* base = parse_declarator(node->at.base, base_type);
                return type_array(base, size);
            }
        case AST_FUNC_TYPE:
            {
                Type* return_type = base_type;
                Type** param_types = NULL;
                int param_count = 0;

                if (node->ft.params && node->ft.params->type == AST_PARAM_LIST) {
                    for (int i = 0; i < node->ft.params->pl.pcount; ++i) {
                        ASTNode* param = node->ft.params->pl.params[i];
                        if (param->type == AST_PARAM) {
                            Type* param_type = get_type_from_declaration_specifiers(
                                param->param.dspecs[0]);
                            param_types = realloc(param_types, (param_count + 1) * sizeof(Type*));
                            param_types[param_count++] = param_type;
                        }
                    }
                }

                return type_function(return_type, param_types, param_count);
            }
        case AST_VAR:
            return base_type;
        default:
            return base_type;
    }
}

int is_valid_type(Type *type) {
    if (!type) return 0;
    switch (type->kind) {
        case TYPE_ARRAY: return type->array.size > 0 && is_valid_type(type->array.base);
        case TYPE_POINTER: return is_valid_type(type->pointer.base);
        case TYPE_FUNCTION: return is_valid_type(type->function.return_type);
        default: return 1;
    }
}

int is_variable_redeclared(SymbolTable *table, const char *name) {
    Scope *current = table->scopes[table->scope_depth];
    for (int i = 0; i < current->symbol_count; ++i) {
        if (strcmp(current->symbols[i]->name, name) == 0) return 1;
    }
    return 0;
}

void handle_function_parameters(ASTNode *func, SymbolTable *table) {
    if (func->type != AST_FUNC_TYPE) return;
    if (!func->ft.params || func->ft.params->type != AST_PARAM_LIST) return;
    
    ASTNode *params_list = func->ft.params;
    for (int i = 0; i < params_list->pl.pcount; ++i) {
        ASTNode *param_node = params_list->pl.params[i];
        if (param_node->type != AST_PARAM) continue;
        
        ASTNode *param = param_node;
        if (param->param.dcount <= 0 || !param->param.dspecs) continue;
        
        Type *param_type = get_type_from_declaration_specifiers(param->param.dspecs[0]);
        for (int j = 0; j < param->param.dcount; ++j) {
            ASTNode *init_decl = param->param.dspecs[j];
            if (init_decl->type != AST_INIT_DECL) continue;
            
            ASTNode *declr = init_decl->id.declr;
            Type *type = parse_declarator(declr, param_type);
            if (!is_valid_type(type)) continue;
            
            if (is_variable_redeclared(table, declr->varname)) continue;
            
            Symbol *sym = malloc(sizeof(Symbol));
            sym->name = strdup(declr->varname);
            sym->type = type;
            sym->scope_depth = table->scope_depth;
            sym->is_constant = 0;
            sym->is_parameter = 1;
            sym->ast_node = init_decl;
            symbol_table_add(table, sym);
        }
    }
}

Type* get_function_return_type(SymbolTable *table) {
    // 实现取决于你的上下文管理逻辑
    return type_basic("int"); // 示例返回
}

int is_in_loop(SymbolTable *table) {
    // 实现取决于你的上下文管理逻辑
    return 1; // 示例返回
}

// 数组大小检查函数
int get_array_size(ASTNode *size_node, int *out_size) {
    if (!size_node) return 0;
    if (size_node->type != AST_INT) return 0;
    if (size_node->intval <= 0) return 0;
    *out_size = size_node->intval;
    return 1;
}

void build_symbol_table(ASTNode *root, SymbolTable *table) {
    build_symbol_table_recursive(root, table);
};