#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "symbol.h"

typedef struct SymbolTable {
    int scope_depth;
    struct Scope **scopes;
    int scope_count;
} SymbolTable;

typedef struct Scope {
    Symbol** symbols;
    int symbol_count;
} Scope;

SymbolTable* symbol_table_create();
void symbol_table_enter_scope(SymbolTable* table);
void symbol_table_leave_scope(SymbolTable* table);
void symbol_table_add(SymbolTable* table, Symbol* symbol);
Symbol* symbol_table_lookup(SymbolTable* table, const char* name);
void symbol_table_print(SymbolTable* table, FILE* out);
void symbol_table_free(SymbolTable* table);

#endif