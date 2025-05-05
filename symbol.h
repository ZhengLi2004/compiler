#ifndef SYMBOL_H
#define SYMBOL_H

#include "ast.h"
#include "type.h"
#include <llvm-c/Core.h>

typedef struct Symbol {
    char *name;
    Type *type;
    int scope_depth;
    int is_constant;
    int is_parameter;
    ASTNode *ast_node;
    LLVMValueRef llvm_value;
} Symbol;

#endif