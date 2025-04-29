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
#line 12 "c99.y" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
#line 1 "c99.y" /* yacc.c:355  */

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
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    TYPE_NAME = 273,
    INT = 274,
    DOUBLE = 275,
    VOID = 276,
    STRUCT = 277,
    ENUM = 278,
    ELLIPSIS = 279,
    IF = 280,
    ELSE = 281,
    WHILE = 282,
    DO = 283,
    FOR = 284,
    CONTINUE = 285,
    BREAK = 286,
    RETURN = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "c99.y" /* yacc.c:355  */

    int       intval;
    char     *id;
    ASTNode  *ast;
    ASTList   list;   /* 仅此一种列表类型 */

#line 166 "c99.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C99_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 183 "c99.tab.c" /* yacc.c:358  */

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   952

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,    48,    41,     2,
      33,    34,    42,    43,    40,    44,    37,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    54,    56,
      49,    55,    50,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    52,    39,    45,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    78,    80,    82,    87,    89,    91,    93,
      99,   101,   103,   105,   107,   111,   122,   128,   144,   146,
     148,   150,   152,   154,   156,   158,   160,   162,   164,   169,
     171,   176,   178,   180,   182,   187,   189,   191,   196,   198,
     200,   205,   207,   209,   211,   213,   218,   220,   222,   227,
     229,   234,   236,   241,   243,   248,   250,   255,   257,   262,
     264,   276,   278,   283,   285,   293,   302,   307,   318,   324,
     335,   341,   351,   353,   359,   360,   361,   362,   363,   365,
     371,   376,   381,   386,   392,   402,   414,   421,   430,   436,
     446,   448,   450,   456,   461,   465,   472,   478,   488,   490,
     496,   498,   503,   505,   507,   509,   511,   513,   518,   520,
     526,   531,   541,   547,   557,   559,   561,   567,   573,   584,
     586,   588,   593,   595,   597,   599,   601,   603,   605,   607,
     609,   611,   613,   619,   621,   623,   628,   634,   641,   653,
     658,   664,   674,   676,   682,   683,   684,   685,   686,   687,
     691,   692,   696,   702,   711,   712,   716,   717,   721,   723,
     728,   730,   732,   734,   736,   738,   743,   744,   745,   746,
     751,   752,   756,   760,   767,   773,   783,   789
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "TYPE_NAME", "INT", "DOUBLE", "VOID", "STRUCT", "ENUM", "ELLIPSIS", "IF",
  "ELSE", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "RETURN", "'('",
  "')'", "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", "'+'",
  "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'",
  "':'", "'='", "';'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enumeration_specifier", "enumerator_list",
  "enumerator", "declarator", "direct_declarator", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "external_declaration", "function_definition",
  "declaration_list", "translation_unit", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    40,    41,    91,    93,    46,   123,   125,
      44,    38,    42,    43,    45,   126,    33,    47,    37,    60,
      62,    94,   124,    63,    58,    61,    59
};
# endif

