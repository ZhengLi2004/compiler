#ifndef AST_H
#define AST_H

/* AST 节点种类 */
typedef enum {
    /* 基本表达式 */
    AST_INT,
    AST_DOUBLE,         /* 如需支持浮点，可扩展 */
    AST_VAR,
    AST_BINOP,
    AST_UNOP,
    AST_ASSIGN,
    AST_CALL,

    /* 复合语句、块 */
    AST_COMPOUND_STMT,
    AST_EXPR_STMT,
    AST_IF,
    AST_WHILE,
    AST_DO_WHILE,
    AST_FOR,
    AST_BREAK,
    AST_CONTINUE,
    AST_RETURN,

    /* 类型与声明 */
    AST_TRANSLATION_UNIT,
    AST_EXTERNAL_DECL,
    AST_DECLARATION,
    AST_FUNC_DEF,
    AST_DECL_SPEC,
    AST_INIT_DECL,
    AST_POINTER_TYPE,
    AST_ARRAY_TYPE,
    AST_FUNC_TYPE,
    AST_PARAM_LIST,
    AST_PARAM,
    AST_INIT_LIST,
    AST_DESIGNATION,
    AST_TYPE_NAME

} ASTNodeType;

struct ASTNode;
typedef struct ASTNode ASTNode;

/* AST 节点结构 */
struct ASTNode {
    ASTNodeType type;
    union {
        /* AST_INT */
        int intval;
        
        /* AST_DOUBLE */
        double fval;

        /* AST_STRING */
        char *str;

        /* AST_VAR */
        char *varname;

        /* AST_BINOP, AST_UNOP */
        struct { char op; ASTNode *lhs, *rhs; } bin, un;

        /* AST_ASSIGN */
        struct { ASTNode *l, *r; } assign;

        /* AST_CALL */
        struct { char *fname; ASTNode **args; int argc; } call;

        /* AST_COMPOUND_STMT, AST_TRANSLATION_UNIT, AST_EXTERNAL_DECL,
        AST_INIT_LIST */
        struct { ASTNode **list; int count; } seq;

        /* AST_EXPR_STMT, AST_RETURN */
        ASTNode *expr;

        /* AST_IF */
        struct { ASTNode *cond, *then_s, *else_s; } sif;

        /* AST_WHILE */
        struct { ASTNode *cond, *body; } sw;

        /* AST_DO_WHILE */
        struct { ASTNode *body, *cond; } sdw;

        /* AST_FOR */
        struct { ASTNode *init, *cond, *post, *body; } sf;

        /* AST_DECL_SPEC */
        struct { ASTNode **specs; int scount; } ds;

        /* AST_INIT_DECL */
        struct { ASTNode *declr, *init; } id;

        /* AST_POINTER_TYPE */
        ASTNode *ptr_to;

        /* AST_ARRAY_TYPE */
        struct { ASTNode *base; ASTNode *size; } at;

        /* AST_FUNC_TYPE */
        struct { char *name; ASTNode *ret_type; ASTNode *params; ASTNode *body; } ft;

        /* AST_PARAM_LIST */
        struct { ASTNode **params; int pcount; } pl;

        /* AST_PARAM */
        struct { ASTNode **dspecs; int dcount; ASTNode *declr; } param;

        /* AST_DESIGNATION */
        ASTNode **des; /* array of designators */

        /* AST_DECLARATION */
        struct {
            ASTNode **specs; int scount;
            ASTNode **inits; int icount;
        } declaration;
    };
};

/* 辅助：可变节点数组扩容 */
static ASTNode **append_node(ASTNode **arr, int *cnt, ASTNode *n) {
    arr = realloc(arr, sizeof(ASTNode*) * (*cnt + 1));
    arr[*cnt] = n;
    (*cnt)++;
    return arr;
}
/* 构造函数 */
ASTNode *ast_int(int v);
ASTNode *ast_double(double d);
ASTNode *ast_string(const char *s);
ASTNode *ast_var(const char *name);
ASTNode *ast_binop(char op, ASTNode *l, ASTNode *r);
ASTNode *ast_unop(char op, ASTNode *e);
ASTNode *ast_assign(ASTNode *l, ASTNode *r);
ASTNode *ast_call(const char *f, ASTNode **args, int n);
ASTNode *ast_compound(ASTNode **stmts, int n);
ASTNode *ast_expr_stmt(ASTNode *e);
ASTNode *ast_if(ASTNode *c, ASTNode *t, ASTNode *e);
ASTNode *ast_while(ASTNode *c, ASTNode *b);
ASTNode *ast_do_while(ASTNode *b, ASTNode *c);
ASTNode *ast_for(ASTNode *i, ASTNode *c, ASTNode *p, ASTNode *b);
ASTNode *ast_break(void);
ASTNode *ast_continue(void);
ASTNode *ast_return(ASTNode *e);

ASTNode *ast_trans_unit(ASTNode **exts, int n);
ASTNode *ast_ext_decl(ASTNode *d);

ASTNode *ast_decl(ASTNode **specs, int sn, ASTNode **inits, int in);
ASTNode *ast_decl_spec(ASTNode **specs, int n);
ASTNode *ast_init_decl(ASTNode *declr, ASTNode *init);

ASTNode *ast_pointer(ASTNode *to);
ASTNode *ast_array(ASTNode *b, ASTNode *sz);
ASTNode *ast_func_type(const char *name, ASTNode *params, ASTNode *body, ASTNode *ret);
ASTNode *ast_param_list(ASTNode **ps, int n);
ASTNode *ast_param(ASTNode **specs, int sn, ASTNode *declr);

ASTNode *ast_init_list(ASTNode **inits, int n);
ASTNode *ast_designation(ASTNode **ds, int n);

ASTNode *ast_type_name(const char *name);

/* 打印与析构 */
void ast_print(ASTNode *node, int indent);
void ast_free(ASTNode *node);

#endif /* AST_H */