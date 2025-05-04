#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

/* 打印缩进 */
static void print_indent(int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
}

/* 构造器实现（示例，多余的可按需删减） */
ASTNode *ast_int(int v) {
    ASTNode *n = calloc(1, sizeof(*n));
    n->type = AST_INT; n->intval = v; return n;
}
ASTNode *ast_double(double d) {
    ASTNode *n = calloc(1, sizeof(*n));
    n->type = AST_DOUBLE; n->fval = d; return n;
};
ASTNode *ast_var(const char *name) {
    if(name == NULL) {
        printf(stderr, "Error, NULL name passed to ast_var()\n");
        return NULL;
    }
    ASTNode *n = calloc(1, sizeof(*n));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    n->type = AST_VAR; n->varname = strdup(name); return n;
}
ASTNode *ast_binop(char op, ASTNode *l, ASTNode *r) {
    ASTNode *n = calloc(1, sizeof(*n));
    n->type = AST_BINOP; n->bin.op = op; n->bin.lhs = l; n->bin.rhs = r; return n;
}
ASTNode *ast_unop(char op, ASTNode *e) {
    ASTNode *n = calloc(1, sizeof(*n));
    n->type = AST_UNOP; n->un.op = op; n->un.lhs = e; return n;
}
ASTNode *ast_assign(ASTNode *l, ASTNode *r) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_ASSIGN; n->assign.l = l; n->assign.r = r; return n;
}
ASTNode *ast_call(const char *f, ASTNode **args, int n) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_CALL;
    node->call.fname = f? strdup(f):NULL;
    node->call.args = args; node->call.argc = n;
    return node;
}
ASTNode *ast_compound(ASTNode **stmts, int n) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_COMPOUND_STMT;
    node->seq.list = stmts; node->seq.count = n;
    return node;
}
ASTNode *ast_expr_stmt(ASTNode *e) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_EXPR_STMT; n->expr = e; return n;
}
ASTNode *ast_if(ASTNode *c, ASTNode *t, ASTNode *e) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_IF; n->sif.cond = c; n->sif.then_s = t; n->sif.else_s = e;
    return n;
}
ASTNode *ast_while(ASTNode *c, ASTNode *b) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_WHILE; n->sw.cond = c; n->sw.body = b; return n;
}
ASTNode *ast_do_while(ASTNode *b, ASTNode *c) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_DO_WHILE; n->sdw.body = b; n->sdw.cond = c; return n;
}
ASTNode *ast_for(ASTNode *i, ASTNode *c, ASTNode *p, ASTNode *b) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_FOR; n->sf.init = i; n->sf.cond = c; n->sf.post = p; n->sf.body = b;
    return n;
}
ASTNode *ast_break(void) {
    ASTNode *n = calloc(1,sizeof(*n)); n->type = AST_BREAK; return n;
}
ASTNode *ast_continue(void) {
    ASTNode *n = calloc(1,sizeof(*n)); n->type = AST_CONTINUE; return n;
}
ASTNode *ast_return(ASTNode *e) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_RETURN; n->expr = e; return n;
}

ASTNode *ast_trans_unit(ASTNode **exts, int n) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_TRANSLATION_UNIT;
    node->seq.list = exts; node->seq.count = n;
    return node;
}
ASTNode *ast_ext_decl(ASTNode *d) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_EXTERNAL_DECL;
    n->seq.list = malloc(sizeof(ASTNode*));
    n->seq.list[0] = d; n->seq.count = 1;
    return n;
}

ASTNode *ast_decl_spec(ASTNode **s, int n) {
    ASTNode *node = malloc(sizeof(*node));
    node->type = AST_DECL_SPEC;
    node->ds.specs = s; node->ds.scount = n;
    return node;
}
ASTNode *ast_init_decl(ASTNode *declr, ASTNode *init) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_INIT_DECL; node->id.declr = declr; node->id.init = init;
    return node;
}
ASTNode *ast_decl(ASTNode **specs, int sn, ASTNode **inits, int in) {
    ASTNode *node = calloc(1, sizeof(*node));
    node->type = AST_DECLARATION;
    node->declaration.specs = specs;
    node->declaration.scount = sn;
    node->declaration.inits = inits;
    node->declaration.icount = in;
    return node;
}
ASTNode *ast_pointer(ASTNode *to) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_POINTER_TYPE; n->ptr_to = to; return n;
}
ASTNode *ast_array(ASTNode *b, ASTNode *sz) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_ARRAY_TYPE; n->at.base = b; n->at.size = sz; return n;
}
ASTNode *ast_func_type(const char *name, ASTNode *p, ASTNode *b, ASTNode *r) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_FUNC_TYPE; n->ft.ret_type = r; n->ft.params = p;  n->ft.body = b; n->ft.name = name ? strdup(name) : NULL; return n;
}
ASTNode *ast_param(ASTNode **s, int sn, ASTNode *d) {
    ASTNode *n = calloc(1,sizeof(*n));
    n->type = AST_PARAM; n->param.dspecs = s; n->param.dcount = sn; n->param.declr = d;
    return n;
}
ASTNode *ast_param_list(ASTNode **ps, int n) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_PARAM_LIST; node->pl.params = ps; node->pl.pcount = n;
    return node;
}
ASTNode *ast_init_list(ASTNode **inits, int n) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_INIT_LIST; node->seq.list = inits; node->seq.count = n;
    return node;
}
ASTNode *ast_designation(ASTNode **ds, int n) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_DESIGNATION; node->des = ds; return node;
}
ASTNode *ast_type_name(const char *name) {
    ASTNode *node = calloc(1,sizeof(*node));
    node->type = AST_TYPE_NAME; node->str = strdup(name); return node;
}

