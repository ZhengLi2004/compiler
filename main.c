#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "c99.tab.h"  // Bison 生成的头文件

extern FILE *yyin;  // 来自 flex 的输入流
extern int yyparse();  // Bison 的解析函数

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source-file>\n", argv[0]);
        return 1;
    }

    // 打开源代码文件
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("Error opening file");
        return 1;
    }
    // 解析源文件，构建 AST
    if (yyparse() == 0) {
        ast_print(ast_root, 4);
        printf("Parsing successful!\n");
    } else {
        fprintf(stderr, "Parsing failed!\n");
        fclose(yyin);
        return 1;
    }

    fclose(yyin);
    return 0;
}
