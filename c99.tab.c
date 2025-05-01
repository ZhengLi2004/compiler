/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 14 "c99.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

#line 73 "c99.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c99.tab.h".  */
#ifndef YY_YY_C99_TAB_H_INCLUDED
# define YY_YY_C99_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 3 "c99.y" /* yacc.c:355  */

	#include "ast.h"

	typedef struct {
		ASTNode **items;
		int       count;
  	} ASTList;

	ASTNode *ast_root;

#line 114 "c99.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    DCONSTANT = 260,
    PTR_OP = 261,
    INC_OP = 262,
    DEC_OP = 263,
    LEFT_OP = 264,
    RIGHT_OP = 265,
    LE_OP = 266,
    GE_OP = 267,
    EQ_OP = 268,
    NE_OP = 269,
    AND_OP = 270,
    OR_OP = 271,
    INT = 272,
    DOUBLE = 273,
    VOID = 274,
    ELLIPSIS = 275,
    IF = 276,
    ELSE = 277,
    WHILE = 278,
    DO = 279,
    FOR = 280,
    CONTINUE = 281,
    BREAK = 282,
    RETURN = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "c99.y" /* yacc.c:355  */

    int       intval;
    float     fval;
    char     *id;
    ASTNode  *ast;
    ASTList   list;   /* 仅此一种列表类型 */

#line 163 "c99.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C99_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 180 "c99.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   667

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  257

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,    42,    35,     2,
      29,    30,    36,    37,    34,    38,    33,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    48,
      43,    47,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    46,    50,    39,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    77,    79,    81,    86,    88,    90,    92,
      98,   100,   102,   104,   113,   119,   135,   137,   139,   141,
     143,   145,   147,   149,   151,   156,   161,   163,   165,   167,
     172,   174,   176,   181,   183,   185,   190,   192,   194,   196,
     198,   203,   205,   207,   212,   214,   219,   221,   226,   228,
     233,   235,   240,   242,   247,   256,   258,   263,   265,   273,
     282,   287,   298,   304,   315,   321,   331,   333,   339,   340,
     341,   363,   365,   370,   372,   374,   376,   378,   383,   385,
     387,   392,   397,   407,   413,   423,   425,   427,   433,   439,
     450,   452,   454,   459,   461,   463,   465,   467,   469,   471,
     473,   475,   477,   479,   485,   487,   489,   494,   500,   507,
     519,   524,   530,   540,   542,   548,   549,   550,   551,   552,
     553,   557,   558,   562,   568,   577,   578,   582,   583,   587,
     589,   594,   596,   598,   600,   602,   604,   609,   610,   611,
     612,   617,   618,   622,   652,   658
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "DCONSTANT",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "INT", "DOUBLE", "VOID", "ELLIPSIS",
  "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN", "'('",
  "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'='", "';'", "'{'",
  "'}'", "':'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "direct_declarator", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "external_declaration", "function_definition",
  "translation_unit", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    40,
      41,    91,    93,    46,    44,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    61,    59,   123,
     125,    58
};
# endif

