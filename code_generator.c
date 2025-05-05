#include "code_generator.h"
#include <stdio.h>
#include <assert.h>

CodeGenerator* codegen_create(SymbolTable *table) {
    CodeGenerator *gen = malloc(sizeof(CodeGenerator));
    gen->context = LLVMGetGlobalContext();
    gen->module = LLVMModuleCreateWithNameInContext("c99_module", gen->context);
    gen->builder = LLVMCreateBuilderInContext(gen->context);
    gen->symbol_table = table;
    gen->loop_stack = loop_stack_create();
    gen->type_converter = type_converter_create(gen->context);
    return gen;
}

LLVMModuleRef codegen_generate(CodeGenerator *gen, ASTNode *root) {
    // 处理全局变量和函数定义
    if(root->type == AST_TRANSLATION_UNIT) {
        for(int i = 0; i < root->seq.count; i++) {
            codegen_visit_node(gen, root->seq.list[i], NULL);
        }
    }
    return gen->module;
}

LoopStack* loop_stack_create() {
    LoopStack *stack = malloc(sizeof(LoopStack));
    stack->capacity = 4;
    stack->size = 0;
    stack->contexts = malloc(sizeof(LoopContext) * stack->capacity);
    return stack;
}

void append_loop_context(LoopStack *stack, LoopContext *context) {
    if (stack->size >= stack->capacity) {
        stack->capacity *= 2;
        stack->contexts = realloc(stack->contexts, sizeof(LoopContext) * stack->capacity);
    }
    stack->contexts[stack->size++] = *context;
}

void pop_loop_context(LoopStack *stack) {
    if (stack->size > 0) {
        stack->size--;
    }
}

LoopContext* get_current_loop_context(LoopStack *stack) {
    if (stack && stack->size > 0) {
        return &stack->contexts[stack->size - 1];
    }
    return NULL;
}

