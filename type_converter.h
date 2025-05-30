#ifndef TYPE_CONVERTER_H
#define TYPE_CONVERTER_H

#include "ast.h"
#include <llvm-c/Core.h>

typedef struct {
    LLVMContextRef context;
} TypeConverter;

TypeConverter* type_converter_create(LLVMContextRef context);

LLVMTypeRef convert_ast_type(TypeConverter *converter, ASTNode *ast_type);

#endif