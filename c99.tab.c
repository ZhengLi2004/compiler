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
    INT = 273,
    DOUBLE = 274,
    VOID = 275,
    STRUCT = 276,
    ELLIPSIS = 277,
    IF = 278,
    ELSE = 279,
    WHILE = 280,
    DO = 281,
    FOR = 282,
    CONTINUE = 283,
    BREAK = 284,
    RETURN = 285
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

#line 165 "c99.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C99_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 182 "c99.tab.c" /* yacc.c:358  */

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   719

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  160
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  283

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,     2,     2,    44,    37,     2,
      31,    32,    38,    39,    36,    40,    35,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    50,
      45,    49,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    48,    52,    41,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    79,    81,    83,    88,    90,    92,    94,
     100,   102,   104,   106,   115,   121,   137,   139,   141,   143,
     145,   147,   149,   151,   153,   155,   160,   165,   167,   169,
     171,   176,   178,   180,   185,   187,   189,   194,   196,   198,
     200,   202,   207,   209,   211,   216,   218,   223,   225,   230,
     232,   237,   239,   244,   246,   251,   260,   262,   267,   269,
     277,   286,   291,   302,   308,   319,   325,   335,   337,   343,
     344,   345,   346,   351,   356,   361,   366,   372,   382,   394,
     401,   410,   416,   426,   428,   430,   436,   438,   443,   445,
     447,   449,   451,   456,   458,   460,   465,   470,   480,   486,
     496,   498,   500,   506,   512,   523,   525,   527,   532,   534,
     536,   538,   540,   542,   544,   546,   548,   550,   552,   558,
     560,   562,   567,   573,   580,   592,   597,   603,   613,   615,
     621,   622,   623,   624,   625,   626,   630,   631,   635,   641,
     650,   651,   655,   656,   660,   662,   667,   669,   671,   673,
     675,   677,   682,   683,   684,   685,   690,   691,   695,   725,
     731
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "DCONSTANT",
  "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "INT", "DOUBLE", "VOID",
  "STRUCT", "ELLIPSIS", "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE",
  "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','", "'&'",
  "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'",
  "'|'", "'='", "';'", "'{'", "'}'", "':'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "expression", "constant_expression",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "type_specifier", "struct_specifier",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "declarator", "direct_declarator",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "external_declaration",
  "function_definition", "translation_unit", YY_NULLPTR
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
     285,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    61,
      59,   123,   125,    58
};
# endif

