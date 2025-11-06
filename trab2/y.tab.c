/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _MAIG = 258,
     _MEIG = 259,
     _IG = 260,
     _DIF = 261,
     _PLUSPLUS = 262,
     _PLUSEQUAL = 263,
     _BOOL = 264,
     _ASM = 265,
     _ID = 266,
     _NUM = 267,
     _STRING = 268,
     _LET = 269,
     _VAR = 270,
     _CONST = 271,
     _IF = 272,
     _ELSE = 273,
     _FOR = 274,
     _WHILE = 275,
     _DO = 276,
     _SWITCH = 277,
     _FUNCTION = 278,
     _CASE = 279,
     _BREAK = 280,
     _DEFAULT = 281,
     _RETURN = 282,
     _DOTDOTDOT = 283
   };
#endif
/* Tokens.  */
#define _MAIG 258
#define _MEIG 259
#define _IG 260
#define _DIF 261
#define _PLUSPLUS 262
#define _PLUSEQUAL 263
#define _BOOL 264
#define _ASM 265
#define _ID 266
#define _NUM 267
#define _STRING 268
#define _LET 269
#define _VAR 270
#define _CONST 271
#define _IF 272
#define _ELSE 273
#define _FOR 274
#define _WHILE 275
#define _DO 276
#define _SWITCH 277
#define _FUNCTION 278
#define _CASE 279
#define _BREAK 280
#define _DEFAULT 281
#define _RETURN 282
#define _DOTDOTDOT 283




/* Copy the first part of user declarations.  */
#line 1 "glc_js.y"

// Includes em C/C++ e outras definições.
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
  int linha, coluna; 
  vector<string> c;
};

struct Simbolo {
  int linha, coluna;
  string tipo_decl; // "let", "const" e "var"
};

int linha = 1;
int coluna = 1;


// Pilha de Tabela de símbolos
vector< map< string, Simbolo > >  ts  = { { } };

vector<string> funcoes;

// Tenta declarar uma variável "let", "var" ou "const"
void tenta_declarar_let( string nome, int linha, int coluna );
void tenta_declarar_const( string nome, int linha, int coluna );

// Verifica se a variável já foi declarada como "var" anteriormente
bool ja_declarou_var( string nome, int linha, int coluna );

string gera_label( string prefixo );
vector<string> resolve_enderecos( vector<string> entrada );

void imprime_codigo( vector<string> codigo );
void erro( string msg );

string trim(const string &s, const string caracter);
vector<string> tokeniza (string s);

vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );

// Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
#define YYSTYPE Atributos

// protótipo para o analisador léxico (gerado pelo lex)
extern "C" int yylex();
void yyerror( const char* );


// string gera_label(string);
int declarar_var(string);
void verificar_var(string);

