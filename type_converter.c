#include "type_converter.h"
#include "ast.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct TypeConverter {
    LLVMContextRef context;
};

TypeConverter* type_converter_create(LLVMContextRef context) {
    TypeConverter *converter = malloc(sizeof(TypeConverter));
    converter->context = context;
    return converter;
}

// 主转换函数
LLVMTypeRef convert_ast_type(TypeConverter *converter, ASTNode *ast_type) {
    if (!ast_type) {
        return LLVMVoidTypeInContext(converter->context);
    }

    printf("%d\n",ast_type->type);

    switch (ast_type->type) {
        case AST_TYPE_NAME:
            if (strcmp(ast_type->varname, "int") == 0)
                return LLVMInt32TypeInContext(converter->context);
            else if (strcmp(ast_type->varname, "double") == 0)
                return LLVMDoubleTypeInContext(converter->context);
            else if (strcmp(ast_type->varname, "void") == 0)
                return LLVMVoidTypeInContext(converter->context);
            else {
                printf("Unknown type: %s\n", ast_type->varname);
                exit(1);
            }
            break;

        case AST_POINTER_TYPE: {
            LLVMTypeRef base = convert_ast_type(converter, ast_type->ptr_to);
            return LLVMPointerType(base, 0);
        }

        case AST_ARRAY_TYPE: {
            LLVMTypeRef base = convert_ast_type(converter, ast_type->at.base);
            int size = 1;
            if (ast_type->at.size) {
                if (ast_type->at.size->type == AST_INT) {
                    size = ast_type->at.size->intval;
                } else {
                    printf("Array size must be a constant integer\n");
                    exit(1);
                }
            }
            return LLVMArrayType(base, size);
        }

        case AST_FUNC_TYPE: {
            LLVMTypeRef return_type = convert_ast_type(converter, ast_type->ft.ret_type);
            int param_count = ast_type->ft.params ? ast_type->ft.params->pl.pcount : 0;
            LLVMTypeRef *param_types = NULL;

            if (param_count > 0) {
                param_types = malloc(sizeof(LLVMTypeRef) * param_count);
                for (int i = 0; i < param_count; i++) {
                    param_types[i] = convert_ast_type(converter, ast_type->ft.params->pl.params[i]);
                }
            }

            return LLVMFunctionType(return_type, param_types, param_count, 0);
        }

        default:
            printf("Unsupported type in convert_ast_type\n");
            exit(1);
    }
}