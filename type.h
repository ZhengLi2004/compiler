#ifndef TYPE_H
#define TYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_BASIC,
    TYPE_POINTER,
    TYPE_ARRAY,
    TYPE_FUNCTION
} TypeKind;

typedef struct Type {
    TypeKind kind;
    union {
        // 基本类型 (int,double,void)
        char *basic;

        // 指针类型
        struct {
            struct Type *base;
        } pointer;

        // 数组类型
        struct {
            struct Type *base;
            int size; // -1 代表不完整
        } array;

        // 函数类型
        struct {
            struct Type *return_type;
            struct Type **param_types;
            int param_count;
        } function;
    };
} Type;

// 构造基本类型
Type* type_basic(const char* name);

// 构造指针类型
Type* type_pointer(Type* base);

// 构造数组类型
Type* type_array(Type* base, int size);

// 构造函数类型
Type* type_function(Type* return_type, Type** param_types, int param_count);

// 打印类型
void type_print(Type* type, FILE* out);

#endif