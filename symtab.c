#include "symtab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1024

static Symbol *table[HASH_SIZE];
static int current_scope = 0;

static unsigned hash(const char *s) {
    unsigned h = 0;
    while (*s) h = h * 33 + *s++;
    return h % HASH_SIZE;
}

void init_symtab(void) {
    memset(table, 0, sizeof(table));
    current_scope = 0;
}

void enter_scope(void) {
    current_scope++;
}

void exit_scope(void) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol *sym = table[i], *prev = NULL;
        while (sym) {
            if (sym->scope_level == current_scope) {
                Symbol *to_delete = sym;
                if (prev) prev->next = sym->next;
                else table[i] = sym->next;
                sym = sym->next;
                free(to_delete->name);
                free(to_delete);
            } else {
                prev = sym;
                sym = sym->next;
            }
        }
    }
    current_scope--;
}

void insert_symbol(const char *name, SymbolKind kind) {
    unsigned idx = hash(name);
    Symbol *sym = malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->kind = kind;
    sym->scope_level = current_scope;
    sym->next = table[idx];
    table[idx] = sym;
}

Symbol *lookup_symbol(const char *name) {
    unsigned idx = hash(name);
    Symbol *sym = table[idx];
    while (sym) {
        if (strcmp(sym->name, name) == 0)
            return sym;
        sym = sym->next;
    }
    return NULL;
}

void print_symtab(void) {
    printf("Symbol Table (Scope level %d):\n", current_scope);
    for (int i = 0; i < HASH_SIZE; i++) {
        for (Symbol *sym = table[i]; sym; sym = sym->next) {
            printf("  [%s] kind=%d, scope=%d\n", sym->name, sym->kind, sym->scope_level);
        }
    }
}