#define YYPACT_NINF -140

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-140)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     156,  -140,  -140,  -140,  -140,   109,  -140,  -140,  -140,    63,
    -140,    16,    16,  -140,    71,  -140,  -140,     1,    39,  -140,
    -140,   -15,  -140,    16,  -140,   387,   220,  -140,   182,   463,
    -140,  -140,   -29,  -140,  -140,  -140,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   372,  -140,   148,   -10,  -140,
      98,   158,    69,    23,   193,   -23,    20,    60,   129,    97,
    -140,  -140,  -140,   115,    93,   120,   334,   168,   165,   167,
     410,  -140,  -140,  -140,    75,  -140,   109,  -140,  -140,   258,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,    25,   130,   183,
    -140,   -14,  -140,   486,   189,  -140,  -140,    19,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   627,   223,  -140,   -20,   387,
      83,  -140,   228,  -140,  -140,   314,   627,   229,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   627,   627,   627,
     627,   627,   627,   627,   627,   627,   627,   334,   627,   627,
     210,   425,  -140,  -140,  -140,    87,   627,  -140,  -140,  -140,
     133,   501,    10,  -140,  -140,   153,  -140,   174,  -140,   231,
    -140,  -140,  -140,  -140,   203,  -140,   296,  -140,  -140,  -140,
    -140,  -140,  -140,    95,  -140,   155,  -140,  -140,  -140,  -140,
    -140,    98,    98,   158,   158,    69,    69,    69,    69,    23,
      23,   193,   -23,    20,    60,   129,  -140,   107,   112,   207,
     448,   448,  -140,  -140,  -140,   212,   221,  -140,   524,   208,
     153,    41,   539,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
     627,  -140,   334,   334,   627,   562,   577,  -140,  -140,  -140,
    -140,  -140,   222,  -140,   615,   218,  -140,   232,  -140,   113,
     334,   131,   334,   137,  -140,  -140,  -140,   334,   205,  -140,
     334,  -140,   334,  -140,  -140,  -140,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    69,    70,    68,   142,     0,    62,   144,   141,     0,
      80,     0,     0,    60,     0,    64,    63,    66,    72,     1,
     145,     0,    71,     0,    61,     0,     0,   143,     0,     0,
      73,    65,    66,     2,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,    16,    25,    26,
      30,    33,    36,    41,    44,    46,    48,    50,    52,    54,
      55,   104,    67,     2,     0,     0,     0,     0,     0,     0,
       0,   127,   121,    57,     0,   125,     0,   126,   116,     0,
     123,   117,   118,   119,   120,    88,    79,    87,     0,    81,
      83,     0,    76,     0,     0,    17,    18,     0,    25,    19,
      20,    21,    22,    23,    24,     0,     0,   107,     0,     0,
       0,   111,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,   138,   139,     0,     0,   128,   122,   124,
       0,     0,    90,    85,    86,    91,    77,     0,    78,     0,
      75,    74,     5,    59,     0,   114,     0,   105,   109,   110,
     112,    11,     8,     0,    14,     0,    10,    56,    27,    28,
      29,    31,    32,    34,    35,    39,    40,    37,    38,    42,
      43,    45,    47,    49,    51,    53,   115,     0,     0,     0,
       0,     0,   140,    58,   100,     0,     0,    94,     0,     0,
      92,     0,     0,    82,    84,    89,   113,   106,   108,     9,
       0,     7,     0,     0,     0,     0,     0,   101,    93,    98,
      95,   102,     0,    96,     0,     0,    15,   129,   131,     0,
       0,     0,     0,     0,   103,    99,    97,     0,     0,   135,
       0,   133,     0,   130,   132,   136,   134
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,  -140,   -36,   -18,    86,   105,    76,    80,
     132,   134,   138,   136,   142,  -140,   169,     2,    -6,  -140,
     -17,    29,  -140,   250,    31,    28,  -140,  -139,  -140,   123,
    -140,   139,   140,   -35,  -140,  -140,  -140,   178,   -64,   273,
    -140,   226,  -124,  -140,  -140,  -140,   282,  -140,  -140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    46,    47,   173,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    73,    74,   164,
       4,    87,    14,    15,     6,    21,    18,    88,    89,    90,
      91,   154,   155,    62,   108,   109,   110,   111,    77,    78,
      79,    80,    81,    82,    83,    84,     7,     8,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      95,    96,   140,    98,    98,    98,    98,    98,    98,    75,
     107,   205,   132,    10,   166,    30,   158,   201,    25,    10,
     159,    99,   100,   101,   102,   103,   104,    61,    10,     5,
     167,    94,    97,    17,   126,   127,    16,   118,     5,   150,
      22,   151,     1,     2,     3,    11,    12,    61,    25,   162,
      26,    32,    12,   146,   150,    76,   151,    98,     1,     2,
       3,   152,    75,    19,   145,   133,   128,   129,    28,    98,
      29,   231,   232,   196,   168,   100,   225,   226,   124,   125,
       1,     2,     3,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,   178,   179,   180,    32,    23,   134,    16,    76,   146,
     175,    61,    10,   136,   105,   153,   106,   174,    16,    24,
     177,   146,   138,   147,   200,   219,     1,     2,     3,   220,
     169,   218,   197,   198,   119,   202,    10,   222,    11,   120,
     121,   146,   223,   248,   135,    12,   146,   146,   203,   139,
       1,     2,     3,   209,   112,   113,   114,    13,   237,   238,
     156,   250,   150,   204,   151,   146,   137,   252,    61,   152,
      76,   146,    98,     1,     2,     3,   249,   115,   251,   116,
      22,   117,   211,   253,   212,    85,   255,   221,   256,   146,
     100,     1,     2,     3,   213,   122,   123,   141,    98,     1,
       2,     3,   185,   186,   187,   188,   130,   131,   181,   182,
     189,   190,    86,   142,   235,   143,   100,   157,   239,   241,
     243,   161,   236,    63,    34,    35,   165,    36,    37,   183,
     184,   171,   176,   199,   215,   216,   224,     1,     2,     3,
     230,    64,   227,    65,    66,    67,    68,    69,    70,    38,
     246,   228,   244,   254,   247,    39,    40,    41,    42,    43,
      44,    63,    34,    35,   191,    36,    37,   192,    71,    26,
      72,   194,   193,    31,   163,     1,     2,     3,   195,    64,
     214,    65,    66,    67,    68,    69,    70,    38,   170,   206,
      27,    20,   210,    39,    40,    41,    42,    43,    44,    33,
      34,    35,     0,    36,    37,   149,    71,    26,   148,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
       0,    36,    37,     0,     0,    38,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,    63,    34,    35,
       0,    36,    37,    38,   172,    45,   217,     0,     0,    39,
      40,    41,    42,    43,    44,    64,     0,    65,    66,    67,
      68,    69,    70,    38,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,    44,    33,    34,    35,     0,    36,
      37,     0,    71,    26,     0,     0,     0,     0,     0,     0,
      33,    34,    35,     0,    36,    37,     0,     0,     0,     0,
       0,    38,     0,   105,     0,   106,     0,    39,    40,    41,
      42,    43,    44,    33,    34,    35,    38,    36,    37,     0,
       0,    45,    39,    40,    41,    42,    43,    44,    33,    34,
      35,     0,    36,    37,     0,     0,    45,     0,     0,    38,
       0,     0,     1,     2,     3,    39,    40,    41,    42,    43,
      44,    33,    34,    35,    38,    36,    37,     0,   144,     0,
      39,    40,    41,    42,    43,    44,    33,    34,    35,     0,
      36,    37,     0,    71,     0,     0,     0,    38,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,    33,
      34,    35,    38,    36,    37,    92,    71,     0,    39,    93,
      41,    42,    43,    44,    33,    34,    35,     0,    36,    37,
       0,     0,     0,     0,     0,    38,     0,     0,   160,     0,
       0,    39,    40,    41,    42,    43,    44,    33,    34,    35,
      38,    36,    37,   207,     0,     0,    39,   208,    41,    42,
      43,    44,    33,    34,    35,     0,    36,    37,     0,     0,
       0,     0,     0,    38,     0,     0,   229,     0,     0,    39,
      40,    41,    42,    43,    44,    33,    34,    35,    38,    36,
      37,   233,     0,     0,    39,   234,    41,    42,    43,    44,
      33,    34,    35,     0,    36,    37,     0,     0,     0,     0,
       0,    38,   240,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,    38,   242,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,    33,    34,
      35,     0,    36,    37,     0,     0,     0,     0,     0,     0,
      33,    34,    35,     0,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,   245,     0,     0,
      39,    40,    41,    42,    43,    44,    38,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44
};