#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-163)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     231,  -163,  -163,  -163,    23,  -163,   149,  -163,  -163,  -163,
    -163,   135,     9,   231,  -163,    19,    19,  -163,   -13,  -163,
    -163,    94,     5,  -163,  -163,   231,   231,   129,  -163,    24,
      -3,  -163,    19,  -163,   392,   217,  -163,    22,   313,   140,
    -163,  -163,  -163,   652,    -6,  -163,    16,  -163,  -163,    37,
    -163,  -163,  -163,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   377,  -163,   165,    44,  -163,   133,    97,
     153,    85,   219,    41,    80,    96,   159,   172,  -163,  -163,
    -163,   144,   188,   222,   337,   233,   163,   224,   452,  -163,
    -163,  -163,    15,  -163,   149,  -163,  -163,   257,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,   681,   259,   268,  -163,    52,
    -163,   492,   278,  -163,  -163,  -163,  -163,    24,  -163,   652,
    -163,  -163,  -163,    64,  -163,  -163,  -163,  -163,  -163,  -163,
     652,   310,  -163,    -4,   392,    -2,  -163,   311,  -163,  -163,
     512,   652,   312,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   337,   652,   652,   295,   432,  -163,  -163,  -163,
      17,   652,  -163,  -163,  -163,   677,   532,    61,  -163,  -163,
     208,  -163,   189,  -163,   320,  -163,  -163,  -163,  -163,  -163,
     290,  -163,   297,  -163,  -163,  -163,  -163,  -163,  -163,    92,
    -163,   245,  -163,  -163,  -163,  -163,  -163,   133,   133,    97,
      97,   153,   153,   153,   153,    85,    85,   219,    41,    80,
      96,   159,  -163,   150,   152,   294,   472,   472,  -163,  -163,
    -163,   298,   299,  -163,   552,   292,   208,   183,   572,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,   652,  -163,   337,   337,
     652,   592,   612,  -163,  -163,  -163,  -163,  -163,   300,  -163,
     632,   293,  -163,   305,  -163,   180,   337,   182,   337,   195,
    -163,  -163,  -163,   337,   283,  -163,   337,  -163,   337,  -163,
    -163,  -163,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    70,    71,    69,     0,   157,     0,    63,    72,   159,
     156,     0,    75,     0,    95,     0,     0,    61,     0,    65,
      64,    67,    87,     1,   160,     0,    80,     0,    76,     0,
       0,    86,     0,    62,     0,     0,   158,     0,     0,     0,
      79,    74,    77,     0,     0,    81,    83,    88,    66,    67,
       2,     3,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,    16,    26,    27,    31,    34,
      37,    42,    45,    47,    49,    51,    53,    55,    56,   119,
      68,     2,     0,     0,     0,     0,     0,     0,     0,   142,
     136,    58,     0,   140,     0,   141,   131,     0,   138,   132,
     133,   134,   135,   103,    94,   102,     0,    96,    98,     0,
      91,     0,     0,    73,    26,    60,    84,     0,    78,     0,
      25,    17,    18,     0,    19,    20,    21,    22,    23,    24,
       0,     0,   122,     0,     0,     0,   126,     0,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   153,   154,
       0,     0,   143,   137,   139,     0,     0,   105,   100,   101,
     106,    92,     0,    93,     0,    90,    89,    82,    85,     5,
       0,   129,     0,   120,   124,   125,   127,    11,     8,     0,
      14,     0,    10,    57,    28,    29,    30,    32,    33,    35,
      36,    40,    41,    38,    39,    43,    44,    46,    48,    50,
      52,    54,   130,     0,     0,     0,     0,     0,   155,    59,
     115,     0,     0,   109,     0,     0,   107,     0,     0,    97,
      99,   104,   128,   121,   123,     9,     0,     7,     0,     0,
       0,     0,     0,   116,   108,   113,   110,   117,     0,   111,
       0,     0,    15,   144,   146,     0,     0,     0,     0,     0,
     118,   114,   112,     0,     0,   150,     0,   148,     0,   145,
     147,   151,   149
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,  -163,   -43,   -55,   142,   143,   119,   155,
     199,   200,   198,   201,   209,  -163,     3,   -14,   -22,     2,
     -27,    28,  -163,   327,    46,  -163,   344,    56,   345,  -163,
     255,    29,  -163,  -162,  -163,   191,  -163,   214,   207,   -54,
    -163,  -163,  -163,   256,   -83,   369,  -163,   296,  -145,  -163,
    -163,  -163,   381,  -163,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    65,   199,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    91,    92,   116,
       5,   105,    18,    19,     7,     8,    27,    28,    29,    44,
      45,    30,    22,   106,   107,   108,   109,   179,   180,    80,
     133,   134,   135,   136,    95,    96,    97,    98,    99,   100,
     101,   102,     9,    10,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     114,   165,   124,   125,   126,   127,   128,   129,    93,   132,
     120,   121,   122,   231,   114,   114,   114,   114,   114,   114,
      79,   227,    14,    32,   112,   103,    12,    14,     6,    47,
     117,   130,   192,   131,   123,    21,    37,    33,    38,     6,
       1,     2,     3,     4,   118,    31,   115,   195,   193,    79,
      15,   171,    20,   171,   104,    15,   125,    16,    46,    26,
      25,    49,    16,    94,    14,   172,   170,   228,   114,   119,
      93,    26,    26,    26,    13,   258,   114,    43,   157,   222,
     194,   251,   252,    42,   183,    26,    34,   114,   184,   204,
     205,   206,   175,   143,   176,    42,   189,   151,   152,    16,
     171,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   201,
      79,   188,   115,    49,   245,    94,   200,   158,   246,   203,
     153,   154,   190,   115,   178,    23,   147,   148,   244,   226,
      20,   223,   224,    34,   159,    35,    46,     1,     2,     3,
       4,    20,    14,     1,     2,     3,     4,   229,     1,     2,
       3,     4,   235,   149,   150,   263,   264,     1,     2,     3,
       4,   144,   137,   138,   139,   160,   145,   146,    79,   125,
      15,    41,   248,   275,   249,   277,   171,    16,   171,   161,
     279,   114,   113,   281,    94,   282,   140,   162,   141,    17,
     142,     1,     2,     3,     4,   125,    31,     1,     2,     3,
       4,   239,   274,   167,   276,   257,   171,   114,   171,   163,
      81,    51,    52,    53,   261,    54,    55,   278,   265,   267,
     269,   171,   262,   155,   156,     1,     2,     3,     4,   237,
      82,   238,    83,    84,    85,    86,    87,    88,    56,     1,
       2,     3,     4,   164,    57,    58,    59,    60,    61,    62,
      81,    51,    52,    53,   166,    54,    55,    89,    35,    90,
     211,   212,   213,   214,   168,     1,     2,     3,     4,   247,
      82,   171,    83,    84,    85,    86,    87,    88,    56,   207,
     208,   181,   209,   210,    57,    58,    59,    60,    61,    62,
      50,    51,    52,    53,   182,    54,    55,    89,    35,   173,
     215,   216,   186,   191,   197,   202,    50,    51,    52,    53,
     225,    54,    55,   241,   242,   250,   256,   272,    56,   273,
     253,   254,   270,   280,    57,    58,    59,    60,    61,    62,
      81,    51,    52,    53,    56,    54,    55,   110,    63,   243,
      57,   111,    59,    60,    61,    62,   217,   219,   218,    48,
      82,   220,    83,    84,    85,    86,    87,    88,    56,    39,
     221,    40,   187,   240,    57,    58,    59,    60,    61,    62,
      50,    51,    52,    53,   236,    54,    55,    89,    35,   232,
      36,   196,    24,   174,     0,    50,    51,    52,    53,     0,
      54,    55,     0,     0,     0,     0,     0,     0,    56,     0,
     130,     0,   131,     0,    57,    58,    59,    60,    61,    62,
       0,     0,     0,    56,     0,     0,     0,     0,    63,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    63,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     0,    50,    51,    52,    53,     0,
      54,    55,     0,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,    89,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,   169,    56,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,    89,    56,     0,     0,   185,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    56,   198,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    56,     0,     0,   233,     0,     0,    57,
     234,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    56,     0,     0,   255,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    56,     0,     0,   259,     0,     0,    57,
     260,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    56,   266,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    56,   268,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    50,    51,    52,    53,     0,
      54,    55,     0,    56,     0,     0,   271,     0,     0,    57,
      58,    59,    60,    61,    62,     0,     0,     0,     0,     0,
      14,     0,     0,    56,    14,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,     1,     2,     3,     4,     1,
       2,     3,     4,     0,     0,     0,     0,     0,   175,   230,
     176,     0,   175,     0,   176,   177,     0,     0,     0,   177
};