string tipo_decl = "let";
int num_params = 0;
int nivel_func = 0;



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      39,    43,    35,    33,    29,    34,    45,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      31,    30,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    13,    15,    17,    19,
      21,    25,    29,    31,    33,    36,    42,    43,    44,    45,
      49,    50,    54,    55,    59,    61,    66,    69,    72,    73,
      79,    89,    96,    99,   100,   111,   118,   119,   124,   126,
     127,   128,   133,   135,   136,   140,   144,   148,   152,   154,
     156,   160,   165,   170,   177,   182,   187,   192,   195,   199,
     204,   206,   209,   214,   218,   222,   225,   229,   233,   237,
     241,   245,   247,   249,   252,   253,   257,   258,   261,   263,
     265,   267,   269,   274,   278,   281,   284,   287
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    49,    48,    -1,    49,    -1,
      53,    40,    -1,    61,    -1,    60,    -1,    59,    -1,    63,
      -1,    72,    10,    40,    -1,    27,    72,    40,    -1,    40,
      -1,    50,    -1,    41,    42,    -1,    41,    51,    48,    42,
      52,    -1,    -1,    -1,    -1,    14,    54,    57,    -1,    -1,
      15,    55,    57,    -1,    -1,    16,    56,    57,    -1,    69,
      -1,    11,    30,    69,    58,    -1,    11,    58,    -1,    29,
      57,    -1,    -1,    20,    39,    68,    43,    49,    -1,    19,
      39,    53,    40,    68,    40,    69,    43,    49,    -1,    17,
      39,    68,    43,    49,    62,    -1,    18,    49,    -1,    -1,
      23,    11,    39,    51,    64,    43,    41,    48,    42,    52,
      -1,    39,    11,    43,    39,    66,    43,    -1,    -1,    11,
      65,    29,    64,    -1,    11,    -1,    -1,    -1,    11,    67,
      29,    64,    -1,    11,    -1,    -1,    69,    31,    69,    -1,
      69,    32,    69,    -1,    69,     5,    69,    -1,    69,     6,
      69,    -1,     9,    -1,    69,    -1,    11,    30,    69,    -1,
      11,    71,    30,    69,    -1,    76,    71,    30,    69,    -1,
      39,    11,    43,    71,    30,    69,    -1,    11,    71,    33,
      69,    -1,    11,    71,    34,    69,    -1,    11,    71,    35,
      69,    -1,    11,    71,    -1,    11,     8,    69,    -1,    11,
      71,     8,    69,    -1,    72,    -1,    11,     7,    -1,    38,
      69,    44,    71,    -1,    45,    11,    71,    -1,    38,    69,
      44,    -1,    45,    11,    -1,    72,    33,    72,    -1,    72,
      34,    72,    -1,    72,    35,    72,    -1,    72,    36,    72,
      -1,    72,    37,    72,    -1,    76,    -1,    70,    -1,    69,
      74,    -1,    -1,    29,    69,    74,    -1,    -1,    11,    71,
      -1,    11,    -1,    75,    -1,    12,    -1,    13,    -1,    75,
      39,    73,    43,    -1,    39,    69,    43,    -1,    34,    76,
      -1,    41,    42,    -1,    38,    44,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    86,    87,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   101,   102,   105,   108,   111,   111,
     112,   112,   113,   113,   114,   117,   123,   131,   132,   135,
     142,   148,   155,   156,   159,   165,   172,   172,   179,   185,
     188,   188,   196,   202,   205,   206,   207,   208,   209,   210,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   226,   229,   230,   231,   232,   235,   236,   237,   238,
     239,   240,   241,   244,   245,   248,   249,   252,   253,   256,
     257,   258,   259,   260,   261,   262,   263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_MAIG", "_MEIG", "_IG", "_DIF",
  "_PLUSPLUS", "_PLUSEQUAL", "_BOOL", "_ASM", "_ID", "_NUM", "_STRING",
  "_LET", "_VAR", "_CONST", "_IF", "_ELSE", "_FOR", "_WHILE", "_DO",
  "_SWITCH", "_FUNCTION", "_CASE", "_BREAK", "_DEFAULT", "_RETURN",
  "_DOTDOTDOT", "','", "'='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'['", "'('", "';'", "'{'", "'}'", "')'", "']'", "'.'", "$accept",
  "S", "CMDs", "CMD", "BLOCO_CMDs", "NOVO_ESCOPO", "DESTROI_ESCOPO",
  "DECL_VAR", "@1", "@2", "@3", "NOMEVAR", "OUTRAVAR", "CMD_WHILE",
  "CMD_FOR", "CMD_IF", "CMD_ELSE", "DECLA_FUNC", "ARGs_FUNC", "@4",
  "ARGs_FUNC2", "@5", "BOOL", "A", "RVALUE", "LVALUEPROP", "E", "PARAMS",
  "PARAM", "LVALUE", "F", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    44,
      61,    60,    62,    43,    45,    42,    47,    37,    91,    40,
      59,   123,   125,    41,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    50,    50,    51,    52,    54,    53,
      55,    53,    56,    53,    53,    57,    57,    58,    58,    59,
      60,    61,    62,    62,    63,    63,    65,    64,    64,    64,
      67,    66,    66,    66,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       3,     3,     1,     1,     2,     5,     0,     0,     0,     3,
       0,     3,     0,     3,     1,     4,     2,     2,     0,     5,
       9,     6,     2,     0,    10,     6,     0,     4,     1,     0,
       0,     4,     1,     0,     3,     3,     3,     3,     1,     1,
       3,     4,     4,     6,     4,     4,     4,     2,     3,     4,
       1,     2,     4,     3,     3,     2,     3,     3,     3,     3,
       3,     1,     1,     2,     0,     3,     0,     2,     1,     1,
       1,     1,     4,     3,     2,     2,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    87,    78,    80,    81,    18,    20,    22,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    16,     0,     2,
       4,    13,     0,     8,     7,     6,     9,    24,    72,    60,
      79,    71,    61,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,    71,
      78,    84,    86,    78,     0,     0,    60,    14,     0,     1,
       3,     5,     0,     0,     0,     0,     0,     0,    74,     0,
      58,    50,     0,    65,     0,     0,     0,     0,     0,    28,
      19,    21,    23,    87,     0,    49,     0,     0,    16,    77,
      85,    11,     0,    78,    83,     0,    10,    66,    67,    68,
      69,    70,    76,     0,     0,    64,    63,    59,    51,    54,
      55,    56,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,    39,    43,     0,     0,    17,     0,    73,    82,
      52,    62,    27,    28,    33,    46,    47,    44,    45,     0,
      29,    36,     0,    40,     0,     0,    15,    76,    25,     0,
      31,     0,     0,     0,     0,    35,    53,    75,    32,     0,
      39,     0,    39,     0,    37,     0,    41,    30,    17,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    58,   146,    22,    38,    39,
      40,    80,   114,    23,    24,    25,   150,    26,   142,   152,
     144,   154,    84,    27,    28,    37,    56,   103,   128,    30,
      31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const yytype_int16 yypact[] =
{
     178,  -125,    -1,  -125,  -125,  -125,  -125,  -125,   -29,   -28,
     -20,    17,   211,   219,   -13,   228,  -125,    14,    49,  -125,
     178,  -125,    19,  -125,  -125,  -125,  -125,  -125,  -125,   149,
      21,   -24,  -125,   252,   252,   252,    51,   136,    62,    62,
      62,   261,   195,   261,    38,     9,   252,    36,    55,  -125,
     -24,  -125,  -125,    92,   267,    37,   248,   143,   178,  -125,
    -125,  -125,    46,   211,   211,   211,   211,   211,   252,    63,
    -125,  -125,    50,   -24,   252,   252,   252,   252,   252,    16,
    -125,  -125,  -125,   -35,    53,    20,    57,    58,  -125,  -125,
    -125,  -125,   -15,    98,  -125,    56,  -125,    -2,    -2,  -125,
    -125,  -125,    73,    60,   252,   -24,  -125,  -125,  -125,  -125,
    -125,  -125,    62,   252,  -125,   178,   252,   252,   252,   252,
     261,   178,    93,    97,    79,   -24,  -125,   252,  -125,  -125,
    -125,  -125,  -125,    81,    94,  -125,  -125,  -125,  -125,    74,
    -125,    70,    75,    76,    86,   252,  -125,    73,  -125,   178,
    -125,   252,    87,    90,    88,  -125,  -125,  -125,  -125,    89,
      93,   178,    93,   178,  -125,    91,  -125,  -125,  -125,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -125,  -125,   -19,  -106,  -125,    52,   -30,   103,  -125,  -125,
    -125,   -36,     6,  -125,  -125,  -125,  -125,  -125,  -124,  -125,
    -125,  -125,   -41,     7,  -125,   -18,     0,  -125,     1,  -125,
       5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -86
static const yytype_int16 yytable[] =
{
      29,    60,    87,    81,    82,   -48,    32,    33,   -48,   134,
      41,    42,    48,    69,    35,   140,    32,    49,    51,    43,
      29,    36,    55,    35,   123,   116,   117,    89,    44,    34,
      36,    52,    89,    65,    66,    67,   164,    35,   166,    95,
      70,    71,    72,   158,    36,   112,   113,    35,    85,    59,
      85,   118,   119,    55,    36,   106,    57,   167,    29,    61,
      68,    55,    73,    97,    98,    99,   100,   101,    49,    49,
      49,    49,    49,    79,   124,   102,   132,    88,    90,   139,
      94,   107,   108,   109,   110,   111,    96,   131,    63,    64,
      65,    66,    67,   104,   105,    91,   115,   120,   126,    32,
      33,   121,   127,   129,   141,    32,    33,   124,   143,   145,
     112,   130,   149,   -38,   151,    29,   160,   162,   153,   -42,
     133,    29,    34,   135,   136,   137,   138,    85,    34,   155,
      35,   161,   163,   168,   147,    92,    35,    36,   169,   148,
     122,   125,   165,    36,    74,    86,   -77,     0,   157,    29,
       0,     0,   156,   -85,     0,     0,     0,     0,   159,    62,
       0,    29,     0,    29,     0,     0,    75,     0,     0,    76,
      77,    78,   -77,   -77,   -77,   -77,   -85,     0,   -85,   -85,
     -85,   -77,    63,    64,    65,    66,    67,     1,   -85,     2,
       3,     4,     5,     6,     7,     8,     0,     9,    10,     0,
       0,    11,     0,     0,     1,    12,     2,     3,     4,     5,
       6,     7,    13,     0,     0,     0,    14,    15,    16,    17,
       1,     0,    45,     3,     4,     0,     0,     0,     1,    13,
      50,     3,     4,    14,    54,     0,    47,     1,     0,    53,
       3,     4,     0,     0,     0,    13,     0,     0,     0,    14,
      46,     0,    47,    13,     0,     0,     0,    14,    46,     0,
      47,     1,    13,     2,     3,     4,    14,    54,     0,    47,
      83,     0,     2,     3,     4,     0,     1,     0,    93,     3,
       4,    63,    64,    65,    66,    67,    13,     0,     0,     0,
      14,    54,     0,    47,     0,    13,     0,     0,     0,    14,
      54,    13,    47,     0,     0,    14,    54,     0,    47
};

static const yytype_int16 yycheck[] =
{
       0,    20,    43,    39,    40,    40,     7,     8,    43,   115,
      39,    39,    12,    31,    38,   121,     7,    12,    13,    39,
      20,    45,    15,    38,    39,     5,     6,    45,    11,    30,
      45,    44,    50,    35,    36,    37,   160,    38,   162,    58,
      33,    34,    35,   149,    45,    29,    30,    38,    41,     0,
      43,    31,    32,    46,    45,    73,    42,   163,    58,    40,
      39,    54,    11,    63,    64,    65,    66,    67,    63,    64,
      65,    66,    67,    11,    92,    68,   112,    39,    42,   120,
      43,    74,    75,    76,    77,    78,    40,   105,    33,    34,
      35,    36,    37,    30,    44,    40,    43,    40,    42,     7,
       8,    43,    29,    43,    11,     7,     8,   125,    11,    30,
      29,   104,    18,    43,    40,   115,    29,    29,    43,    43,
     113,   121,    30,   116,   117,   118,   119,   120,    30,    43,
      38,    41,    43,    42,   127,    43,    38,    45,   168,   133,
      88,    43,   161,    45,     8,    42,    10,    -1,   147,   149,
      -1,    -1,   145,    10,    -1,    -1,    -1,    -1,   151,    10,
      -1,   161,    -1,   163,    -1,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    33,    -1,    35,    36,
      37,    45,    33,    34,    35,    36,    37,     9,    45,    11,
      12,    13,    14,    15,    16,    17,    -1,    19,    20,    -1,
      -1,    23,    -1,    -1,     9,    27,    11,    12,    13,    14,
      15,    16,    34,    -1,    -1,    -1,    38,    39,    40,    41,
       9,    -1,    11,    12,    13,    -1,    -1,    -1,     9,    34,
      11,    12,    13,    38,    39,    -1,    41,     9,    -1,    11,
      12,    13,    -1,    -1,    -1,    34,    -1,    -1,    -1,    38,
      39,    -1,    41,    34,    -1,    -1,    -1,    38,    39,    -1,
      41,     9,    34,    11,    12,    13,    38,    39,    -1,    41,
       9,    -1,    11,    12,    13,    -1,     9,    -1,    11,    12,
      13,    33,    34,    35,    36,    37,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    -1,    34,    -1,    -1,    -1,    38,
      39,    34,    41,    -1,    -1,    38,    39,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    11,    12,    13,    14,    15,    16,    17,    19,
      20,    23,    27,    34,    38,    39,    40,    41,    47,    48,
      49,    50,    53,    59,    60,    61,    63,    69,    70,    72,
      75,    76,     7,     8,    30,    38,    45,    71,    54,    55,
      56,    39,    39,    39,    11,    11,    39,    41,    72,    76,
      11,    76,    44,    11,    39,    69,    72,    42,    51,     0,
      48,    40,    10,    33,    34,    35,    36,    37,    39,    71,
      69,    69,    69,    11,     8,    30,    33,    34,    35,    11,
      57,    57,    57,     9,    68,    69,    53,    68,    39,    71,
      42,    40,    43,    11,    43,    48,    40,    72,    72,    72,
      72,    72,    69,    73,    30,    44,    71,    69,    69,    69,
      69,    69,    29,    30,    58,    43,     5,     6,    31,    32,
      40,    43,    51,    39,    71,    43,    42,    29,    74,    43,
      69,    71,    57,    69,    49,    69,    69,    69,    69,    68,
      49,    11,    64,    11,    66,    30,    52,    69,    58,    18,
      62,    40,    65,    43,    67,    43,    69,    74,    49,    69,
      29,    41,    29,    43,    64,    48,    64,    49,    42,    52
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 83 "glc_js.y"
    { imprime_codigo( (yyvsp[(1) - (1)]).c + "." + funcoes );  }
    break;

  case 3:
#line 86 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c; }
    break;

  case 10:
#line 95 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(2) - (3)]).c + "^"; }
    break;

  case 11:
#line 96 "glc_js.y"
    { (yyval).c = (yyvsp[(2) - (3)]).c + "'&retorno'" + "@" + "~"; }
    break;

  case 12:
#line 97 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 14:
#line 101 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 15:
#line 102 "glc_js.y"
    { (yyval).c.clear(); (yyval).c = (yyval).c + "<{" + (yyvsp[(3) - (5)]).c + "}>"; }
    break;

  case 16:
#line 105 "glc_js.y"
    { ts.push_back( {} ); }
    break;

  case 17:
#line 108 "glc_js.y"
    { ts.pop_back(); }
    break;

  case 18:
#line 111 "glc_js.y"
    { tipo_decl = "let"; }
    break;

  case 19:
#line 111 "glc_js.y"
    { (yyval).c = (yyvsp[(3) - (3)]).c; }
    break;

  case 20:
#line 112 "glc_js.y"
    { tipo_decl = "var"; }
    break;

  case 21:
#line 112 "glc_js.y"
    { (yyval).c = (yyvsp[(3) - (3)]).c; }
    break;

  case 22:
#line 113 "glc_js.y"
    { tipo_decl = "const"; }
    break;

  case 23:
#line 113 "glc_js.y"
    { (yyval).c = (yyvsp[(3) - (3)]).c; }
    break;

  case 24:
#line 114 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (1)]).c + "^"; }
    break;

  case 25:
#line 118 "glc_js.y"
    {
              (yyval).c.clear();
              if(declarar_var((yyvsp[(1) - (4)]).c[0])) (yyval).c = (yyvsp[(1) - (4)]).c + "&";
              (yyval).c = (yyval).c + (yyvsp[(1) - (4)]).c + (yyvsp[(3) - (4)]).c + "=" + "^" + (yyvsp[(4) - (4)]).c;
            }
    break;

  case 26:
#line 124 "glc_js.y"
    {
             (yyval).c.clear();
             if(declarar_var((yyvsp[(1) - (2)]).c[0])) (yyval).c = (yyvsp[(1) - (2)]).c + "&";
             (yyval).c = (yyval).c+ (yyvsp[(2) - (2)]).c;
          }
    break;

  case 27:
#line 131 "glc_js.y"
    { (yyval).c = (yyvsp[(2) - (2)]).c; }
    break;

  case 28:
#line 132 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 29:
#line 135 "glc_js.y"
    {
                              string bloco = gera_label("LBL_LOOP");
                              string end_bloco = gera_label("LBL_ENDWHILE");
                              (yyval).c.clear(); (yyval).c =  (yyval).c + (":" + bloco) + (yyvsp[(3) - (5)]).c + "!" +  end_bloco + "?" + (yyvsp[(5) - (5)]).c + bloco + "#" + (":" + end_bloco);
                              }
    break;

  case 30:
#line 142 "glc_js.y"
    { 
                              string bloco = gera_label("LBL_LOOP");
                              string end_bloco = gera_label("LBL_ENDFOR");
                              (yyval).c = (yyvsp[(3) - (9)]).c + (":" +bloco) + (yyvsp[(5) - (9)]).c + "!" + end_bloco + "?" + (yyvsp[(9) - (9)]).c + (yyvsp[(7) - (9)]).c + "^" + bloco + "#" +(":" + end_bloco);
                              }
    break;

  case 31:
#line 148 "glc_js.y"
    {
                              string bloco = gera_label("LBL_THEN");
                              string end_bloco = gera_label("LBL_ENDIF");
                              (yyval).c = (yyvsp[(3) - (6)]).c + "!" + bloco+ "?" + (yyvsp[(5) - (6)]).c + end_bloco + "#" + (":" + bloco) + (yyvsp[(6) - (6)]).c +(":" + end_bloco);
                              }
    break;

  case 32:
#line 155 "glc_js.y"
    {(yyval).c = (yyvsp[(2) - (2)]).c; }
    break;

  case 33:
#line 156 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 34:
#line 160 "glc_js.y"
    {
                string labelfunc = gera_label("LABELFUNCAO");
                (yyval).c = (yyvsp[(2) - (10)]).c + "&" + (yyvsp[(2) - (10)]).c + "{}" + "=" + "'&funcao'" + labelfunc + "[=]" + "^";
                funcoes = funcoes + (":"+labelfunc) + (yyvsp[(5) - (10)]).c + (yyvsp[(8) - (10)]).c + "undefined" + "@" + "'&retorno'" + "@" + "~";
              }
    break;

  case 35:
#line 166 "glc_js.y"
    {
                num_params++;
                (yyval).c = (yyvsp[(5) - (6)]).c + to_string(num_params) +(yyvsp[(2) - (6)]).c + "@" +"$" + "^";
              }
    break;

  case 36:
#line 172 "glc_js.y"
    { num_params++; }
    break;

  case 37:
#line 173 "glc_js.y"
    {
              (yyval).c.clear();
              if(declarar_var((yyvsp[(1) - (4)]).c[0])) (yyval).c = (yyvsp[(1) - (4)]).c + "&";
              num_params--;
              (yyval).c = (yyval).c + (yyvsp[(1) - (4)]).c + "arguments" + "@" + to_string(num_params) + "[@]" + "=" + "^" + (yyvsp[(4) - (4)]).c;
            }
    break;

  case 38:
#line 180 "glc_js.y"
    { 
              (yyval).c.clear();
              if(declarar_var((yyvsp[(1) - (1)]).c[0])) (yyval).c = (yyvsp[(1) - (1)]).c + "&";
              (yyval).c = (yyval).c + (yyvsp[(1) - (1)]).c + "arguments" + "@" + to_string(num_params) + "[@]" + "=" + "^";
            }
    break;

  case 39:
#line 185 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 40:
#line 188 "glc_js.y"
    {num_params++;}
    break;

  case 41:
#line 189 "glc_js.y"
    {
                (yyval).c.clear();
                if(declarar_var((yyvsp[(1) - (4)]).c[0])) (yyval).c = (yyvsp[(1) - (4)]).c + "&";
                num_params--;
                (yyval).c = (yyval).c + (yyvsp[(1) - (4)]).c + "arguments" + "@" + to_string(num_params) + "[@]" + "=" + "^" + (yyvsp[(4) - (4)]).c;
              }
    break;

  case 42:
#line 197 "glc_js.y"
    {
              (yyval).c.clear();
              if(declarar_var((yyvsp[(1) - (1)]).c[0])) (yyval).c = (yyvsp[(1) - (1)]).c + "&";;
              (yyval).c = (yyval).c + (yyvsp[(1) - (1)]).c + "@";
            }
    break;

  case 43:
#line 202 "glc_js.y"
    { (yyval).c.clear();}
    break;

  case 44:
#line 205 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c  + (yyvsp[(3) - (3)]).c + "<"; }
    break;

  case 45:
#line 206 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c  + (yyvsp[(3) - (3)]).c + ">"; }
    break;

  case 46:
#line 207 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c  + (yyvsp[(3) - (3)]).c + "=="; }
    break;

  case 47:
#line 208 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c  + (yyvsp[(3) - (3)]).c + "!="; }
    break;

  case 50:
#line 213 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "="; }
    break;

  case 51:
#line 214 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (4)]).c+ "@" + (yyvsp[(2) - (4)]).c + (yyvsp[(4) - (4)]).c + "[=]"; }
    break;

  case 52:
#line 215 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (4)]).c + (yyvsp[(2) - (4)]).c + (yyvsp[(4) - (4)]).c + "[=]"; }
    break;

  case 53:
#line 216 "glc_js.y"
    { (yyval).c = (yyvsp[(2) - (6)]).c+ "@" + (yyvsp[(4) - (6)]).c + (yyvsp[(6) - (6)]).c + "[=]"; }
    break;

  case 54:
#line 217 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (4)]).c+ "@" + (yyvsp[(2) - (4)]).c + "[@]"+ (yyvsp[(4) - (4)]).c + "+"; }
    break;

  case 55:
#line 218 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (4)]).c+ "@" + (yyvsp[(2) - (4)]).c + "[@]"+ (yyvsp[(4) - (4)]).c + "-"; }
    break;

  case 56:
#line 219 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (4)]).c+ "@" + (yyvsp[(2) - (4)]).c + "[@]"+ (yyvsp[(4) - (4)]).c + "*"; }
    break;

  case 57:
#line 220 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (2)]).c+ "@" + (yyvsp[(2) - (2)]).c + "[@]"; }
    break;

  case 58:
#line 221 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(1) - (3)]).c + "@" + (yyvsp[(3) - (3)]).c + "+"+ "="; }
    break;

  case 59:
#line 222 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (4)]).c+ "@" + (yyvsp[(2) - (4)]).c + (yyvsp[(1) - (4)]).c+ "@" + (yyvsp[(2) - (4)]).c + "[@]" + (yyvsp[(4) - (4)]).c + "+" + "[=]"; }
    break;

  case 61:
#line 226 "glc_js.y"
    { verificar_var((yyvsp[(1) - (2)]).c[0]); (yyval).c = (yyvsp[(1) - (2)]).c + "@" + (yyvsp[(1) - (2)]).c + (yyvsp[(1) - (2)]).c + "@" + "1" + "+" + "=" + "^"; }
    break;

  case 62:
#line 229 "glc_js.y"
    { (yyval).c = (yyvsp[(2) - (4)]).c + "[@]" + (yyvsp[(4) - (4)]).c ; }
    break;

  case 63:
#line 230 "glc_js.y"
    { (yyval).c = (yyvsp[(2) - (3)]).c + "[@]" + (yyvsp[(3) - (3)]).c; }
    break;

  case 64:
#line 231 "glc_js.y"
    { (yyval).c =  (yyvsp[(2) - (3)]).c; }
    break;

  case 65:
#line 232 "glc_js.y"
    { (yyval).c = (yyvsp[(2) - (2)]).c; }
    break;

  case 66:
#line 235 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "+"; }
    break;

  case 67:
#line 236 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "-"; }
    break;

  case 68:
#line 237 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "*"; }
    break;

  case 69:
#line 238 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "/"; }
    break;

  case 70:
#line 239 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (3)]).c + (yyvsp[(3) - (3)]).c + "%"; }
    break;

  case 73:
#line 244 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (2)]).c + (yyvsp[(2) - (2)]).c; num_params++; }
    break;

  case 74:
#line 245 "glc_js.y"
    { (yyval).c.clear(); }
    break;

  case 75:
#line 248 "glc_js.y"
    { (yyval).c = (yyvsp[(2) - (3)]).c + (yyvsp[(3) - (3)]).c; num_params++;}
    break;

  case 76:
#line 249 "glc_js.y"
    { (yyval).c.clear();  }
    break;

  case 77:
#line 252 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (2)]).c + "@" + (yyvsp[(2) - (2)]).c + "[@]"; }
    break;

  case 78:
#line 253 "glc_js.y"
    { (yyval).c = (yyvsp[(1) - (1)]).c + "@"; }
    break;

  case 82:
#line 259 "glc_js.y"
    { (yyval).c = (yyvsp[(3) - (4)]).c + to_string(num_params) + (yyvsp[(1) - (4)]).c + "$"; num_params = 0; }
    break;

  case 83:
#line 260 "glc_js.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 84:
#line 261 "glc_js.y"
    { (yyval).c.clear(); (yyval).c = (yyval).c + "0" + (yyvsp[(2) - (2)]).c + (yyvsp[(1) - (2)]).c; }
    break;

  case 85:
#line 262 "glc_js.y"
    { (yyval).c.clear(); (yyval).c = (yyval).c + "{}"; }
    break;

  case 86:
#line 263 "glc_js.y"
    { (yyval).c.clear(); (yyval).c = (yyval).c + "[]"; }
    break;


/* Line 1267 of yacc.c.  */
#line 1993 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 267 "glc_js.y"


#include "lex.yy.c"

void yyerror(const char* msg){
    cout << endl << "Erro: " << msg << endl
         << "Perto de :'" << yylval.c[0] << "'" <<endl
         << "Linha: " << linha << " " 
         << "Coluna: "<< coluna<< endl;
    exit(0);
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

void verificar_var(string nome) {
  for(int i = 0; i < ts.size(); i++) {
    map<string,Simbolo> escopo = ts[i];
    if(escopo.count(nome) > 0) return;
  }
  cout << "Erro: a variável '" << nome << "' não foi declarada." << endl;
  exit(1);
}

int declarar_var(string nome) {
  map<string,Simbolo> escopo = ts.back();
  if(escopo.count(nome) > 0 && escopo[nome].tipo_decl == "let") {
    cout << "Erro: a variável '" << nome << "' já foi declarada na linha "
         << escopo[nome].linha << "." << endl;
    exit(1);
  }

  for(map<string,Simbolo> escopo: ts){
    if(escopo.count(nome) > 0 && escopo[nome].tipo_decl == "var" && tipo_decl == "var") return 0;
  }

  Simbolo v;
  v.tipo_decl = tipo_decl;
  v.linha = linha;
  ts.back()[nome] = v;
  return 1;
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ )
    if( entrada[i][0] == ':' ) 
      label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
      saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

void imprime_codigo( vector<string> codigo ) {
  vector<string> codigo_resolvido = resolve_enderecos(codigo);
  for( int i = 0; i < codigo_resolvido.size(); i++ )
    cout << codigo_resolvido[i] << " ";
  cout << endl;
}

vector<string> tokeniza (string s){
	vector<string> result;
	string aux;
	int inicio = 0, final = s.find(" ");
  while (final > 0) {
      aux = s.substr(inicio, final - inicio);
      result = result + aux;
      inicio = final + 1;
      final = s.find(" ", inicio);
  }
  aux = s.substr(inicio, final - inicio);
  result = result + aux;
  return result;
}

string trim(const string &s, const string caracter) {
    string str4 = s.substr(s.find_first_not_of(caracter[0]));
    str4 = str4.substr(0,str4.find_last_not_of(caracter[1])+1) ;
    return str4;
}

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  vector<string> aux{ a };
  return aux + b;
}

int main(){
  yyparse();
  cout << endl;
  return 0;
}
