#ifndef SYMBOL_H
#define SYMBOL_H

#include "ast.h"
#include "type.h"

typedef struct Symbol {
    char *name;
    Type *type;
    int scope_depth;
    int is_constant;
    int is_parameter;
    ASTNode *ast_node;
} Symbol;

#endif