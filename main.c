#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "c99.tab.h"
#include "symbol_table.h"
#include "type_check.h"

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
        fprintf(stderr, "❌ Parsing failed\n");
        fclose(yyin);
        return 1;
    }

    // 打印AST（可选）
    ast_print(ast_root, 2);

    // 构建符号表
    SymbolTable* symtab = symbol_table_create();
    build_symbol_table(ast_root, symtab);

    printf("✅ Symbol table built:\n");
    symbol_table_print(symtab, stdout);

    // 类型检查
    if (type_check_ast(ast_root, symtab) == 0) {
        printf("✅ Type check passed\n");
    } else {
        printf("❌ Type check failed\n");
        fclose(yyin);
        return 1;
    }

    // 清理
    symbol_table_free(symtab);
    ast_free(ast_root);
    fclose(yyin);
    return 0;
}