static const yytype_int16 yycheck[] =
{
      43,    84,    57,    58,    59,    60,    61,    62,    35,    63,
      53,    54,    55,   175,    57,    58,    59,    60,    61,    62,
      34,   166,     3,    36,    38,     3,     3,     3,     0,    32,
      36,    33,    36,    35,    56,     6,    31,    50,    33,    11,
      18,    19,    20,    21,    50,    16,    43,    49,    52,    63,
      31,    36,     6,    36,    32,    31,   111,    38,    29,    13,
      51,    32,    38,    35,     3,    50,    88,    50,   111,    53,
      97,    25,    26,    27,    51,   237,   119,    53,    37,   162,
     134,   226,   227,    27,    32,    39,    49,   130,    36,   144,
     145,   146,    31,    49,    33,    39,    32,    12,    13,    38,
      36,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   141,
     134,   119,   119,    94,    32,    97,   140,    47,    36,   143,
      45,    46,   130,   130,   105,     0,    39,    40,   192,   166,
      94,   163,   164,    49,    48,    51,   117,    18,    19,    20,
      21,   105,     3,    18,    19,    20,    21,   171,    18,    19,
      20,    21,   176,    10,    11,   248,   249,    18,    19,    20,
      21,    38,     7,     8,     9,    16,    43,    44,   192,   234,
      31,    52,    32,   266,    32,   268,    36,    38,    36,    17,
     273,   234,    52,   276,   166,   278,    31,    53,    33,    50,
      35,    18,    19,    20,    21,   260,   177,    18,    19,    20,
      21,    22,    32,    50,    32,    32,    36,   260,    36,    31,
       3,     4,     5,     6,   238,     8,     9,    32,   250,   251,
     252,    36,   246,    14,    15,    18,    19,    20,    21,    31,
      23,    33,    25,    26,    27,    28,    29,    30,    31,    18,
      19,    20,    21,    31,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,    31,     8,     9,    50,    51,    52,
     151,   152,   153,   154,    50,    18,    19,    20,    21,    34,
      23,    36,    25,    26,    27,    28,    29,    30,    31,   147,
     148,    32,   149,   150,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,    36,     8,     9,    50,    51,    52,
     155,   156,    34,     3,     3,     3,     3,     4,     5,     6,
      25,     8,     9,     3,    34,    31,    34,    34,    31,    24,
      32,    32,    32,    50,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,    31,     8,     9,    34,    51,    52,
      37,    38,    39,    40,    41,    42,   157,   159,   158,    32,
      23,   160,    25,    26,    27,    28,    29,    30,    31,    25,
     161,    26,   117,   182,    37,    38,    39,    40,    41,    42,
       3,     4,     5,     6,   177,     8,     9,    50,    51,   175,
      21,   135,    11,    97,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    35,    -1,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    51,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    50,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    50,    31,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    50,    31,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,     3,     4,     5,     6,    -1,
       8,     9,    -1,    31,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    31,     3,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    18,    19,    20,    21,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    -1,    31,    -1,    33,    38,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    19,    20,    21,    74,    75,    78,    79,   106,
     107,   108,     3,    51,     3,    31,    38,    50,    76,    77,
      78,    85,    86,     0,   106,    51,    78,    80,    81,    82,
      85,    85,    36,    50,    49,    51,    99,    31,    33,    80,
      82,    52,    81,    53,    83,    84,    85,    32,    77,    85,
       3,     4,     5,     6,     8,     9,    31,    37,    38,    39,
      40,    41,    42,    51,    55,    56,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      93,     3,    23,    25,    26,    27,    28,    29,    30,    50,
      52,    71,    72,    74,    75,    98,    99,   100,   101,   102,
     103,   104,   105,     3,    32,    75,    87,    88,    89,    90,
      34,    38,    71,    52,    58,    70,    73,    36,    50,    53,
      58,    58,    58,    72,    59,    59,    59,    59,    59,    59,
      33,    35,    93,    94,    95,    96,    97,     7,     8,     9,
      31,    33,    35,    49,    38,    43,    44,    39,    40,    10,
      11,    12,    13,    45,    46,    14,    15,    37,    47,    48,
      16,    17,    53,    31,    31,    98,    31,    50,    50,    50,
      72,    36,    50,    52,   101,    31,    33,    38,    85,    91,
      92,    32,    36,    32,    36,    34,    34,    84,    73,    32,
      73,     3,    36,    52,    93,    49,    97,     3,    32,    57,
      71,    72,     3,    71,    59,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    64,    65,    66,
      67,    68,    98,    72,    72,    25,    74,   102,    50,    71,
      32,    87,    91,    34,    38,    71,    92,    31,    33,    22,
      89,     3,    34,    52,    93,    32,    36,    34,    32,    32,
      31,   102,   102,    32,    32,    34,    34,    32,    87,    34,
      38,    71,    71,    98,    98,    72,    32,    72,    32,    72,
      32,    34,    34,    24,    32,    98,    32,    98,    32,    98,
      50,    98,    98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    59,    60,    60,    60,
      60,    61,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    71,    72,    72,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    79,    79,    79,    80,    80,    81,    82,
      82,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    88,
      89,    89,    89,    90,    90,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    94,    94,    94,    95,    96,    96,    97,    97,
      98,    98,    98,    98,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   106,   106,   107,   108,
     108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     3,     1,     3,
       1,     2,     3,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     5,     4,     2,     1,     2,     3,     2,
       1,     1,     3,     1,     2,     3,     2,     1,     3,     4,
       4,     3,     4,     4,     3,     1,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     1,     2,     3,     2,
       3,     3,     4,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     2,     2,     1,     2,     3,     2,
       3,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       1,     1,     1,     2,     5,     7,     5,     7,     6,     7,
       6,     7,     2,     2,     2,     3,     1,     1,     3,     1,
       2
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
#line 78 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 1563 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_int((yyvsp[0].intval)); }
#line 1569 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 82 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_double((yyvsp[0].fval)); }
#line 1575 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 84 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1581 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 89 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1587 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('[', (yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 1593 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_call(NULL, NULL, 0); }
#line 1599 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 95 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_call(NULL,
                          (yyvsp[-1].list).items,
                          (yyvsp[-1].list).count);
        }
