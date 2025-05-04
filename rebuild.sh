#!/bin/bash
set -e

# 清理旧文件
rm -f c99.tab.c c99.tab.h lex.yy.c *.o c99c

# 生成词法和语法分析器
lex c99.l
bison -d c99.y

# 获取 LLVM 编译参数
LLVM_CFLAGS=$(llvm-config --cflags)
LLVM_LDFLAGS=$(llvm-config --ldflags)
LLVM_LIBS=$(llvm-config --libs core support)

# 编译各模块
gcc -c -o ast.o ast.c $LLVM_CFLAGS
gcc -c -o type.o type.c $LLVM_CFLAGS
gcc -c -o symbol_table.o symbol_table.c $LLVM_CFLAGS
gcc -c -o build_symbol_table.o build_symbol_table.c $LLVM_CFLAGS
gcc -c -o type_converter.o type_converter.c $LLVM_CFLAGS
gcc -c -o type_check.o type_check.c $LLVM_CFLAGS
gcc -c -o main.o main.c $LLVM_CFLAGS

# 链接最终可执行文件
gcc -o c99c main.o c99.tab.c lex.yy.c ast.o type.o symbol_table.o \
    build_symbol_table.o type_converter.o type_check.o $LLVM_LDFLAGS $LLVM_LIBS -lfl

echo "✅ Build completed: c99c"