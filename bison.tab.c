/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "bison.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;

// Um simbolo da tabela de simbolos é um id e seu endereço
typedef struct {
    char *id;
    int end;
} simbolo;

typedef struct {
    int entrada;
    int saida;
} registradores;

typedef struct {
    int topo;
    registradores R[1000];
} Pilha;

// Vetor de simbolos (a tabela de simbolos em si)
Pilha *p;
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

simbolo tabsimb[1000];
int nsimbs = 0;
int auxEnd = 0;
// Dado um ID, busca na tabela de simbolos o endereço respectivo
int getendereco(char * id) {
    for (int i = 0; i < nsimbs; i++){
            if (!strcmp(tabsimb[i].id, id))
                return tabsimb[i].end;
    }
    return -1;
}
void push(Pilha *p,int entrada, int saida)
{
    p->topo++;
    p->R[p->topo].entrada = entrada;
    p->R[p->topo].saida = saida;
}
registradores pop(Pilha *p)
{
    if(p->topo==-1)
    {
        exit(1);
    }
    return p->R[p->topo--];
}

void erroSemantico(char *c) {
    if (getendereco(c) == -1) {
        //printf("printf \"Erro semantico, %s nao foi declarada\n\"", c);
        printf("Erro semantico, %s nao foi declarada\n", c);
        exit(1);
    }
}

void reDeclara(char *c){
    for (int i = 0; i < nsimbs; i++){
        if (!strcmp(tabsimb[i].id, c)){ 
            //printf("printf \"Erro semantico, %s nao pode ser redeclarada\" \n", c);
            printf("Erro semantico, %s nao pode ser redeclarada\n", c);
            exit(1);
        }
    }
}

/* Contador global de registradores temporarios */
int T=0;
/* Contador global de labels temporarios */
int S=0;