void ast_print(ASTNode *node, int indent) {
    if (!node) return;
    print_indent(indent);
    switch (node->type) {
        case AST_INT:
            printf("Int(%d)\n", node->intval);
            break;
        case AST_DOUBLE:
            printf("Double(%f)\n", node->fval);
            break;
        case AST_VAR:
            printf("Var(%s)\n", node->varname);
            break;
        case AST_BINOP:
            printf("BinOp('%c')\n", node->bin.op);
            ast_print(node->bin.lhs, indent + 1);
            ast_print(node->bin.rhs, indent + 1);
            break;
        case AST_UNOP:
            printf("UnOp('%c')\n", node->un.op);
            ast_print(node->un.lhs, indent + 1);
            break;
        case AST_ASSIGN:
            printf("Assign\n");
            ast_print(node->assign.l, indent + 1);
            ast_print(node->assign.r, indent + 1);
            break;
        case AST_CALL:
            printf("Call(%s) [argc=%d]\n",
                   node->call.fname ? node->call.fname : "<anon>",
                   node->call.argc);
            for (int i = 0; i < node->call.argc; i++) {
                ast_print(node->call.args[i], indent + 1);
            }
            break;
        case AST_COMPOUND_STMT:
            printf("CompoundStmt [%d stmts]\n", node->seq.count);
            for (int i = 0; i < node->seq.count; i++) {
                ast_print(node->seq.list[i], indent + 1);
            }
            break;
        case AST_EXPR_STMT:
            printf("ExprStmt\n");
            ast_print(node->expr, indent + 1);
            break;
        case AST_IF:
            printf("If\n");
            ast_print(node->sif.cond, indent + 1);
            ast_print(node->sif.then_s, indent + 1);
            if (node->sif.else_s) {
                print_indent(indent + 1);
                printf("Else\n");
                ast_print(node->sif.else_s, indent + 2);
            }
            break;
        case AST_WHILE:
            printf("While\n");
            ast_print(node->sw.cond, indent + 1);
            ast_print(node->sw.body, indent + 1);
            break;
        case AST_DO_WHILE:
            printf("DoWhile\n");
            ast_print(node->sdw.body, indent + 1);
            ast_print(node->sdw.cond, indent + 1);
            break;
        case AST_FOR:
            printf("For\n");
            ast_print(node->sf.init, indent + 1);
            ast_print(node->sf.cond, indent + 1);
            ast_print(node->sf.post, indent + 1);
            ast_print(node->sf.body, indent + 1);
            break;
        case AST_BREAK:
            printf("Break\n");
            break;
        case AST_CONTINUE:
            printf("Continue\n");
            break;
        case AST_RETURN:
            printf("Return\n");
            if (node->expr) ast_print(node->expr, indent + 1);
            break;
        case AST_TRANSLATION_UNIT:
            printf("TranslationUnit [%d ext_decls]\n", node->seq.count);
            for (int i = 0; i < node->seq.count; i++) {
                ast_print(node->seq.list[i], indent + 1);
            }
            break;
        case AST_DECL_SPEC:
            printf("DeclSpec [%d specifiers]\n", node->ds.scount);
            for (int i = 0; i < node->ds.scount; i++) {
                ast_print(node->ds.specs[i], indent + 1);
            }
            break;
        case AST_EXTERNAL_DECL:
            printf("ExternalDecl\n");
            for (int i = 0; i < node->seq.count; i++) {
                ast_print(node->seq.list[i], indent + 1);
            }
            break;
        case AST_DECLARATION:
            printf("Declaration (specs=%d, inits=%d)\n",
                node->declaration.scount, node->declaration.icount);
            for (int i = 0; i < node->declaration.scount; ++i) {
                ast_print(node->declaration.specs[i], indent + 1);
            }
            for (int i = 0; i < node->declaration.icount; ++i) {
                ast_print(node->declaration.inits[i], indent + 1);
            }
            break;
        case AST_TYPE_NAME:
            printf("Type(%s)\n", node->str);
            break;
        case AST_INIT_DECL:
            printf("InitDecl\n");
            ast_print(node->id.declr, indent + 1);
            if (node->id.init) ast_print(node->id.init, indent + 1);
            break;
        case AST_POINTER_TYPE:
            printf("PointerType\n");
            ast_print(node->ptr_to, indent + 1);
            break;
        case AST_ARRAY_TYPE:
            printf("ArrayType\n");
            ast_print(node->at.base, indent + 1);
            if (node->at.size) ast_print(node->at.size, indent + 1);
            break;
        case AST_FUNC_TYPE:
            printf("FuncType %s\n", node->ft.name ? node->ft.name : "<anon>");
            ast_print(node->ft.ret_type, indent + 1);
            if (node->ft.params) {
                ast_print(node->ft.params, indent + 1);
            }
            if (node->ft.body) {
                print_indent(indent + 1);
                printf("Body\n");
                ast_print(node->ft.body, indent + 2);
            }
            break;
        case AST_PARAM_LIST:
            printf("ParamList [%d]\n", node->pl.pcount);
            for (int i = 0; i < node->pl.pcount; i++)
                ast_print(node->pl.params[i], indent + 1);
            break;
        case AST_PARAM:
            printf("Param\n");
            for (int i = 0; i < node->param.dcount; i++)
                ast_print(node->param.dspecs[i], indent + 1);
            if (node->param.declr)
                ast_print(node->param.declr, indent + 1);
            break;
        case AST_INIT_LIST:
            printf("InitList [%d]\n", node->seq.count);
            for (int i = 0; i < node->seq.count; i++)
                ast_print(node->seq.list[i], indent + 1);
            break;
        case AST_DESIGNATION:
            printf("Designation\n");
            /* designator 列表本身用 ASTList 存储 */
            break;
        default:
            printf("UnknownNode(type=%d)\n", node->type);
    }
}

