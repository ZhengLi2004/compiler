#include "type_converter.h"
#include "ast.h"
#include <stdio.h>
#include <assert.h>

void test_basic_type_conversion() {
    LLVMContextRef context = LLVMGetGlobalContext();
    TypeConverter *converter = type_converter_create(context);

    ASTNode *int_type = ast_type_name("int");
    LLVMTypeRef llvm_type = convert_ast_type(converter, int_type);
    assert(LLVMGetTypeKind(llvm_type) == LLVMIntegerTypeKind);
    printf("✅ Basic type conversion (int) passed\n");

    ast_free(int_type);
    type_converter_free(converter);
}

void test_pointer_type_conversion() {
    LLVMContextRef context = LLVMGetGlobalContext();
    TypeConverter *converter = type_converter_create(context);

    ASTNode *int_type = ast_type_name("int");
    ASTNode *ptr_type = ast_pointer(int_type);
    LLVMTypeRef llvm_type = convert_ast_type(converter, ptr_type);
    LLVMTypeRef pointee_type = LLVMGetElementType(llvm_type);

    assert(LLVMGetTypeKind(pointee_type) == LLVMIntegerTypeKind);
    printf("✅ Pointer type conversion passed\n");

    ast_free(ptr_type);
    type_converter_free(converter);
}

int main() {
    test_basic_type_conversion();
    test_pointer_type_conversion();
    return 0;
}