#line 152 "bison.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIS = 3,                       /* MAIS  */
  YYSYMBOL_MENOS = 4,                      /* MENOS  */
  YYSYMBOL_MENOR = 5,                      /* MENOR  */
  YYSYMBOL_MAIOR = 6,                      /* MAIOR  */
  YYSYMBOL_MENORIGUAL = 7,                 /* MENORIGUAL  */
  YYSYMBOL_MAIORIGUAL = 8,                 /* MAIORIGUAL  */
  YYSYMBOL_PORCENTO = 9,                   /* PORCENTO  */
  YYSYMBOL_LPAR = 10,                      /* LPAR  */
  YYSYMBOL_RPAR = 11,                      /* RPAR  */
  YYSYMBOL_PEV = 12,                       /* PEV  */
  YYSYMBOL_MAISMAIS = 13,                  /* MAISMAIS  */
  YYSYMBOL_MENOSMENOS = 14,                /* MENOSMENOS  */
  YYSYMBOL_LCHAVES = 15,                   /* LCHAVES  */
  YYSYMBOL_RCHAVES = 16,                   /* RCHAVES  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_NUM = 22,                       /* NUM  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_IGUAL = 24,                     /* IGUAL  */
  YYSYMBOL_ATRIB = 25,                     /* ATRIB  */
  YYSYMBOL_DIFERENTE = 26,                 /* DIFERENTE  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_MULT = 28,                      /* MULT  */
  YYSYMBOL_IF = 29,                        /* IF  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_CHAR = 31,                      /* CHAR  */
  YYSYMBOL_STRING = 32,                    /* STRING  */
  YYSYMBOL_INT = 33,                       /* INT  */
  YYSYMBOL_FLOAT = 34,                     /* FLOAT  */
  YYSYMBOL_PRINTF = 35,                    /* PRINTF  */
  YYSYMBOL_ASPASDUPLAS = 36,               /* ASPASDUPLAS  */
  YYSYMBOL_VIRGULA = 37,                   /* VIRGULA  */
  YYSYMBOL_SCANF = 38,                     /* SCANF  */
  YYSYMBOL_LCOLCHETES = 39,                /* LCOLCHETES  */
  YYSYMBOL_RCOLCHETES = 40,                /* RCOLCHETES  */
  YYSYMBOL_ESPECIAL = 41,                  /* ESPECIAL  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_codigos = 43,                   /* codigos  */
  YYSYMBOL_codigo = 44,                    /* codigo  */
  YYSYMBOL_declara = 45,                   /* declara  */
  YYSYMBOL_atrib = 46,                     /* atrib  */
  YYSYMBOL_expr = 47,                      /* expr  */
  YYSYMBOL_termo = 48,                     /* termo  */
  YYSYMBOL_fator = 49,                     /* fator  */
  YYSYMBOL_condicional = 50,               /* condicional  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_else_optional = 52,             /* else_optional  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_condicoes = 54,                 /* condicoes  */
  YYSYMBOL_condicao = 55,                  /* condicao  */
  YYSYMBOL_cremento_for = 56,              /* cremento_for  */
  YYSYMBOL_cremento = 57,                  /* cremento  */
  YYSYMBOL_laco = 58,                      /* laco  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_61_5 = 61,                      /* $@5  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_print = 64,                     /* print  */
  YYSYMBOL_read = 65                       /* read  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   132,   132,   133,   136,   137,   138,   139,   140,   141,
     142,   145,   151,   157,   166,   170,   176,   180,   184,   187,
     191,   195,   199,   202,   208,   212,   215,   222,   222,   231,
     234,   234,   243,   244,   248,   252,   258,   262,   266,   270,
     274,   278,   282,   285,   288,   293,   296,   301,   306,   310,
     301,   322,   326,   322,   336,   339,   344,   347
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAIS", "MENOS",
  "MENOR", "MAIOR", "MENORIGUAL", "MAIORIGUAL", "PORCENTO", "LPAR", "RPAR",
  "PEV", "MAISMAIS", "MENOSMENOS", "LCHAVES", "RCHAVES", "ELSE", "FOR",
  "AND", "OR", "NOT", "NUM", "ID", "IGUAL", "ATRIB", "DIFERENTE", "DIV",
  "MULT", "IF", "WHILE", "CHAR", "STRING", "INT", "FLOAT", "PRINTF",
  "ASPASDUPLAS", "VIRGULA", "SCANF", "LCOLCHETES", "RCOLCHETES",
  "ESPECIAL", "$accept", "codigos", "codigo", "declara", "atrib", "expr",
  "termo", "fator", "condicional", "$@1", "else_optional", "$@2",
  "condicoes", "condicao", "cremento_for", "cremento", "laco", "$@3",
  "$@4", "$@5", "$@6", "$@7", "print", "read", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      54,    14,    -3,    16,   -36,     6,    24,    42,    45,    54,
     -36,   -36,   -36,   -36,   -36,   -36,   -36,    32,    53,    69,
      27,    46,    27,    47,    -7,    44,    65,   -36,   -36,    -6,
     -36,   -36,   -36,    27,    27,   -36,   -35,    56,     0,   -36,
      84,     1,     4,   -36,    27,   -36,    27,    57,    87,    67,
      -8,    27,    88,   -36,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,   -36,    27,    27,    75,
      90,   -36,    91,    62,    93,    94,    95,    46,   -36,   -36,
      11,     0,     0,    71,    71,    71,    71,    71,    71,   -36,
     -36,   -36,   -36,   -36,    27,    96,    97,   -36,    98,   -36,
     -36,   -36,    13,   100,   -36,   101,    54,    99,   -36,   104,
      86,   -36,   105,    54,   108,    72,   106,   109,   -36,   -36,
     -36,   111,   -36,   -36,   -36,   102,   112,    54,    54,   -36,
     110,   113,   -36,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    51,     0,     0,     0,     0,     2,
       7,     4,     6,    10,     5,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     0,
      47,    45,    46,     0,     0,    24,    23,    42,    18,    22,
       0,    32,     0,    27,     0,    11,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,    48,    25,
       0,    16,    17,    41,    40,    39,    38,    36,    37,    21,
      19,    20,    34,    33,     0,     0,     0,    13,     0,    54,
      55,    56,     0,     0,    26,     0,     0,     0,    12,     0,
       0,    15,     0,     0,     0,     0,    29,     0,    57,    43,
      44,     0,    30,    28,    53,     0,     0,     0,     0,    49,
       0,     0,    31,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,    -9,   -36,   -36,   107,   -19,    35,    30,   -36,   -36,
     -36,   -36,   -21,   -36,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    37,    38,    39,    12,    70,
     123,   126,    40,    41,   121,    13,    14,    51,   103,   131,
      23,    96,    15,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    43,    42,    76,    54,    45,    49,    55,    56,    63,
      18,    19,    52,    53,    55,    56,    55,    56,    46,    20,
      67,    68,    20,    71,    17,    72,    22,    64,    65,    24,
      78,    77,    47,    21,    25,    80,    21,    33,    83,    84,
      85,    86,    87,    88,    69,    27,    92,    93,    34,    35,
      36,   104,    26,   109,    33,    29,    33,    44,   102,    55,
      56,    57,    58,    59,    60,    31,    35,    36,    35,    36,
      55,    56,     1,   105,    55,    56,    48,     2,    75,    73,
      61,    32,    62,     3,     4,   119,   120,     5,    50,     6,
      81,    82,     7,    89,    90,    91,    66,   112,    74,    79,
      94,    95,    98,    97,   117,    99,   100,   101,   107,   115,
     108,   106,   110,   111,   113,   114,     0,   127,   129,   130,
     118,   116,   125,   122,    30,   124,   132,   128,     0,   133
};

static const yytype_int16 yycheck[] =
{
       9,    22,    21,    11,    39,    12,    25,     3,     4,     9,
      13,    14,    33,    34,     3,     4,     3,     4,    25,    25,
      19,    20,    25,    44,    10,    46,    10,    27,    28,    23,
      51,    39,    39,    39,    10,    54,    39,    10,    57,    58,
      59,    60,    61,    62,    40,     0,    67,    68,    21,    22,
      23,    40,    10,    40,    10,    23,    10,    10,    77,     3,
       4,     5,     6,     7,     8,    12,    22,    23,    22,    23,
       3,     4,    18,    94,     3,     4,    32,    23,    11,    22,
      24,    12,    26,    29,    30,    13,    14,    33,    23,    35,
      55,    56,    38,    63,    64,    65,    12,   106,    11,    11,
      25,    11,    40,    12,   113,    12,    12,    12,    11,    23,
      12,    15,    12,    12,    15,    11,    -1,    15,   127,   128,
      12,    16,    11,    17,    17,    16,    16,    15,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    23,    29,    30,    33,    35,    38,    43,    44,
      45,    46,    50,    57,    58,    64,    65,    10,    13,    14,
      25,    39,    10,    62,    23,    10,    10,     0,    43,    23,
      46,    12,    12,    10,    21,    22,    23,    47,    48,    49,
      54,    55,    47,    54,    10,    12,    25,    39,    32,    47,
      23,    59,    54,    54,    39,     3,     4,     5,     6,     7,
       8,    24,    26,     9,    27,    28,    12,    19,    20,    40,
      51,    54,    54,    22,    11,    11,    11,    39,    54,    11,
      47,    48,    48,    47,    47,    47,    47,    47,    47,    49,
      49,    49,    54,    54,    25,    11,    63,    12,    40,    12,
      12,    12,    47,    60,    40,    54,    15,    11,    12,    40,
      12,    12,    43,    15,    11,    23,    16,    43,    12,    13,
      14,    56,    17,    52,    16,    11,    53,    15,    15,    43,
      43,    61,    16,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    45,    45,    45,    46,    46,    47,    47,    47,    48,
      48,    48,    48,    49,    49,    49,    49,    51,    50,    52,
      53,    52,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    56,    56,    57,    57,    59,    60,    61,
      58,    62,    63,    58,    64,    64,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     6,     5,     4,     7,     3,     3,     1,     3,
       3,     3,     1,     1,     1,     3,     4,     0,     9,     0,
       0,     5,     1,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     3,     0,     0,     0,
      14,     0,     0,     9,     5,     5,     5,     8
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 11: /* declara: INT ID PEV  */
#line 145 "bison.y"
                     { 
            reDeclara((yyvsp[-1].str_val));
            tabsimb[nsimbs] = (simbolo){strdup((yyvsp[-1].str_val)), auxEnd}; 
            auxEnd++;
            nsimbs++; 
         }