static const yytype_int16 yycheck[] =
{
      36,    37,    66,    39,    40,    41,    42,    43,    44,    26,
      45,   150,    35,     3,    34,    30,    30,   141,    47,     3,
      34,    39,    40,    41,    42,    43,    44,    25,     3,     0,
      50,    29,    38,     5,    11,    12,     5,    47,     9,    29,
      12,    31,    17,    18,    19,    29,    36,    45,    47,    30,
      49,    23,    36,    34,    29,    26,    31,    93,    17,    18,
      19,    36,    79,     0,    70,    45,    43,    44,    29,   105,
      31,    30,   211,   137,   109,    93,   200,   201,     9,    10,
      17,    18,    19,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   119,   120,   121,    76,    34,    46,    76,    79,    34,
     116,   109,     3,    16,    31,    87,    33,   115,    87,    48,
     118,    34,    29,    48,   141,    30,    17,    18,    19,    34,
      47,   166,   138,   139,    36,    48,     3,    30,    29,    41,
      42,    34,    30,    30,    15,    36,    34,    34,   146,    29,
      17,    18,    19,   151,     6,     7,     8,    48,   222,   223,
      30,    30,    29,    30,    31,    34,    51,    30,   166,    36,
     141,    34,   208,    17,    18,    19,   240,    29,   242,    31,
     152,    33,    29,   247,    31,     3,   250,    32,   252,    34,
     208,    17,    18,    19,    20,    37,    38,    29,   234,    17,
      18,    19,   126,   127,   128,   129,    13,    14,   122,   123,
     130,   131,    30,    48,   212,    48,   234,    34,   224,   225,
     226,    32,   220,     3,     4,     5,     3,     7,     8,   124,
     125,     3,     3,    23,     3,    32,    29,    17,    18,    19,
      32,    21,    30,    23,    24,    25,    26,    27,    28,    29,
      32,    30,    30,    48,    22,    35,    36,    37,    38,    39,
      40,     3,     4,     5,   132,     7,     8,   133,    48,    49,
      50,   135,   134,    23,   105,    17,    18,    19,   136,    21,
     157,    23,    24,    25,    26,    27,    28,    29,   110,   150,
      17,     9,   152,    35,    36,    37,    38,    39,    40,     3,
       4,     5,    -1,     7,     8,    79,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,     3,     4,     5,
      -1,     7,     8,    29,    30,    49,    50,    -1,    -1,    35,
      36,    37,    38,    39,    40,    21,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,     3,     4,     5,    -1,     7,
       8,    -1,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    -1,    33,    -1,    35,    36,    37,
      38,    39,    40,     3,     4,     5,    29,     7,     8,    -1,
      -1,    49,    35,    36,    37,    38,    39,    40,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    49,    -1,    -1,    29,
      -1,    -1,    17,    18,    19,    35,    36,    37,    38,    39,
      40,     3,     4,     5,    29,     7,     8,    -1,    48,    -1,
      35,    36,    37,    38,    39,    40,     3,     4,     5,    -1,
       7,     8,    -1,    48,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,     3,
       4,     5,    29,     7,     8,    32,    48,    -1,    35,    36,
      37,    38,    39,    40,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    39,    40,     3,     4,     5,
      29,     7,     8,    32,    -1,    -1,    35,    36,    37,    38,
      39,    40,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    35,
      36,    37,    38,    39,    40,     3,     4,     5,    29,     7,
       8,    32,    -1,    -1,    35,    36,    37,    38,    39,    40,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      35,    36,    37,    38,    39,    40,    29,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    18,    19,    72,    73,    76,    98,    99,   100,
       3,    29,    36,    48,    74,    75,    76,    77,    78,     0,
      98,    77,    77,    34,    48,    47,    49,    91,    29,    31,
      30,    75,    77,     3,     4,     5,     7,     8,    29,    35,
      36,    37,    38,    39,    40,    49,    53,    54,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    85,     3,    21,    23,    24,    25,    26,    27,
      28,    48,    50,    69,    70,    72,    73,    90,    91,    92,
      93,    94,    95,    96,    97,     3,    30,    73,    79,    80,
      81,    82,    32,    36,    69,    56,    56,    70,    56,    57,
      57,    57,    57,    57,    57,    31,    33,    85,    86,    87,
      88,    89,     6,     7,     8,    29,    31,    33,    47,    36,
      41,    42,    37,    38,     9,    10,    11,    12,    43,    44,
      13,    14,    35,    45,    46,    15,    16,    51,    29,    29,
      90,    29,    48,    48,    48,    70,    34,    48,    50,    93,
      29,    31,    36,    77,    83,    84,    30,    34,    30,    34,
      32,    32,    30,    68,    71,     3,    34,    50,    85,    47,
      89,     3,    30,    55,    69,    70,     3,    69,    57,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    63,    64,    65,    66,    90,    70,    70,    23,
      72,    94,    48,    69,    30,    79,    83,    32,    36,    69,
      84,    29,    31,    20,    81,     3,    32,    50,    85,    30,
      34,    32,    30,    30,    29,    94,    94,    30,    30,    32,
      32,    30,    79,    32,    36,    69,    69,    90,    90,    70,
      30,    70,    30,    70,    30,    32,    32,    22,    30,    90,
      30,    90,    30,    90,    48,    90,    90
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      61,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    82,    82,
      83,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    86,    86,    86,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    96,    96,    96,    97,    97,    97,
      97,    98,    98,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     1,     3,     1,
       2,     3,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     2,     1,     3,     4,     4,     3,     4,     4,     3,
       1,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     1,     2,     3,     2,     3,     3,     4,     3,     4,
       2,     3,     3,     4,     1,     3,     4,     1,     3,     2,
       2,     1,     2,     3,     2,     3,     1,     1,     1,     1,
       1,     2,     3,     1,     2,     1,     1,     1,     2,     5,
       7,     5,     7,     6,     7,     6,     7,     2,     2,     2,
       3,     1,     1,     3,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 76 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 1531 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 78 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_int((yyvsp[0].intval)); }
