#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H

#include "ast.h"
#include "symbol_table.h"

// 类型检查上下文
typedef struct {
    SymbolTable *symtab;
} TypeCheckContext;

TypeCheckContext* type_check_context_create(SymbolTable *symtab);
void type_check_context_free(TypeCheckContext *ctx);

// 类型检查入口函数
int type_check_ast(ASTNode *root, SymbolTable *symtab);

#endif