#line 1559 "bison.tab.c"
    break;

  case 12: /* declara: INT ID LCOLCHETES NUM RCOLCHETES PEV  */
#line 151 "bison.y"
                                               {
            reDeclara((yyvsp[-4].str_val));
            tabsimb[nsimbs] = (simbolo){strdup((yyvsp[-4].str_val)), auxEnd};
            auxEnd = auxEnd + (yyvsp[-2].int_val); 
            nsimbs++;  
         }
#line 1570 "bison.tab.c"
    break;

  case 13: /* declara: INT ID ATRIB condicoes PEV  */
#line 157 "bison.y"
                                     { 
            reDeclara((yyvsp[-3].str_val));
            tabsimb[nsimbs] = (simbolo){strdup((yyvsp[-3].str_val)), auxEnd}; 
            nsimbs++;
            auxEnd++;
            printf("mov %%r%d, %%t%d\n",getendereco((yyvsp[-3].str_val)),(yyvsp[-1].int_val));
         }
#line 1582 "bison.tab.c"
    break;

  case 14: /* atrib: ID ATRIB condicoes PEV  */
#line 166 "bison.y"
                               { 
         erroSemantico((yyvsp[-3].str_val));
         printf("mov %%r%d, %%t%d\n",getendereco((yyvsp[-3].str_val)),(yyvsp[-1].int_val) );
        }