#line 1537 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_double((yyvsp[0].fval)); }
#line 1543 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1549 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1555 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 89 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('[', (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1561 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 91 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_call(NULL, NULL, 0); }
#line 1567 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_call(NULL,
                          (yyvsp[-1].list).items,
                          (yyvsp[-1].list).count);
        }
#line 1577 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 99 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('.', (yyvsp[-2].ast), ast_var((yyvsp[0].id))); }
#line 1583 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), ast_var((yyvsp[0].id))); }
#line 1589 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('+', (yyvsp[-1].ast)); }
#line 1595 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 105 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[-1].ast)); }
#line 1601 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 114 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 1611 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 120 "c99.y" /* yacc.c:1646  */
    {
            /* $1 是 ASTList */
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count] = (yyvsp[0].ast);
            (yyvsp[-2].list).count++;
            (yyval.list) = (yyvsp[-2].list);
        }
#line 1624 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1630 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('+', (yyvsp[0].ast)); }
#line 1636 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[0].ast)); }
#line 1642 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 142 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('&', (yyvsp[0].ast)); }
#line 1648 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 144 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 1654 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1660 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 148 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[0].ast)); }
#line 1666 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('~', (yyvsp[0].ast)); }
#line 1672 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('!', (yyvsp[0].ast)); }
#line 1678 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 157 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1684 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 162 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1690 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 164 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1696 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 166 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1702 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 168 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('%', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1708 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 173 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1714 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 175 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1720 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 177 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1726 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 182 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1732 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 184 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('<', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1738 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 186 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1744 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 191 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1750 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 193 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('<', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1756 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 195 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1762 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 197 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('l', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1768 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 199 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('g', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1774 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 204 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1780 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 206 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('=', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1786 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 208 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('!', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1792 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 213 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1798 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 215 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('&', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1804 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 220 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1810 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 222 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('^', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1816 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 227 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1822 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 229 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('|', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1828 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1834 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 236 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('&', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1840 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 241 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1846 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 243 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('|', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1852 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 248 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1858 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 257 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1864 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 259 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_assign((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1870 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 264 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1876 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 266 "c99.y" /* yacc.c:1646  */
    {
            ASTNode *arr[2] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = ast_compound(arr, 2);
        }