#define YYPACT_NINF -187

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-187)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     237,  -187,  -187,  -187,  -187,     5,    29,  -187,   228,  -187,
    -187,  -187,  -187,   197,   -13,   237,    30,    42,  -187,  -187,
      27,    27,  -187,   -16,  -187,  -187,   171,    69,  -187,  -187,
     237,   237,   433,  -187,    77,    42,    46,    45,  -187,    92,
    -187,    27,  -187,   272,   523,  -187,   228,  -187,   677,   711,
     549,   652,  -187,  -187,  -187,   859,    -7,  -187,    76,    94,
     859,  -187,    42,  -187,  -187,    56,   105,  -187,  -187,   866,
     873,   873,   150,   152,   360,   162,   165,   181,   417,   568,
    -187,   859,   859,   859,   859,   859,   859,  -187,  -187,    90,
      83,  -187,    93,   156,   202,    44,   220,   186,   191,   214,
     252,     6,  -187,  -187,    -2,  -187,  -187,  -187,   316,  -187,
    -187,  -187,  -187,  -187,  -187,   461,  -187,  -187,  -187,  -187,
    -187,  -187,   910,   235,   233,  -187,     8,  -187,   594,   243,
    -187,  -187,  -187,  -187,    77,  -187,   859,  -187,  -187,  -187,
     360,   613,  -187,   644,  -187,  -187,   859,   859,   255,   391,
    -187,  -187,  -187,    10,   249,    78,  -187,  -187,  -187,  -187,
    -187,  -187,   283,  -187,  -187,   660,   859,   284,   859,   859,
     859,   859,   859,   859,   859,   859,   859,   859,   859,   859,
     859,   859,   859,   859,   859,   859,   859,   859,   859,  -187,
    -187,  -187,   859,   285,  -187,   200,   523,     0,  -187,   787,
     675,    11,  -187,  -187,   122,  -187,   127,  -187,   286,  -187,
    -187,  -187,  -187,  -187,   262,   264,    82,   103,   273,   435,
     435,  -187,   719,  -187,  -187,  -187,   120,  -187,    73,  -187,
    -187,  -187,  -187,  -187,    93,    93,   156,   156,   202,   202,
     202,   202,    44,    44,   220,   186,   191,   214,   252,    60,
    -187,   271,  -187,  -187,   479,  -187,  -187,  -187,  -187,   274,
     275,  -187,   733,   276,   122,   825,   750,  -187,  -187,  -187,
     288,   288,   360,   360,   859,   794,   808,   461,  -187,  -187,
     859,  -187,   859,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,   289,  -187,   852,   291,   303,  -187,   146,   360,   147,
     360,   148,   205,  -187,  -187,  -187,  -187,  -187,   360,   277,
    -187,   360,  -187,   360,  -187,   505,  -187,  -187,  -187,  -187,
    -187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    79,    75,    76,    74,     0,     0,   171,     0,    68,
      77,   176,   170,     0,    82,     0,    95,     0,    78,   102,
       0,     0,    66,     0,    70,    69,    72,   101,     1,   177,
       0,    87,     0,    83,     0,     0,    98,     0,    96,     0,
     100,     0,    67,     0,     0,   174,     0,   173,     0,     0,
       0,     0,    86,    81,    84,     0,     0,    88,    90,     0,
       0,    93,     0,   103,    71,    72,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,     0,     0,     0,     0,     0,     0,   156,     6,    18,
      29,    31,    35,    38,    41,    46,    49,    51,    53,    55,
      57,    59,    61,    63,     0,   154,   155,   145,     0,   152,
     146,   147,   148,   149,     2,     0,   133,    73,   175,   172,
     117,   109,   116,     0,   110,   112,     0,   106,     0,     0,
      80,    29,    65,    91,     0,    85,     0,    94,    99,    97,
       0,     0,    27,     0,    19,    20,     0,     0,     0,     0,
     166,   167,   168,     0,     0,     0,    21,    22,    23,    24,
      25,    26,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     151,   153,     0,     0,   136,     0,     0,     0,   140,     0,
       0,   119,   114,   115,   120,   107,     0,   108,     0,   105,
     104,    89,    92,   144,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     5,    11,     8,     0,    16,     0,    10,
      62,    32,    33,    34,    36,    37,    39,    40,    44,    45,
      42,    43,    47,    48,    50,    52,    54,    56,    58,     0,
      64,     0,   143,   134,     0,   138,   139,   141,   129,     0,
       0,   123,     0,     0,   121,     0,     0,   111,   113,   118,
      28,     0,     0,     0,     0,     0,     0,     0,    30,     9,
       0,     7,     0,   142,   135,   137,   130,   122,   127,   124,
     131,     0,   125,     0,     0,   158,   160,     0,     0,     0,
       0,     0,     0,    17,    60,   132,   128,   126,     0,     0,
     164,     0,   162,     0,    14,     0,   159,   161,   165,   163,
      15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,    -8,   -64,    80,    88,    28,    84,
     149,   157,   158,   145,   164,  -187,   -50,   -44,   -51,   -53,
     -17,     2,  -187,   310,    57,  -187,   302,     7,   321,  -187,
     219,  -187,   332,   294,    -5,  -187,  -186,  -187,   167,  -187,
     172,   169,   -43,    97,  -187,  -187,   178,   -70,   -14,  -187,
     268,  -138,  -187,  -187,  -187,   364,  -187,  -187,  -187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    88,    89,   226,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   133,
       7,    46,    23,    24,     9,    10,    32,    33,    34,    56,
      57,    18,    37,    38,    39,    27,   123,   124,   125,   126,
     203,   204,   194,   195,   196,   197,   198,   106,   107,   108,
     109,   110,   111,   112,   113,    11,    12,    48,    13
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     116,   117,     8,    26,   148,   132,   129,   138,    14,    45,
     132,   220,    47,   259,    19,     8,    40,   156,   157,   158,
     159,   160,   161,   186,    41,    30,   105,   153,   155,    58,
      19,   118,    16,   134,   119,   192,    65,   193,   188,    54,
      42,    65,   207,    15,   199,    36,   200,   131,   208,   135,
     188,   122,   131,    21,   189,   256,   176,   177,    54,   187,
      20,   142,   144,   145,   157,    25,   221,    17,    35,    21,
     213,   116,    31,   131,   131,   131,   131,   131,   131,   291,
      19,   275,   276,   212,    61,    62,   132,    31,    31,    31,
     155,   105,   155,   178,   179,   216,   217,   162,   163,   164,
     188,    60,    49,    25,    50,   231,   232,   233,    31,   281,
      20,    44,   223,   188,   282,   228,   272,   202,   188,    21,
     131,   227,   188,   165,   230,   166,    63,   167,   131,    58,
     136,    55,   219,   137,    62,   169,   249,   273,   168,   251,
     170,   171,   132,   188,   250,     1,     2,     3,     4,     5,
       6,   267,   116,   255,   279,   265,   263,   266,   278,   140,
     280,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,    25,
     309,   311,   313,   146,   131,   147,   188,   188,   188,     1,
       2,     3,     4,     5,     6,   149,    40,    28,   157,   172,
     173,   122,   295,   296,   238,   239,   240,   241,   122,    43,
     116,   285,   174,   175,   131,     1,     2,     3,     4,     5,
       6,   150,   294,   297,   299,   301,    44,   182,   310,   157,
     312,    19,   304,   116,   180,   181,   303,   151,   316,   253,
     254,   318,   183,   319,   314,   315,     1,     2,     3,     4,
       5,     6,   234,   235,   131,     1,     2,     3,     4,     5,
       6,    20,   236,   237,   242,   243,   184,   122,   185,   205,
      21,   116,   285,   206,   131,    66,    67,    68,    69,   210,
      70,    71,   218,   222,    22,   131,   224,   229,   252,   269,
       1,     2,     3,     4,     5,     6,   270,    72,   271,    73,
      74,    75,    76,    77,    78,    79,   274,   283,   286,   287,
      43,    80,   289,    81,    82,    83,    84,    85,    86,    66,
      67,    68,    69,   305,    70,    71,   277,   307,    87,   308,
     247,   244,    51,   317,     1,     2,     3,     4,     5,     6,
     245,    72,   246,    73,    74,    75,    76,    77,    78,    79,
     248,    64,    52,   211,    43,   190,   139,    81,    82,    83,
      84,    85,    86,    66,    67,    68,    69,    59,    70,    71,
     264,   260,    87,   268,   302,   257,   191,    29,     0,     0,
       0,     0,     0,     0,     0,    72,     0,    73,    74,    75,
      76,    77,    78,    79,   114,    67,    68,    69,    43,    70,
      71,    81,    82,    83,    84,    85,    86,     0,     0,     1,
       2,     3,     4,     5,     6,     0,    87,     0,     0,     0,
     114,    67,    68,    69,    79,    70,    71,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,   114,    67,
      68,    69,     0,    70,    71,     0,     0,    87,     0,     0,
      79,     1,     2,     3,     4,     5,     6,     0,    81,    82,
      83,    84,    85,    86,   114,    67,    68,    69,    79,    70,
      71,     0,    53,   152,     0,     0,    81,    82,    83,    84,
      85,    86,   114,    67,    68,    69,     0,    70,    71,     0,
       0,    87,     0,     0,    79,     0,   192,     0,   193,   115,
       0,     0,    81,    82,    83,    84,    85,    86,   114,    67,
      68,    69,    79,    70,    71,     0,     0,   115,   284,     0,
      81,    82,    83,    84,    85,    86,   114,    67,    68,    69,
       0,    70,    71,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,   115,   320,     0,    81,    82,    83,    84,
      85,    86,   114,    67,    68,    69,    79,    70,    71,     0,
       0,   115,     0,     0,    81,    82,    83,    84,    85,    86,
       0,   114,    67,    68,    69,     0,    70,    71,     0,     0,
       0,     0,    79,     0,     0,   127,   154,     0,     0,     0,
      81,   128,    83,    84,    85,    86,     0,   114,    67,    68,
      69,    79,    70,    71,     0,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,     0,   114,    67,    68,    69,
       0,    70,    71,     0,     0,     0,     0,    79,     0,     0,
     209,   214,     0,     0,     0,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,    79,   114,    67,    68,
      69,     0,    70,    71,    81,    82,    83,    84,    85,    86,
       0,     0,   215,   114,    67,    68,    69,     0,    70,    71,
       1,     2,     3,     4,     5,     6,     0,    79,   114,    67,
      68,    69,     0,    70,    71,    81,    82,    83,    84,    85,
      86,   130,     0,    79,   225,     1,     2,     3,     4,     5,
       6,    81,    82,    83,    84,    85,    86,     0,    79,     0,
       0,   261,     0,     0,   120,    43,    81,   262,    83,    84,
      85,    86,   114,    67,    68,    69,     0,    70,    71,     1,
       2,     3,     4,     5,     6,     0,   114,    67,    68,    69,
       0,    70,    71,     0,     0,   121,     0,     0,     0,     0,
       0,     0,    79,   114,    67,    68,    69,   277,    70,    71,
      81,    82,    83,    84,    85,    86,    79,     0,     0,   288,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     0,     0,    79,     0,     0,   292,     0,     0,     0,
      19,    81,   293,    83,    84,    85,    86,   114,    67,    68,
      69,     0,    70,    71,     0,     1,     2,     3,     4,     5,
       6,   114,    67,    68,    69,     0,    70,    71,     0,     0,
     199,   258,   200,     0,     0,     0,     0,    79,   298,   201,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    79,   300,     1,     2,     3,     4,     5,     6,    81,
      82,    83,    84,    85,    86,   114,    67,    68,    69,   290,
      70,    71,   114,    67,    68,    69,     0,    70,    71,   114,
      67,    68,    69,     0,    70,    71,   114,    67,    68,    69,
       0,    70,    71,     0,     0,    79,     0,     0,   306,     0,
       0,     0,    79,    81,    82,    83,    84,    85,    86,   141,
      81,    82,    83,    84,    85,    86,   143,    81,    82,    83,
      84,    85,    86,    19,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,   200,     0,     0,     0,     0,
       0,     0,   201
};