#line 1591 "bison.tab.c"
    break;

  case 15: /* atrib: ID LCOLCHETES expr RCOLCHETES ATRIB condicoes PEV  */
#line 170 "bison.y"
                                                          { 
         erroSemantico((yyvsp[-6].str_val)); 
         printf("store %%t%d, %%t%d(%d)\n",(yyvsp[-1].int_val),(yyvsp[-4].int_val),getendereco((yyvsp[-6].str_val)));
        }
#line 1600 "bison.tab.c"
    break;

  case 16: /* expr: expr MAIS termo  */
#line 176 "bison.y"
                       {
           printf("add %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
           (yyval.int_val) = T++;
       }
#line 1609 "bison.tab.c"
    break;

  case 17: /* expr: expr MENOS termo  */
#line 180 "bison.y"
                        {
           printf("sub %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
           (yyval.int_val) = T++;
       }
#line 1618 "bison.tab.c"
    break;

  case 18: /* expr: termo  */
#line 184 "bison.y"
             { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1624 "bison.tab.c"
    break;

  case 19: /* termo: termo DIV fator  */
#line 187 "bison.y"
                        {
           printf("div %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
           (yyval.int_val) = T++;
       }
#line 1633 "bison.tab.c"
    break;

  case 20: /* termo: termo MULT fator  */
#line 191 "bison.y"
                         {
           printf("mult %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
           (yyval.int_val) = T++;
       }
#line 1642 "bison.tab.c"
    break;

  case 21: /* termo: termo PORCENTO fator  */
#line 195 "bison.y"
                             {
           printf("mod %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
           (yyval.int_val) = T++;
       }
#line 1651 "bison.tab.c"
    break;

  case 22: /* termo: fator  */
#line 199 "bison.y"
              { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1657 "bison.tab.c"
    break;

  case 23: /* fator: ID  */
#line 202 "bison.y"
           { 
            erroSemantico((yyvsp[0].str_val)); 
            //int end = getendereco($1);
            printf("mov %%t%d, %%r%d\n", T, getendereco((yyvsp[0].str_val)));
            (yyval.int_val) = T++;
         }
#line 1668 "bison.tab.c"
    break;

  case 24: /* fator: NUM  */
#line 208 "bison.y"
              {
            printf("mov %%t%d, %d\n", T, (yyvsp[0].int_val));
            (yyval.int_val) = T++;
         }
#line 1677 "bison.tab.c"
    break;

  case 25: /* fator: LPAR condicoes RPAR  */
#line 212 "bison.y"
                              {
            (yyval.int_val) = (yyvsp[-1].int_val);
         }
#line 1685 "bison.tab.c"
    break;

  case 26: /* fator: ID LCOLCHETES expr RCOLCHETES  */
#line 215 "bison.y"
                                        { 
            erroSemantico((yyvsp[-3].str_val)); 
            printf("load %%t%d, %%t%d(%d)\n",T,(yyvsp[-1].int_val),getendereco((yyvsp[-3].str_val)));
            (yyval.int_val) = T++;
         }
#line 1695 "bison.tab.c"
    break;

  case 27: /* $@1: %empty  */
#line 222 "bison.y"
                                {
                printf("jf %%t%d, R%d\n",(yyvsp[0].int_val),S);
                S++;
                push(p,S-1,S);
             }
#line 1705 "bison.tab.c"
    break;

  case 28: /* condicional: IF LPAR condicoes $@1 RPAR LCHAVES codigos RCHAVES else_optional  */
#line 226 "bison.y"
                                                          {
                pop(p);
             }
#line 1713 "bison.tab.c"
    break;

  case 29: /* else_optional: %empty  */
#line 231 "bison.y"
                {
                printf("label R%d\n",p->R[p->topo].entrada);
               }
#line 1721 "bison.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 234 "bison.y"
                     {
                printf("jump R%d\n",p->R[p->topo].saida);
                printf("label R%d\n",p->R[p->topo].entrada);
                S++; 
               }
#line 1731 "bison.tab.c"
    break;

  case 31: /* else_optional: ELSE $@2 LCHAVES codigos RCHAVES  */
#line 238 "bison.y"
                                         {
                printf("label R%d\n",p->R[p->topo].saida);
               }
#line 1739 "bison.tab.c"
    break;

  case 33: /* condicoes: condicao OR condicoes  */
#line 244 "bison.y"
                                  {
                printf("or %%t%d, %%t%d, %%t%d\n",T,(yyvsp[-2].int_val),(yyvsp[0].int_val));
                (yyval.int_val)=T++;
          }
#line 1748 "bison.tab.c"
    break;

  case 34: /* condicoes: condicao AND condicoes  */
#line 248 "bison.y"
                                   {
                printf("and %%t%d, %%t%d, %%t%d\n",T,(yyvsp[-2].int_val),(yyvsp[0].int_val));
                (yyval.int_val)=T++;
           }
#line 1757 "bison.tab.c"
    break;

  case 35: /* condicoes: NOT condicoes  */
#line 252 "bison.y"
                          {
                printf("not %%t%d, %%t%d\n",T,(yyvsp[0].int_val));
                (yyval.int_val)=T++;
           }
#line 1766 "bison.tab.c"
    break;

  case 36: /* condicao: expr IGUAL expr  */
#line 258 "bison.y"
                           {
            printf("equal %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
            (yyval.int_val) = T++;
          }
#line 1775 "bison.tab.c"
    break;

  case 37: /* condicao: expr DIFERENTE expr  */
#line 262 "bison.y"
                               {
            printf("diff %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
            (yyval.int_val) = T++;
          }
#line 1784 "bison.tab.c"
    break;

  case 38: /* condicao: expr MAIORIGUAL expr  */
#line 266 "bison.y"
                                {
            printf("greatereq %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
            (yyval.int_val) = T++;
          }
#line 1793 "bison.tab.c"
    break;

  case 39: /* condicao: expr MENORIGUAL expr  */
#line 270 "bison.y"
                                {
            printf("lesseq %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
            (yyval.int_val) = T++;
          }
#line 1802 "bison.tab.c"
    break;

  case 40: /* condicao: expr MAIOR expr  */
#line 274 "bison.y"
                           {
            printf("greater %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
            (yyval.int_val) = T++;
          }
#line 1811 "bison.tab.c"
    break;

  case 41: /* condicao: expr MENOR expr  */
#line 278 "bison.y"
                           {
            printf("less %%t%d, %%t%d, %%t%d\n", T, (yyvsp[-2].int_val), (yyvsp[0].int_val));
            (yyval.int_val) = T++;
          }
#line 1820 "bison.tab.c"
    break;

  case 43: /* cremento_for: MAISMAIS  */
#line 285 "bison.y"
                        {
                (yyval.int_val) = 1;
              }
#line 1828 "bison.tab.c"
    break;

  case 44: /* cremento_for: MENOSMENOS  */
#line 288 "bison.y"
                          {
                (yyval.int_val) = 2;
              }
#line 1836 "bison.tab.c"
    break;

  case 45: /* cremento: ID MAISMAIS PEV  */
#line 293 "bison.y"
                          {
            printf("add %%r%d, %%r%d, 1\n",getendereco((yyvsp[-2].str_val)),getendereco((yyvsp[-2].str_val)));
         }
#line 1844 "bison.tab.c"
    break;

  case 46: /* cremento: ID MENOSMENOS PEV  */
#line 296 "bison.y"
                            {
            printf("sub %%r%d, %%r%d, 1\n",getendereco((yyvsp[-2].str_val)),getendereco((yyvsp[-2].str_val)));
         }
#line 1852 "bison.tab.c"
    break;

  case 47: /* $@3: %empty  */
#line 301 "bison.y"
                      {
            printf("label R%d\n",S);
            S++;
            push(p,S-1,S);
         }
#line 1862 "bison.tab.c"
    break;

  case 48: /* $@4: %empty  */
#line 306 "bison.y"
                  {
            printf("jf %%t%d, R%d\n",(yyvsp[0].int_val),S);   
            S++;   
         }
#line 1871 "bison.tab.c"
    break;

  case 49: /* $@5: %empty  */
#line 310 "bison.y"
                                                 {
            if((yyvsp[-3].int_val)==1)
            {
                printf("add %%r%d, %%r%d, 1\n",getendereco((yyvsp[-4].str_val)),getendereco((yyvsp[-4].str_val)));
            }else{
                printf("sub %%r%d, %%r%d, 1\n",getendereco((yyvsp[-4].str_val)),getendereco((yyvsp[-4].str_val)));
            }
            printf("jump R%d\n",p->R[p->topo].entrada);
         }
#line 1885 "bison.tab.c"
    break;

  case 50: /* laco: FOR LPAR atrib $@3 condicoes $@4 PEV ID cremento_for RPAR LCHAVES codigos $@5 RCHAVES  */
#line 318 "bison.y"
                   {
            printf("label R%d\n",p->R[p->topo].saida);
            pop(p);
         }
#line 1894 "bison.tab.c"
    break;

  case 51: /* $@6: %empty  */
#line 322 "bison.y"
                {
            printf("label R%d\n",S);
            S++;
            push(p,S-1,S);
         }
#line 1904 "bison.tab.c"
    break;

  case 52: /* $@7: %empty  */
#line 326 "bison.y"
                         {
            printf("jf %%t%d, R%d\n",(yyvsp[0].int_val),S);
            S++;
         }
#line 1913 "bison.tab.c"
    break;

  case 53: /* laco: WHILE $@6 LPAR condicoes $@7 RPAR LCHAVES codigos RCHAVES  */
#line 329 "bison.y"
                                        {
            printf("jump R%d\n",p->R[p->topo].entrada);
            printf("label R%d\n",p->R[p->topo].saida);
            pop(p);
         }
#line 1923 "bison.tab.c"
    break;

  case 54: /* print: PRINTF LPAR STRING RPAR PEV  */
#line 336 "bison.y"
                                    {
            printf("printf %s\n",(yyvsp[-2].str_val));
         }
#line 1931 "bison.tab.c"
    break;

  case 55: /* print: PRINTF LPAR expr RPAR PEV  */
#line 339 "bison.y"
                                    {
            printf("printv %%t%d\n",(yyvsp[-2].int_val));
         }
#line 1939 "bison.tab.c"
    break;

  case 56: /* read: SCANF LPAR ID RPAR PEV  */
#line 344 "bison.y"
                              {
        printf("read %%r%d\n", getendereco((yyvsp[-2].str_val)));
      }
#line 1947 "bison.tab.c"
    break;

  case 57: /* read: SCANF LPAR ID LCOLCHETES expr RCOLCHETES RPAR PEV  */
#line 347 "bison.y"
                                                        {
        printf("read %%t%d\n", T);
        printf("store %%t%d, %%t%d(%d)\n",T,(yyvsp[-3].int_val),getendereco((yyvsp[-5].str_val)));
        T++;
      }
#line 1957 "bison.tab.c"
    break;


#line 1961 "bison.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 354 "bison.y"


int main(int argc, char *argv[]) {
    p = (Pilha *)malloc(sizeof(Pilha));
    inicializaPilha(p);
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
 
    yyparse();
    fclose(yyin);
    return 0;
}

void yyerror(const char *s) { fprintf(stderr, "ERRO Sintatico: %s\n", s); }
