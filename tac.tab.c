
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "tac.y"

  #include <bits/stdc++.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  using namespace std;


 int yylex();
 extern int yylineno;

void yyerror (const char *s) {fprintf (stderr, "\033[0;31mLine:%d | %s\n\033[0m\n",yylineno, s);} 
  extern FILE *yyin;


  typedef struct quadruples
  {
    char *op;
    char *arg1;
    char *arg2;
    char *res;
  }quad;
  int quadlen = 0;
  
  quad q[100];

  int top=-1;


void push();
void pushi(char * i);
void pusha();
void pushx();
void pushab();
void codegen();
void codegen_assign();
void codegen_incdec(int o);
void for1();
void for2();
void for3();
void for4();
void printStack();
void printQuadraples();
void constantPropagation(int index, quad arr[100]);
int checkForDigits(char *ch);
char* compute(char *x, char *y, char *op);
void constantFolding(quad arr[100]);
void copyPropagation(quad arr[100]);
void DCE(quad arr[100]);


/* Line 189 of yacc.c  */
#line 126 "tac.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_PACKAGE = 258,
     T_IMPORT = 259,
     T_FUNC = 260,
     T_BREAK = 261,
     T_CONST = 262,
     T_CONTINUE = 263,
     T_PRINT = 264,
     T_ELSE = 265,
     T_FOR = 266,
     T_IF = 267,
     T_RETURN = 268,
     T_VAR = 269,
     T_VAR_TYPE = 270,
     T_BOOL_CONST = 271,
     T_IDENTIFIER = 272,
     T_STRING = 273,
     T_NIL_VAL = 274,
     T_INTEGER = 275,
     T_FLOAT = 276,
     T_INCREMENT = 277,
     T_DECREMENT = 278,
     T_MOD = 279,
     T_DIVIDE = 280,
     T_MULTIPLY = 281,
     T_MINUS = 282,
     T_ADD = 283,
     T_NOT = 284,
     T_ASSIGN = 285,
     T_SEMICOLON = 286,
     T_GEQ = 287,
     T_LEQ = 288,
     T_NEQ = 289,
     T_EQL = 290,
     T_LOR = 291,
     T_LAND = 292,
     T_PERIOD = 293,
     T_COMMA = 294,
     T_RIGHTBRACKET = 295,
     T_LEFTBRACKET = 296,
     T_RIGHTBRACE = 297,
     T_LEFTBRACE = 298,
     T_RIGHTPARANTHESES = 299,
     T_LEFTPARANTHESES = 300,
     T_LSR = 301,
     T_GTR = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 55 "tac.y"

     char *sval;
	 int nval;



