
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
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "ea3.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>
#include "y.tab.h"

typedef struct {
       		    char lexema[100]; // lexema
                char tipo[100];				
                char valor[100];	
				char longitud[25];
	            }tsimbolos;
tsimbolos ts[50];

char * yytext;
int yystopparser=0;
int yylineno;
FILE  *yyin;
char *yyltext;


char idAux[100];
char idAsig[100];
char bufferaux1[100];
char bufferaux2[100];
char pivot[50];

int yylex();                
FILE  *yyin;

/*****************TERCETOS**********************/
int L_ind = 0;
int cant_tercetos = 0;
typedef struct terceto {
		int nroTerceto;
		char ope[30];
		char te1[99];
		char te2[30];
		char resultado_aux[10];
        int esEtiqueta;
	} terceto;
terceto vector_tercetos[100];
int indice_terceto = 0;	
int tercetosSaltos[100];
int tercetosEtiquetas[100];
int indiceSaltos = 0;
int cantConstantesImpar = 0;
int cantConstantesTotal = 0;
int saltoError1 = 0;
int saltoError2 = 0;
int saltoError3 = 0;
int saltoError4 = 0;
int saltoError5 = 0;

void insertarEtiqueta(char *indiceTerceto);
/* crea un terceto y lo agrega a la coleccion */
int crear_terceto(char*, char*, char*);
/* escribe los tercetos en un archivo */
void escribir_tercetos();
void escribirEtiquetas();
void preparar_assembler();
void convertirSalto(int);
int listaVacia = 0;

/***************ASSEMBLER******************/


void generarAsm();
void imprimirHeader(FILE*);
void imprimirVariables(FILE*);
void imprimirCodigo(FILE*);
int esSalto(int);
int esOperacion(int);
char* validaTipo(char*);
char* buscarValor(char *);




/* Line 189 of yacc.c  */
#line 155 "y.tab.c"

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
     WRITE = 258,
     READ = 259,
     SUMAIMPAR = 260,
     CTE = 261,
     CTE_S = 262,
     ID = 263,
     COMA = 264,
     PYC = 265,
     ASIGNA = 266,
     PARA = 267,
     PARC = 268,
     CA = 269,
     CC = 270
   };
#endif
/* Tokens.  */
#define WRITE 258
#define READ 259
#define SUMAIMPAR 260
#define CTE 261
#define CTE_S 262
#define ID 263
#define COMA 264
#define PYC 265
#define ASIGNA 266
#define PARA 267
#define PARC 268
#define CA 269
#define CC 270




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 82 "ea3.y"

	int int_val;
	double float_val;
	char *str_val;



/* Line 214 of yacc.c  */
#line 229 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "y.tab.c"

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   22

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  16
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  18
/* YYNRULES -- Number of states.  */
#define YYNSTATES  33

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

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
      15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    19,
      20,    25,    26,    32,    38,    43,    45,    49,    52
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      17,     0,    -1,    18,    -1,    19,    -1,    18,    19,    -1,
      20,    -1,    27,    -1,    21,    -1,     4,     8,    -1,    -1,
       8,    22,    11,    23,    -1,    -1,     5,    12,     8,    24,
      25,    -1,    10,    14,    26,    15,    13,    -1,    10,    14,
      15,    13,    -1,     6,    -1,    26,     9,     6,    -1,     3,
       7,    -1,     3,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   107,   108,   110,   110,   110,   112,   119,
     119,   135,   134,   235,   237,   249,   298,   374,   386
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WRITE", "READ", "SUMAIMPAR", "CTE",
  "CTE_S", "ID", "COMA", "PYC", "ASIGNA", "PARA", "PARC", "CA", "CC",
  "$accept", "s", "prog", "sent", "read", "asig", "$@1", "sumaimpar",
  "$@2", "sumaimpar2", "lista", "write", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    16,    17,    18,    18,    19,    19,    19,    20,    22,
      21,    24,    23,    25,    25,    26,    26,    27,    27
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     0,
       4,     0,     5,     5,     4,     1,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,     2,     3,     5,     7,     6,
      17,    18,     8,     0,     1,     4,     0,     0,    10,     0,
      11,     0,     0,    12,     0,    15,     0,     0,    14,     0,
       0,    16,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    13,    18,    21,    23,
      27,     9
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -10
static const yytype_int8 yypact[] =
{
       0,    -2,     2,   -10,    11,     0,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,    -9,   -10,   -10,     7,     1,   -10,     6,
     -10,     5,     3,   -10,    -6,   -10,     8,    -8,   -10,    10,
       9,   -10,   -10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -10,   -10,   -10,    13,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      25,    29,    16,     1,     2,    10,    11,    30,     3,    26,
      12,    14,    17,    19,    20,    22,    31,    24,    15,     0,
       0,    28,    32
};

