#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "c99.tab.h"
#include "symbol_table.h"
#include "code_generator.h"
#include "build_symbol_table.h"

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

    // 创建代码生成器
    CodeGenerator *gen = codegen_create(symtab);
    
    // 生成IR
    LLVMModuleRef module = codegen_generate(gen, ast_root);

    // 输出IR到文件
    char *ir = LLVMPrintModuleToString(module);
    FILE *out = fopen("output.ll", "w");
    fprintf(out, "%s", ir);
    fclose(out);
    
    // 清理
    fclose(yyin);
    return 0;
}
