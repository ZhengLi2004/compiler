#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "ast.h"
#include "symbol_table.h"
#include "type_converter.h"
#include <llvm-c/Core.h>

typedef struct LoopContext {
    LLVMBasicBlockRef break_block;
    LLVMBasicBlockRef continue_block;
} LoopContext;

typedef struct LoopStack {
    LoopContext *contexts;
    int size;
    int capacity;
} LoopStack;

typedef struct CodeGenerator {
    LLVMContextRef context;
    LLVMModuleRef module;
    LLVMBuilderRef builder;
    SymbolTable *symbol_table;
    TypeConverter *type_converter;
    LoopStack *loop_stack;
} CodeGenerator;

CodeGenerator* codegen_create(SymbolTable *table);
LLVMModuleRef codegen_generate(CodeGenerator *gen, ASTNode *root);
void codegen_visit_node(CodeGenerator *gen, ASTNode *node, LLVMValueRef *value);

LoopStack* loop_stack_create();
void append_loop_context(LoopStack *stack, LoopContext *context);
void pop_loop_context(LoopStack *stack);
LoopContext* get_current_loop_context(LoopStack *stack);

#endif