static const yytype_int16 yycheck[] =
{
      44,    44,     0,     8,    74,    55,    50,    60,     3,    26,
      60,   149,    26,   199,     3,    13,    21,    81,    82,    83,
      84,    85,    86,    17,    40,    38,    43,    78,    79,    34,
       3,    48,     3,    40,    48,    35,    41,    37,    40,    32,
      56,    46,    34,    38,    33,     3,    35,    55,    40,    56,
      40,    49,    60,    42,    56,    55,    12,    13,    51,    53,
      33,    69,    70,    71,   128,     8,    56,    38,    38,    42,
     140,   115,    15,    81,    82,    83,    84,    85,    86,   265,
       3,   219,   220,   136,    39,    40,   136,    30,    31,    32,
     141,   108,   143,    49,    50,   146,   147,     7,     8,     9,
      40,    55,    33,    46,    35,   169,   170,   171,    51,    36,
      33,    55,    34,    40,    54,   166,    34,   122,    40,    42,
     128,   165,    40,    33,   168,    35,    34,    37,   136,   134,
      54,    54,   149,    39,    40,    42,   187,    34,    55,   192,
      47,    48,   192,    40,   188,    18,    19,    20,    21,    22,
      23,    24,   196,   196,    34,    33,   200,    35,   222,    54,
      40,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   122,
      34,    34,    34,    33,   192,    33,    40,    40,    40,    18,
      19,    20,    21,    22,    23,    33,   201,     0,   262,    43,
      44,   199,   272,   273,   176,   177,   178,   179,   206,    38,
     254,   254,    10,    11,   222,    18,    19,    20,    21,    22,
      23,    56,   266,   274,   275,   276,    55,    41,   298,   293,
     300,     3,   282,   277,    14,    15,   280,    56,   308,    39,
      40,   311,    51,   313,    39,    40,    18,    19,    20,    21,
      22,    23,   172,   173,   262,    18,    19,    20,    21,    22,
      23,    33,   174,   175,   180,   181,    52,   265,    16,    34,
      42,   315,   315,    40,   282,     3,     4,     5,     6,    36,
       8,     9,    27,    34,    56,   293,     3,     3,     3,     3,
      18,    19,    20,    21,    22,    23,    34,    25,    34,    27,
      28,    29,    30,    31,    32,    33,    33,    36,    34,    34,
      38,    39,    36,    41,    42,    43,    44,    45,    46,     3,
       4,     5,     6,    34,     8,     9,    38,    36,    56,    26,
     185,   182,    30,    56,    18,    19,    20,    21,    22,    23,
     183,    25,   184,    27,    28,    29,    30,    31,    32,    33,
     186,    41,    31,   134,    38,    39,    62,    41,    42,    43,
      44,    45,    46,     3,     4,     5,     6,    35,     8,     9,
     201,   199,    56,   206,   277,   197,   108,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,     3,     4,     5,     6,    38,     8,
       9,    41,    42,    43,    44,    45,    46,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    56,    -1,    -1,    -1,
       3,     4,     5,     6,    33,     8,     9,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    56,    -1,    -1,
      33,    18,    19,    20,    21,    22,    23,    -1,    41,    42,
      43,    44,    45,    46,     3,     4,     5,     6,    33,     8,
       9,    -1,    39,    56,    -1,    -1,    41,    42,    43,    44,
      45,    46,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    56,    -1,    -1,    33,    -1,    35,    -1,    37,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,     3,     4,
       5,     6,    33,     8,     9,    -1,    -1,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,     3,     4,     5,     6,    33,     8,     9,    -1,
      -1,    38,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    36,    18,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    -1,     3,     4,     5,
       6,    33,     8,     9,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      36,    18,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    33,     3,     4,     5,
       6,    -1,     8,     9,    41,    42,    43,    44,    45,    46,
      -1,    -1,    18,     3,     4,     5,     6,    -1,     8,     9,
      18,    19,    20,    21,    22,    23,    -1,    33,     3,     4,
       5,     6,    -1,     8,     9,    41,    42,    43,    44,    45,
      46,    39,    -1,    33,    34,    18,    19,    20,    21,    22,
      23,    41,    42,    43,    44,    45,    46,    -1,    33,    -1,
      -1,    36,    -1,    -1,     3,    38,    41,    42,    43,    44,
      45,    46,     3,     4,     5,     6,    -1,     8,     9,    18,
      19,    20,    21,    22,    23,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    33,     3,     4,     5,     6,    38,     8,     9,
      41,    42,    43,    44,    45,    46,    33,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    33,    -1,    -1,    36,    -1,    -1,    -1,
       3,    41,    42,    43,    44,    45,    46,     3,     4,     5,
       6,    -1,     8,     9,    -1,    18,    19,    20,    21,    22,
      23,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      33,    34,    35,    -1,    -1,    -1,    -1,    33,    34,    42,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    33,    34,    18,    19,    20,    21,    22,    23,    41,
      42,    43,    44,    45,    46,     3,     4,     5,     6,    34,
       8,     9,     3,     4,     5,     6,    -1,     8,     9,     3,
       4,     5,     6,    -1,     8,     9,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    33,    -1,    -1,    36,    -1,
      -1,    -1,    33,    41,    42,    43,    44,    45,    46,    33,
      41,    42,    43,    44,    45,    46,    33,    41,    42,    43,
      44,    45,    46,     3,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    19,    20,    21,    22,    23,    77,    78,    81,
      82,   112,   113,   115,     3,    38,     3,    38,    88,     3,
      33,    42,    56,    79,    80,    81,    91,    92,     0,   112,
      38,    81,    83,    84,    85,    38,     3,    89,    90,    91,
      91,    40,    56,    38,    55,    77,    78,   105,   114,    33,
      35,    83,    85,    39,    84,    54,    86,    87,    91,    89,
      55,    39,    40,    34,    80,    91,     3,     4,     5,     6,
       8,     9,    25,    27,    28,    29,    30,    31,    32,    33,
      39,    41,    42,    43,    44,    45,    46,    56,    58,    59,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    77,   104,   105,   106,   107,
     108,   109,   110,   111,     3,    38,    74,    99,    77,   105,
       3,    34,    78,    93,    94,    95,    96,    36,    42,    74,
      39,    61,    73,    76,    40,    56,    54,    39,    76,    90,
      54,    33,    61,    33,    61,    61,    33,    33,   104,    33,
      56,    56,    56,    75,    18,    75,    62,    62,    62,    62,
      62,    62,     7,     8,     9,    33,    35,    37,    55,    42,
      47,    48,    43,    44,    10,    11,    12,    13,    49,    50,
      14,    15,    41,    51,    52,    16,    17,    53,    40,    56,
      39,   107,    35,    37,    99,   100,   101,   102,   103,    33,
      35,    42,    91,    97,    98,    34,    40,    34,    40,    36,
      36,    87,    76,   104,    18,    18,    75,    75,    27,    77,
     108,    56,    34,    34,     3,    34,    60,    74,    75,     3,
      74,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    66,    66,    67,    68,    69,    70,    71,    75,
      74,    76,     3,    39,    40,    99,    55,   103,    34,    93,
      97,    36,    42,    74,    98,    33,    35,    24,    95,     3,
      34,    34,    34,    34,    33,   108,   108,    38,    62,    34,
      40,    36,    54,    36,    39,    99,    34,    34,    36,    36,
      34,    93,    36,    42,    74,   104,   104,    75,    34,    75,
      34,    75,   100,    74,    73,    34,    36,    36,    26,    34,
     104,    34,   104,    34,    39,    40,   104,    56,   104,   104,
      39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      65,    66,    66,    66,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    84,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    99,    99,    99,   100,   100,   100,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   111,   111,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     1,
       4,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     3,     1,     2,     3,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       5,     4,     2,     1,     2,     3,     2,     1,     1,     3,
       1,     2,     3,     3,     4,     1,     1,     3,     1,     3,
       2,     1,     1,     3,     4,     4,     3,     4,     4,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       1,     2,     3,     2,     3,     3,     4,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     2,     2,
       1,     2,     3,     2,     3,     1,     1,     1,     1,     1,
       2,     3,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     7,     6,     7,     6,     7,     2,     2,     2,     3,
       1,     1,     4,     3,     1,     2,     1,     2
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
#line 77 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 1628 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_int((yyvsp[0].intval)); }
#line 1634 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_string((yyvsp[0].id)); }
#line 1640 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1646 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 88 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1652 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('[', (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1658 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_call(NULL, NULL, 0); }
#line 1664 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 94 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_call(NULL,
                          (yyvsp[-1].list).items,
                          (yyvsp[-1].list).count);
        }
