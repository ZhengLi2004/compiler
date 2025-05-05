#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "symbol.h"
#include <llvm-c/Core.h>

typedef struct SymbolTable {
    int scope_depth;
    struct Scope **scopes;
    int scope_count;
} SymbolTable;

typedef struct Scope {
    Symbol** symbols;
    int symbol_count;
} Scope;

Symbol* symbol_create(const char *name, LLVMTypeRef type, int scope_depth, int is_constant, int is_parameter, ASTNode *ast_node);

SymbolTable* symbol_table_create();
void symbol_table_enter_scope(SymbolTable* table);
void symbol_table_leave_scope(SymbolTable* table);
void symbol_table_add(SymbolTable* table, Symbol* symbol);
Symbol* symbol_table_lookup(SymbolTable* table, const char* name);
void symbol_table_print(SymbolTable* table, FILE* out);

#endif