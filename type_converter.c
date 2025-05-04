#include "type_converter.h"
#include "ast.h"
#include <string.h>

struct TypeConverter {
    LLVMContextRef context;
};

TypeConverter* type_converter_create(LLVMContextRef context) {
    TypeConverter *converter = malloc(sizeof(TypeConverter));
    converter->context = context;
    return converter;
}

void type_converter_free(TypeConverter *converter) {
    free(converter);
}

// 内部函数：基本类型转换
static LLVMTypeRef convert_basic_type(TypeConverter *converter, ASTNode *type_node) {
    if (strcmp(type_node->str, "void") == 0) {
        return LLVMVoidTypeInContext(converter->context);
    } else if (strcmp(type_node->str, "int") == 0) {
        return LLVMInt32TypeInContext(converter->context);
    } else if (strcmp(type_node->str, "double") == 0) {
        return LLVMDoubleTypeInContext(converter->context);
    }
    return LLVMInt32TypeInContext(converter->context);
}

// 内部函数：指针类型转换
static LLVMTypeRef convert_pointer_type(TypeConverter *converter, ASTNode *ptr_node) {
    LLVMTypeRef pointee_type = convert_ast_type(converter, ptr_node->ptr_to);
    return LLVMPointerType(pointee_type, 0);
}

// 主转换函数
LLVMTypeRef convert_ast_type(TypeConverter *converter, ASTNode *ast_type) {
    switch(ast_type->type) {
        case AST_TYPE_NAME:
            return convert_basic_type(converter, ast_type);
        case AST_POINTER_TYPE:
            return convert_pointer_type(converter, ast_type);
        default:
            return LLVMInt32TypeInContext(converter->context);
    }
}