#line 1674 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 100 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('.', (yyvsp[-2].ast), ast_var((yyvsp[0].id))); }
#line 1680 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), ast_var((yyvsp[0].id))); }
#line 1686 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('+', (yyvsp[-1].ast)); }
#line 1692 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 106 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[-1].ast)); }
#line 1698 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 108 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_init_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
        }
#line 1706 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 112 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_init_list((yyvsp[-2].list).items, (yyvsp[-2].list).count);
        }
#line 1714 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 123 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 1724 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 129 "c99.y" /* yacc.c:1646  */
    {
            /* $1 是 ASTList */
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count] = (yyvsp[0].ast);
            (yyvsp[-2].list).count++;
            (yyval.list) = (yyvsp[-2].list);
        }
#line 1737 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 145 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1743 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 147 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('+', (yyvsp[0].ast)); }
#line 1749 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 149 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[0].ast)); }
#line 1755 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 151 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('&', (yyvsp[0].ast)); }
#line 1761 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 1767 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 155 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1773 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 157 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[0].ast)); }
#line 1779 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 159 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('~', (yyvsp[0].ast)); }
#line 1785 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('!', (yyvsp[0].ast)); }
#line 1791 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 163 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('$', (yyvsp[0].ast)); }
#line 1797 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 165 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('$', ast_var((yyvsp[-1].id))); }
#line 1803 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 170 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1809 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 172 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1815 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 177 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1821 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 179 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1827 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 181 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1833 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 183 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('%', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1839 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 188 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1845 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 190 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1851 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 192 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1857 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 197 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1863 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 199 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('<', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1869 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 201 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1875 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 206 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1881 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 208 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('<', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1887 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 210 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1893 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 212 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('l', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1899 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 214 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('g', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1905 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 219 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1911 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 221 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('=', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1917 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 223 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('!', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1923 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 228 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1929 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 230 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('&', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1935 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 235 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1941 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 237 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('^', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1947 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 242 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1953 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 244 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('|', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1959 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 249 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1965 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 251 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('&', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1971 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 256 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1977 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 258 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('|', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1983 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 263 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1989 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 265 "c99.y" /* yacc.c:1646  */
    {
            ASTNode *arr[3] = { (yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = ast_compound(arr, 3);
        }
#line 1998 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 277 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2004 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 279 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_assign((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2010 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 284 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2016 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 286 "c99.y" /* yacc.c:1646  */
    {
            ASTNode *arr[2] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = ast_compound(arr, 2);
        }
#line 2025 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 294 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2031 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 303 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_decl((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, NULL, 0);
            ast_free((yyvsp[-1].ast));
        }
#line 2040 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 308 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_decl((yyvsp[-2].ast)->ds.specs,
                          (yyvsp[-2].ast)->ds.scount,
                          (yyvsp[-1].list).items,
                          (yyvsp[-1].list).count);
            ast_free((yyvsp[-2].ast));
        }