/* Line 214 of yacc.c  */
#line 216 "tac.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "tac.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     8,    12,    13,    17,    20,    23,    25,
      27,    29,    31,    33,    35,    37,    41,    44,    47,    51,
      52,    58,    62,    68,    72,    77,    83,    86,    90,    92,
      94,    96,    98,   100,   102,   106,   110,   116,   122,   123,
     124,   125,   126,   138,   140,   142,   144,   146,   148,   149,
     154,   155,   160,   164,   167,   169,   171,   173,   175,   177,
     179,   181,   183,   185,   187,   189,   191,   193,   195,   197,
     199,   201,   203,   205,   207,   210,   213,   215,   216,   219,
     224,   227
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,     3,    77,    78,    57,    -1,    43,    51,
      42,    -1,    -1,    51,    52,    31,    -1,    52,    31,    -1,
      51,    52,    -1,    52,    -1,    54,    -1,    53,    -1,    50,
      -1,    61,    -1,    62,    -1,    55,    -1,    69,    76,    69,
      -1,    69,    22,    -1,    69,    23,    -1,    67,    76,    67,
      -1,    -1,    14,    69,    59,    76,    67,    -1,    14,    69,
      59,    -1,     7,    69,    59,    76,    67,    -1,     7,    69,
      59,    -1,     9,    45,    18,    44,    -1,     5,    17,    45,
      44,    50,    -1,    57,    58,    -1,    57,    31,    58,    -1,
      58,    -1,    54,    -1,    56,    -1,    15,    -1,    68,    -1,
      17,    -1,    45,    69,    44,    -1,    12,    69,    50,    -1,
      12,    69,    50,    10,    50,    -1,    12,    69,    50,    10,
      61,    -1,    -1,    -1,    -1,    -1,    11,    53,    63,    31,
      69,    64,    31,    53,    65,    50,    66,    -1,    69,    -1,
      20,    -1,    21,    -1,    18,    -1,    16,    -1,    -1,    69,
      74,    69,    70,    -1,    -1,    69,    73,    69,    71,    -1,
      69,    72,    69,    -1,    75,    60,    -1,    60,    -1,    36,
      -1,    37,    -1,    35,    -1,    34,    -1,    46,    -1,    33,
      -1,    47,    -1,    32,    -1,    28,    -1,    27,    -1,    26,
      -1,    25,    -1,    24,    -1,    28,    -1,    27,    -1,    29,
      -1,    30,    -1,    17,    -1,    18,    -1,    18,    31,    -1,
      78,    79,    -1,    79,    -1,    -1,     4,    77,    -1,     4,
      45,    80,    44,    -1,    80,    77,    -1,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    85,    86,    89,    90,    91,    92,    95,
      96,    97,    98,    99,   100,   103,   104,   105,   106,   109,
     112,   113,   114,   115,   119,   122,   125,   126,   127,   130,
     131,   134,   138,   139,   140,   144,   145,   146,   150,   150,
     150,   150,   150,   154,   157,   158,   159,   160,   164,   164,
     167,   167,   169,   172,   174,   177,   178,   181,   182,   183,
     184,   185,   186,   189,   190,   191,   192,   193,   196,   197,
     198,   201,   204,   205,   206,   211,   212,   213,   216,   217,
     220,   221
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PACKAGE", "T_IMPORT", "T_FUNC",
  "T_BREAK", "T_CONST", "T_CONTINUE", "T_PRINT", "T_ELSE", "T_FOR", "T_IF",
  "T_RETURN", "T_VAR", "T_VAR_TYPE", "T_BOOL_CONST", "T_IDENTIFIER",
  "T_STRING", "T_NIL_VAL", "T_INTEGER", "T_FLOAT", "T_INCREMENT",
  "T_DECREMENT", "T_MOD", "T_DIVIDE", "T_MULTIPLY", "T_MINUS", "T_ADD",
  "T_NOT", "T_ASSIGN", "T_SEMICOLON", "T_GEQ", "T_LEQ", "T_NEQ", "T_EQL",
  "T_LOR", "T_LAND", "T_PERIOD", "T_COMMA", "T_RIGHTBRACKET",
  "T_LEFTBRACKET", "T_RIGHTBRACE", "T_LEFTBRACE", "T_RIGHTPARANTHESES",
  "T_LEFTPARANTHESES", "T_LSR", "T_GTR", "$accept", "StartFile", "Block",
  "StatementList", "Statement", "SimpleStmt", "Declaration", "PrintStmt",
  "FunctionDecl", "TopLevelDeclList", "TopLevelDecl", "Type", "Operand",
  "IfStmt", "ForStmt", "$@1", "$@2", "$@3", "$@4", "ExpressionList",
  "BasicLit", "Expression", "$@5", "$@6", "bin_op", "rel_op", "math_op",
  "unary_op", "assign_op", "PackageName", "ImportDeclList", "ImportDecl",
  "ImportSpecList", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    55,    56,    57,    57,    57,    58,
      58,    59,    60,    60,    60,    61,    61,    61,    63,    64,
      65,    66,    62,    67,    68,    68,    68,    68,    70,    69,
      71,    69,    69,    69,    69,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
      75,    76,    77,    77,    77,    78,    78,    78,    79,    79,
      80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     0,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     3,     0,
       5,     3,     5,     3,     4,     5,     2,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     5,     5,     0,     0,
       0,     0,    11,     1,     1,     1,     1,     1,     0,     4,
       0,     4,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     0,     2,     4,
       2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    72,    73,    77,     1,    74,     0,     0,
      76,     0,    78,     0,     0,     0,    29,    30,     2,    28,
      75,    81,     0,     0,    47,    33,    46,    44,    45,    69,
      68,    70,     0,    54,    32,     0,     0,     0,     0,    26,
      79,    80,     0,     0,    31,    67,    66,    65,    64,    63,
      62,    60,    58,    57,    55,    56,    59,    61,    23,     0,
       0,     0,    53,    21,    27,     4,    34,    71,     0,    52,
      50,    48,     0,     4,    25,    22,    43,    51,    49,    20,
       0,    19,     0,    11,     4,     8,    10,     9,    14,    12,
      13,     0,     0,     0,    38,     4,     3,     7,     6,     0,
      16,    17,     0,     0,     0,    35,     5,    18,    15,    24,
       0,     4,    39,    36,    37,     0,    19,    40,     4,    41,
      42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    83,    84,    85,    86,    16,    88,    17,    18,
      19,    58,    33,    89,    90,   104,   115,   118,   120,    91,
      34,    92,    78,    77,    59,    60,    61,    36,    68,     5,
       9,    10,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
       3,    19,    20,   -73,    -9,    30,   -73,   -73,    11,   211,
     -73,    19,   -73,    34,    99,    99,   -73,   -73,    26,   -73,
     -73,   -73,     9,     7,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,    99,   -73,   -73,    77,    73,    77,    72,   -73,
     -73,   -73,    15,   129,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,    31,    99,
      99,    99,   -73,    31,   -73,    17,   -73,   -73,    99,   177,
     177,   177,    99,    55,   -73,   -73,   177,   -73,   -73,   -73,
      29,    99,    99,   -73,    -4,    39,   -73,   -73,   -73,   -73,
     -73,    31,   113,    47,   -73,   153,   -73,    49,   -73,    99,
     -73,   -73,    99,    37,    56,    68,   -73,   -73,   177,   -73,
      99,    -8,   177,   -73,   -73,    64,    99,   -73,    17,   -73,
     -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -63,   -73,    13,   -72,   -54,   -73,   -73,   -73,
      25,    62,    70,    -3,   -73,   -73,   -73,   -73,   -73,   -57,
     -73,   -14,   -73,   -73,   -73,   -73,   -73,   -73,   -42,   160,
     -73,    98,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      35,    37,    74,    14,    82,    80,     1,    81,    82,    94,
      15,    75,    24,    25,    26,    79,    27,    28,    43,    87,
       6,    72,     7,    29,    30,    31,     3,     4,     3,     4,
      87,    13,   105,    14,     8,    73,     3,     4,    96,    73,
      15,    32,   107,    39,   117,    69,    70,    71,   113,    99,
     102,    23,    42,    40,    76,   119,    11,    38,    76,    65,
      73,    67,    14,    64,    80,   103,    81,    82,    95,    15,
      98,    24,    25,    26,    93,    27,    28,    13,   111,    14,
     106,   109,    29,    30,    31,    76,    15,   110,   108,    24,
      25,    26,    44,    27,    28,   116,   112,    97,    73,    63,
      32,    45,    46,    47,    48,    49,    62,    20,   114,    50,
      51,    52,    53,    54,    55,    24,    25,    26,    32,    27,
      28,     0,     0,    56,    57,     0,    29,    30,    31,     0,
       0,     0,     0,     0,     0,   100,   101,    45,    46,    47,
      48,    49,     0,    67,    32,    50,    51,    52,    53,    54,
      55,     0,     0,    45,    46,    47,    48,    49,     0,    56,
      57,    50,    51,    52,    53,    54,    55,     0,    12,     0,
       0,    21,     0,    66,     0,    56,    57,    45,    46,    47,
      48,    49,    41,     0,     0,    50,    51,    52,    53,    54,
      55,     0,     0,     0,     0,     0,    73,     0,     0,    56,
      57,    45,    46,    47,    48,    49,     0,     0,     0,    50,
      51,    52,    53,    54,    55,     8,    13,     0,    14,     0,
       0,     0,     0,    56,    57,    15
};

