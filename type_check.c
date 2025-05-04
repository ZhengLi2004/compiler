#include "type_check.h"
#include "ast.h"
#include "symbol_table.h"
#include "type_converter.h"
#include <stdio.h>

TypeCheckContext* type_check_context_create(SymbolTable *symtab) {
    TypeCheckContext *ctx = malloc(sizeof(TypeCheckContext));
    ctx->symtab = symtab;
    return ctx;
}

void type_check_context_free(TypeCheckContext *ctx) {
    free(ctx);
}

static int check_expression(ASTNode *expr, TypeCheckContext *ctx) {
    switch(expr->type) {
        case AST_VAR: {
            Symbol *sym = symbol_table_lookup(ctx->symtab, expr->varname);
            if (!sym) {
                fprintf(stderr, "❌ Error: Undefined variable '%s'\n", expr->varname);
                return -1;
            }
            break;
        }
        case AST_ASSIGN: {
            if (check_expression(expr->assign.l, ctx) != 0 ||
                check_expression(expr->assign.r, ctx) != 0) {
                return -1;
            }
            // 检查类型是否匹配
            break;
        }
        case AST_BINOP: {
            if (check_expression(expr->bin.lhs, ctx) != 0 ||
                check_expression(expr->bin.rhs, ctx) != 0) {
                return -1;
            }
            // 检查操作符是否适用于类型
            break;
        }
        default:
            break;
    }
    return 0;
}

int type_check_ast(ASTNode *root, SymbolTable *symtab) {
    TypeCheckContext *ctx = type_check_context_create(symtab);
    int result = 0;

    if (root->type == AST_TRANSLATION_UNIT) {
        for (int i = 0; i < root->seq.count; i++) {
            ASTNode *unit = root->seq.list[i];
            if (unit->type == AST_FUNC_TYPE) {
                for (int j = 0; j < unit->ft.body->seq.count; j++) {
                    ASTNode *stmt = unit->ft.body->seq.list[j];
                    if (check_expression(stmt, ctx) != 0) {
                        result = -1;
                        break;
                    }
                }
            }
        }
    }

    type_check_context_free(ctx);
    return result;
}