#line 2052 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 319 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            (yyval.ast) = ast_decl_spec(a, 1);
        }
#line 2062 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 325 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].ast)->ds.specs = realloc((yyvsp[-1].ast)->ds.specs,
                                   sizeof(ASTNode*) * ((yyvsp[-1].ast)->ds.scount + 1));
            (yyvsp[-1].ast)->ds.specs[(yyvsp[-1].ast)->ds.scount++] = (yyvsp[0].ast);
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 2073 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 336 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2083 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 342 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2094 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 352 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_decl((yyvsp[0].ast), NULL); }
#line 2100 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 354 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_decl((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2106 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 359 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("void"); }
#line 2112 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 360 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("int"); }
#line 2118 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 361 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("double"); }
#line 2124 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 362 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2130 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 364 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_enum_spec((yyvsp[0].ast)->ses.name, (yyvsp[0].ast)->ses.fields); }
#line 2136 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 366 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 2142 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 372 "c99.y" /* yacc.c:1646  */
    { 
			ASTNode *flds = ast_field_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
			(yyval.ast) = ast_struct_spec((yyvsp[-3].id), flds);
		}
#line 2151 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 377 "c99.y" /* yacc.c:1646  */
    { 
			ASTNode *flds = ast_field_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
			(yyval.ast) = ast_struct_spec(NULL, flds);
		}