#line 1609 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 101 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('.', (yyvsp[-2].ast), ast_var((yyvsp[0].id))); }
#line 1615 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), ast_var((yyvsp[0].id))); }
#line 1621 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 105 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('+', (yyvsp[-1].ast)); }
#line 1627 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 107 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[-1].ast)); }
#line 1633 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 1643 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 122 "c99.y" /* yacc.c:1646  */
    {
            /* $1 是 ASTList */
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count] = (yyvsp[0].ast);
            (yyvsp[-2].list).count++;
            (yyval.list) = (yyvsp[-2].list);
        }
#line 1656 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1662 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 140 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('+', (yyvsp[0].ast)); }
#line 1668 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 142 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[0].ast)); }
#line 1674 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 144 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('&', (yyvsp[0].ast)); }
#line 1680 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 146 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 1686 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 148 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1692 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('-', (yyvsp[0].ast)); }
#line 1698 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 152 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('~', (yyvsp[0].ast)); }
#line 1704 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 154 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('!', (yyvsp[0].ast)); }
#line 1710 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 156 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_unop('$', (yyvsp[0].ast)); }
#line 1716 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1722 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 166 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1728 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 168 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('*', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1734 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 170 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('/', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1740 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 172 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('%', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1746 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 177 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1752 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 179 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('+', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1758 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 181 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('-', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1764 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 186 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1770 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 188 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('<', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1776 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 190 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1782 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 195 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1788 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 197 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('<', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1794 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 199 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('>', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1800 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 201 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('l', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1806 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 203 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('g', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1812 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 208 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1818 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 210 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('=', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1824 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 212 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('!', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1830 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 217 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1836 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 219 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('&', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1842 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 224 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1848 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 226 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('^', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1854 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 231 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1860 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 233 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('|', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1866 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 238 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1872 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 240 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('&', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1878 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 245 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1884 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 247 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_binop('|', (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1890 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1896 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 261 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1902 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 263 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_assign((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1908 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 268 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1914 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 270 "c99.y" /* yacc.c:1646  */
    {
            ASTNode *arr[2] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = ast_compound(arr, 2);
        }