static const yytype_int8 yycheck[] =
{
       6,     9,    11,     3,     4,     7,     8,    15,     8,    15,
       8,     0,     5,    12,     8,    10,     6,    14,     5,    -1,
      -1,    13,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     8,    17,    18,    19,    20,    21,    27,
       7,     8,     8,    22,     0,    19,    11,     5,    23,    12,
       8,    24,    10,    25,    14,     6,    15,    26,    13,     9,
      15,     6,    13
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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

/* Line 1455 of yacc.c  */
#line 105 "ea3.y"
    {printf("\nCOMPILACION EXITOSA\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 113 "ea3.y"
    {
        strcpy(idAux,yytext);
        crear_terceto("READ",idAux,"_");

    }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 119 "ea3.y"
    {strcpy(idAsig,yytext);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 120 "ea3.y"
    {
        int j;
        int saltoFinSumaImpar;
        saltoFinSumaImpar = crear_terceto("=",idAsig,"@auxResultado");

        for (j = 0; j < indiceSaltos; j++)
        {
            char auxSalto[5];
            itoa(saltoFinSumaImpar,auxSalto,10);
            strcpy(vector_tercetos[tercetosSaltos[j]].te1,auxSalto);
            insertarEtiqueta(auxSalto);
        }
    }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 135 "ea3.y"
    {
                strcpy(pivot,yytext);
                char auxSalto[5];
                char auxTe1[5];
                char auxLexema[100];
                int nroLexema = 0;

                //Creo el terceto que va a comparar si el pivot es mayor o igual a 1
                saltoError1 = crear_terceto("CMP",pivot,"_1");
                guardarLexemas("1",2);
                itoa(saltoError1+4,auxSalto,10);
                crear_terceto("BGE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"El valor de pivot debe ser >= 1\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");

                
                //Creo el terceto que va a comparar si la lista esta vacia
                saltoError4 = crear_terceto("CMP","_1","_");
                guardarLexemas("1",2);
                itoa(saltoError4+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"La lista está vacía\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");

                
                //Creo el terceto que va a comparar si el pivot es mayor a la cantidad de constantes totales
                saltoError3 = crear_terceto("CMP",pivot,"_");
                itoa(saltoError3+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"La lista tiene menos elementos que el indicado\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");
                    

                //Creo el terceto que va a comparar si hay impares
                saltoError5 = crear_terceto("CMP","_1","_");
                guardarLexemas("1",2);
                itoa(saltoError5+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"Elementos impares no encontrados\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");
                    

                //Creo el terceto que va a comparar si el pivot es mayor a la cantidad de constantes a sumar
                saltoError2 = crear_terceto("CMP",pivot,"_");
                itoa(saltoError2+4,auxSalto,10);
                crear_terceto("BLE",auxSalto,"_");
                insertarEtiqueta(auxSalto);
                strcpy(auxLexema,"\"No existen suficientes elementos impares para el cálculo\"");
                nroLexema = guardarLexemas(auxLexema,1);
                sprintf(auxTe1,"_STR%d",nroLexema);
                crear_terceto("PRINT",auxTe1,"_");
                crear_terceto("BI","END","_");
                

                

               }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 212 "ea3.y"
    {
                char auxCantConstantesImpar[5];
                char auxCantConstantesTotal[5];
                //Agrego en el terceto del salto por constantes impares la cantidad de constantes a comparar
                strcpy(bufferaux1,"_");
                itoa(cantConstantesImpar,auxCantConstantesImpar,10);
                guardarLexemas(auxCantConstantesImpar,2);
                strcat(bufferaux1,auxCantConstantesImpar);
                strcpy(vector_tercetos[saltoError2].te2,bufferaux1);
                strcpy(vector_tercetos[saltoError5].te2,bufferaux1);
                

                //Agrego en el terceto del salto por constantes totales la cantidad de constantes a comparar
                strcpy(bufferaux1,"_");
                itoa(cantConstantesTotal,auxCantConstantesTotal,10);
                guardarLexemas(auxCantConstantesTotal,2);
                strcat(bufferaux1,auxCantConstantesTotal);
                strcpy(vector_tercetos[saltoError3].te2,bufferaux1);
                strcpy(vector_tercetos[saltoError4].te2,bufferaux1);
                

            }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 238 "ea3.y"
    {
                char auxCantConstantesTotal[5];
                //Agrego en el terceto del salto por lista vacia
                strcpy(bufferaux1,"_");
                itoa(cantConstantesTotal,auxCantConstantesTotal,10);
                guardarLexemas(auxCantConstantesTotal,2);
                strcat(bufferaux1,auxCantConstantesTotal);
                strcpy(vector_tercetos[saltoError4].te2,bufferaux1);

            }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 250 "ea3.y"
    {
            //si la CTE es impar creo el terceto constante
            int valor;
            char auxResultado[5];
            strcpy(idAux,yytext);
            valor = atoi(idAux);
            printf("Nro:%d\n",valor);
            //Incremento la cantidad de constantes totales
            cantConstantesTotal++;
            if(valor%2!=0)
            {
                strcpy(bufferaux1,"_");
	            strcat(bufferaux1,idAux);
                L_ind = crear_terceto(bufferaux1,"_","_");
                

                
                strcpy(bufferaux1,"@aux");							// copio @aux
                itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                guardarLexemas(bufferaux1,0);

                sprintf(auxResultado,"%d",L_ind);
                crear_terceto("=","@auxResultado",auxResultado);
                
                //Creo el terceto que incrementa la cantidad de constantes sumadas
                L_ind = crear_terceto("+","@auxSumas","_1");
                strcpy(bufferaux1,"@aux");							// copio @aux
                itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                guardarLexemas(bufferaux1,0);

                sprintf(auxResultado,"%d",L_ind);
                crear_terceto("=","@auxSumas",auxResultado);



                //Incremento la cantidad de constantes para sumar
                cantConstantesImpar++;
            }
            else
            {
                L_ind = -1; //Si la primer constante es par no se creo el terceto 
            }
            
        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 299 "ea3.y"
    {
            //Si la CTE es impar creo el terceto suma, lista, constante
            char aux[5];
            char auxResultado[5];
            int valor;
            strcpy(idAux,yytext);
            valor = atoi(idAux);
            printf("Nro:%d\n",valor);
            //Incremento la cantidad de constantes totales
            cantConstantesTotal++;
            strcpy(bufferaux1,"_");
	        strcat(bufferaux1,idAux);
            if(valor%2!=0)
            {
                if( L_ind == -1) //Si la primer constante que se recibio fue par y no pudo crear el terceto)
                {
                    
                    L_ind = crear_terceto(bufferaux1,"_","_");

                    strcpy(bufferaux1,"@aux");							// copio @aux
                    itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                    strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                    strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                    guardarLexemas(bufferaux1,0);

                    sprintf(auxResultado,"%d",L_ind);
                    crear_terceto("=","@auxResultado",auxResultado);
                    
                }
                else //Si la primer constante que se recibio fue impar y pudo crear el terceto
                {
                    //creo el terceto para comparar el pivot con la cantidad de constantes que ya sume
                    crear_terceto("CMP",pivot,"@auxSumas");

                    //Creo el terceto del salto y lo guardo para luego escribirle el terceto a donde saltar
                    tercetosSaltos[indiceSaltos] = crear_terceto("BLE","_","_");
                    indiceSaltos++;
                    
                    
                    
                    //sprintf(aux,"%d",L_ind);
                    L_ind = crear_terceto("+","@auxResultado",bufferaux1);

                    strcpy(bufferaux1,"@aux");							// copio @aux
                    itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                    strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                    strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                    guardarLexemas(bufferaux1,0);


                    sprintf(auxResultado,"%d",L_ind);
                    crear_terceto("=","@auxResultado",auxResultado);
                    
                }

                //Creo el terceto que incrementa la cantidad de constantes sumadas
                L_ind = crear_terceto("+","@auxSumas","_1");

                strcpy(bufferaux1,"@aux");							// copio @aux
                itoa(L_ind,bufferaux2,10);									// transformo el nro de terceto
                strcat(bufferaux1,bufferaux2);								// creo la variable aux de assembler
                strcpy(vector_tercetos[L_ind].resultado_aux,bufferaux1);	// guardo junto al terceto
                guardarLexemas(bufferaux1,0);

                sprintf(auxResultado,"%d",L_ind);
                crear_terceto("=","@auxSumas",auxResultado);




                //Incremento la cantidad de constantes para sumar
                cantConstantesImpar++;
            }
        }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 375 "ea3.y"
    {
            char auxTe1[5];
            char auxLexema[100];
            int nroLexema = 0;
            
            strcpy(auxLexema,yytext);
            nroLexema = guardarLexemas(auxLexema,1);
            sprintf(auxTe1,"_STR%d",nroLexema);
            crear_terceto("PRINT",auxTe1,"_");

        }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 387 "ea3.y"
    {
            strcpy(idAux,yytext);
            crear_terceto("PRINT",idAux,"_");
        }
    break;



/* Line 1455 of yacc.c  */
#line 1775 "y.tab.c"
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



/* Line 1675 of yacc.c  */
#line 394 "ea3.y"



int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {

	yyparse();
    guardarLexemas("@auxResultado",0);
    guardarLexemas("@auxSumas",0);
	guardarTS_Archivo();
	escribir_tercetos();
    escribirEtiquetas();
    generarAsm();
  }
  fclose(yyin);
  return 0;
}

int yyerror(void)
{
     printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
}







/*****************TERCETOS**********************/

int  crear_terceto(char* p_ope, char* p_te1, char* p_te2)
{
	terceto res;
	res.nroTerceto = indice_terceto;
	strcpy(res.ope, p_ope);
	strcpy(res.te1, p_te1);
	strcpy(res.te2, p_te2);
	strcpy(res.resultado_aux,"_");
	vector_tercetos[indice_terceto] = res;
	indice_terceto++;
	return indice_terceto-1;
}

void escribir_tercetos()
{
	FILE* arch;
	int i;
	terceto aux;
	arch = fopen("intermedia.txt", "w+");

	for(i = 0; i < indice_terceto; i++)
	{	
		aux =  vector_tercetos[i];
		fprintf(arch, "[%d] (%s,%s,%s)\n", aux.nroTerceto, aux.ope,aux.te1, aux.te2 );
		
	}
	fclose(arch);
}

void insertarEtiqueta(char *indiceTerceto)
{
    int indice = atoi(indiceTerceto);
    tercetosEtiquetas[indice] = 1;
}

void escribirEtiquetas()
{
    int i = 0;
    for(i=0 ;i<100;i++)
    {
        if(tercetosEtiquetas[i]==1)
            vector_tercetos[i].esEtiqueta = 1;
        else
            vector_tercetos[i].esEtiqueta = 0;
    }

}

/***************ASSEMBLER******************/


void generarAsm()
{
	FILE *final = fopen("Final.asm","wt");
	if (final == NULL){
		printf("\r\nNo se pudo abrir el archivo Final\r\n");
		return;
	}
	char linea[50];
	char cmp[10]="FCOMP";

    preparar_assembler();

	imprimirHeader(final);

	imprimirVariables(final);

    imprimirCodigo(final);

    fprintf(final,"\nEtiqueta_END:\n");

    fprintf(final, "\nMOV AH, 1\nINT 21h\nMOV AX, 4C00h\nINT 21h\n\nEND START\n");
    
    fclose(final);
}


void imprimirHeader(FILE *p)
{
	
/*
    fprintf(p,"include macros2.asm\ninclude number.asm\n ");

    fprintf(p,".MODEL LARGE\n.386\n.STACK 200h\nMAXTEXTSIZE equ 50\n \n.DATA\n\n.DATA\n");*/
    
}

 void imprimirVariables(FILE * p)
{ 
int s,r,y;
   char aux[100];
   

	fprintf(p, "\ninclude macros2.asm\t\t ;incluye macros2");
    fprintf(p, "\ninclude number.asm\t\t ;incluye el asm para impresion de numeros");
	fprintf(p, "\n\n.model large");
	fprintf(p, "\n.386");
	fprintf(p, "\n.stack 200h");
	fprintf(p, "\n.LEN_LEXEMA equ 32");
	fprintf(p, "\n");
	fprintf(p, "\n.DATA\n");
	
	fprintf(p, "\n;Declaracion de variables y constantes.\n\n");
	
    fprintf(p, "@msg_int db \"Ingrese un entero:\", '$'\n");
	for(s=0;s<100;s++)
    {
        if(!strcmp(ts[s].tipo,"String"))
        {
        
            strcpy(aux,ts[s].lexema);
            for(y=0;y<strlen(aux);y++)
            {       
                if( aux[y]==' ' )
                    aux[y]='_';		
                if( aux[y]==':' )
                    aux[y]='_';
            }
            
            fprintf(p, "%s  DB  %s,'$'\n",aux,ts[s].valor);
        }
        
        
        if(!strcmp(ts[s].tipo,"CTE_INT"))
        {
            fprintf(p, "%s  DD  %.2f\n",ts[s].lexema,atof(ts[s].valor));
        }

        if(!strcmp(ts[s].tipo,"Integer"))
        {
            fprintf(p, "%s  DD ?\n",ts[s].lexema);
        }
   }

   fprintf(p, "\naux1 dd ?; auxiliar para realizar operaciones.");
 
   
    fprintf(p, "\n");
	fprintf(p, "\n.CODE");
	fprintf(p, "\nSTART:");
	
	fprintf(p, "\nmov AX,@DATA ;Copiar en AX (Registro Acumulador) la Direccion del Segmento de Datos");
	fprintf(p, "\nmov DS,AX ;Copiar en DS (Segmento de Datos) el registro AX");   
	fprintf(p, "\nMOV  ES,AX   ;Copiar en ES (Segmento Extra) el registro AX\n\n");  
 }

void preparar_assembler()
{
	char etiqueta[20] = "etiqueta_";
	int entero_aux;
    int i;
    int j;
	
/*	printf("ANTES: \n\n");
	for(i=0;i<indice_terceto;i++)
	{
		printf("    %s  %s  %s  %s  %d\n",vector_tercetos[i].ope,vector_tercetos[i].te1,vector_tercetos[i].te2,vector_tercetos[i].resultado_aux,vector_tercetos[i].esEtiqueta);
	}*/

	for(i=0;i<indice_terceto;i++)
	{

		if(strcmp(vector_tercetos[i].te1,"_")==0 && strcmp(vector_tercetos[i].te2,"_")==0 && vector_tercetos[i].esEtiqueta!=1 )
		{
			
			for(j=i+1;j< indice_terceto;j++)
			{
				itoa(i,bufferaux1,10);
				if(strcmp(vector_tercetos[j].te1,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].te1,vector_tercetos[i].ope);
				}
				if(strcmp(vector_tercetos[j].te2,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].te2,vector_tercetos[i].ope);
				}
			}
		}

		
		
		if(strcmp(vector_tercetos[i].te1,"_")==0 && strcmp(vector_tercetos[i].te2,"_")==0 && vector_tercetos[i].esEtiqueta==1 )
		{
			//printf("ETIQUETA + TERCETO _ _\n");
			j=i+1;
			itoa(i,bufferaux1,10);
			while(strcmp(vector_tercetos[j].te1,bufferaux1)!=0 && strcmp(vector_tercetos[j].te2,bufferaux1)!=0)
			j++;
			if(strcmp(vector_tercetos[j].te1,bufferaux1)==0)
			strcpy(vector_tercetos[j].te1,vector_tercetos[i].ope);
			else
			strcpy(vector_tercetos[j].te2,vector_tercetos[i].ope);
			
		}
		
        convertirSalto(i);

		if(esOperacion(i))
		{
            for(j=i+1;j< indice_terceto;j++)
			{	
				itoa(i,bufferaux1,10);
				if(strcmp(vector_tercetos[j].te1,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].te1,vector_tercetos[i].resultado_aux);
				}
				
				if(strcmp(vector_tercetos[j].te2,bufferaux1)==0)
				{
                    strcpy(vector_tercetos[j].te2,vector_tercetos[i].resultado_aux);
				}
				
			}
			
		}
		
		if(esSalto(i))
		{	
			//printf("OPE: %s - TE1: %s - TE2: %s\n",vector_tercetos[i].ope,vector_tercetos[i].te1,vector_tercetos[i].te2);
			entero_aux = atoi(vector_tercetos[i].te1);
			// printf("\nentero_aux: %d",entero_aux);
			vector_tercetos[entero_aux].esEtiqueta = 1;
			strcat(etiqueta,vector_tercetos[i].te1);
			// printf("\nETIQUETA: %s",etiqueta);
			strcpy(vector_tercetos[i].te1,etiqueta);
			// printf("\nvector_tercetos[%d].te1: %s",i,vector_tercetos[i].te1);
			strcpy(etiqueta,"etiqueta_");
		}
		
	}
	
	/*printf("DESPUES: \n\n");
	for(i=0;i<indice_terceto;i++)
	{
		printf("    %s  %s  %s  %s  %d\n",vector_tercetos[i].ope,vector_tercetos[i].te1,vector_tercetos[i].te2,vector_tercetos[i].resultado_aux,vector_tercetos[i].esEtiqueta);
	}*/
}


 void imprimirCodigo(FILE *p)
 {
    int i;

	for(i=0;i <= indice_terceto;i++)
	{		        

		if(vector_tercetos[i].esEtiqueta == 1)
		{
            // printf("\nVALOR i: %d", i);
            // printf("\nES ETIQUETA[%s, %s, %s]", vector_tercetos[i].te1, vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			fprintf(p,"etiqueta_%d:\n",i);
		}

         //printf("ES OPERACION %d", esOperacion(i));
        // printf("\n[%s, %s, %s]\n", vector_tercetos[i].te1, vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
		
		switch(esOperacion(i))
		{
		case 1:
			fprintf(p,"fld %s\nfld %s\nfadd\nfstp %s\n",vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 2:
			fprintf(p,"fld %s\nfld %s\nfsub\nfstp %s\n", vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 3:
			fprintf(p,"fld %s\nfld %s\nfmul\nfstp %s\n", vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 4:
			fprintf(p,"fld %s\nfld %s\nfdiv\nfstp %s\n", vector_tercetos[i].te1,vector_tercetos[i].te2, vector_tercetos[i].resultado_aux);
			break;
			
		case 5:
			fprintf(p,"fld %s\nfstp %s\n", vector_tercetos[i].te2, vector_tercetos[i].te1);
			break;
			
		case 6:
			fprintf(p,"DisplayFloat %s,1\nnewLine\n\n", vector_tercetos[i].te1);
			break;
			
		case 7:
			fprintf(p,"DisplayString %s,1\nnewLine\n\n", vector_tercetos[i].te1);
			break;
			
		case 8: //Read enteros
			fprintf(p,"DisplayString @msg_int \n");
			fprintf(p,"int 21h \n");
			fprintf(p,"newLine 1\n");
			fprintf(p,"GetFloat %s \n",vector_tercetos[i].te1);
			break;
			
		case 9: //Read Real
			fprintf(p,"DisplayString @msg_float \n");
			fprintf(p,"int 21h \n");
			fprintf(p,"newLine 1\n");
			fprintf(p,"GetFloat %s \n",vector_tercetos[i].te1);
			break;
			
		case 10:
			fprintf(p,"LEA EAX, %s\n MOV %s , EAX\n", vector_tercetos[i].te2, vector_tercetos[i].te1);
			break;
			
		case 11:
			fprintf(p,"DisplayFloat %s,3\nnewLine\n\n", vector_tercetos[i].te1);
			break;
			
		}
		
		
		if(strcmp(vector_tercetos[i].ope,"CMP")==0)						// terceto de COMPARACION
		fprintf(p,"fld %s\nfld %s\nfxch\nfcomp\nfstsw ax\nsahf\n", vector_tercetos[i].te1,vector_tercetos[i].te2);
		
		
		switch(esSalto(i))
		{		
		case 1:
			fprintf(p,"JNA %s\n\n", vector_tercetos[i].te1);			// condicion >
			break;
			
		case 2:
			fprintf(p,"JAE %s\n\n", vector_tercetos[i].te1);			// condicion <
			break;
			
		case 3:
			fprintf(p,"JNAE %s\n\n", vector_tercetos[i].te1);			// condicion >=
			break;
			
		case 4:
			fprintf(p,"JA %s\n\n", vector_tercetos[i].te1);			// condicion <=
			break;
			
		case 5:
			fprintf(p,"JNE %s\n\n", vector_tercetos[i].te1);			// condicion ==
			break;
			
		case 6:
			fprintf(p,"JE %s\n\n", vector_tercetos[i].te1);			// condicion !=
			break;
			
		case 7:
			fprintf(p,"JMP %s\n\n", vector_tercetos[i].te1);			// salto incondicional
			break;
		}
		
		
	}
}


int esOperacion(int indice)
{

	char auxTipo[100];
    strcpy(auxTipo,validaTipo(vector_tercetos[indice].te1));
    if(strcmp(vector_tercetos[indice].ope,"+")==0)
	return 1;	
	if(strcmp(vector_tercetos[indice].ope,"=")==0)
    return 5;
	
  

	if(strcmp(vector_tercetos[indice].ope,"PRINT")==0)
    {
        if (strstr(vector_tercetos[indice].te1,"_STR"))
        return 7;
		else
		return 6;										
	}
	if(strcmp(vector_tercetos[indice].ope,"READ")==0)
        return 8;
	
	return 0;
}


void convertirSalto(int indice)
{
    if(!strcmp(vector_tercetos[indice].ope,"BLT"))
        strcpy(vector_tercetos[indice].ope,"JNAE");
    if(!strcmp(vector_tercetos[indice].ope,"BLE"))
        strcpy(vector_tercetos[indice].ope,"JNA");   
    if(!strcmp(vector_tercetos[indice].ope,"BGT"))
        strcpy(vector_tercetos[indice].ope,"JA");
    if(!strcmp(vector_tercetos[indice].ope,"BGE"))
        strcpy(vector_tercetos[indice].ope,"JAE");
    if(!strcmp(vector_tercetos[indice].ope,"BEQ"))
        strcpy(vector_tercetos[indice].ope,"JE");
    if(!strcmp(vector_tercetos[indice].ope,"BNE"))
        strcpy(vector_tercetos[indice].ope,"JNE");
    if(!strcmp(vector_tercetos[indice].ope,"BI"))
        strcpy(vector_tercetos[indice].ope,"JMP");
}

int esSalto(int indice)
{	
	if(strcmp(vector_tercetos[indice].ope,"JNA")==0)		// >
	return 1;
	
	if(strcmp(vector_tercetos[indice].ope,"JAE")==0)		// <
	return 2;
	
	if(strcmp(vector_tercetos[indice].ope,"JNAE")==0)		// >=
	return 3;
	
	if(strcmp(vector_tercetos[indice].ope,"JA")==0)			// <=
	return 4;
	
	if(strcmp(vector_tercetos[indice].ope,"JNE")==0)		// ==
	return 5;
	
	if(strcmp(vector_tercetos[indice].ope,"JE")==0)			// !=
	return 6;
	
	if(strcmp(vector_tercetos[indice].ope,"JMP")==0)		// salto incondicional
	return 7;
	
	return 0;
}

char* validaTipo(char* id)
{
	int i;
	for(i=0;i<100;i++)
	{		
		if(strcmp(id,ts[i].lexema)==0)
		{	
			return ts[i].tipo;
		}
	}

	return id;
}

char* buscarValor(char * valor)
{
	int x;
	for(x=0;x<100;x++)
	{
		if(strcmp(ts[x].valor,valor)==0)  
		    return ts[x].lexema;  
	}
	return valor;
}
