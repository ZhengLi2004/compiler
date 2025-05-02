#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

SymbolTable* symbol_table_create() {
    SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
    table->scopes = (Scope**)malloc(sizeof(Scope*));
    table->scopes[0] = (Scope*)malloc(sizeof(Scope));
    table->scopes[0]->symbols = NULL;
    table->scopes[0]->symbol_count = 0;
    table->scope_count = 1;
    table->scope_depth = 0;
    return table;
}

void symbol_table_enter_scope(SymbolTable* table) {
    table->scope_count++;
    table->scopes = (Scope**)realloc(table->scopes, table->scope_count * sizeof(Scope*));
    table->scopes[table->scope_depth + 1] = (Scope*)malloc(sizeof(Scope));
    table->scopes[table->scope_depth + 1]->symbols = NULL;
    table->scopes[table->scope_depth + 1]->symbol_count = 0;
    table->scope_depth++;
}

void symbol_table_leave_scope(SymbolTable* table) {
    if (table->scope_depth > 0) {
        Scope* scope = table->scopes[table->scope_depth];
        for (int i = 0; i < scope->symbol_count; ++i) {
            free(scope->symbols[i]->name);
            type_free(scope->symbols[i]->type);
            free(scope->symbols[i]);
        }
        free(scope->symbols);
        free(scope);
        table->scope_depth--;
        table->scope_count--;
    }
}

void symbol_table_add(SymbolTable* table, Symbol* symbol) {
    Scope* scope = table->scopes[table->scope_depth];
    scope->symbols = (Symbol**)realloc(scope->symbols, (scope->symbol_count + 1) * sizeof(Symbol*));
    scope->symbols[scope->symbol_count++] = symbol;
}

Symbol* symbol_table_lookup(SymbolTable* table, const char* name) {
    for (int i = table->scope_depth; i >= 0; --i) {
        Scope* scope = table->scopes[i];
        for (int j = 0; j < scope->symbol_count; ++j) {
            if (strcmp(scope->symbols[j]->name, name) == 0) {
                return scope->symbols[j];
            }
        }
    }
    return NULL;
}

void symbol_table_print(SymbolTable* table, FILE* out) {
    for (int i = 0; i < table->scope_count; ++i) {
        fprintf(out, "Scope %d:\n", i);
        Scope* scope = table->scopes[i];
        for (int j = 0; j < scope->symbol_count; ++j) {
            Symbol* sym = scope->symbols[j];
            fprintf(out, "  %s: ", sym->name);
            type_print(sym->type, out);
            fprintf(out, "\n");
        }
    }
}

void symbol_table_free(SymbolTable* table) {
    free(table->scopes);
    free(table);
}