#line 1923 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 278 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 1929 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 287 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_decl((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, NULL, 0);
            // ast_free($1);
        }
#line 1938 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 292 "c99.y" /* yacc.c:1646  */
    {
            (yyval.ast) = ast_decl((yyvsp[-2].ast)->ds.specs,
                          (yyvsp[-2].ast)->ds.scount,
                          (yyvsp[-1].list).items,
                          (yyvsp[-1].list).count);
            // ast_free($1);
        }
#line 1950 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 303 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            (yyval.ast) = ast_decl_spec(a, 1);
        }
#line 1960 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 309 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].ast)->ds.specs = realloc((yyvsp[-1].ast)->ds.specs,
                                   sizeof(ASTNode*) * ((yyvsp[-1].ast)->ds.scount + 1));
            (yyvsp[-1].ast)->ds.specs[(yyvsp[-1].ast)->ds.scount++] = (yyvsp[0].ast);
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 1971 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 320 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 1981 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 326 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 1992 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 336 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_decl((yyvsp[0].ast), NULL); }
#line 1998 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 338 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_decl((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2004 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 343 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("void"); }
#line 2010 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 344 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("int"); }
#line 2016 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 345 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_type_name("double"); }
#line 2022 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 346 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2028 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 352 "c99.y" /* yacc.c:1646  */
    { 
			ASTNode *flds = ast_field_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
			(yyval.ast) = ast_struct_spec((yyvsp[-3].id), flds);
		}
