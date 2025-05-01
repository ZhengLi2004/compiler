# !/bin/bash
rm c99.tab.c c99.tab.h lex.yy.c
lex c99.l
bison -d c99.y
gcc -o c99c main.c c99.tab.c lex.yy.c ast.c -lfl