#line 1885 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 274 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1891 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 283 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_decl((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, NULL, 0);
            // ast_free($1);
        }
#line 1900 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 288 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_decl((yyvsp[-2].ast)->ds.specs,
                          (yyvsp[-2].ast)->ds.scount,
                          (yyvsp[-1].list).items,
                          (yyvsp[-1].list).count);
            // ast_free($1);
        }
#line 1912 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 299 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            (yyval.ast) = ast_decl_spec(a, 1);
        }
#line 1922 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 305 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].ast)->ds.specs = realloc((yyvsp[-1].ast)->ds.specs,
                                   sizeof(ASTNode*) * ((yyvsp[-1].ast)->ds.scount + 1));
            (yyvsp[-1].ast)->ds.specs[(yyvsp[-1].ast)->ds.scount++] = (yyvsp[0].ast);
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 1933 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 316 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 1943 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 322 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 1954 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 332 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_decl((yyvsp[0].ast), NULL); }
#line 1960 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 334 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_decl((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1966 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 339 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("void"); }
#line 1972 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 340 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("int"); }
#line 1978 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 341 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("double"); }
#line 1984 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 364 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 1990 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 366 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1996 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 371 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2002 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 373 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2008 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 375 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), NULL); }
#line 2014 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 377 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-2].ast), NULL); }
#line 2020 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 379 "c99.y" /* yacc.c:1646  */
    {
            ASTNode *plist = ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
            (yyval.ast) = ast_func_type((yyvsp[-3].ast)->varname, plist, NULL, NULL);
        }
#line 2029 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 384 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type((yyvsp[-3].ast)->varname, NULL, NULL, NULL); }
#line 2035 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 386 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type((yyvsp[-2].ast)->varname, NULL, NULL, NULL); }
#line 2041 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 388 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 2047 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 393 "c99.y" /* yacc.c:1646  */
    { 
			(yyval.list).items = (yyvsp[0].list).items;
			(yyval.list).count = (yyvsp[0].list).count;
		}
#line 2056 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 398 "c99.y" /* yacc.c:1646  */
    {
			ASTNode *ellipsis_node = ast_var("...");
            (yyval.list).items = realloc((yyvsp[-2].list).items, sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyval.list).items[(yyvsp[-2].list).count] = ellipsis_node;
            (yyval.list).count = (yyvsp[-2].list).count + 1;
		}