static const yytype_int8 yycheck[] =
{
      14,    15,    65,     7,    12,     9,     3,    11,    12,    81,
      14,    68,    16,    17,    18,    72,    20,    21,    32,    73,
       0,    63,    31,    27,    28,    29,    17,    18,    17,    18,
      84,     5,    95,     7,     4,    43,    17,    18,    42,    43,
      14,    45,    99,    18,   116,    59,    60,    61,   111,    91,
      92,    17,    45,    44,    68,   118,    45,    31,    72,    44,
      43,    30,     7,    38,     9,    18,    11,    12,    82,    14,
      31,    16,    17,    18,    45,    20,    21,     5,    10,     7,
      31,    44,    27,    28,    29,    99,    14,    31,   102,    16,
      17,    18,    15,    20,    21,    31,   110,    84,    43,    37,
      45,    24,    25,    26,    27,    28,    36,     9,   111,    32,
      33,    34,    35,    36,    37,    16,    17,    18,    45,    20,
      21,    -1,    -1,    46,    47,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    45,    32,    33,    34,    35,    36,
      37,    -1,    -1,    24,    25,    26,    27,    28,    -1,    46,
      47,    32,    33,    34,    35,    36,    37,    -1,     8,    -1,
      -1,    11,    -1,    44,    -1,    46,    47,    24,    25,    26,
      27,    28,    22,    -1,    -1,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    46,
      47,    24,    25,    26,    27,    28,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,     4,     5,    -1,     7,    -1,
      -1,    -1,    -1,    46,    47,    14
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    49,    17,    18,    77,     0,    31,     4,    78,
      79,    45,    77,     5,     7,    14,    54,    56,    57,    58,
      79,    77,    80,    17,    16,    17,    18,    20,    21,    27,
      28,    29,    45,    60,    68,    69,    75,    69,    31,    58,
      44,    77,    45,    69,    15,    24,    25,    26,    27,    28,
      32,    33,    34,    35,    36,    37,    46,    47,    59,    72,
      73,    74,    60,    59,    58,    44,    44,    30,    76,    69,
      69,    69,    76,    43,    50,    67,    69,    71,    70,    67,
       9,    11,    12,    50,    51,    52,    53,    54,    55,    61,
      62,    67,    69,    45,    53,    69,    42,    52,    31,    76,
      22,    23,    76,    18,    63,    50,    31,    67,    69,    44,
      31,    10,    69,    50,    61,    64,    31,    53,    65,    50,
      66
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 81 "tac.y"
    {
	;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 85 "tac.y"
    {;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 86 "tac.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 89 "tac.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 90 "tac.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 91 "tac.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 92 "tac.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 95 "tac.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 96 "tac.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 97 "tac.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 98 "tac.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 99 "tac.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 100 "tac.y"
    {;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 103 "tac.y"
    {codegen_assign();;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 104 "tac.y"
    {codegen_incdec(1);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 105 "tac.y"
    {codegen_incdec(0);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 106 "tac.y"
    {
		// b,c = 2,3
	;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 109 "tac.y"
    {;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 112 "tac.y"
    {codegen_assign();;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 113 "tac.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 114 "tac.y"
    {codegen_assign();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 115 "tac.y"
    {;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 119 "tac.y"
    {;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 122 "tac.y"
    {;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 125 "tac.y"
    {;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 126 "tac.y"
    {;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 127 "tac.y"
    {;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 130 "tac.y"
    {;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 131 "tac.y"
    {;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 134 "tac.y"
    {
	;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 138 "tac.y"
    {;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 139 "tac.y"
    {pushi((yyvsp[(1) - (1)].sval));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 140 "tac.y"
    {;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 150 "tac.y"
    {for1();;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 150 "tac.y"
    {for2();;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 150 "tac.y"
    {for3();;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 150 "tac.y"
    {for4();;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 150 "tac.y"
    {
  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 154 "tac.y"
    {;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 157 "tac.y"
    {push();;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 158 "tac.y"
    {push();;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 159 "tac.y"
    {push();;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 160 "tac.y"
    {push();
	;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 164 "tac.y"
    {codegen();;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 165 "tac.y"
    {
	;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 167 "tac.y"
    {codegen();;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 167 "tac.y"
    {
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 169 "tac.y"
    {
		// For logical operators
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 172 "tac.y"
    {
		;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 174 "tac.y"
    {;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 177 "tac.y"
    {push();;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 178 "tac.y"
    {push();;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 181 "tac.y"
    {push();;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 182 "tac.y"
    {push();;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 183 "tac.y"
    {push();;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 184 "tac.y"
    {push();;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 185 "tac.y"
    {push();;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 186 "tac.y"
    {push();;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 189 "tac.y"
    {push();;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 190 "tac.y"
    {push();;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 191 "tac.y"
    {push();;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 192 "tac.y"
    {push();;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 193 "tac.y"
    {push();;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 196 "tac.y"
    {;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 197 "tac.y"
    {;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 198 "tac.y"
    {;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 201 "tac.y"
    {push();;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 204 "tac.y"
    {;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 205 "tac.y"
    {;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 206 "tac.y"
    {;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 211 "tac.y"
    {;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 212 "tac.y"
    {;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 213 "tac.y"
    {;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 216 "tac.y"
    {;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 217 "tac.y"
    {;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 220 "tac.y"
    {;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 221 "tac.y"
    {;}
    break;



/* Line 1455 of yacc.c  */
#line 2167 "tac.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 223 "tac.y"


#include "lex.yy.c"
#include<ctype.h>
#include<fstream>
char st[100][100];
char i_[2]="0";
int temp_i=0;
char tmp_i[3];
char temp[2]="t";
int label[20];
int lnum=0;
int ltop=0;
int l_for=0;
ofstream fo;

int main (int argc, char** argv) {	
	printf("Inside main\n");
	FILE * fp= fopen(argv[1], "r");
	yyin = fp;
    fo.open("tac.txt");
	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");
	yyparse ( );
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");
	printf("---------------------ICG in the Three addres code in form of Quadruples-------------------------\n\n");
    printQuadraples();
    fo.close();
	return 0;
}

void printQuadraples()
{
    for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
    printf("Operator \t | Arg1 \t | Arg2 \t | Result \n");
    for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
    int i;
    for(i=0;i<quadlen;i++)
    {
        printf("%-8s \t | %-8s \t | %-8s \t | %-6s \n",q[i].op,q[i].arg1,q[i].arg2,q[i].res);
    }
	for(int i=0;i<62;i++)
        printf("-");
    cout << endl;
}

void printStack()
{
    cout << "Stack Top " << st[top] <<" "<<st[top-1]<<" "<<st[top-2]<<" "<<st[top-3]<<endl;
}

void push()
{
    cout << "Pushed to stack : "<<yytext<<endl;
    strcpy(st[++top],yytext);
    printStack();
}
void pusha()
{
    strcpy(st[++top],"  ");
}

void pushi(char * i)
{
    cout << "Pushed to stack : "<<i<<endl;
    strcpy(st[++top],i);
}
void pushx()
{
    strcpy(st[++top],"x ");
}
void pushab()
{
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
    strcpy(st[++top],"  ");
}

void codegen()
{   
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
    
    fo << temp <<" = "<<st[top-2]<<" "<<st[top-1]<<" "<<st[top]<<endl;
    q[quadlen].op = (char*)malloc(sizeof(char)*strlen(st[top-1]));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    q[quadlen].arg2 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,st[top-1]);
    strcpy(q[quadlen].arg1,st[top-2]);
    strcpy(q[quadlen].arg2,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    top-=2;
    strcpy(st[top],temp);
    temp_i++;
}

void codegen_assign()
{  
    fo << st[top-2] <<" = "<<st[top]<<endl;
    printf("%s = %s\n",st[top-2],st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char));
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(st[top-2]));
    strcpy(q[quadlen].op,"=");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,st[top-2]);
    quadlen++;

    top-=2;
}

void codegen_incdec(int o){
    if(o)
        pushi("+");
    else
        pushi("-");
    pushi("1");
    char tempi[31];
    strcpy(tempi,st[top-2]);
    codegen();
    pushi("=");
    cout<<"hello "<<st[top]<<" "<<st[top-1]<<" "<<st[top-2]<<endl;
    pushi(st[top-1]);
    cout<<"hello "<<st[top]<<" "<<st[top-1]<<" "<<st[top-2]<<endl;
    strcpy(st[top-2],tempi);
    codegen_assign();
}

void for1()
{   
    l_for = lnum;
    fo << "L"<<lnum<<": "<<endl;
    printf("L%d: \n",lnum++);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x[10];
    sprintf(x,"%d",lnum-1);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
}
void for2()
{ 
    strcpy(temp,"T");
    sprintf(tmp_i, "%d", temp_i);
    strcat(temp,tmp_i);
    fo << temp <<" = not "<<st[top]<<endl;
    printf("%s = not %s\n",temp,st[top]);
    q[quadlen].op = (char*)malloc(sizeof(char)*4);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(st[top]));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"not");
    strcpy(q[quadlen].arg1,st[top]);
    strcpy(q[quadlen].res,temp);
    quadlen++;
    fo <<"if "<<temp<<" goto L"<<lnum<<endl;
    printf("if %s goto L%d\n",temp,lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*3);
    q[quadlen].arg1 = (char*)malloc(sizeof(char)*strlen(temp));
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"if");
    strcpy(q[quadlen].arg1,temp);
    char x[10];
    sprintf(x,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,x));
    quadlen++;
    temp_i++;
    label[++ltop]=lnum;
    lnum++;
    fo <<"goto L"<<lnum<<endl;
    printf("goto L%d\n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"goto");
    char x1[10];
    sprintf(x1,"%d",lnum);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,x1));
    quadlen++;
    label[++ltop]=lnum;
    printf("L%d: \n",++lnum);
    fo <<"L"<<lnum<<": "<<endl;
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(lnum+2));
    strcpy(q[quadlen].op,"Label");
    char x2[10];
    sprintf(x2,"%d",lnum);
    char l2[]="L";
    strcpy(q[quadlen].res,strcat(l2,x2));
    quadlen++;
 }
void for3()
{   
    int x;
    x=label[ltop--];
    fo <<"goto L"<<l_for<<" "<<endl;
    printf("goto L%d \n",l_for);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",l_for);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    fo <<"L"<<x<<": "<<endl;
    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;

}
void for4()
{   
    int x;
    x=label[ltop--];
    fo <<"goto L"<<lnum<<" "<<endl;
    printf("goto L%d \n",lnum);
    q[quadlen].op = (char*)malloc(sizeof(char)*5);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*strlen(temp));
    strcpy(q[quadlen].op,"goto");
    char jug[10];
    sprintf(jug,"%d",lnum);
    char l[]="L";
    strcpy(q[quadlen].res,strcat(l,jug));
    quadlen++;
    fo <<"L"<<x<<": "<<endl;
    printf("L%d: \n",x);
    q[quadlen].op = (char*)malloc(sizeof(char)*6);
    q[quadlen].arg1 = NULL;
    q[quadlen].arg2 = NULL;
    q[quadlen].res = (char*)malloc(sizeof(char)*(x+2));
    strcpy(q[quadlen].op,"Label");
    char jug1[10];
    sprintf(jug1,"%d",x);
    char l1[]="L";
    strcpy(q[quadlen].res,strcat(l1,jug1));
    quadlen++;
}

char* compute(char *x, char *y, char *op)
{
    char* res;
    int xx=atoi(x);
    int yy=atoi(y);
    int result = 0;
    switch(*op)
    {
      case '+':
        result = xx+yy;
        break;
      case '-':
        result = xx-yy;
        break;
      case '*':
        result = xx*yy;
        break;
      case '/':
        result = xx/yy;
        break;
      case '%':
        result = xx%yy;
        break;
      case '>':
        res= strdup((xx>yy)?"true":"false");
        return res;
      case '<':
        res= strdup((xx<yy)?"true":"false");
        return res;
      default:
        if(strcmp(op,"==")) return (xx==yy)?(char *)"true":(char *)"false";
        else if(strcmp(op,">=")) return (xx>=yy)?(char *)"true":(char *)"false";
        else if(strcmp(op,"!=")) return (xx!=yy)?(char *)"true":(char *)"false";
        else if(strcmp(op,"<=")) return (xx<=yy)?(char *)"true":(char *)"false";
    }
    return (char*)to_string(result).c_str();
}
void copyPropagation(quad arr[100])
{
    char val[50], var[50];
    int i=0;
    for(; i<quadlen; i++)
    {     
        if(!arr[i].arg2){
            strcpy(var, arr[i].res);
            strcpy(val, arr[i].arg1);
            
            int flag = 0; 
            for(int j = i + 1; j<quadlen; j++)
            {
                    
                    if(strcmp(arr[j].res, var)==0){
                        break;
                    }
                    
                    if (strcmp(arr[j].arg1, var)==0){
                        strcpy(arr[j].arg1, val);
                        flag = 1;
                    }
                    
                    if (arr[j].arg2 && strcmp(arr[j].arg2, var)==0){
                        strcpy(arr[j].arg2, val);
                        flag = 1;
                    }
            }
            
            if(flag){
                int del = i;
                for (int k = del-1; k < quadlen; k++)
                {
                    arr[del]=arr[del+1];
                    del++;
                }
                
                quadlen=quadlen-1;
            }
        }
    }
}
void constantPropagation(int index, quad arr[100])
{
    char val[50], var[50];
    int i=index;
    strcpy(var, arr[i].res);
    strcpy(val, arr[i].arg1);
    i=index+1;
    for(; i<quadlen; i++)
    {   
        if (strcmp(arr[i].op, "if")!=0 && strcmp(arr[i].op, "goto")!=0 && strcmp(arr[i].op, "call")!=0 && strcmp(arr[i].op, "proc")!=0 && arr[i].op[0]!='L'&&strcmp(arr[i].res, "stack top")!=0){    
            if(strcmp(arr[i].res, var)==0)
            {
                return;
            }
            else if(arr[i].arg2 && strcmp(arr[i].arg2, var)==0)
            {
                strcpy(arr[i].arg2, val);
            }
            else if(arr[i].arg1 && strcmp(arr[i].arg1, var)==0)
            {
                strcpy(arr[i].arg1, val);
            }
        }
    }
}
int checkForDigits(char *ch)
{
    if(!ch) return 0;
    while(*ch)
    {
        if(isdigit(*ch++)==0)
        {
          return 0;
        }
        return 1;
    }
}

void constantFolding(quad arr[100])
{
  int i=0, flag=0;
  char* res=0;

  while(i<quadlen)
  {
    
    if(!arr[i].arg2)
    {
      flag=1;
      constantPropagation(i, arr);
    }
    int ch1=checkForDigits(arr[i].arg1);
    int ch2=checkForDigits(arr[i].arg2);

    char stringres[50];
    if(ch1==1 && ch2==1) 
    {
      
      res=compute(arr[i].arg1, arr[i].arg2, arr[i].op);
    
      strcpy(arr[i].op, "=");
      strcpy(arr[i].arg1, res);
      strcpy(arr[i].arg2, " ");

      constantPropagation(i, arr); 
    }
    i++;
  }
}
void DCE(quad arr[100])
{   
    char val[50], var[50];
    int i=0;
    for(; i<quadlen-1; i++)
    {       
            strcpy(var, arr[i].res);
            int flag = 1; 
            for(int j = i + 1; j<quadlen; j++)
            {
                    if (strcmp(arr[j].arg1, var)==0 || (arr[j].arg2 && strcmp(arr[j].arg2, var)==0) || (strcmp(arr[j].res,var)==0)){
                        flag = 0;
                        break;
                    }
            }
            if(flag){
                int del = i;
                for (int k = del-1; k < quadlen; k++)
                {
                    arr[del]=arr[del+1];
                    del++;
                }
                quadlen=quadlen-1;
            }

    }
}
