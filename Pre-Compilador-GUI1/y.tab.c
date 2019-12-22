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
#line 1 "alfa.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "alfa.h"

    void yyerror(const char* err);
    extern int line, col, error;
    extern FILE *yyin;
    extern FILE *yyout;
    extern int yylex();
    extern int yyleng;

    /*variables para conocer el estado actual del simbolo*/
    TIPO tipo_actual;
    CLASE clase_actual;
    INFO_SIMBOLO * aux;
    int tamanio_vector_actual=0; //Tamanio del vector
    int pos_variable_local_actual=1; //Posicion de variable global en ambitos de variables locales


    /*Ambito global y local*/
    extern TABLA_HASH * tablaSimbolosLocal;
    extern TABLA_HASH * tablaSimbolosGlobal;

    /*Otra informacion*/
    int num_variables_locales_actual=0;
    int cuantos_no=0;
    char aux_char[100];
    int en_explist=0;
    int etiqueta=1;

    /*Parametros*/
    int num_parametros_actual=0;
    int pos_parametro_actual=0;
    int num_parametros_llamada_actual=0;
    int comprobacion_parametros=0;

    /*Etiquetas*/
    int num_comparaciones=0;

    /*Funciones*/
    int fn_return=0;
    int tipo_retorno=0;


#line 114 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_CONSTANTE_ENTERA = 258,
    TOK_CONSTANTE_REAL = 259,
    TOK_IDENTIFICADOR = 260,
    TOK_MAIN = 261,
    TOK_INT = 262,
    TOK_BOOLEAN = 263,
    TOK_ARRAY = 264,
    TOK_FUNCTION = 265,
    TOK_IF = 266,
    TOK_ELSE = 267,
    TOK_WHILE = 268,
    TOK_SCANF = 269,
    TOK_PRINTF = 270,
    TOK_RETURN = 271,
    TOK_PUNTOYCOMA = 272,
    TOK_COMA = 273,
    TOK_PARENTESISIZQUIERDO = 274,
    TOK_PARENTESISDERECHO = 275,
    TOK_CORCHETEIZQUIERDO = 276,
    TOK_CORCHETEDERECHO = 277,
    TOK_LLAVEIZQUIERDA = 278,
    TOK_LLAVEDERECHA = 279,
    TOK_ASIGNACION = 280,
    TOK_MAS = 281,
    TOK_MENOS = 282,
    TOK_DIVISION = 283,
    TOK_ASTERISCO = 284,
    TOK_AND = 285,
    TOK_OR = 286,
    TOK_NOT = 287,
    TOK_IGUAL = 288,
    TOK_DISTINTO = 289,
    TOK_MENORIGUAL = 290,
    TOK_MAYORIGUAL = 291,
    TOK_MENOR = 292,
    TOK_MAYOR = 293,
    TOK_TRUE = 294,
    TOK_FALSE = 295,
    TOK_ERROR = 296,
    MENOSU = 297
  };
#endif
/* Tokens.  */
#define TOK_CONSTANTE_ENTERA 258
#define TOK_CONSTANTE_REAL 259
#define TOK_IDENTIFICADOR 260
#define TOK_MAIN 261
#define TOK_INT 262
#define TOK_BOOLEAN 263
#define TOK_ARRAY 264
#define TOK_FUNCTION 265
#define TOK_IF 266
#define TOK_ELSE 267
#define TOK_WHILE 268
#define TOK_SCANF 269
#define TOK_PRINTF 270
#define TOK_RETURN 271
#define TOK_PUNTOYCOMA 272
#define TOK_COMA 273
#define TOK_PARENTESISIZQUIERDO 274
#define TOK_PARENTESISDERECHO 275
#define TOK_CORCHETEIZQUIERDO 276
#define TOK_CORCHETEDERECHO 277
#define TOK_LLAVEIZQUIERDA 278
#define TOK_LLAVEDERECHA 279
#define TOK_ASIGNACION 280
#define TOK_MAS 281
#define TOK_MENOS 282
#define TOK_DIVISION 283
#define TOK_ASTERISCO 284
#define TOK_AND 285
#define TOK_OR 286
#define TOK_NOT 287
#define TOK_IGUAL 288
#define TOK_DISTINTO 289
#define TOK_MENORIGUAL 290
#define TOK_MAYORIGUAL 291
#define TOK_MENOR 292
#define TOK_MAYOR 293
#define TOK_TRUE 294
#define TOK_FALSE 295
#define TOK_ERROR 296
#define MENOSU 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 49 "alfa.y" /* yacc.c:355  */

            tipo_atributos atributos;
        

