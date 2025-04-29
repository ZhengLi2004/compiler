// symtab.h
#ifndef SYMTAB_H
#define SYMTAB_H

typedef enum {
    SYM_VAR,
    SYM_FUNC,
    SYM_STRUCT,
} SymbolKind;

typedef struct Symbol {
    char *name;
    SymbolKind kind;
    int scope_level;
    struct Symbol *next;
} Symbol;

void init_symtab(void);
void enter_scope(void);
void exit_scope(void);
void insert_symbol(const char *name, SymbolKind kind);
Symbol *lookup_symbol(const char *name);

void print_symtab(void);

#endif