void codegen_visit_node(CodeGenerator *gen, ASTNode *node, LLVMValueRef *value) {
    if (!node) return;
    
    switch (node->type) {
        case AST_INT:
            *value = LLVMConstInt(LLVMInt32TypeInContext(gen->context), node->intval, 0);
            break;
            
        case AST_DOUBLE:
            *value = LLVMConstReal(LLVMDoubleTypeInContext(gen->context), node->fval);
            break;
            
        case AST_VAR: {
            Symbol* sym = symbol_table_lookup(gen->symbol_table, node->varname);
            if (!sym) {
                fprintf(stderr, "Undefined variable: %s\n", node->varname);
                exit(1);
            }
            *value = LLVMBuildLoad(gen->builder, sym->llvm_value, node->varname);
            break;
        }
        
        case AST_BINOP: {
            LLVMValueRef lhs_val, rhs_val;
            codegen_visit_node(gen, node->bin.lhs, &lhs_val);
            codegen_visit_node(gen, node->bin.rhs, &rhs_val);
            
            switch (node->bin.op) {
                case '+': *value = LLVMBuildAdd(gen->builder, lhs_val, rhs_val, "add"); break;
                case '-': *value = LLVMBuildSub(gen->builder, lhs_val, rhs_val, "sub"); break;
                case '*': *value = LLVMBuildMul(gen->builder, lhs_val, rhs_val, "mul"); break;
                case '/': *value = LLVMBuildUDiv(gen->builder, lhs_val, rhs_val, "div"); break;
                case '%': *value = LLVMBuildURem(gen->builder, lhs_val, rhs_val, "rem"); break;
                case '<': *value = LLVMBuildICmp(gen->builder, LLVMIntULT, lhs_val, rhs_val, "lt"); break;
                case '>': *value = LLVMBuildICmp(gen->builder, LLVMIntUGT, lhs_val, rhs_val, "gt"); break;
                case 'l': // <=
                    *value = LLVMBuildICmp(gen->builder, LLVMIntULE, lhs_val, rhs_val, "le");
                    break;
                case 'g': // >=
                    *value = LLVMBuildICmp(gen->builder, LLVMIntUGE, lhs_val, rhs_val, "ge");
                    break;
                case 'e': // ==
                    *value = LLVMBuildICmp(gen->builder, LLVMIntEQ, lhs_val, rhs_val, "eq");
                    break;
                case '!': // !=
                    *value = LLVMBuildICmp(gen->builder, LLVMIntNE, lhs_val, rhs_val, "ne");
                    break;
            }
            break;
        }
        
        case AST_UNOP: {
            LLVMValueRef expr_val;
            codegen_visit_node(gen, node->un.rhs, &expr_val);
            
            switch (node->un.op) {
                case '-': *value = LLVMBuildNeg(gen->builder, expr_val, "neg"); break;
                case '~': *value = LLVMBuildNot(gen->builder, expr_val, "not"); break;
                case '!': *value = LLVMBuildNot(gen->builder, expr_val, "not"); break;
                case '+': *value = expr_val; break;
            }
            break;
        }
        
        case AST_ASSIGN: {
            LLVMValueRef rhs_val;
            codegen_visit_node(gen, node->assign.r, &rhs_val);
            
            // 左值必须是变量或指针
            if (node->assign.l->type == AST_VAR) {
                Symbol* lhs_sym = symbol_table_lookup(gen->symbol_table, node->assign.l->varname);
                if (!lhs_sym) {
                    fprintf(stderr, "Undefined variable in assignment: %s\n", node->assign.l->varname);
                    exit(1);
                }
                LLVMBuildStore(gen->builder, rhs_val, lhs_sym->llvm_value);
                *value = rhs_val;
            } else if (node->assign.l->type == AST_POINTER_TYPE) {
                // 处理指针赋值
                LLVMValueRef ptr_val;
                codegen_visit_node(gen, node->assign.l, &ptr_val);
                LLVMBuildStore(gen->builder, rhs_val, ptr_val);
                *value = rhs_val;
            }
            break;
        }
        
        case AST_CALL: {
            // 获取函数
            LLVMValueRef func = LLVMGetNamedFunction(gen->module, node->call.fname);
            if (!func) {
                fprintf(stderr, "Undefined function: %s\n", node->call.fname);
                exit(1);
            }
            
            // 生成参数
            LLVMValueRef* args = malloc(sizeof(LLVMValueRef) * node->call.argc);
            for (int i = 0; i < node->call.argc; i++) {
                codegen_visit_node(gen, node->call.args[i], &args[i]);
            }
            
            // 调用函数
            *value = LLVMBuildCall(gen->builder, func, args, node->call.argc, "call");
            break;
        }
        
        case AST_COMPOUND_STMT:
            symbol_table_enter_scope(gen->symbol_table);
            for (int i = 0; i < node->seq.count; i++) {
                codegen_visit_node(gen, node->seq.list[i], NULL);
            }
            symbol_table_leave_scope(gen->symbol_table);
            break;
            
        case AST_EXPR_STMT:
            if (node->expr) {
                codegen_visit_node(gen, node->expr, NULL);
            }
            break;
            
        case AST_IF: {
            LLVMValueRef cond_val;
            codegen_visit_node(gen, node->sif.cond, &cond_val);
            
            LLVMValueRef current_func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(gen->builder));
            LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "then");
            LLVMBasicBlockRef else_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "else");
            LLVMBasicBlockRef merge_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "if_merge");
            
            LLVMBuildCondBr(gen->builder, cond_val, then_block, else_block);
            
            // Then 分支
            LLVMPositionBuilderAtEnd(gen->builder, then_block);
            codegen_visit_node(gen, node->sif.then_s, NULL);
            if (LLVMGetInsertBlock(gen->builder) && 
                LLVMGetBasicBlockParent(LLVMGetInsertBlock(gen->builder)) == current_func) {
                LLVMBuildBr(gen->builder, merge_block);
            }
            
            // Else 分支
            LLVMPositionBuilderAtEnd(gen->builder, else_block);
            if (node->sif.else_s) {
                codegen_visit_node(gen, node->sif.else_s, NULL);
                if (LLVMGetInsertBlock(gen->builder) && 
                    LLVMGetBasicBlockParent(LLVMGetInsertBlock(gen->builder)) == current_func) {
                    LLVMBuildBr(gen->builder, merge_block);
                }
            } else {
                LLVMBuildBr(gen->builder, merge_block);
            }
            
            // 合并块
            LLVMPositionBuilderAtEnd(gen->builder, merge_block);
            break;
        }
        
        case AST_WHILE: {
            // 创建循环块
            LLVMValueRef current_func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(gen->builder));
            LLVMBasicBlockRef cond_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "while_cond");
            LLVMBasicBlockRef body_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "while_body");
            LLVMBasicBlockRef end_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "while_end");
            
            // 保存当前循环块用于break/continue
            LoopContext loop_context = {
                .break_block = end_block,
                .continue_block = cond_block
            };
            append_loop_context(gen->loop_stack, &loop_context);
            
            // 跳转到条件块
            LLVMBuildBr(gen->builder, cond_block);
            
            // 条件块
            LLVMPositionBuilderAtEnd(gen->builder, cond_block);
            LLVMValueRef cond_val;
            codegen_visit_node(gen, node->sw.cond, &cond_val);
            LLVMBuildCondBr(gen->builder, cond_val, body_block, end_block);
            
            // 循环体
            LLVMPositionBuilderAtEnd(gen->builder, body_block);
            codegen_visit_node(gen, node->sw.body, NULL);
            LLVMBuildBr(gen->builder, cond_block);
            
            // 循环结束块
            LLVMPositionBuilderAtEnd(gen->builder, end_block);
            pop_loop_context(gen->loop_stack);
            break;
        }
        
        case AST_DO_WHILE: {
            LLVMValueRef current_func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(gen->builder));
            LLVMBasicBlockRef body_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "do_body");
            LLVMBasicBlockRef cond_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "do_cond");
            LLVMBasicBlockRef end_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "do_end");
            
            // 保存循环上下文
            LoopContext loop_context = {
                .break_block = end_block,
                .continue_block = cond_block
            };
            append_loop_context(gen->loop_stack, &loop_context);
            
            // 进入循环体
            LLVMBuildBr(gen->builder, body_block);
            LLVMPositionBuilderAtEnd(gen->builder, body_block);
            
            // 处理循环体
            codegen_visit_node(gen, node->sdw.body, NULL);
            
            // 条件块
            LLVMBuildBr(gen->builder, cond_block);
            LLVMPositionBuilderAtEnd(gen->builder, cond_block);
            LLVMValueRef cond_val;
            codegen_visit_node(gen, node->sdw.cond, &cond_val);
            LLVMBuildCondBr(gen->builder, cond_val, body_block, end_block);
            
            // 结束块
            LLVMPositionBuilderAtEnd(gen->builder, end_block);
            pop_loop_context(gen->loop_stack);
            break;
        }
        
        case AST_FOR: {
            LLVMValueRef cond_val;
            // 进入新作用域
            symbol_table_enter_scope(gen->symbol_table);
            
            // 处理初始化
            if (node->sf.init) {
                codegen_visit_node(gen, node->sf.init, NULL);
            }
            
            LLVMValueRef current_func = LLVMGetBasicBlockParent(LLVMGetInsertBlock(gen->builder));
            LLVMBasicBlockRef cond_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "for_cond");
            LLVMBasicBlockRef body_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "for_body");
            LLVMBasicBlockRef post_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "for_post");
            LLVMBasicBlockRef end_block = LLVMAppendBasicBlockInContext(gen->context, current_func, "for_end");
            
            // 保存循环上下文
            LoopContext loop_context = {
                .break_block = end_block,
                .continue_block = post_block
            };
            append_loop_context(gen->loop_stack, &loop_context);
            
            // 跳转到条件块
            LLVMBuildBr(gen->builder, cond_block);
            
            // 条件块
            LLVMPositionBuilderAtEnd(gen->builder, cond_block);
            if (node->sf.cond) {
                codegen_visit_node(gen, node->sf.cond, &cond_val);
                LLVMBuildCondBr(gen->builder, cond_val, body_block, end_block);
            } else {
                LLVMBuildBr(gen->builder, body_block);
            }
            
            // 循环体
            LLVMPositionBuilderAtEnd(gen->builder, body_block);
            codegen_visit_node(gen, node->sf.body, NULL);
            LLVMBuildBr(gen->builder, post_block);
            
            // 后处理块
            LLVMPositionBuilderAtEnd(gen->builder, post_block);
            if (node->sf.post) {
                codegen_visit_node(gen, node->sf.post, NULL);
            }
            LLVMBuildBr(gen->builder, cond_block);
            
            // 结束块
            LLVMPositionBuilderAtEnd(gen->builder, end_block);
            pop_loop_context(gen->loop_stack);
            symbol_table_leave_scope(gen->symbol_table);
            break;
        }
        
        case AST_BREAK: {
            LoopContext* ctx = get_current_loop_context(gen->loop_stack);
            if (ctx) {
                LLVMBuildBr(gen->builder, ctx->break_block);
            } else {
                fprintf(stderr, "Break outside loop\n");
                exit(1);
            }
            break;
        }
            
        case AST_CONTINUE: {
            LoopContext* ctx = get_current_loop_context(gen->loop_stack);
            if (ctx) {
                LLVMBuildBr(gen->builder, ctx->continue_block);
            } else {
                fprintf(stderr, "Continue outside loop\n");
                exit(1);
            }
            break;
        }
            
        case AST_RETURN:
            if (node->expr) {
                LLVMValueRef return_val;
                codegen_visit_node(gen, node->expr, &return_val);
                LLVMBuildRet(gen->builder, return_val);
            } else {
                LLVMBuildRetVoid(gen->builder);
            }
            break;
        
        case AST_FUNC_TYPE: {
            // 获取返回类型
            LLVMTypeRef ret_type = convert_ast_type(gen->type_converter, node->ft.ret_type);
            int param_count = node->ft.params ? node->ft.params->pl.pcount : 0;
        
            // 转换参数类型
            LLVMTypeRef *param_types = NULL;
            if (param_count > 0) {
                param_types = malloc(sizeof(LLVMTypeRef) * param_count);
                for (int i = 0; i < param_count; i++) {
                    ASTNode *param = node->ft.params->pl.params[i];
                    param_types[i] = convert_ast_type(gen->type_converter, param->param.declr);
                }
            }
        
            // 创建函数类型
            LLVMTypeRef func_type = LLVMFunctionType(ret_type, param_types, param_count, 0);
            LLVMValueRef func = LLVMAddFunction(gen->module, node->ft.name, func_type);
        
            // 创建函数入口块
            LLVMBasicBlockRef entry = LLVMAppendBasicBlockInContext(gen->context, func, "entry");
            LLVMPositionBuilderAtEnd(gen->builder, entry);
        
            // 添加参数到符号表
            if (node->ft.params) {
                for (int i = 0; i < param_count; i++) {
                    LLVMValueRef param = LLVMGetParam(func, i);
                    ASTNode *param_node = node->ft.params->pl.params[i];
                    Symbol *sym = symbol_create(param_node->param.declr->varname, param, 1, 0, 1, param_node->param.declr);
                    symbol_table_add(gen->symbol_table, sym);
                }
            }
        
            // 处理函数体
            if (node->ft.body) {
                codegen_visit_node(gen, node->ft.body, NULL);
            }
            break;
        }
        
        case AST_DECLARATION: {
            // 获取类型说明符（如 int, double, void）
            if (node->declaration.scount <= 0 || node->declaration.specs == NULL) {
                fprintf(stderr, "Error: Declaration has no specifiers.\n");
                exit(1);
            }
        
            ASTNode *type_node = node->declaration.specs[0];
            LLVMTypeRef llvm_type = convert_ast_type(gen->type_converter, type_node);
        
            if (!llvm_type) {
                fprintf(stderr, "Error: Failed to convert type.\n");
                exit(1);
            }
        
            // 遍历所有初始化声明
            for (int i = 0; i < node->declaration.icount; i++) {
                ASTNode *init_node = node->declaration.inits[i];
                if (init_node->type != AST_INIT_DECL) {
                    fprintf(stderr, "Error: Expected AST_INIT_DECL in declaration.\n");
                    continue;
                }
        
                ASTNode *declr = init_node->id.declr;
                if (!declr) {
                    fprintf(stderr, "Error: Declaration has no declarator.\n");
                    exit(1);
                }
        
                // 提取变量名（处理指针、数组等复杂声明）
                ASTNode *var_node = declr;
                while (var_node->type == AST_POINTER_TYPE || var_node->type == AST_ARRAY_TYPE) {
                    if (var_node->type == AST_POINTER_TYPE) {
                        var_node = var_node->ptr_to;
                    } else {
                        var_node = var_node->at.base;
                    }
                }
        
                if (var_node->type != AST_VAR) {
                    fprintf(stderr, "Error: Declarator is not a variable.\n");
                    exit(1);
                }
        
                const char *var_name = var_node->varname;
                if (!var_name) {
                    fprintf(stderr, "Error: Variable name is NULL.\n");
                    exit(1);
                }
        
                // 为变量分配内存
                LLVMValueRef var = LLVMBuildAlloca(gen->builder, llvm_type, var_name);
        
                // 将变量加入符号表
                Symbol *sym = symbol_create(var_name, var, gen->symbol_table->scope_depth, 0, 0, declr);
                if (!sym) {
                    fprintf(stderr, "Error: Failed to create symbol for %s\n", var_name);
                    exit(1);
                }
                symbol_table_add(gen->symbol_table, sym);
        
                // 设置返回值（如需）
                if (value) *value = var;
                break;
            }
            break;
        }
        
        case AST_INIT_DECL: {
            ASTNode *declr = node->id.declr;
            if (!declr) {
                fprintf(stderr, "Error: AST_INIT_DECL has no declarator.\n");
                exit(1);
            }
        
            // 提取变量名
            ASTNode *var_node = declr;
            while (var_node->type == AST_POINTER_TYPE || var_node->type == AST_ARRAY_TYPE) {
                if (var_node->type == AST_POINTER_TYPE) {
                    var_node = var_node->ptr_to;
                } else {
                    var_node = var_node->at.base;
                }
            }
        
            if (var_node->type != AST_VAR) {
                fprintf(stderr, "Error: Declarator is not a variable.\n");
                exit(1);
            }
        
            const char *var_name = var_node->varname;
            if (!var_name) {
                fprintf(stderr, "Error: Variable name is NULL.\n");
                exit(1);
            }
        
            // 获取类型
            LLVMTypeRef var_type = convert_ast_type(gen->type_converter, declr);
            if (!var_type) {
                fprintf(stderr, "Error: Failed to convert variable type.\n");
                exit(1);
            }
        
            // 分配内存
            LLVMValueRef var = LLVMBuildAlloca(gen->builder, var_type, var_name);
        
            // 加入符号表
            Symbol *sym = symbol_create(var_name, var, gen->symbol_table->scope_depth, 0, 0, declr);
            if (!sym) {
                fprintf(stderr, "Error: Failed to create symbol.\n");
                exit(1);
            }
            symbol_table_add(gen->symbol_table, sym);
        
            // 如果有初始化表达式
            if (node->id.init) {
                LLVMValueRef init_val;
                codegen_visit_node(gen, node->id.init, &init_val);
                LLVMBuildStore(gen->builder, init_val, var);
            }
        
            if (value) *value = var;
            break;
        }
        
        case AST_POINTER_TYPE: {
            LLVMTypeRef base_type = convert_ast_type(gen->type_converter, node->ptr_to);
            *value = LLVMPointerType(base_type, 0);
            break;
        }
        
        case AST_ARRAY_TYPE: {
            LLVMTypeRef base_type = convert_ast_type(gen->type_converter, node->at.base);
            LLVMValueRef size_val;
            codegen_visit_node(gen, node->at.size, &size_val);
            *value = LLVMArrayType(base_type, LLVMConstIntGetSExtValue(size_val));
            break;
        }
        
        case AST_PARAM_LIST: {
            // 生成参数类型数组
            int param_count = node->pl.pcount;
            LLVMTypeRef *param_types = malloc(sizeof(LLVMTypeRef) * param_count);
            for (int i = 0; i < param_count; i++) {
                ASTNode* param = node->pl.params[i];
                param_types[i] = convert_ast_type(gen->type_converter, param->param.declr);
            }
            *value = LLVMFunctionType(LLVMVoidTypeInContext(gen->context), param_types, param_count, 0);
            break;
        }
        
        case AST_PARAM: {
            // 参数类型由 declaration_specifiers 提供
            LLVMTypeRef type = convert_ast_type(gen->type_converter, node->param.declr);
            *value = type;
            break;
        }
        
        case AST_INIT_LIST: {
            int count = node->seq.count;
            LLVMValueRef* elements = malloc(sizeof(LLVMValueRef) * count);
            for (int i = 0; i < count; i++) {
                codegen_visit_node(gen, node->seq.list[i], &elements[i]);
            }

            // 假设是数组初始化
            LLVMTypeRef elem_type = LLVMTypeOf(elements[0]);
            LLVMTypeRef array_type = LLVMArrayType(elem_type, count);
            *value = LLVMConstArray(elem_type, elements, count);
            break;
        }
        
        case AST_TYPE_NAME: {
            *value = convert_ast_type(gen->type_converter, node);
            break;
        }
        
        case AST_TRANSLATION_UNIT: {
            // 处理全局声明
            for (int i = 0; i < node->seq.count; i++) {
                codegen_visit_node(gen, node->seq.list[i], NULL);
            }
            break;
        }
        
        case AST_EXTERNAL_DECL: {
            codegen_visit_node(gen, node->seq.list[0], NULL);
            break;
        }
        
        default:
            // 未处理的节点类型
            break;
    }
}