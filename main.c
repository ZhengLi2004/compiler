#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "c99.tab.h"
#include "symbol_table.h"

extern FILE* yyin;
extern int yyparse();
extern ASTNode* ast_root;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Failed to open file");
        return 1;
    }

    if (yyparse() != 0) {
        fprintf(stderr, "Parsing failed\n");
        fclose(yyin);
        return 1;
    }

    ast_print(ast_root, 2);

    SymbolTable* symtab = symbol_table_create();
    build_symbol_table(ast_root, symtab);

    printf("Symbol Table:\n");
    symbol_table_print(symtab, stdout);

    symbol_table_free(symtab);
    ast_free(ast_root);
    fclose(yyin);
    return 0;
}