#line 243 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 260 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   142,   152,   161,   183,   191,   199,   209,
     218,   226,   235,   243,   251,   260,   273,   280,   288,   295,
     303,   333,   354,   383,   390,   399,   406,   414,   422,   429,
     437,   444,   452,   459,   467,   474,   481,   488,   496,   503,
     511,   546,   565,   605,   613,   622,   630,   639,   655,   664,
     680,   689,   790,   803,   822,   842,   860,   878,   896,   913,
     931,   949,   967,  1067,  1079,  1088,  1097,  1107,  1132,  1141,
    1149,  1159,  1168,  1178,  1194,  1211,  1228,  1246,  1263,  1282,
    1292,  1303,  1313,  1324,  1335,  1382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_CONSTANTE_ENTERA",
  "TOK_CONSTANTE_REAL", "TOK_IDENTIFICADOR", "TOK_MAIN", "TOK_INT",
  "TOK_BOOLEAN", "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE",
  "TOK_WHILE", "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA",
  "TOK_COMA", "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE", "TOK_FALSE", "TOK_ERROR", "MENOSU",
  "$accept", "programa", "inicio", "fin", "escritura1", "escritura2",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "fn_name",
  "fn_declaracion", "funcion", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "declaraciones_funcion",
  "sentencias", "sentencia", "sentencia_simple", "bloque", "asignacion",
  "elemento_vector", "condicional", "if_exp_sentencias",
  "if_exp_else_sentencias", "if_exp", "bucle", "bucle_exp_sentencias",
  "bucle_exp", "lectura", "escritura", "retorno_funcion", "exp",
  "activar_en_explist", "lista_expresiones", "resto_lista_expresiones",
  "comparacion", "constante", "constante_logica", "constante_entera",
  "identificador", "idpf", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -69

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    -8,    23,   -40,   -40,    33,   -40,   -40,    42,   -40,
      33,    38,   -40,   -40,   -40,    26,    35,   -40,   -40,    39,
      37,    54,    42,   -40,    41,   144,    35,   -40,    38,   -40,
      40,    56,   144,    42,   -11,    51,   -40,    66,    19,    19,
      70,   144,    78,   -40,   -40,    71,   -40,   -40,    74,   144,
     -40,   144,    79,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,    94,    80,    84,    19,    19,    19,   -40,    -3,    19,
      19,    19,   -40,   -40,   -40,   -22,   -40,   -40,   -40,   -22,
     -40,   -40,   -40,    19,   144,    83,    85,    19,    87,   -40,
     -40,    81,    42,   -40,    47,   -22,   105,    89,    86,    82,
     -40,   -40,    19,    19,    19,    19,    19,    19,   -22,   102,
      91,   -40,   117,   -40,    33,    84,   -40,    95,    19,   -40,
      19,    19,    19,    19,    19,    19,   -40,    24,    24,   -40,
     -40,     7,     7,   -40,   -40,   104,   -40,   -40,   -40,   -40,
      62,   108,   -22,   -22,   -22,   -22,   -22,   -22,   -40,    19,
     -40,   -40,    62,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    13,    14,     0,     5,
       7,     0,    10,    12,    11,     0,    19,     8,    84,     0,
      16,     0,     0,     6,     0,     0,    19,     9,     0,    83,
       0,     0,     0,    24,     0,     0,    50,     0,     0,     0,
       0,    30,     0,    33,    34,     0,    38,    43,     0,     0,
      39,     0,     0,    35,    36,    37,    18,    17,    15,    20,
       4,     0,     0,    26,     0,     0,     0,    51,    62,     0,
       0,     0,    81,    82,    66,    52,    63,    79,    80,    53,
      22,    31,    32,     0,     0,     0,     0,     0,     0,    85,
      27,     0,     0,    23,     0,    40,     0,     0,     0,     0,
      58,    61,     0,     0,     0,     0,     0,     0,    41,     0,
      45,    48,     0,     2,    29,    26,    42,     0,    70,    64,
       0,     0,     0,     0,     0,     0,    65,    54,    55,    56,
      57,    59,    60,    44,    46,     0,    28,    21,    25,    47,
      72,     0,    73,    74,    75,    76,    77,    78,    49,     0,
      69,    67,    72,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,   -40,    -9,   -40,   -40,   -40,
      -5,   -40,   101,   112,   -40,   -40,   -40,   -40,    15,    48,
     -40,   -30,   -40,   -40,   -40,   -40,   -12,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -39,   -40,   -40,
     -13,   -40,   -40,   -40,   120,   -40,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    88,    16,    32,     9,    10,    11,    12,
      13,    14,    19,    23,    24,    25,    26,    62,    93,    63,
     137,    40,    41,    42,    43,    44,    74,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    75,    97,   141,
     150,    99,    76,    77,    78,    20,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    17,    60,    15,   102,   103,   104,   105,   106,   107,
      64,    81,     1,    45,    65,     3,   -68,    31,    64,    85,
      45,    86,    29,     4,    68,    94,    95,    96,    61,    45,
      98,   100,   101,   102,   103,   104,   105,    45,    69,    45,
       6,     7,     8,    18,   108,    22,    70,    21,   112,     6,
       7,    71,   104,   105,   109,    28,    27,    29,    72,    73,
      33,    59,    58,   127,   128,   129,   130,   131,   132,   116,
      66,    67,    45,   102,   103,   104,   105,   106,   107,   140,
     149,   142,   143,   144,   145,   146,   147,    61,   102,   103,
     104,   105,   106,   107,    80,    82,    83,    84,    87,    89,
      91,    92,   126,   134,   114,   136,   119,   110,   118,   111,
     152,   113,   102,   103,   104,   105,   106,   107,   139,   120,
     121,   122,   123,   124,   125,   117,   133,   148,   151,    57,
     138,   102,   103,   104,   105,   106,   107,   135,    56,   153,
     115,    30,     0,   102,   103,   104,   105,   106,   107,    34,
       0,     0,     0,     0,     0,    35,     0,    36,    37,    38,
      39
};

