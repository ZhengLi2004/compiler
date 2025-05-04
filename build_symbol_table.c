#include "ast.h"
#include "type.h"
#include "symbol_table.h"

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
                int is_variadic = 0;

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

                return type_function(return_type, param_types, param_count, is_variadic);
            }
        case AST_VAR:
            return base_type;
        default:
            return base_type;
    }
}

void build_symbol_table(ASTNode* node, SymbolTable* symtab) {
    if (!node) return;

    switch (node->type) {
        case AST_EXPR_STMT:
            build_symbol_table(node->expr, symtab);
            break;

        case AST_IF:
            build_symbol_table(node->sif.cond, symtab);
            build_symbol_table(node->sif.then_s, symtab);
            if (node->sif.else_s) build_symbol_table(node->sif.else_s, symtab);
            break;

        case AST_WHILE:
            build_symbol_table(node->sw.cond, symtab);
            build_symbol_table(node->sw.body, symtab);
            break;

        case AST_DO_WHILE:
            build_symbol_table(node->sdw.body, symtab);
            build_symbol_table(node->sdw.cond, symtab);
            break;

        case AST_FOR:
            build_symbol_table(node->sf.init, symtab);
            build_symbol_table(node->sf.cond, symtab);
            build_symbol_table(node->sf.post, symtab);
            build_symbol_table(node->sf.body, symtab);
            break;

        case AST_ASSIGN:
            build_symbol_table(node->assign.l, symtab);
            build_symbol_table(node->assign.r, symtab);
            break;

        case AST_CALL:
            for (int i = 0; i < node->call.argc; ++i) {
                build_symbol_table(node->call.args[i], symtab);
            }
            break;

        case AST_COMPOUND_STMT:
            symbol_table_enter_scope(symtab);
            printf("DEBUG: Entering scope %d (compound statement)\n", symtab->scope_depth);
            for (int i = 0; i < node->seq.count; ++i) {
                build_symbol_table(node->seq.list[i], symtab);
            }
            printf("DEBUG: Current scope %d after processing compound statement:\n", symtab->scope_depth);
            symbol_table_print(symtab, stdout);
            symbol_table_leave_scope(symtab);
            break;

        case AST_DECLARATION:
            {
                // 获取声明说明符的类型（如 int, double）
                Type* base_type = get_type_from_declaration_specifiers(node->declaration.specs[0]);

                // 遍历所有初始化声明符（如变量声明）
                for (int i = 0; i < node->declaration.icount; ++i) {
                    ASTNode* init_decl = node->declaration.inits[i];

                    if (init_decl->type == AST_INIT_DECL) {
                        ASTNode* declr = init_decl->id.declr;
                        ASTNode* var_node = declr;

                        while (var_node->type == AST_ARRAY_TYPE)
                            var_node = var_node->at.base;

                        if (var_node->type == AST_VAR) {
                            Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
                            sym->name = strdup(var_node->varname);
                            sym->type = parse_declarator(declr, base_type);
                            sym->scope_depth = symtab->scope_depth;
                            sym->is_constant = 0;
                            sym->is_parameter = 0;
                            sym->ast_node = init_decl;
                            symbol_table_add(symtab, sym);
                        }
                    }
                }
            }
            break;

        case AST_FUNC_TYPE:
            {
                Type* return_type = get_type_from_declaration_specifiers(node->ft.ret_type);
                Type** param_types = NULL;
                int param_count = 0;

                if (node->ft.params && node->ft.params->type == AST_PARAM_LIST) {
                    for (int i = 0; i < node->ft.params->pl.pcount; ++i) {
                        ASTNode* param = node->ft.params->pl.params[i];
                        if (param->type == AST_PARAM && param->param.declr && param->param.declr->type == AST_VAR) {
                            Type* param_type = get_type_from_declaration_specifiers(param->param.dspecs[0]);
                            param_types = realloc(param_types, (param_count + 1) * sizeof(Type*));
                            param_types[param_count++] = param_type;
                        }
                    }
                }

                Type* func_type = type_function(return_type, param_types, param_count, 0);
                Symbol* sym = (Symbol*)malloc(sizeof(Symbol));
                sym->name = strdup(node->ft.name);
                sym->type = func_type;
                sym->scope_depth = symtab->scope_depth;
                sym->is_constant = 0;
                sym->is_parameter = 0;
                sym->ast_node = node;
                symbol_table_add(symtab, sym);

                symbol_table_enter_scope(symtab);
                printf("DEBUG: Entering scope %d (function: %s)\n", symtab->scope_depth, node->ft.name);

                if (node->ft.params && node->ft.params->type == AST_PARAM_LIST) {
                    for (int i = 0; i < node->ft.params->pl.pcount; ++i) {
                        ASTNode* param = node->ft.params->pl.params[i];
                        if (param->type == AST_PARAM && param->param.declr && param->param.declr->type == AST_VAR) {
                            Symbol* param_sym = (Symbol*)malloc(sizeof(Symbol));
                            param_sym->name = strdup(param->param.declr->varname);
                            param_sym->type = param_types[i];
                            param_sym->scope_depth = symtab->scope_depth;
                            param_sym->is_constant = 0;
                            param_sym->is_parameter = 1;
                            param_sym->ast_node = param->param.declr;
                            symbol_table_add(symtab, param_sym);
                        }
                    }
                }

                build_symbol_table(node->ft.body, symtab);

                printf("DEBUG: Current scope %d (function: %s) after processing body:\n", symtab->scope_depth, node->ft.name);
                symbol_table_print(symtab, stdout);

                symbol_table_leave_scope(symtab);
            }
            break;

        case AST_INIT_LIST:
            for (int i = 0; i < node->seq.count; ++i) {
                build_symbol_table(node->seq.list[i], symtab);
            }
            break;

        case AST_DESIGNATION:
            for (int i = 0; i < node->des; ++i) {
                build_symbol_table(node->des[i], symtab);
            }
            break;

        case AST_EXTERNAL_DECL:
            for (int i = 0; i < node->seq.count; ++i) {
                build_symbol_table(node->seq.list[i], symtab);
            }
            break;

        case AST_TRANSLATION_UNIT:
            for (int i = 0; i < node->seq.count; ++i) {
                build_symbol_table(node->seq.list[i], symtab);
            }
            break;

        default:
            break;
    }
}