#line 2037 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 357 "c99.y" /* yacc.c:1646  */
    { 
			ASTNode *flds = ast_field_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
			(yyval.ast) = ast_struct_spec(NULL, flds);
		}
#line 2046 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 362 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_struct_spec((yyvsp[0].id), NULL); }
#line 2052 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 367 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2062 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 373 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2073 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 383 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **fields = NULL;
            int fn = 0;
            for (int i = 0; i < (yyvsp[-1].list).count; i++)
                fields = append_node(fields, &fn, (yyvsp[-1].list).items[i]);
            (yyval.ast) = ast_field_list(fields, fn);
        }
#line 2085 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 395 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[0].ast)->ds.specs = realloc((yyvsp[0].ast)->ds.specs,
                                   sizeof(ASTNode*) * ((yyvsp[0].ast)->ds.scount + 1));
            (yyvsp[0].ast)->ds.specs[(yyvsp[0].ast)->ds.scount++] = (yyvsp[-1].ast);
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 2096 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 402 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            (yyval.ast) = ast_decl_spec(a, 1);
        }
#line 2106 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 411 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2116 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 417 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2127 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 427 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_field(NULL, 0, (yyvsp[0].ast)); }
#line 2133 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 429 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_designation(NULL, 0); }
#line 2139 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 431 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_field(NULL, 0, (yyvsp[-2].ast)); }
#line 2145 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 437 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 2151 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 439 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2157 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 444 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2163 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 446 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2169 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 448 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), NULL); }
#line 2175 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 450 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-2].ast), NULL); }
#line 2181 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 452 "c99.y" /* yacc.c:1646  */
    {
            ASTNode *plist = ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count);
            (yyval.ast) = ast_func_type((yyvsp[-3].ast)->varname, plist, NULL, NULL);
        }
#line 2190 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 457 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type((yyvsp[-3].ast)->varname, NULL, NULL, NULL); }
#line 2196 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 459 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type((yyvsp[-2].ast)->varname, NULL, NULL, NULL); }
#line 2202 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 461 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 2208 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 466 "c99.y" /* yacc.c:1646  */
    { 
			(yyval.list).items = (yyvsp[0].list).items;
			(yyval.list).count = (yyvsp[0].list).count;
		}
#line 2217 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 471 "c99.y" /* yacc.c:1646  */
    {
			ASTNode *ellipsis_node = ast_var("...");
            (yyval.list).items = realloc((yyvsp[-2].list).items, sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyval.list).items[(yyvsp[-2].list).count] = ellipsis_node;
            (yyval.list).count = (yyvsp[-2].list).count + 1;
		}
#line 2228 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 481 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2238 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 487 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2249 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 497 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, (yyvsp[0].ast)); }
#line 2255 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 499 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[-1].ast)->ds.specs, (yyvsp[-1].ast)->ds.scount, (yyvsp[0].ast)); }
#line 2261 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 501 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_param((yyvsp[0].ast)->ds.specs, (yyvsp[0].ast)->ds.scount, NULL); }
#line 2267 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 507 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = ast_var((yyvsp[0].id));
            (yyval.list).count    = 1;
        }
#line 2277 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 513 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = ast_var((yyvsp[0].id));
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2288 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 524 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer(NULL); }
#line 2294 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 526 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2300 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 528 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_pointer((yyvsp[0].ast)); }
#line 2306 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 533 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2312 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 535 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, NULL); }
#line 2318 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 537 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, (yyvsp[-1].ast)); }
#line 2324 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 539 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-2].ast), NULL); }
#line 2330 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 541 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), (yyvsp[-1].ast)); }
#line 2336 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 543 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array(NULL, NULL); }
#line 2342 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 545 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_array((yyvsp[-3].ast), NULL); }
#line 2348 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 547 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, NULL, NULL, NULL); }
#line 2354 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 549 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count), NULL, NULL); }
#line 2360 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 551 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, NULL, NULL, NULL); }
#line 2366 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 553 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_func_type(NULL, ast_param_list((yyvsp[-1].list).items, (yyvsp[-1].list).count), NULL, NULL); }
#line 2372 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 559 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2378 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 561 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_list((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2384 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 563 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_init_list((yyvsp[-2].list).items, (yyvsp[-2].list).count); }
#line 2390 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 568 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2400 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 574 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].list).items = realloc((yyvsp[-2].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-2].list).count + 1));
            (yyvsp[-2].list).items[(yyvsp[-2].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-2].list);
        }