void ast_free(ASTNode *node) {
    if (!node) return;
    switch (node->type) {
        case AST_VAR:
            free(node->varname);
            break;
        case AST_BINOP:
            ast_free(node->bin.lhs);
            ast_free(node->bin.rhs);
            break;
        case AST_UNOP:
            ast_free(node->un.lhs);
            break;
        case AST_ASSIGN:
            ast_free(node->assign.l);
            ast_free(node->assign.r);
            break;
        case AST_CALL:
            if (node->call.fname) free(node->call.fname);
            for (int i = 0; i < node->call.argc; i++)
                ast_free(node->call.args[i]);
            free(node->call.args);
            break;
        case AST_COMPOUND_STMT:
        case AST_TRANSLATION_UNIT:
        case AST_EXTERNAL_DECL:
        case AST_DECLARATION:
        case AST_INIT_LIST:
            for (int i = 0; i < node->seq.count; i++)
                ast_free(node->seq.list[i]);
            free(node->seq.list);
            break;
        case AST_EXPR_STMT:
        case AST_RETURN:
            if (node->expr) ast_free(node->expr);
            break;
        case AST_IF:
            ast_free(node->sif.cond);
            ast_free(node->sif.then_s);
            if (node->sif.else_s) ast_free(node->sif.else_s);
            break;
        case AST_WHILE:
            ast_free(node->sw.cond);
            ast_free(node->sw.body);
            break;
        case AST_DO_WHILE:
            ast_free(node->sdw.body);
            ast_free(node->sdw.cond);
            break;
        case AST_FOR:
            ast_free(node->sf.init);
            ast_free(node->sf.cond);
            ast_free(node->sf.post);
            ast_free(node->sf.body);
            break;
        case AST_PARAM_LIST:
            for (int i = 0; i < node->pl.pcount; i++)
                ast_free(node->pl.params[i]);
            free(node->pl.params);
            break;
        case AST_PARAM:
            for (int i = 0; i < node->param.dcount; i++)
                ast_free(node->param.dspecs[i]);
            free(node->param.dspecs);
            if (node->param.declr) ast_free(node->param.declr);
            break;
        case AST_POINTER_TYPE:
            if (node->ptr_to) ast_free(node->ptr_to);
            break;
        case AST_ARRAY_TYPE:
            if (node->at.base) ast_free(node->at.base);
            if (node->at.size) ast_free(node->at.size);
            break;
        case AST_FUNC_TYPE:
            if (node->ft.ret_type) ast_free(node->ft.ret_type);
            if (node->ft.params) ast_free(node->ft.params);
            if (node->ft.body) ast_free(node->ft.body);
            break;
        default:
            break;
    }
    free(node);
}