#line 2160 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 382 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_struct_spec((yyvsp[0].id), NULL); }
#line 2166 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 387 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2176 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 393 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2187 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 403 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **fields = NULL;
            int fn = 0;
            for (int i = 0; i < (yyvsp[-1].list).count; i++)
                fields = append_node(fields, &fn, (yyvsp[-1].list).items[i]);
            (yyval.ast) = ast_field_list(fields, fn);
        }
#line 2199 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 415 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[0].ast)->ds.specs = realloc((yyvsp[0].ast)->ds.specs,
                                   sizeof(ASTNode*) * ((yyvsp[0].ast)->ds.scount + 1));
            (yyvsp[0].ast)->ds.specs[(yyvsp[0].ast)->ds.scount++] = (yyvsp[-1].ast);
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 2210 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 422 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            (yyval.ast) = ast_decl_spec(a, 1);
        }
#line 2220 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 431 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2230 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 437 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2241 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 447 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_field(NULL, 0, (yyvsp[0].ast)); }
#line 2247 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 449 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_designation(NULL, 0); }
#line 2253 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 451 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_field(NULL, 0, (yyvsp[-2].ast)); }
#line 2259 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 457 "c99.y" /* yacc.c:1646  */
    {
			ASTNode *flds = ast_field_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
            (yyval.ast) = ast_enum_spec(NULL, flds);
        }