#line 2411 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 581 "c99.y" /* yacc.c:1646  */
    {
            /* designator + init 都视为一个节点列表 */
            (yyval.list).items = malloc(sizeof(ASTNode*) * 2);
            (yyval.list).items[0] = (yyvsp[-1].ast);
            (yyval.list).items[1] = (yyvsp[0].ast);
            (yyval.list).count    = 2;
        }
#line 2423 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 593 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_designation((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2429 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 598 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2439 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 604 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items,
                               sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2450 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 614 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[-1].ast); }
#line 2456 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 616 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_var((yyvsp[0].id)); }
#line 2462 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 621 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt(NULL); }
#line 2468 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 622 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2474 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 623 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2480 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 624 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2486 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 625 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2492 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 626 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2498 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 630 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_compound(NULL, 0); }
#line 2504 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 631 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_compound((yyvsp[-1].list).items, (yyvsp[-1].list).count); }
#line 2510 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 636 "c99.y" /* yacc.c:1646  */
    {
            (yyval.list).items = malloc(sizeof(ASTNode*));
            (yyval.list).items[0] = (yyvsp[0].ast);
            (yyval.list).count    = 1;
        }
#line 2520 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 642 "c99.y" /* yacc.c:1646  */
    {
            (yyvsp[-1].list).items = realloc((yyvsp[-1].list).items, sizeof(ASTNode*) * ((yyvsp[-1].list).count + 1));
            (yyvsp[-1].list).items[(yyvsp[-1].list).count++] = (yyvsp[0].ast);
            (yyval.list) = (yyvsp[-1].list);
        }
#line 2530 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 650 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2536 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 651 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = (yyvsp[0].ast); }
#line 2542 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 655 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt(NULL); }
#line 2548 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 656 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_expr_stmt((yyvsp[-1].ast)); }
#line 2554 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 661 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_if((yyvsp[-2].ast), (yyvsp[0].ast), NULL); }
#line 2560 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 663 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_if((yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2566 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 668 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_while((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2572 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 670 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_do_while((yyvsp[-5].ast), (yyvsp[-2].ast)); }
#line 2578 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 672 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for((yyvsp[-3].ast), (yyvsp[-2].ast), NULL, (yyvsp[0].ast)); }
#line 2584 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 674 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for((yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2590 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 676 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for(ast_ext_decl((yyvsp[-3].ast)), (yyvsp[-2].ast), NULL, (yyvsp[0].ast)); }
#line 2596 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 678 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_for(ast_ext_decl((yyvsp[-4].ast)), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 2602 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 682 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_continue(); }
#line 2608 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 683 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_break(); }
#line 2614 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 684 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_return(NULL); }
#line 2620 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 685 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_return((yyvsp[-1].ast)); }
#line 2626 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 690 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_ext_decl((yyvsp[0].ast)); }
#line 2632 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 691 "c99.y" /* yacc.c:1646  */
    { (yyval.ast) = ast_ext_decl((yyvsp[0].ast)); }
#line 2638 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 696 "c99.y" /* yacc.c:1646  */
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
#line 2653 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 726 "c99.y" /* yacc.c:1646  */
    {
            ASTNode **a = malloc(sizeof(ASTNode*));
            a[0] = (yyvsp[0].ast);
            ast_root = ast_trans_unit(a, 1);
        }
#line 2663 "c99.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 732 "c99.y" /* yacc.c:1646  */
    {
            int old = ast_root->seq.count;
            ast_root->seq.list = realloc(ast_root->seq.list,
                                         sizeof(ASTNode*) * (old + 1));
            ast_root->seq.list[old] = (yyvsp[0].ast);
            ast_root->seq.count++;
        }
#line 2675 "c99.tab.c" /* yacc.c:1646  */
    break;


#line 2679 "c99.tab.c" /* yacc.c:1646  */
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
#line 741 "c99.y" /* yacc.c:1906  */

/* Error handling & main */
extern int yylineno;
void yyerror(const char *msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
}
