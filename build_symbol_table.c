#include "build_symbol_table.h"
#include "ast.h"
#include "type.h"
#include "symbol_table.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 提取数组大小并验证是否合法
static int get_array_size(ASTNode *size_node, int *out_size) {
    if (!size_node) {
        fprintf(stderr, "❌ Error: Missing array size\n");
        return 0;
    }

    if (size_node->type != AST_INT) {
        fprintf(stderr, "❌ Error: Array size must be an integer constant\n");
        return 0;
    }

    if (size_node->intval <= 0) {
        fprintf(stderr, "❌ Error: Array size must be a positive integer\n");
        return 0;
    }

    *out_size = size_node->intval;
    return 1;
}

// 从声明说明符中提取基本类型
static Type* get_type_from_declaration_specifiers(ASTNode *spec) {
    if (spec && spec->type == AST_TYPE_NAME) {
        return type_basic(spec->str);
    }
    return type_basic("int"); // 默认类型
}

static Type* parse_declarator(ASTNode *declr, Type *base_type) {
    if (!declr) return base_type;

    switch (declr->type) {
        case TYPE_BASIC:
            return base_type;

        case TYPE_POINTER:
            return type_pointer(parse_declarator(declr->ptr_to, base_type));

        case TYPE_ARRAY: {
            int size;
            if (!get_array_size(declr->at.size, &size)) {
                return NULL; // 返回 NULL 表示类型非法
            }

            Type *element_type = parse_declarator(declr->at.base, base_type);
            return type_array(element_type, size);
        }

        case TYPE_FUNCTION:
            return type_function(base_type, NULL, 0, 0);

        default:
            return base_type;
    }
}

// 检查数组大小是否合法
static int is_valid_array_size(int size) {
    return size >= 0;
}

// 检查类型是否合法（如数组大小是否合法）
static int is_valid_type(Type *type) {
    if (!type) return 0;

    switch (type->kind) {
        case TYPE_ARRAY:
            return type->array.size > 0 && is_valid_type(type->array.base);
        case TYPE_POINTER:
            return is_valid_type(type->pointer.base);
        case TYPE_FUNCTION:
            for (int i = 0; i < type->function.param_count; ++i) {
                if (!is_valid_type(type->function.param_types[i])) {
                    return 0;
                }
            }
            return is_valid_type(type->function.return_type);
        default:
            return 1;
    }
}

// 检查变量是否已在当前作用域中声明
static int is_variable_redeclared(SymbolTable *table, const char *name) {
    Scope *current_scope = table->scopes[table->scope_depth];
    for (int i = 0; i < current_scope->symbol_count; ++i) {
        if (strcmp(current_scope->symbols[i]->name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

// 检查函数参数是否重复
static int is_parameter_redeclared(SymbolTable *table, const char *name, int scope_depth) {
    Scope *current_scope = table->scopes[scope_depth];
    for (int i = 0; i < current_scope->symbol_count; ++i) {
        if (strcmp(current_scope->symbols[i]->name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

// 处理函数参数声明
static void handle_function_parameters(ASTNode *func, SymbolTable *table) {
    if (func->type != AST_FUNC_TYPE) return;

    // 进入函数作用域
    symbol_table_enter_scope(table);

    for (int i = 0; func->ft.params != NULL && i < func->ft.params->pl.pcount; ++i) {
        ASTNode *param = func->ft.params->pl.params[i];

        if (param->type != AST_DECLARATION) {
            fprintf(stderr, "❌ Error: Invalid function parameter declaration\n");
            continue;
        }

        Type *param_type = get_type_from_declaration_specifiers(param->ds.specs[0]);

        for (int j = 0; j < param->seq.count; ++j) {
            ASTNode *init_decl = param->seq.list[j];
            if (init_decl->type != AST_INIT_DECL) continue;

            ASTNode *declr = init_decl->id.declr;
            Type *type = parse_declarator(declr, param_type);

            if (!is_valid_type(type)) {
                fprintf(stderr, "❌ Error: Invalid type for parameter '%s'\n", declr->varname);
                type_free(type);
                continue;
            }

            if (is_parameter_redeclared(table, declr->varname, table->scope_depth)) {
                fprintf(stderr, "❌ Error: Parameter '%s' already declared\n", declr->varname);
                type_free(type);
                continue;
            }

            Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
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

// 递归构建符号表
static void build_symbol_table_recursive(ASTNode *node, SymbolTable *table) {
    if (!node) return;

    switch (node->type) {
        case AST_TRANSLATION_UNIT:
        case AST_EXTERNAL_DECL:
            for (int i = 0; i < node->seq.count; ++i) {
                build_symbol_table_recursive(node->seq.list[i], table);
            }
            break;

        case AST_DECLARATION: {
            Type *base_type = get_type_from_declaration_specifiers(node->ds.specs[0]);
        
            for (int i = 0; i < node->seq.count; ++i) {
                ASTNode *init_decl = node->seq.list[i];
                if (init_decl->type == AST_INIT_DECL) {
                    ASTNode *declr = init_decl->id.declr;
                    Type *type = parse_declarator(declr, base_type);
        
                    if (!type) {
                        // 类型不合法，跳过
                        continue;
                    }
        
                    if (!is_valid_type(type)) {
                        fprintf(stderr, "❌ Error: Invalid type for variable '%s'\n", declr->varname);
                        type_free(type);
                        continue;
                    }
        
                    if (is_variable_redeclared(table, declr->varname)) {
                        fprintf(stderr, "❌ Error: Variable '%s' already declared in current scope\n", declr->varname);
                        type_free(type);
                        continue;
                    }
        
                    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
                    sym->name = strdup(declr->varname);
                    sym->type = type;
                    sym->scope_depth = table->scope_depth;
                    sym->is_constant = 0;
                    sym->is_parameter = 0;
                    sym->ast_node = init_decl;
        
                    symbol_table_add(table, sym);
                }
            }
            break;
        }

        case AST_FUNC_TYPE: {
            handle_function_parameters(node, table);

            // 递归处理函数体（进入函数体作用域）
            if (node->ft.body) {
                build_symbol_table_recursive(node->ft.body, table);
            }

            // 离开函数作用域
            symbol_table_leave_scope(table);
            break;
        }

        case AST_COMPOUND_STMT:
            symbol_table_enter_scope(table);
            for (int i = 0; i < node->seq.count; ++i) {
                build_symbol_table_recursive(node->seq.list[i], table);
            }
            symbol_table_leave_scope(table);
            break;

        case AST_EXPR_STMT:
            // 表达式语句（如赋值、函数调用）的类型检查仍需后续处理
            break;

        default:
            break;
    }
}

// 公共接口：构建符号表并进行类型检查
void build_symbol_table(ASTNode *root, SymbolTable *table) {
    build_symbol_table_recursive(root, table);
}