#line 2268 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 462 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_enum_spec((yyvsp[-3].id), (yyvsp[-1].list).items);
        }
#line 2276 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 466 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_enum_spec((yyvsp[0].id), NULL);
        }
#line 2284 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 473 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2294 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 479 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2305 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 489 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_field(NULL, 0, ast_var((yyvsp[0].id))); }
#line 2311 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 491 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_field(NULL, 0, ast_var((yyvsp[-2].id))); }
#line 2317 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 497 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 2323 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 499 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2329 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 504 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 2335 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 506 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2341 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 508 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2347 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 510 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), NULL); }
#line 2353 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 512 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-2].ast), NULL); }
#line 2359 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 514 "c99.y" /* yacc.c:1646  */
    { 
			ASTNode *plist = ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
			(yyval.ast) = ast_func_type((yyvsp[-3].ast), plist);
		}
#line 2368 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 519 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type((yyvsp[-3].ast), NULL); }
#line 2374 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 521 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type((yyvsp[-2].ast), NULL); }
#line 2380 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 527 "c99.y" /* yacc.c:1646  */
    { 
			(yyval.list).items = (yyvsp[0].list).items;
			(yyval.list).count = (yyvsp[0].list).count;
		}
#line 2389 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 532 "c99.y" /* yacc.c:1646  */
    {
			ASTNode *ellipsis_node = ast_var("...");
            (yyval.list).items = realloc((yyvsp[-2].list).items, sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyval.list).items[(yyvsp[-2].list).count] = ellipsis_node;
            (yyval.list).count = (yyvsp[-2].list).count + 1;
		}