static const yytype_int16 yycheck[] =
{
      39,    10,    32,     8,    26,    27,    28,    29,    30,    31,
      21,    41,     6,    25,    25,    23,    19,    22,    21,    49,
      32,    51,     3,     0,     5,    64,    65,    66,    33,    41,
      69,    70,    71,    26,    27,    28,    29,    49,    19,    51,
       7,     8,     9,     5,    83,    10,    27,    21,    87,     7,
       8,    32,    28,    29,    84,    18,    17,     3,    39,    40,
      19,     5,    22,   102,   103,   104,   105,   106,   107,    22,
      19,     5,    84,    26,    27,    28,    29,    30,    31,   118,
      18,   120,   121,   122,   123,   124,   125,    92,    26,    27,
      28,    29,    30,    31,    24,    17,    25,    23,    19,     5,
      20,    17,    20,    12,    23,   114,    20,    24,    19,    24,
     149,    24,    26,    27,    28,    29,    30,    31,    23,    33,
      34,    35,    36,    37,    38,    20,    24,    23,    20,    28,
     115,    26,    27,    28,    29,    30,    31,    20,    26,   152,
      92,    21,    -1,    26,    27,    28,    29,    30,    31,     5,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    44,    23,     0,    45,     7,     8,     9,    49,
      50,    51,    52,    53,    54,    53,    47,    49,     5,    55,
      88,    21,    10,    56,    57,    58,    59,    17,    18,     3,
      87,    53,    48,    19,     5,    11,    13,    14,    15,    16,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    56,    55,    22,     5,
      64,    53,    60,    62,    21,    25,    19,     5,     5,    19,
      27,    32,    39,    40,    69,    80,    85,    86,    87,    80,
      24,    64,    17,    25,    23,    64,    64,    19,    46,     5,
      89,    20,    17,    61,    80,    80,    80,    81,    80,    84,
      80,    80,    26,    27,    28,    29,    30,    31,    80,    64,
      24,    24,    80,    24,    23,    62,    22,    20,    19,    20,
      33,    34,    35,    36,    37,    38,    20,    80,    80,    80,
      80,    80,    80,    24,    12,    20,    49,    63,    61,    23,
      80,    82,    80,    80,    80,    80,    80,    80,    23,    18,
      83,    20,    80,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    47,    48,    49,    49,    50,
      51,    51,    52,    53,    53,    54,    55,    55,    56,    56,
      57,    58,    59,    60,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    85,
      85,    86,    86,    87,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     0,     0,     0,     0,     1,     2,     3,
       1,     1,     1,     1,     1,     5,     1,     3,     2,     0,
       3,     6,     3,     2,     0,     3,     0,     2,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     1,     4,     3,     4,     5,     3,     5,
       1,     2,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     2,     1,     1,     3,     3,     1,     5,     0,     2,
       0,     3,     0,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1
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
#line 133 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
}
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 142 "alfa.y" /* yacc.c:1646  */
    {
    CrearTablaGlobal();
    escribir_subseccion_data(yyout);
    escribir_cabecera_bss(yyout);
}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 152 "alfa.y" /* yacc.c:1646  */
    {
    escribir_fin(yyout);
    LimpiarTablas();
}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 161 "alfa.y" /* yacc.c:1646  */
    {
    INFO_SIMBOLO * totales = tablaSimbolosGlobal->simbolos;
    while(totales != NULL){

        if(totales->categoria == VARIABLE){
            if(totales->tipo == INT) {
                declarar_variable(yyout,totales->lexema,ENTERO,(totales->clase == VECTOR) ? totales->adicional1 : 1);
            }else if(totales->tipo == BOOLEAN){
                declarar_variable(yyout,totales->lexema,BOOLEANO,(totales->clase == VECTOR) ? totales->adicional1 : 1);
            }
        }

        totales = totales->siguiente;
    }

    escribir_segmento_codigo(yyout);
}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 183 "alfa.y" /* yacc.c:1646  */
    {
    escribir_inicio_main(yyout);
}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 191 "alfa.y" /* yacc.c:1646  */
    {

    fprintf(stdout, ";R2:\t<declaraciones> ::= <declaracion>\n");
}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 199 "alfa.y" /* yacc.c:1646  */
    {

    fprintf(stdout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 209 "alfa.y" /* yacc.c:1646  */
    {

    fprintf(stdout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 218 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R5:\t<clase> ::= <clase_escalar>\n");
    clase_actual=ESCALAR;
}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 226 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R7:\t<clase> ::= <clase_vector>\n");
    clase_actual=VECTOR;
}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 235 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R9:\t<clase_escalar> ::= <tipo>\n");
}
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 243 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R10:\t<tipo> ::= int\n");
    tipo_actual=INT;
}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 251 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R11:\t<tipo> ::= boolean\n");
    tipo_actual=BOOLEAN;
}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 260 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
    tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
    if((tamanio_vector_actual < 1) || (tamanio_vector_actual > MAX_TAMANIO_VECTOR)){
        fprintf(stdout,"****Error Semantico en la linea %d: El tamanyo del vector excede los limites permitidos (1,64).\n", line);
        return -1;
    }
}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 273 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R18:\t<identificadores> ::= <identificador>\n");
}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 280 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 288 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");
}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 295 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R21:\t<funciones> ::=\n");
}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 303 "alfa.y" /* yacc.c:1646  */
    {

    aux = UsoGlobal((yyvsp[0].atributos).lexema);

    if(aux != NULL){ //Error porque el identificador ya existe en este ambito
        fprintf(stdout,"****Error Semantico en la linea %d: Declaracion duplicada %s.\n", line, (yyvsp[0].atributos).lexema);
        return -1;
    }else{

        if(DeclararFuncion((yyvsp[0].atributos).lexema,FUNCION,tipo_actual,ESCALAR,-1,-1) == OK){
            pos_variable_local_actual=1;
            num_variables_locales_actual=0;
            pos_parametro_actual=0;
            num_parametros_actual=0;
            tamanio_vector_actual=0;
            (yyval.atributos).tipo = tipo_actual;
            strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);
            fn_return = 0;
        }else{
            fprintf(stdout,"****Error Semantico en la linea %d: Fallo al declarar funcion (%s).\n",line,(yyvsp[0].atributos).lexema);
            return -1;
        }

    }
}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 333 "alfa.y" /* yacc.c:1646  */
    {

    aux = UsoExclusivoLocal((yyvsp[-5].atributos).lexema);

    aux->adicional1 = num_parametros_actual;
    aux->adicional2 = num_variables_locales_actual;

    aux = UsoGlobal((yyvsp[-5].atributos).lexema);

    aux->adicional1 = num_parametros_actual;
    aux->adicional2 = num_variables_locales_actual;

    (yyval.atributos) = (yyvsp[-5].atributos);

    declararFuncion(yyout,(yyvsp[-5].atributos).lexema,num_variables_locales_actual);
}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 354 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");

    CerrarFuncion();
    tablaSimbolosLocal=NULL;

    aux = UsoGlobal((yyvsp[-2].atributos).lexema);

    if(aux == NULL){
        fprintf(stdout,"****Error Semantico en la linea %d:  Acceso a variable no declarada (%s).\n", line, (yyvsp[-2].atributos).lexema);
        return -1;
    }

    if(fn_return == 0){
        fprintf(stdout,"****Error Semantico en la linea %d:  Funcion %s sin sentencia de retorno.\n", line, (yyvsp[-2].atributos).lexema);
        return -1;
    }

    if(tipo_retorno != aux->tipo){
      fprintf(stdout,"****Error Semantico en la linea %d: Retorno funcion %s tipo incorrecto.\n", line, (yyvsp[-2].atributos).lexema);
      return -1;
    }

}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 383 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 390 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";;R24:\t<parametros_funcion> ::=\n");
}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 399 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R25:\t <resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 406 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R26:\t<resto_parametros_funcion> ::=\n");
}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 414 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 422 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 429 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R29:\t<declaraciones_funcion> ::=\n");
}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 437 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R30:\t<sentencias> ::= <sentencia>\n");
}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 444 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");
}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 452 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");
}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 459 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R33:\t<sentencia> ::= <bloque>\n");
}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 467 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 474 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 481 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 488 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 496 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R40:\t<bloque> ::= <condicional>\n");
}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 503 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R41:\t<bloque> ::= <bucle>\n");
}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 511 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
    aux = UsoLocal((yyvsp[-2].atributos).lexema);

    if(aux == NULL){ fprintf(stdout,"Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n",line,(yyvsp[-2].atributos).lexema);
    return -1;}
    if(aux->categoria == FUNCION){ fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
    return -1;}
    if(aux->clase == VECTOR){ fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
    return -1;}
    if(aux->tipo != (yyvsp[0].atributos).tipo){ fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
    return -1;}

    /*quiere decir que es global*/
    if(UsoExclusivoLocal((yyvsp[-2].atributos).lexema) == NULL){
        asignar(yyout,(yyvsp[-2].atributos).lexema,(yyvsp[0].atributos).direcciones);

    /*quiere decir que es parametro*/
    }else if(aux->categoria == PARAMETRO){
        escribirParametro(yyout,aux->adicional2,num_parametros_actual);
        invertirEnPila(yyout);
        asignarDestinoEnPila(yyout,(yyvsp[0].atributos).direcciones);

    /*quiere decir que es local*/
    }else{
        escribirVariableLocal(yyout,aux->adicional2);
        invertirEnPila(yyout);
        asignarDestinoEnPila(yyout,(yyvsp[0].atributos).direcciones);
    }

}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 546 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(stdout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
        aux = UsoLocal((yyvsp[-2].atributos).lexema);

        if(aux == NULL){
            fprintf(stdout,"Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n",line, (yyvsp[-2].atributos).lexema);
            return -1;}
        if(aux->tipo != (yyvsp[0].atributos).tipo){
            fprintf(stdout,"Error Semantico en la linea %d: Asignacion incompatible.\n",line);
            return -1;
        }

        asignarDestinoEnPila(yyout,(yyvsp[0].atributos).direcciones); /*o es una constante o es una variable*/
}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 565 "alfa.y" /* yacc.c:1646  */
    {

    fprintf(stdout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
    aux = UsoGlobal((yyvsp[-3].atributos).lexema);

    if(aux == NULL){
        fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n",line, (yyvsp[-3].atributos).lexema);
        return -1;
    }

    if(aux->clase != VECTOR){
        fprintf(stdout,"****Error Semantico en la linea %d: Intento de indexacion de una variable que no es de tipo vector.\n",line);
        return -1;
    }

    if((yyvsp[-1].atributos).valor_entero >= aux->adicional1){
        fprintf(stdout,"****Error Semantico en la linea %d: Posicion incorrecta para la indexacion del vector.\n",line);
        return -1;
    }

    if((yyvsp[-1].atributos).tipo != INT){
        fprintf(stdout,"****Error Semantico en la linea %d:  El indice en una operacion de indexacion tiene que ser de tipo entero.\n",line);
        return -1;
    }

    if (en_explist == 0) {
      escribir_elemento_vector(yyout,(yyvsp[-3].atributos).lexema,MAX_TAMANIO_VECTOR,(yyvsp[-1].atributos).direcciones);
    }else{
      escribir_elemento_vector(yyout,(yyvsp[-3].atributos).lexema,MAX_TAMANIO_VECTOR,(yyvsp[-1].atributos).direcciones);
      operandoEnPilaAArgumento(yyout,1);
    }

    (yyval.atributos).tipo = aux->tipo;
    (yyval.atributos).direcciones = 1;
}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 605 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
    ifthen_fin(yyout, (yyvsp[0].atributos).etiqueta);
}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 613 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
    ifthenelse_fin(yyout, (yyvsp[-3].atributos).etiqueta);
}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 622 "alfa.y" /* yacc.c:1646  */
    {
    (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 630 "alfa.y" /* yacc.c:1646  */
    {
    (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
    ifthenelse_fin_then(yyout, (yyval.atributos).etiqueta);
}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 639 "alfa.y" /* yacc.c:1646  */
    {

    if((yyvsp[-2].atributos).tipo != BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Condicional con condicion de tipo int.\n",line);
        return -1;
    }

    (yyval.atributos).etiqueta = etiqueta++;
    ifthen_inicio(yyout, (yyvsp[-2].atributos).direcciones, (yyval.atributos).etiqueta);
}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 655 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
    while_fin(yyout,(yyvsp[-2].atributos).etiqueta);
}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 664 "alfa.y" /* yacc.c:1646  */
    {

    if((yyvsp[-2].atributos).tipo != BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Bucle con condicion de tipo int.\n",line);
        return -1;
    }

    (yyval.atributos).direcciones = (yyvsp[-2].atributos).direcciones;
    (yyval.atributos).etiqueta = (yyvsp[-4].atributos).etiqueta;
    while_exp_pila(yyout,(yyval.atributos).direcciones,(yyval.atributos).etiqueta);
}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 680 "alfa.y" /* yacc.c:1646  */
    {
    (yyval.atributos).etiqueta = etiqueta++;
    while_inicio(yyout,(yyval.atributos).etiqueta);
}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 689 "alfa.y" /* yacc.c:1646  */
    {

      fprintf(stdout, ";R54:\t<lectura> ::= scanf <identificador>\n");


      if(tablaSimbolosLocal != NULL){ //HAY AMBITO LOCAL

        aux = UsoExclusivoLocal((yyvsp[0].atributos).lexema);

        if(aux != NULL){

            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura enteros o booleanos.\n", line);
                return -1;
            }

            if(aux->clase == VECTOR){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura de variables escalares.\n", line);
                return -1;
            }

            /*LEER SI ES UN PARAMETRO*/
            if(aux->categoria == PARAMETRO){

                escribirParametro(yyout,aux->adicional2,num_parametros_actual);
                if(aux->tipo == INT){
                    leer_en_pila(yyout,0);
                }else{
                    leer_en_pila(yyout,1);
                }
            }else{/*LEER SI ES UNA LOCAL*/

                escribirVariableLocal(yyout,aux->adicional2);
                if(aux->tipo == INT){
                    leer_en_pila(yyout,0);
                }else{
                    leer_en_pila(yyout,1);
                }
            }
        }else{
            aux = UsoGlobal((yyvsp[0].atributos).lexema);

            if(aux != NULL){
                if(aux->categoria == FUNCION){
                    fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura enteros o booleanos.\n", line);
                    return -1;
                }

                if(aux->clase == VECTOR){
                    fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura de variables escalares.\n", line);
                    return -1;
                }

                if(aux->tipo == INT){
                    leer(yyout,(yyvsp[0].atributos).lexema,0);
                }else if(aux->tipo == BOOLEAN){
                    leer(yyout,(yyvsp[0].atributos).lexema,1);
                }


            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, (yyvsp[0].atributos).lexema);
                return -1;
            }
        }

    }else{

        aux = UsoGlobal((yyvsp[0].atributos).lexema);

        if(aux != NULL){
            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura enteros o booleanos.\n", line);
                return -1;
            }

            if(aux->clase == VECTOR){
                fprintf(stdout,"****Error Semantico en la linea %d: Solo lectura de variables escalares.\n", line);
                return -1;
            }

            if(aux->tipo == INT){
                leer(yyout,(yyvsp[0].atributos).lexema,0);
            }else if(aux->tipo == BOOLEAN){
                leer(yyout,(yyvsp[0].atributos).lexema,1);
            }


        }else{
            fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, (yyvsp[0].atributos).lexema);
            return -1;
        }

    }

}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 790 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R56:\t<escritura> ::= printf <exp>\n");
    if((yyvsp[0].atributos).tipo == INT){
        escribir(yyout,(yyvsp[0].atributos).direcciones,0);
    }else{
        escribir(yyout,(yyvsp[0].atributos).direcciones,1);
    }
}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 803 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R61:\t<retorno_funcion> ::= return <exp>\n");

    if(tablaSimbolosLocal == NULL){
      fprintf(stdout,"****Error Semantico en la linea %d: Sentencia de retorno fuera del cuerpo de una función.",line);
      return -1;
    }

    retornarFuncion(yyout,(yyvsp[0].atributos).direcciones);
    tipo_retorno = (yyvsp[0].atributos).tipo;
    fn_return++;


}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 822 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R72:\t<exp> ::= <exp> + <exp>\n");
    if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){

        (yyval.atributos).tipo = INT;
        (yyval.atributos).direcciones = 0;

        sumar(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }


}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 842 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R73:\t<exp> ::= <exp> - <exp>\n");
    if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){

        (yyval.atributos).tipo = INT;
        (yyval.atributos).direcciones = 0;

        restar(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones);

    }else{
        fprintf(stdout, "****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 860 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R74:\t<exp> ::= <exp> / <exp>\n");
    if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){

        (yyval.atributos).tipo = INT;
        (yyval.atributos).direcciones = 0;

        dividir(yyout, (yyvsp[-2].atributos).direcciones, (yyvsp[0].atributos).direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 878 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R75:\t<exp> ::= <exp> * <exp>\n");
    if((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == INT){

        (yyval.atributos).tipo = INT;
        (yyval.atributos).direcciones = 0;

        multiplicar(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 896 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R76:\t<exp> ::= - <exp>\n");
    if((yyvsp[0].atributos).tipo == INT){

        (yyval.atributos).tipo = INT;
        (yyval.atributos).direcciones = 0;

        cambiar_signo(yyout,(yyvsp[0].atributos).direcciones);
    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion aritmetica con operandos boolean.\n", line);
        return -1;
    }
}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 913 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R77:\t<exp> ::= <exp> && <exp>\n");
    if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;

        y(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion logica con operandos boolean.\n", line);
        return -1;
    }
}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 931 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R78:\t<exp> ::= <exp> || <exp>\n");
    if((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == BOOLEAN){

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;

        o(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones);

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion logica con operandos boolean.\n", line);
        return -1;
    }
}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 949 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R79:\t<exp> ::= ! <exp>\n");
    if((yyvsp[0].atributos).tipo == BOOLEAN){
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).direcciones = 0;

        no(yyout,(yyvsp[0].atributos).direcciones,cuantos_no);
        cuantos_no++;

    }else{
        fprintf(stdout,"****Error Semantico en la linea %d: Operacion logica con operandos boolean.\n",line);
        return -1;
    }
}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 967 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R80:\t<exp> ::= <identificador>\n");

    strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);

    if(tablaSimbolosLocal != NULL){
        aux = UsoExclusivoLocal((yyvsp[0].atributos).lexema);
        if(aux != NULL){ //BUSQUEDA EN LOCAL

            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de categoria incorrecta.\n", line, (yyvsp[0].atributos).lexema);
                return -1;
            }

            if(aux->clase == VECTOR){
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de clase incorrecta.\n", line, (yyvsp[0].atributos).lexema);
                return -1;
            }


            if(aux->categoria == VARIABLE){
                escribirVariableLocal(yyout,aux->adicional2);
            }else if(aux->categoria == PARAMETRO){
                escribirParametro(yyout,aux->adicional2,num_parametros_actual);
            }

            (yyval.atributos).tipo = aux->tipo;
            (yyval.atributos).direcciones = 1;

        }else{


            aux =  UsoGlobal((yyvsp[0].atributos).lexema);

            if(aux != NULL){

                if(aux->categoria == FUNCION){
                    fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de categoria incorrecta.\n", line, (yyvsp[0].atributos).lexema);
                    return -1;
                }

                if(aux->clase == VECTOR){
                    fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de clase incorrecta.\n", line, (yyvsp[0].atributos).lexema);
                    return -1;
                }

                if(en_explist == 0){
                  escribir_operando(yyout,(yyvsp[0].atributos).lexema,1); //Direccion
                }else{
                  escribir_operando(yyout,(yyvsp[0].atributos).lexema,1); //Direccion
                  operandoEnPilaAArgumento(yyout,1); //DUDAS
                }

                (yyval.atributos).tipo = aux->tipo;
                (yyval.atributos).direcciones = 1;


            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, (yyvsp[0].atributos).lexema);
                return -1;
            }
        }

    }else{ //BUSQUEDA EN GLOBAL

        aux =  UsoGlobal((yyvsp[0].atributos).lexema);
        if(aux != NULL){
            if(aux->categoria == FUNCION){
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de categoria incorrecta.\n", line, (yyvsp[0].atributos).lexema);
                return -1;
            }

            if(aux->clase == VECTOR){
              fprintf(stdout,"****Error Semantico en la linea %d: Variable %s de clase incorrecta.\n", line, (yyvsp[0].atributos).lexema);
                return -1;
            }

            if(en_explist == 0){
              escribir_operando(yyout,(yyvsp[0].atributos).lexema,1); //Direccion
            }else{
              escribir_operando(yyout,(yyvsp[0].atributos).lexema,1); //Direccion
              operandoEnPilaAArgumento(yyout,1); //DUDAS
            }

            (yyval.atributos).tipo = aux->tipo;
            (yyval.atributos).direcciones = 1;

        }else{
            fprintf(stdout,"****Error Semantico en la linea %d: Acceso a variable no declarada (%s).\n", line, (yyvsp[0].atributos).lexema);
            return -1;
        }

    }


}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1067 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R81:\t<constante>\n");
    snprintf(aux_char, sizeof(aux_char), "%d", (yyvsp[0].atributos).valor_entero);
    escribir_operando(yyout,aux_char,(yyvsp[0].atributos).direcciones);
    (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
    (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1079 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R82:\t<exp> ::= ( <exp> )\n");
    (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
    (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1088 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R83:\t<exp> ::= ( <comparacion> )\n");
    (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
    (yyval.atributos).direcciones = (yyvsp[-1].atributos).direcciones;
}
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1097 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R85:\t<exp> ::= <elemento_vector>\n");

    (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
    (yyval.atributos).direcciones = (yyvsp[0].atributos).direcciones;
}
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1107 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");

    if((aux = UsoLocal((yyvsp[-4].atributos).lexema)) == NULL){
        fprintf(stdout,"****Error Semantico en la linea %d: Acceso a funcion no declarada (%s).\n",line,(yyvsp[-4].atributos).lexema);
        return -1;
    }


    if(aux->categoria != FUNCION){
        fprintf(stdout,"****Error Semantico en la linea %d: Variable %s no es de categoria funcion.\n",line,(yyvsp[-4].atributos).lexema);
        return -1;
    }

    if(aux->adicional1 != comprobacion_parametros){
        fprintf(stdout,"****Error Semantico en la linea %d:Numero incorrecto de parametros en llamada a funcion.\n",line);
        return -1;
    }

    llamarFuncion(yyout, aux->lexema, aux->adicional1);
    en_explist = 0;
    (yyval.atributos).tipo = aux->tipo;
    (yyval.atributos).direcciones = 0;
}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1132 "alfa.y" /* yacc.c:1646  */
    {
    en_explist = 1;
}
#line 2492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1141 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
    comprobacion_parametros = comprobacion_parametros + 1;
}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1149 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R90:\t<lista_expresiones> ::=\n");
    comprobacion_parametros = 0;

}
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1159 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
    comprobacion_parametros = comprobacion_parametros + 1;

}
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1168 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R92:\t<resto_lista_expresiones> ::=\n");
    comprobacion_parametros = 0;

}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1178 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
    if((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    (yyval.atributos).tipo = BOOLEAN;
    (yyval.atributos).direcciones = 0;

    igual(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones,num_comparaciones++);
}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1194 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");

    if((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    (yyval.atributos).tipo = BOOLEAN;
    (yyval.atributos).direcciones = 0;

    distinto(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones,num_comparaciones++);
}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1211 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");

    if((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    (yyval.atributos).tipo = BOOLEAN;
    (yyval.atributos).direcciones = 0;

    menor_igual(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones,num_comparaciones++);
}
#line 2584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1228 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");

    if((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    mayor_igual(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones,num_comparaciones++);


    (yyval.atributos).tipo = BOOLEAN;
    (yyval.atributos).direcciones = 0;
}
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1246 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");

    if((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    (yyval.atributos).tipo = BOOLEAN;
    (yyval.atributos).direcciones = 0;

    menor(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones,num_comparaciones++);
}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1263 "alfa.y" /* yacc.c:1646  */
    {

    fprintf(stdout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");

    if((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
        fprintf(stdout,"****Error Semantico en la linea %d: Comparacion con operandos boolean.\n",line);
        return -1;
    }

    (yyval.atributos).tipo = BOOLEAN;
    (yyval.atributos).direcciones = 0;

    mayor(yyout,(yyvsp[-2].atributos).direcciones,(yyvsp[0].atributos).direcciones,num_comparaciones++);
}
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1282 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R99:\t<constante> ::= <constante_logica>\n");
    (yyval.atributos).tipo=(yyvsp[0].atributos).tipo;
    (yyval.atributos).direcciones=(yyvsp[0].atributos).direcciones;
    (yyval.atributos).valor_entero=(yyvsp[0].atributos).valor_entero;
}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1292 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R100:\t<constante> ::= <constante_entera>\n");
    (yyval.atributos).tipo=(yyvsp[0].atributos).tipo;
    (yyval.atributos).direcciones=(yyvsp[0].atributos).direcciones;
    (yyval.atributos).valor_entero=(yyvsp[0].atributos).valor_entero;
}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1303 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R102:\t<constante_logica> ::= true\n");
    (yyval.atributos).tipo=BOOLEAN;
    (yyval.atributos).direcciones=0;
    (yyval.atributos).valor_entero=1;
}
#line 2673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1313 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R103:\t<constante_logica> ::= false\n");
    (yyval.atributos).tipo=BOOLEAN;
    (yyval.atributos).direcciones=0;
    (yyval.atributos).valor_entero=0;
}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1324 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R104:\t<constante_entera> ::= <numero>\n");
    (yyval.atributos).tipo=INT;
    (yyval.atributos).direcciones=0;
    (yyval.atributos).valor_entero=(yyvsp[0].atributos).valor_entero;
}
#line 2695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1335 "alfa.y" /* yacc.c:1646  */
    {
    fprintf(stdout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");

    if(tablaSimbolosLocal != NULL){ //EXISTE LA LOCAL
        aux = UsoExclusivoLocal((yyvsp[0].atributos).lexema);
        if(aux != NULL){ //YA EXISTE EL ELEMENTO
            fprintf(stdout,"****Error Semantico en linea %d: Declaracion duplicada.\n", line);
            return -1;
        }else{
            //INSERTARLO EN LA TABLA LOCAL MIRANDO QUE SU CLASE SEA ESCALAR, NO PUEDE SER UN VECTOR
            if(clase_actual != ESCALAR){
                //ERROR DE DECLARACION, INDICAMOS
                fprintf(stdout,"****Error Semantico en la linea %d: Variable %s no es de clase escalar.\n",line, (yyvsp[0].atributos).lexema);
                return -1;
            }else{
                //INSERTARLO EN LA TABLA LOCAL
                if(DeclararLocal((yyvsp[0].atributos).lexema,VARIABLE,tipo_actual,clase_actual,0,pos_variable_local_actual) == OK){
                    pos_variable_local_actual++;
                    num_variables_locales_actual++;
                }else{
                    fprintf(stdout,"****Error Semantico en la linea %d: Fallo al crear variable (%s).",line, (yyvsp[0].atributos).lexema);
                    return -1;
                }
            }
        }
    }else{
        aux = UsoExclusivoGlobal((yyvsp[0].atributos).lexema);
        if(aux != NULL){ //YA EXISTE EL ELEMENTO
            fprintf(stdout,"****Error Semantico en la linea %d: Declaracion duplicada.\n", line);
            return -1;
        }else{
            //INSERTARLO EN LA TABLA GLOBAL(Revisar parametros)
            if(DeclararGlobal((yyvsp[0].atributos).lexema,VARIABLE,tipo_actual,clase_actual,tamanio_vector_actual,0) == OK){
                tamanio_vector_actual=0;
            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Fallo al crear variable (%s).",line, (yyvsp[0].atributos).lexema);
                return -1;
            }

        }
    }
}
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1382 "alfa.y" /* yacc.c:1646  */
    {

    if(tablaSimbolosLocal != NULL){
        aux = UsoExclusivoLocal((yyvsp[0].atributos).lexema);
        if(aux != NULL){
            fprintf(stdout,"****Error Semantico en la linea %d: Declaracion duplicada.\n", line);
            return -1;
        }else{
            if(DeclararLocal((yyvsp[0].atributos).lexema,PARAMETRO,tipo_actual,ESCALAR,0,pos_parametro_actual) == OK){
                pos_parametro_actual++;
                num_parametros_actual++;
            }else{
                fprintf(stdout,"****Error Semantico en la linea %d: Fallo al crear parametro (%s).",line,(yyvsp[0].atributos).lexema);
                return -1;
            }
        }
    }else{
        fprintf(stdout,"****Ambito local no esta abierto\n");
        return -1;
    }
}
#line 2768 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2772 "y.tab.c" /* yacc.c:1646  */
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
#line 1404 "alfa.y" /* yacc.c:1906  */


/*-------------------------------------------------------------------------------------------------------------------------*/
/*  CODIGO DE ERRORES SINTACTICOS
*/
/*-------------------------------------------------------------------------------------------------------------------------*/
void yyerror (const char* err){
        if(error == 0){
                fprintf(stdout,"****Error sintactico en [lin %d, col %d]\n", line, col-yyleng);
        }
        error = 0;
}