#line 2067 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 408 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2077 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 414 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2088 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 424 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, (yyvsp[0].ast)); }
#line 2094 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 426 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, (yyvsp[0].ast)); }
#line 2100 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 428 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[0].ast)->ds.specs, (yyvsp[0].ast)->ds.scount, NULL); }
#line 2106 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 434 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = ast_var((yyvsp[0].id));
            (yyval.list).count    = 1;
        }
#line 2116 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 440 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = ast_var((yyvsp[0].id));
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2127 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 451 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer(NULL); }
#line 2133 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 453 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2139 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 455 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 2145 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 460 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2151 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 462 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, NULL); }
#line 2157 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 464 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, (yyvsp[-1].ast)); }
#line 2163 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 466 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-2].ast), NULL); }
#line 2169 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 468 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2175 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 470 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, NULL); }
#line 2181 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 472 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), NULL); }
#line 2187 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 474 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, NULL, NULL, NULL); }
#line 2193 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 476 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count), NULL, NULL); }
#line 2199 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 478 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, NULL, NULL, NULL); }
#line 2205 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 480 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count), NULL, NULL); }
#line 2211 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 486 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2217 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 488 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_list((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2223 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 490 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_list((yyvsp[-2].list).items, (yyvsp[-2].list).count); }
#line 2229 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 495 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2239 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 501 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2250 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 508 "c99.y" /* yacc.c:1646  */
    {
            /* designator + init 都视为一个节点列表 */
            (yyval.list).items = malloc(sizeof(ASTNode*) * 2);
            (yyval.list).items[0] = (yyvsp[-1].ast);
            (yyval.list).items[1] = (yyvsp[0].ast);
            (yyval.list).count    = 2;
        }
#line 2262 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 520 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_designation((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2268 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 525 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2278 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 531 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2289 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 541 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2295 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 543 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 2301 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 548 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt(NULL); }
#line 2307 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 549 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2313 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 550 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2319 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 551 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2325 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 552 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2331 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 553 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2337 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 557 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_compound(NULL, 0); }
#line 2343 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 558 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_compound((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2349 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 563 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2359 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 569 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items, sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2369 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 577 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2375 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 578 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2381 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 582 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt(NULL); }
#line 2387 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 583 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt((yyvsp[-1].ast)); }
#line 2393 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 588 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_if((yyvsp[-2].ast), (yyvsp[0].ast), NULL); }
#line 2399 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 590 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_if((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2405 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 595 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_while((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2411 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 597 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_do_while((yyvsp[-5].ast), (yyvsp[-2].ast)); }
#line 2417 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 599 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for((yyvsp[-3].ast), (yyvsp[-2].ast), NULL, (yyvsp[0].ast)); }
#line 2423 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 601 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for((yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2429 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 603 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for(ast_ext_decl((yyvsp[-3].ast)), (yyvsp[-2].ast), NULL, (yyvsp[0].ast)); }
#line 2435 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 605 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for(ast_ext_decl((yyvsp[-4].ast)), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2441 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 609 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_continue(); }
#line 2447 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 610 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_break(); }
#line 2453 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 611 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_return(NULL); }
#line 2459 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 612 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_return((yyvsp[-1].ast)); }
#line 2465 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 617 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_ext_decl((yyvsp[0].ast)); }
#line 2471 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 618 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_ext_decl((yyvsp[0].ast)); }
#line 2477 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 623 "c99.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].ast)->type == AST_FUNC_TYPE) {
                (yyvsp[-1].ast)->ft.ret_type = (yyvsp[-2].ast)->ds.specs[0];
                (yyvsp[-1].ast)->ft.body = (yyvsp[0].ast);
                (yyval.ast) = (yyvsp[-1].ast);
            } else {
                yyerror("Expected function declarator");
                (yyval.ast) = NULL;
            }
        }
#line 2492 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 653 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            ast_root = ast_trans_unit(a, 1);
        }
#line 2502 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 659 "c99.y" /* yacc.c:1646  */
    {
            int old = ast_root->seq.count;
            ast_root->seq.list = realloc(ast_root->seq.list,
                                         sizeof(ASTNode*) * (old + 1));
            ast_root->seq.list[old] = (yyvsp[0].ast);
            ast_root->seq.count++;
        }
#line 2514 "c99.tab.c" /* yacc.c:1646  */
    break;


#line 2518 "c99.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 668 "c99.y" /* yacc.c:1906  */

/* Error handling & main */
extern int yylineno;
void yyerror(const char *msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
}