#line 2400 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 542 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2410 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 548 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2421 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 558 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, (yyvsp[0].ast)); }
#line 2427 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 560 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, (yyvsp[0].ast)); }
#line 2433 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 562 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[0].ast)->ds.specs, (yyvsp[0].ast)->ds.scount, NULL); }
#line 2439 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 568 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = ast_var((yyvsp[0].id));
            (yyval.list).count    = 1;
        }
#line 2449 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 574 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = ast_var((yyvsp[0].id));
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2460 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 585 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer(NULL); }
#line 2466 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 587 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2472 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 589 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 2478 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 594 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2484 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 596 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, NULL); }
#line 2490 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 598 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, (yyvsp[-1].ast)); }
#line 2496 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 600 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-2].ast), NULL); }
#line 2502 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 602 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2508 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 604 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, NULL); }
#line 2514 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 606 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), NULL); }
#line 2520 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 608 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, NULL); }
#line 2526 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 610 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count)); }
#line 2532 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 612 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, NULL); }
#line 2538 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 614 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count)); }
#line 2544 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 620 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2550 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 622 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_list((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2556 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 624 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_list((yyvsp[-2].list).items, (yyvsp[-2].list).count); }
#line 2562 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 629 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2572 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 635 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2583 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 642 "c99.y" /* yacc.c:1646  */
    {
            /* designator + init 都视为一个节点列表 */
            (yyval.list).items = malloc(sizeof(ASTNode*) * 2);
            (yyval.list).items[0] = (yyvsp[-1].ast);
            (yyval.list).items[1] = (yyvsp[0].ast);
            (yyval.list).count    = 2;
        }
#line 2595 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 654 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_designation((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2601 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 659 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2611 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 665 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2622 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 675 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2628 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 677 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 2634 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 682 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt(NULL); }
#line 2640 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 683 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2646 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 684 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2652 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 685 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2658 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 686 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2664 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 687 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2670 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 691 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_compound(NULL, 0); }
#line 2676 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 692 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_compound((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2682 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 697 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2692 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 703 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items, sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2702 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 711 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2708 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 712 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2714 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 716 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt(NULL); }
#line 2720 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 717 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt((yyvsp[-1].ast)); }
#line 2726 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 722 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_if((yyvsp[-2].ast), (yyvsp[0].ast), NULL); }
#line 2732 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 724 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_if((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2738 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 729 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_while((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2744 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 731 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_do_while((yyvsp[-5].ast), (yyvsp[-2].ast)); }
#line 2750 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 733 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for((yyvsp[-3].ast), (yyvsp[-2].ast), NULL, (yyvsp[0].ast)); }
#line 2756 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 735 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for((yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2762 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 737 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for(ast_ext_decl((yyvsp[-3].ast)), (yyvsp[-2].ast), NULL, (yyvsp[0].ast)); }
#line 2768 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 739 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for(ast_ext_decl((yyvsp[-4].ast)), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2774 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 743 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_continue(); }
#line 2780 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 744 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_break(); }
#line 2786 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 745 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_return(NULL); }
#line 2792 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 746 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_return((yyvsp[-1].ast)); }
#line 2798 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 751 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_ext_decl((yyvsp[0].ast)); }
#line 2804 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 752 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_ext_decl((yyvsp[0].ast)); }
#line 2810 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 757 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_func_type((yyvsp[-3].ast), (yyvsp[0].ast));
        }
#line 2818 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 761 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_func_type((yyvsp[-2].ast), (yyvsp[0].ast));
        }
#line 2826 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 768 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2836 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 774 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2847 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 784 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            ast_root = ast_trans_unit(a, 1);
        }
#line 2857 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 790 "c99.y" /* yacc.c:1646  */
    {
            int old = ast_root->seq.count;
            ast_root->seq.list = realloc(ast_root->seq.list,
                                         sizeof(ASTNode*) * (old + 1));
            ast_root->seq.list[old] = (yyvsp[0].ast);
            ast_root->seq.count++;
        }
#line 2869 "c99.tab.c" /* yacc.c:1646  */
    break;


#line 2873 "c99.tab.c" /* yacc.c:1646  */
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
#line 799 "c99.y" /* yacc.c:1906  */

/* Error handling & main */
extern int yylineno;
void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}
