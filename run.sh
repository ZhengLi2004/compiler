#!/bin/bash
set -e

# 检查测试文件是否存在
if [ ! -f test.c ]; then
    echo "❌ Error: test.c not found"
    exit 1
fi

# 执行编译器
./c99c test.c

echo "✅ Type checking completed"