#include <stdio.h>
#include <stdlib.h>
#include "type.h"

Type* type_basic(const char* name) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = TYPE_BASIC;
    t->basic = strdup(name);
    return t;
}

Type* type_pointer(Type* base) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = TYPE_POINTER;
    t->pointer.base = base;
    return t;
}

Type* type_array(Type* base, int size) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = TYPE_ARRAY;
    t->array.base = base;
    t->array.size = size;
    return t;
}

Type* copy_type(Type *src) {
    if (!src) return NULL;

    Type* dst = (Type*)malloc(sizeof(Type));
    dst->kind = src->kind;

    switch (src->kind) {
        case TYPE_BASIC:
            dst->basic = strdup(src->basic);
            break;
        case TYPE_POINTER:
            dst->pointer.base = copy_type(src->pointer.base);
            break;
        case TYPE_ARRAY:
            dst->array.base = copy_type(src->array.base);
            dst->array.size = src->array.size;
            break;
        case TYPE_FUNCTION:
            dst->function.return_type = copy_type(src->function.return_type);
            dst->function.param_count = src->function.param_count;
            dst->function.param_types = (Type**)malloc(dst->function.param_count * sizeof(Type*));
            for (int i = 0; i < dst->function.param_count; ++i) {
                dst->function.param_types[i] = copy_type(src->function.param_types[i]);
            }
            break;
    }

    return dst;
}

Type* type_function(Type* return_type, Type** param_types, int param_count) {
    Type* t = (Type*)malloc(sizeof(Type));
    t->kind = TYPE_FUNCTION;
    t->function.return_type = copy_type(return_type);  // 深拷贝

    t->function.param_types = (Type**)malloc(param_count * sizeof(Type*));
    for (int i = 0; i < param_count; ++i) {
        t->function.param_types[i] = copy_type(param_types[i]);  // 深拷贝
    }
    t->function.param_count = param_count;
    return t;
}

void type_print(Type* type, FILE* out) {
    if (!type) {
        fprintf(out, "null");
        return;
    }
    switch (type->kind) {
        case TYPE_BASIC:
            fprintf(out, "%s", type->basic);
            break;
        case TYPE_POINTER:
            fprintf(out, "pointer to ");
            type_print(type->pointer.base, out);
            break;
        case TYPE_ARRAY:
            fprintf(out, "array[%d] of ", type->array.size);
            type_print(type->array.base, out);
            break;
        case TYPE_FUNCTION:
            fprintf(out, "function returning ");
            type_print(type->function.return_type, out);
            fprintf(out, " with %d parameters", type->function.param_count);
            break;
    }
}