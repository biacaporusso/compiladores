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
#line 1 "sintatico.y"

    /* definitions */

    #include <stdio.h>
    #include <string.h>
    #include <stdarg.h>

    extern char* yytext;
    extern int yylex();

    void yyerror(char* s);
    FILE* input_file = NULL;

    extern int linha;
    extern int coluna;

    void print_line(FILE* input, int n){
        int i = 1;
        char c;
        fseek(input, 0, SEEK_SET);
        while(i < n){
            c = fgetc(input);
            if(c == EOF){
                break;
            }
            else if(c == '\n'){
                i++;
            }
        }
        c = fgetc(input);
        while(c != '\n' && c != EOF){
            printf("%c", c);
            c = fgetc(input);
        }
        printf("\n");
    }

#line 109 "sintatico.tab.c"

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

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_BREAK = 7,                      /* BREAK  */
  YYSYMBOL_SWITCH = 8,                     /* SWITCH  */
  YYSYMBOL_CASE = 9,                       /* CASE  */
  YYSYMBOL_DEFAULT = 10,                   /* DEFAULT  */
  YYSYMBOL_DO = 11,                        /* DO  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_TYPEDEF = 16,                   /* TYPEDEF  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_PLUS = 18,                      /* PLUS  */
  YYSYMBOL_MINUS = 19,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 20,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 21,                       /* DIV  */
  YYSYMBOL_REMAINDER = 22,                 /* REMAINDER  */
  YYSYMBOL_INC = 23,                       /* INC  */
  YYSYMBOL_DEC = 24,                       /* DEC  */
  YYSYMBOL_BITWISE_AND = 25,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 26,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_NOT = 27,               /* BITWISE_NOT  */
  YYSYMBOL_BITWISE_XOR = 28,               /* BITWISE_XOR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LOGICAL_AND = 30,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 31,                /* LOGICAL_OR  */
  YYSYMBOL_EQUAL = 32,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 33,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 34,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_THAN = 35,              /* GREATER_THAN  */
  YYSYMBOL_LESS_EQUAL = 36,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 37,             /* GREATER_EQUAL  */
  YYSYMBOL_R_SHIFT = 38,                   /* R_SHIFT  */
  YYSYMBOL_L_SHIFT = 39,                   /* L_SHIFT  */
  YYSYMBOL_ASSIGN = 40,                    /* ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 41,                /* ADD_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 42,              /* MINUS_ASSIGN  */
  YYSYMBOL_SEMICOLON = 43,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 44,                     /* COMMA  */
  YYSYMBOL_COLON = 45,                     /* COLON  */
  YYSYMBOL_L_PAREN = 46,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 47,                   /* R_PAREN  */
  YYSYMBOL_L_CURLY_BRACKET = 48,           /* L_CURLY_BRACKET  */
  YYSYMBOL_R_CURLY_BRACKET = 49,           /* R_CURLY_BRACKET  */
  YYSYMBOL_L_SQUARE_BRACKET = 50,          /* L_SQUARE_BRACKET  */
  YYSYMBOL_R_SQUARE_BRACKET = 51,          /* R_SQUARE_BRACKET  */
  YYSYMBOL_TERNARY_CONDITIONAL = 52,       /* TERNARY_CONDITIONAL  */
  YYSYMBOL_NUMBER_SIGN = 53,               /* NUMBER_SIGN  */
  YYSYMBOL_POINTER = 54,                   /* POINTER  */
  YYSYMBOL_PRINTF = 55,                    /* PRINTF  */
  YYSYMBOL_SCANF = 56,                     /* SCANF  */
  YYSYMBOL_DEFINE = 57,                    /* DEFINE  */
  YYSYMBOL_EXIT = 58,                      /* EXIT  */
  YYSYMBOL_NUM_HEXA = 59,                  /* NUM_HEXA  */
  YYSYMBOL_NUM_OCTAL = 60,                 /* NUM_OCTAL  */
  YYSYMBOL_NUM_INTEGER = 61,               /* NUM_INTEGER  */
  YYSYMBOL_IDENTIFIER = 62,                /* IDENTIFIER  */
  YYSYMBOL_CHARACTER = 63,                 /* CHARACTER  */
  YYSYMBOL_STRING = 64,                    /* STRING  */
  YYSYMBOL_UNTERMINATED_COMMENT = 65,      /* UNTERMINATED_COMMENT  */
  YYSYMBOL_IDENTIFIER_TOO_LONG = 66,       /* IDENTIFIER_TOO_LONG  */
  YYSYMBOL_END_OF_FILE = 67,               /* END_OF_FILE  */
  YYSYMBOL_OTHER = 68,                     /* OTHER  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_programa = 70,                  /* programa  */
  YYSYMBOL_program = 71,                   /* program  */
  YYSYMBOL_declaracao = 72,                /* declaracao  */
  YYSYMBOL_funcao = 73,                    /* funcao  */
  YYSYMBOL_declaracao_variaveis_func = 74, /* declaracao_variaveis_func  */
  YYSYMBOL_declaracao_variaveis = 75,      /* declaracao_variaveis  */
  YYSYMBOL_dec_var = 76,                   /* dec_var  */
  YYSYMBOL_dec_var_aux = 77,               /* dec_var_aux  */
  YYSYMBOL_declaracao_prototipos = 78,     /* declaracao_prototipos  */
  YYSYMBOL_parametros = 79,                /* parametros  */
  YYSYMBOL_param = 80,                     /* param  */
  YYSYMBOL_param_aux = 81,                 /* param_aux  */
  YYSYMBOL_array = 82,                     /* array  */
  YYSYMBOL_tipo = 83,                      /* tipo  */
  YYSYMBOL_bloco = 84,                     /* bloco  */
  YYSYMBOL_comandos = 85,                  /* comandos  */
  YYSYMBOL_lista_de_comandos = 86,         /* lista_de_comandos  */
  YYSYMBOL_printf_exp = 87,                /* printf_exp  */
  YYSYMBOL_else_exp = 88,                  /* else_exp  */
  YYSYMBOL_exp_opcional = 89,              /* exp_opcional  */
  YYSYMBOL_expressao = 90,                 /* expressao  */
  YYSYMBOL_atribuicao = 91,                /* atribuicao  */
  YYSYMBOL_atribuicao_aux = 92,            /* atribuicao_aux  */
  YYSYMBOL_expressao_condicional = 93,     /* expressao_condicional  */
  YYSYMBOL_expressao_or_logico = 94,       /* expressao_or_logico  */
  YYSYMBOL_expressao_and_logico = 95,      /* expressao_and_logico  */
  YYSYMBOL_expressao_or = 96,              /* expressao_or  */
  YYSYMBOL_expressao_xor = 97,             /* expressao_xor  */
  YYSYMBOL_expressao_and = 98,             /* expressao_and  */
  YYSYMBOL_expressao_igualdade = 99,       /* expressao_igualdade  */
  YYSYMBOL_exp_igualdade_aux = 100,        /* exp_igualdade_aux  */
  YYSYMBOL_expressao_relacional = 101,     /* expressao_relacional  */
  YYSYMBOL_exp_relacional_aux = 102,       /* exp_relacional_aux  */
  YYSYMBOL_expressao_shift = 103,          /* expressao_shift  */
  YYSYMBOL_exp_shift_aux = 104,            /* exp_shift_aux  */
  YYSYMBOL_expressao_add = 105,            /* expressao_add  */
  YYSYMBOL_exp_add_aux = 106,              /* exp_add_aux  */
  YYSYMBOL_expressao_mult = 107,           /* expressao_mult  */
  YYSYMBOL_exp_mult_aux = 108,             /* exp_mult_aux  */
  YYSYMBOL_expressao_cast = 109,           /* expressao_cast  */
  YYSYMBOL_expressao_unaria = 110,         /* expressao_unaria  */
  YYSYMBOL_exp_unaria_aux = 111,           /* exp_unaria_aux  */
  YYSYMBOL_expressao_posfixa = 112,        /* expressao_posfixa  */
  YYSYMBOL_exp_posfixa_aux = 113,          /* exp_posfixa_aux  */
  YYSYMBOL_expressao_primaria = 114,       /* expressao_primaria  */
  YYSYMBOL_numero = 115,                   /* numero  */
  YYSYMBOL_pointer = 116                   /* pointer  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   338

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  222

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   323


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   116,   116,   117,   121,   122,   126,   127,   128,   132,
     136,   137,   141,   145,   146,   150,   151,   155,   159,   160,
     164,   168,   169,   173,   174,   178,   179,   180,   184,   188,
     189,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   207,   208,   212,   213,   217,   218,   222,   223,
     227,   228,   232,   233,   234,   238,   239,   243,   244,   248,
     249,   253,   254,   258,   259,   263,   264,   268,   269,   273,
     274,   278,   279,   283,   284,   285,   286,   290,   291,   295,
     296,   300,   301,   305,   306,   310,   311,   315,   316,   317,
     321,   322,   326,   327,   328,   329,   333,   334,   335,   336,
     337,   341,   342,   343,   344,   345,   346,   350,   351,   355,
     356,   357,   358,   359,   363,   364,   365,   369,   370
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "CHAR",
  "RETURN", "BREAK", "SWITCH", "CASE", "DEFAULT", "DO", "WHILE", "FOR",
  "IF", "ELSE", "TYPEDEF", "STRUCT", "PLUS", "MINUS", "MULTIPLY", "DIV",
  "REMAINDER", "INC", "DEC", "BITWISE_AND", "BITWISE_OR", "BITWISE_NOT",
  "BITWISE_XOR", "NOT", "LOGICAL_AND", "LOGICAL_OR", "EQUAL", "NOT_EQUAL",
  "LESS_THAN", "GREATER_THAN", "LESS_EQUAL", "GREATER_EQUAL", "R_SHIFT",
  "L_SHIFT", "ASSIGN", "ADD_ASSIGN", "MINUS_ASSIGN", "SEMICOLON", "COMMA",
  "COLON", "L_PAREN", "R_PAREN", "L_CURLY_BRACKET", "R_CURLY_BRACKET",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "TERNARY_CONDITIONAL",
  "NUMBER_SIGN", "POINTER", "PRINTF", "SCANF", "DEFINE", "EXIT",
  "NUM_HEXA", "NUM_OCTAL", "NUM_INTEGER", "IDENTIFIER", "CHARACTER",
  "STRING", "UNTERMINATED_COMMENT", "IDENTIFIER_TOO_LONG", "END_OF_FILE",
  "OTHER", "$accept", "programa", "program", "declaracao", "funcao",
  "declaracao_variaveis_func", "declaracao_variaveis", "dec_var",
  "dec_var_aux", "declaracao_prototipos", "parametros", "param",
  "param_aux", "array", "tipo", "bloco", "comandos", "lista_de_comandos",
  "printf_exp", "else_exp", "exp_opcional", "expressao", "atribuicao",
  "atribuicao_aux", "expressao_condicional", "expressao_or_logico",
  "expressao_and_logico", "expressao_or", "expressao_xor", "expressao_and",
  "expressao_igualdade", "exp_igualdade_aux", "expressao_relacional",
  "exp_relacional_aux", "expressao_shift", "exp_shift_aux",
  "expressao_add", "exp_add_aux", "expressao_mult", "exp_mult_aux",
  "expressao_cast", "expressao_unaria", "exp_unaria_aux",
  "expressao_posfixa", "exp_posfixa_aux", "expressao_primaria", "numero",
  "pointer", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-151)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,  -151,  -151,  -151,   -53,    25,    11,  -151,  -151,  -151,
    -151,    -9,   -22,  -151,  -151,   -21,    -9,    17,    20,   227,
    -151,  -151,  -151,   -43,  -151,  -151,   274,   274,  -151,  -151,
    -151,   103,  -151,  -151,  -151,  -151,  -151,  -151,  -151,    40,
    -151,    44,    67,    69,    74,    73,    77,    23,    53,    41,
      76,    49,    34,   227,    -1,  -151,  -151,    26,   227,    -5,
      -3,   227,  -151,  -151,    -9,    57,   227,   227,   227,   227,
     227,   227,   227,  -151,  -151,   227,  -151,  -151,  -151,  -151,
     227,  -151,  -151,   227,  -151,  -151,   227,  -151,  -151,  -151,
     227,  -151,  -151,  -151,   227,  -151,  -151,  -151,  -151,   215,
     227,  -151,    58,    -9,    59,  -151,    88,   227,    -9,  -151,
      62,  -151,  -151,    66,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,    70,    64,  -151,    51,
      68,   168,    88,    -9,    72,  -151,    55,   227,   227,   227,
      78,  -151,    68,  -151,   227,    75,    83,    87,    89,  -151,
     168,    90,    92,    93,  -151,    85,   168,    81,  -151,  -151,
      68,  -151,  -151,    70,  -151,    96,    98,  -151,   130,   227,
     227,   227,    94,    80,    82,   227,  -151,  -151,  -151,  -151,
      88,  -151,  -151,    99,   100,   105,   106,  -151,   110,   111,
     112,  -151,   227,    75,   227,    75,   227,   113,   132,   115,
     114,  -151,   125,   154,  -151,   127,   109,  -151,   129,   227,
     160,  -151,   131,  -151,   136,    75,  -151,   133,    75,  -151,
    -151,  -151
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    27,    25,    26,     0,     0,     0,     4,     5,     7,
       8,   118,     0,     1,     3,     0,   118,     0,     0,     0,
       2,   117,    12,    24,    97,    98,     0,     0,    96,    99,
     100,     0,   115,   116,   114,   109,   111,   112,     6,    48,
      50,    55,    57,    59,    61,    63,    65,    67,    71,    77,
      81,    85,    90,     0,    92,   101,   110,     0,     0,     0,
      16,     0,    93,    94,   118,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70,     0,    73,    75,    74,    76,
       0,    80,    79,     0,    83,    84,     0,    87,    88,    89,
       0,    52,    53,    54,     0,    95,    90,   102,   103,     0,
       0,    19,     0,   118,     0,    17,    11,     0,   118,    14,
       0,   113,    49,     0,    58,    60,    62,    64,    66,    68,
      72,    78,    82,    86,    51,   105,   108,     0,    18,     0,
      24,     0,    11,   118,    16,    15,     0,     0,     0,     0,
       0,   104,    24,    23,    47,     0,     0,     0,     0,    40,
       0,     0,     0,     0,    41,     0,    30,     0,    10,    13,
      24,    91,    56,   108,   106,    22,     0,    46,     0,     0,
      47,     0,     0,     0,     0,     0,     9,    29,    39,   107,
       0,    20,    38,     0,     0,     0,     0,    28,    43,     0,
       0,    21,     0,     0,    47,     0,     0,     0,     0,     0,
       0,    33,     0,     0,    42,     0,     0,    37,     0,    47,
      45,    35,     0,    31,     0,     0,    32,     0,     0,    44,
      36,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,   178,  -151,  -151,  -151,    56,  -100,    86,    65,  -151,
    -151,     5,  -151,  -106,   -29,  -132,  -123,  -151,  -151,  -151,
    -150,   -19,   -73,  -151,    52,   121,   134,   126,   135,   128,
     123,  -151,   122,  -151,   118,  -151,   119,  -151,   117,  -151,
     -52,   -18,  -151,  -151,    45,  -151,  -151,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   131,     9,    17,   109,    10,
      59,   102,   181,    60,    11,   154,   155,   156,   197,   216,
     166,   167,    39,    94,    40,    41,    42,    43,    44,    45,
      46,    75,    47,    80,    48,    83,    49,    86,    50,    90,
      51,    52,    53,    54,   140,    55,    56,   136
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    95,    64,    57,    12,    18,   132,    58,    62,    63,
      21,    16,    65,   168,     1,     2,     3,     1,     2,     3,
     185,   124,    97,    98,   143,    13,   126,   172,   103,     1,
       2,     3,   132,   177,   134,    96,   165,   107,   105,   104,
      19,   108,    65,   106,   202,    99,    20,   112,   113,   100,
      96,    96,    96,    96,    96,    73,    74,    96,   110,   214,
      22,   201,    96,   203,     4,    96,   163,     4,    96,    87,
      88,    89,    96,   101,    91,    92,    93,   133,    14,    81,
      82,   127,    23,   219,    66,   161,   221,    76,    77,    78,
      79,     1,     2,     3,    84,    85,    67,   129,    68,    69,
      70,    71,    72,   133,   111,   128,     1,     2,     3,   137,
     130,   138,   157,   142,   139,   141,   108,   160,    58,    96,
      96,    24,    25,   150,   178,   164,    26,    27,    28,   169,
      29,   157,    30,   170,   176,   171,   173,   157,   174,   175,
     180,   182,   183,   187,   188,   192,   189,   193,   194,    31,
     184,   103,   186,   195,   196,   198,   190,   206,   207,   199,
     205,   208,    32,    33,    34,    35,    36,    37,   209,   210,
     211,   212,   213,   200,   144,   215,   220,   204,   217,   145,
     146,   147,   148,   218,    15,   191,    24,    25,   158,   114,
     162,    26,    27,    28,   135,    29,   116,    30,   119,   159,
     118,   121,   120,   115,     0,   122,   117,   123,   179,     0,
       0,   149,     0,     0,    31,     0,   150,     0,     0,     0,
       0,     0,     0,   151,   152,     0,   153,    32,    33,    34,
      35,    36,    37,    24,    25,     0,     0,     0,    26,    27,
      28,     0,    29,     0,    30,    24,    25,     0,     0,     0,
      26,    27,    28,     0,    29,     0,    30,     0,     0,     0,
       0,    31,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,    32,    33,    34,    35,
      36,    37,    24,    25,     0,     0,     0,    26,    27,    28,
       0,    29,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,    36,    37
};

static const yytype_int16 yycheck[] =
{
      19,    53,    31,    46,    57,    11,   106,    50,    26,    27,
      16,    20,    31,   145,     3,     4,     5,     3,     4,     5,
     170,    94,    23,    24,   130,     0,    99,   150,    57,     3,
       4,     5,   132,   156,   107,    53,   142,    40,    43,    58,
      62,    44,    61,    48,   194,    46,    67,    66,    67,    50,
      68,    69,    70,    71,    72,    32,    33,    75,    64,   209,
      43,   193,    80,   195,    53,    83,   139,    53,    86,    20,
      21,    22,    90,    47,    40,    41,    42,   106,    67,    38,
      39,   100,    62,   215,    44,   137,   218,    34,    35,    36,
      37,     3,     4,     5,    18,    19,    52,   103,    31,    30,
      26,    28,    25,   132,    47,    47,     3,     4,     5,    47,
      51,    45,   131,    62,    44,    51,    44,    62,    50,   137,
     138,    18,    19,    48,    43,    47,    23,    24,    25,    46,
      27,   150,    29,    46,    49,    46,    46,   156,    46,    46,
      44,    43,    12,    49,    64,    46,    64,    47,    43,    46,
     169,   180,   171,    47,    44,    44,   175,    25,    43,    47,
      47,    47,    59,    60,    61,    62,    63,    64,    43,    15,
      43,    62,    43,   192,     6,    15,    43,   196,    47,    11,
      12,    13,    14,    47,     6,   180,    18,    19,   132,    68,
     138,    23,    24,    25,   108,    27,    70,    29,    75,   134,
      72,    83,    80,    69,    -1,    86,    71,    90,   163,    -1,
      -1,    43,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    56,    -1,    58,    59,    60,    61,
      62,    63,    64,    18,    19,    -1,    -1,    -1,    23,    24,
      25,    -1,    27,    -1,    29,    18,    19,    -1,    -1,    -1,
      23,    24,    25,    -1,    27,    -1,    29,    -1,    -1,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    18,    19,    -1,    -1,    -1,    23,    24,    25,
      -1,    27,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    53,    70,    71,    72,    73,    75,
      78,    83,    57,     0,    67,    70,    20,    76,   116,    62,
      67,   116,    43,    62,    18,    19,    23,    24,    25,    27,
      29,    46,    59,    60,    61,    62,    63,    64,    90,    91,
      93,    94,    95,    96,    97,    98,    99,   101,   103,   105,
     107,   109,   110,   111,   112,   114,   115,    46,    50,    79,
      82,    46,   110,   110,    83,    90,    44,    52,    31,    30,
      26,    28,    25,    32,    33,   100,    34,    35,    36,    37,
     102,    38,    39,   104,    18,    19,   106,    20,    21,    22,
     108,    40,    41,    42,    92,   109,   110,    23,    24,    46,
      50,    47,    80,    83,    90,    43,    48,    40,    44,    77,
     116,    47,    90,    90,    94,    95,    96,    97,    98,    99,
     101,   103,   105,   107,    91,    47,    91,    90,    47,   116,
      51,    74,    75,    83,    91,    76,   116,    47,    45,    44,
     113,    51,    62,    82,     6,    11,    12,    13,    14,    43,
      48,    55,    56,    58,    84,    85,    86,    90,    74,    77,
      62,   109,    93,    91,    47,    82,    89,    90,    84,    46,
      46,    46,    85,    46,    46,    46,    49,    85,    43,   113,
      44,    81,    43,    12,    90,    89,    90,    49,    64,    64,
      90,    80,    46,    47,    43,    47,    44,    87,    44,    47,
      90,    84,    89,    84,    90,    47,    25,    43,    47,    43,
      15,    43,    62,    43,    89,    15,    88,    47,    47,    84,
      43,    84
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    72,    72,    72,    73,
      74,    74,    75,    76,    76,    77,    77,    78,    79,    79,
      80,    81,    81,    82,    82,    83,    83,    83,    84,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    92,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   108,
     109,   109,   110,   110,   110,   110,   111,   111,   111,   111,
     111,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   114,   114,   114,   115,   115,   115,   116,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     4,     1,     1,     8,
       2,     0,     3,     6,     4,     2,     0,     5,     3,     2,
       5,     2,     0,     4,     0,     1,     1,     1,     3,     2,
       1,     7,     7,     5,     9,     6,     8,     5,     3,     2,
       1,     1,     2,     0,     2,     0,     1,     0,     1,     3,
       1,     3,     1,     1,     1,     1,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     5,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     5,     3,     0,     1,
       1,     1,     1,     3,     1,     1,     1,     2,     0
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
  case 2: /* programa: program programa END_OF_FILE  */
#line 116 "sintatico.y"
                                 { printf("SUCESSFUL COMPILATION."); return 0; }
#line 1401 "sintatico.tab.c"
    break;

  case 3: /* programa: program END_OF_FILE  */
#line 117 "sintatico.y"
                          { printf("SUCESSFUL COMPILATION."); return 0; }
#line 1407 "sintatico.tab.c"
    break;

  case 4: /* program: declaracao  */
#line 121 "sintatico.y"
               {}
#line 1413 "sintatico.tab.c"
    break;

  case 5: /* program: funcao  */
#line 122 "sintatico.y"
             {}
#line 1419 "sintatico.tab.c"
    break;

  case 6: /* declaracao: NUMBER_SIGN DEFINE IDENTIFIER expressao  */
#line 126 "sintatico.y"
                                            {}
#line 1425 "sintatico.tab.c"
    break;

  case 7: /* declaracao: declaracao_variaveis  */
#line 127 "sintatico.y"
                           {}
#line 1431 "sintatico.tab.c"
    break;

  case 8: /* declaracao: declaracao_prototipos  */
#line 128 "sintatico.y"
                            {}
#line 1437 "sintatico.tab.c"
    break;

  case 9: /* funcao: tipo pointer IDENTIFIER parametros L_CURLY_BRACKET declaracao_variaveis_func comandos R_CURLY_BRACKET  */
#line 132 "sintatico.y"
                                                                                                          {}
#line 1443 "sintatico.tab.c"
    break;

  case 10: /* declaracao_variaveis_func: declaracao_variaveis declaracao_variaveis_func  */
#line 136 "sintatico.y"
                                                   {}
#line 1449 "sintatico.tab.c"
    break;

  case 11: /* declaracao_variaveis_func: %empty  */
#line 137 "sintatico.y"
      {}
#line 1455 "sintatico.tab.c"
    break;

  case 12: /* declaracao_variaveis: tipo dec_var SEMICOLON  */
#line 141 "sintatico.y"
                           {}
#line 1461 "sintatico.tab.c"
    break;

  case 13: /* dec_var: pointer IDENTIFIER array ASSIGN atribuicao dec_var_aux  */
#line 145 "sintatico.y"
                                                           {}
#line 1467 "sintatico.tab.c"
    break;

  case 14: /* dec_var: pointer IDENTIFIER array dec_var_aux  */
#line 146 "sintatico.y"
                                           {}
#line 1473 "sintatico.tab.c"
    break;

  case 15: /* dec_var_aux: COMMA dec_var  */
#line 150 "sintatico.y"
                  {}
#line 1479 "sintatico.tab.c"
    break;

  case 16: /* dec_var_aux: %empty  */
#line 151 "sintatico.y"
      {}
#line 1485 "sintatico.tab.c"
    break;

  case 17: /* declaracao_prototipos: tipo pointer IDENTIFIER parametros SEMICOLON  */
#line 155 "sintatico.y"
                                                 {}
#line 1491 "sintatico.tab.c"
    break;

  case 18: /* parametros: L_PAREN param R_PAREN  */
#line 159 "sintatico.y"
                          {}
#line 1497 "sintatico.tab.c"
    break;

  case 19: /* parametros: L_PAREN R_PAREN  */
#line 160 "sintatico.y"
                      {}
#line 1503 "sintatico.tab.c"
    break;

  case 20: /* param: tipo pointer IDENTIFIER array param_aux  */
#line 164 "sintatico.y"
                                            {}
#line 1509 "sintatico.tab.c"
    break;

  case 21: /* param_aux: COMMA param  */
#line 168 "sintatico.y"
                {}
#line 1515 "sintatico.tab.c"
    break;

  case 22: /* param_aux: %empty  */
#line 169 "sintatico.y"
      {}
#line 1521 "sintatico.tab.c"
    break;

  case 23: /* array: L_SQUARE_BRACKET expressao R_SQUARE_BRACKET array  */
#line 173 "sintatico.y"
                                                      {}
#line 1527 "sintatico.tab.c"
    break;

  case 24: /* array: %empty  */
#line 174 "sintatico.y"
      {}
#line 1533 "sintatico.tab.c"
    break;

  case 25: /* tipo: INT  */
#line 178 "sintatico.y"
        {}
#line 1539 "sintatico.tab.c"
    break;

  case 26: /* tipo: CHAR  */
#line 179 "sintatico.y"
           {}
#line 1545 "sintatico.tab.c"
    break;

  case 27: /* tipo: VOID  */
#line 180 "sintatico.y"
           {}
#line 1551 "sintatico.tab.c"
    break;

  case 28: /* bloco: L_CURLY_BRACKET comandos R_CURLY_BRACKET  */
#line 184 "sintatico.y"
                                             {}
#line 1557 "sintatico.tab.c"
    break;

  case 29: /* comandos: lista_de_comandos comandos  */
#line 188 "sintatico.y"
                               {}
#line 1563 "sintatico.tab.c"
    break;

  case 30: /* comandos: lista_de_comandos  */
#line 189 "sintatico.y"
                        {}
#line 1569 "sintatico.tab.c"
    break;

  case 31: /* lista_de_comandos: DO bloco WHILE L_PAREN expressao R_PAREN SEMICOLON  */
#line 193 "sintatico.y"
                                                       {}
#line 1575 "sintatico.tab.c"
    break;

  case 32: /* lista_de_comandos: IF L_PAREN expressao R_PAREN bloco ELSE else_exp  */
#line 194 "sintatico.y"
                                                       {}
#line 1581 "sintatico.tab.c"
    break;

  case 33: /* lista_de_comandos: WHILE L_PAREN expressao R_PAREN bloco  */
#line 195 "sintatico.y"
                                            {}
#line 1587 "sintatico.tab.c"
    break;

  case 34: /* lista_de_comandos: FOR L_PAREN exp_opcional SEMICOLON exp_opcional SEMICOLON exp_opcional R_PAREN bloco  */
#line 196 "sintatico.y"
                                                                                           {}
#line 1593 "sintatico.tab.c"
    break;

  case 35: /* lista_de_comandos: PRINTF L_PAREN STRING printf_exp R_PAREN SEMICOLON  */
#line 197 "sintatico.y"
                                                         {}
#line 1599 "sintatico.tab.c"
    break;

  case 36: /* lista_de_comandos: SCANF L_PAREN STRING COMMA BITWISE_AND IDENTIFIER R_PAREN SEMICOLON  */
#line 198 "sintatico.y"
                                                                          {}
#line 1605 "sintatico.tab.c"
    break;

  case 37: /* lista_de_comandos: EXIT L_PAREN expressao R_PAREN SEMICOLON  */
#line 199 "sintatico.y"
                                               {}
#line 1611 "sintatico.tab.c"
    break;

  case 42: /* printf_exp: COMMA expressao  */
#line 207 "sintatico.y"
                    {}
#line 1617 "sintatico.tab.c"
    break;

  case 43: /* printf_exp: %empty  */
#line 208 "sintatico.y"
      {}
#line 1623 "sintatico.tab.c"
    break;

  case 44: /* else_exp: ELSE bloco  */
#line 212 "sintatico.y"
               {}
#line 1629 "sintatico.tab.c"
    break;

  case 45: /* else_exp: %empty  */
#line 213 "sintatico.y"
      {}
#line 1635 "sintatico.tab.c"
    break;

  case 46: /* exp_opcional: expressao  */
#line 217 "sintatico.y"
              {}
#line 1641 "sintatico.tab.c"
    break;

  case 47: /* exp_opcional: %empty  */
#line 218 "sintatico.y"
      {}
#line 1647 "sintatico.tab.c"
    break;

  case 48: /* expressao: atribuicao  */
#line 222 "sintatico.y"
               {}
#line 1653 "sintatico.tab.c"
    break;

  case 49: /* expressao: atribuicao COMMA expressao  */
#line 223 "sintatico.y"
                                 {}
#line 1659 "sintatico.tab.c"
    break;

  case 50: /* atribuicao: expressao_condicional  */
#line 227 "sintatico.y"
                          {}
#line 1665 "sintatico.tab.c"
    break;

  case 51: /* atribuicao: expressao_unaria atribuicao_aux atribuicao  */
#line 228 "sintatico.y"
                                                 {}
#line 1671 "sintatico.tab.c"
    break;

  case 52: /* atribuicao_aux: ASSIGN  */
#line 232 "sintatico.y"
           {}
#line 1677 "sintatico.tab.c"
    break;

  case 53: /* atribuicao_aux: ADD_ASSIGN  */
#line 233 "sintatico.y"
                 {}
#line 1683 "sintatico.tab.c"
    break;

  case 54: /* atribuicao_aux: MINUS_ASSIGN  */
#line 234 "sintatico.y"
                   {}
#line 1689 "sintatico.tab.c"
    break;

  case 55: /* expressao_condicional: expressao_or_logico  */
#line 238 "sintatico.y"
                        {}
#line 1695 "sintatico.tab.c"
    break;

  case 56: /* expressao_condicional: expressao_or_logico TERNARY_CONDITIONAL expressao COLON expressao_condicional  */
#line 239 "sintatico.y"
                                                                                    {}
#line 1701 "sintatico.tab.c"
    break;

  case 57: /* expressao_or_logico: expressao_and_logico  */
#line 243 "sintatico.y"
                         {}
#line 1707 "sintatico.tab.c"
    break;

  case 58: /* expressao_or_logico: expressao_and_logico LOGICAL_OR expressao_or_logico  */
#line 244 "sintatico.y"
                                                          {}
#line 1713 "sintatico.tab.c"
    break;

  case 59: /* expressao_and_logico: expressao_or  */
#line 248 "sintatico.y"
                 {}
#line 1719 "sintatico.tab.c"
    break;

  case 60: /* expressao_and_logico: expressao_or LOGICAL_AND expressao_and_logico  */
#line 249 "sintatico.y"
                                                    {}
#line 1725 "sintatico.tab.c"
    break;

  case 61: /* expressao_or: expressao_xor  */
#line 253 "sintatico.y"
                  {}
#line 1731 "sintatico.tab.c"
    break;

  case 62: /* expressao_or: expressao_xor BITWISE_OR expressao_or  */
#line 254 "sintatico.y"
                                            {}
#line 1737 "sintatico.tab.c"
    break;

  case 63: /* expressao_xor: expressao_and  */
#line 258 "sintatico.y"
                  {}
#line 1743 "sintatico.tab.c"
    break;

  case 64: /* expressao_xor: expressao_and BITWISE_XOR expressao_xor  */
#line 259 "sintatico.y"
                                              {}
#line 1749 "sintatico.tab.c"
    break;

  case 65: /* expressao_and: expressao_igualdade  */
#line 263 "sintatico.y"
                        {}
#line 1755 "sintatico.tab.c"
    break;

  case 66: /* expressao_and: expressao_igualdade BITWISE_AND expressao_and  */
#line 264 "sintatico.y"
                                                    {}
#line 1761 "sintatico.tab.c"
    break;

  case 67: /* expressao_igualdade: expressao_relacional  */
#line 268 "sintatico.y"
                         {}
#line 1767 "sintatico.tab.c"
    break;

  case 68: /* expressao_igualdade: expressao_relacional exp_igualdade_aux expressao_igualdade  */
#line 269 "sintatico.y"
                                                                 {}
#line 1773 "sintatico.tab.c"
    break;

  case 69: /* exp_igualdade_aux: EQUAL  */
#line 273 "sintatico.y"
          {}
#line 1779 "sintatico.tab.c"
    break;

  case 70: /* exp_igualdade_aux: NOT_EQUAL  */
#line 274 "sintatico.y"
                {}
#line 1785 "sintatico.tab.c"
    break;

  case 71: /* expressao_relacional: expressao_shift  */
#line 278 "sintatico.y"
                    {}
#line 1791 "sintatico.tab.c"
    break;

  case 72: /* expressao_relacional: expressao_shift exp_relacional_aux expressao_relacional  */
#line 279 "sintatico.y"
                                                              {}
#line 1797 "sintatico.tab.c"
    break;

  case 73: /* exp_relacional_aux: LESS_THAN  */
#line 283 "sintatico.y"
              {}
#line 1803 "sintatico.tab.c"
    break;

  case 74: /* exp_relacional_aux: LESS_EQUAL  */
#line 284 "sintatico.y"
                 {}
#line 1809 "sintatico.tab.c"
    break;

  case 75: /* exp_relacional_aux: GREATER_THAN  */
#line 285 "sintatico.y"
                   {}
#line 1815 "sintatico.tab.c"
    break;

  case 76: /* exp_relacional_aux: GREATER_EQUAL  */
#line 286 "sintatico.y"
                    {}
#line 1821 "sintatico.tab.c"
    break;

  case 77: /* expressao_shift: expressao_add  */
#line 290 "sintatico.y"
                  {}
#line 1827 "sintatico.tab.c"
    break;

  case 78: /* expressao_shift: expressao_add exp_shift_aux expressao_shift  */
#line 291 "sintatico.y"
                                                  {}
#line 1833 "sintatico.tab.c"
    break;

  case 79: /* exp_shift_aux: L_SHIFT  */
#line 295 "sintatico.y"
            {}
#line 1839 "sintatico.tab.c"
    break;

  case 80: /* exp_shift_aux: R_SHIFT  */
#line 296 "sintatico.y"
              {}
#line 1845 "sintatico.tab.c"
    break;

  case 81: /* expressao_add: expressao_mult  */
#line 300 "sintatico.y"
                   {}
#line 1851 "sintatico.tab.c"
    break;

  case 82: /* expressao_add: expressao_mult exp_add_aux expressao_add  */
#line 301 "sintatico.y"
                                               {}
#line 1857 "sintatico.tab.c"
    break;

  case 83: /* exp_add_aux: PLUS  */
#line 305 "sintatico.y"
         {}
#line 1863 "sintatico.tab.c"
    break;

  case 84: /* exp_add_aux: MINUS  */
#line 306 "sintatico.y"
            {}
#line 1869 "sintatico.tab.c"
    break;

  case 85: /* expressao_mult: expressao_cast  */
#line 310 "sintatico.y"
                   {}
#line 1875 "sintatico.tab.c"
    break;

  case 86: /* expressao_mult: expressao_cast exp_mult_aux expressao_mult  */
#line 311 "sintatico.y"
                                                 {}
#line 1881 "sintatico.tab.c"
    break;

  case 87: /* exp_mult_aux: MULTIPLY  */
#line 315 "sintatico.y"
             {}
#line 1887 "sintatico.tab.c"
    break;

  case 88: /* exp_mult_aux: DIV  */
#line 316 "sintatico.y"
          {}
#line 1893 "sintatico.tab.c"
    break;

  case 89: /* exp_mult_aux: REMAINDER  */
#line 317 "sintatico.y"
                {}
#line 1899 "sintatico.tab.c"
    break;

  case 90: /* expressao_cast: expressao_unaria  */
#line 321 "sintatico.y"
                     {}
#line 1905 "sintatico.tab.c"
    break;

  case 91: /* expressao_cast: L_PAREN tipo pointer R_PAREN expressao_cast  */
#line 322 "sintatico.y"
                                                  {}
#line 1911 "sintatico.tab.c"
    break;

  case 92: /* expressao_unaria: expressao_posfixa  */
#line 326 "sintatico.y"
                      {}
#line 1917 "sintatico.tab.c"
    break;

  case 93: /* expressao_unaria: INC expressao_unaria  */
#line 327 "sintatico.y"
                           {}
#line 1923 "sintatico.tab.c"
    break;

  case 94: /* expressao_unaria: DEC expressao_unaria  */
#line 328 "sintatico.y"
                           {}
#line 1929 "sintatico.tab.c"
    break;

  case 95: /* expressao_unaria: exp_unaria_aux expressao_cast  */
#line 329 "sintatico.y"
                                    {}
#line 1935 "sintatico.tab.c"
    break;

  case 96: /* exp_unaria_aux: BITWISE_AND  */
#line 333 "sintatico.y"
                {}
#line 1941 "sintatico.tab.c"
    break;

  case 97: /* exp_unaria_aux: PLUS  */
#line 334 "sintatico.y"
           {}
#line 1947 "sintatico.tab.c"
    break;

  case 98: /* exp_unaria_aux: MINUS  */
#line 335 "sintatico.y"
            {}
#line 1953 "sintatico.tab.c"
    break;

  case 99: /* exp_unaria_aux: BITWISE_NOT  */
#line 336 "sintatico.y"
                  {}
#line 1959 "sintatico.tab.c"
    break;

  case 100: /* exp_unaria_aux: NOT  */
#line 337 "sintatico.y"
          {}
#line 1965 "sintatico.tab.c"
    break;

  case 101: /* expressao_posfixa: expressao_primaria  */
#line 341 "sintatico.y"
                       {}
#line 1971 "sintatico.tab.c"
    break;

  case 102: /* expressao_posfixa: expressao_posfixa INC  */
#line 342 "sintatico.y"
                            {}
#line 1977 "sintatico.tab.c"
    break;

  case 103: /* expressao_posfixa: expressao_posfixa DEC  */
#line 343 "sintatico.y"
                            {}
#line 1983 "sintatico.tab.c"
    break;

  case 104: /* expressao_posfixa: expressao_posfixa L_SQUARE_BRACKET expressao R_SQUARE_BRACKET  */
#line 344 "sintatico.y"
                                                                    {}
#line 1989 "sintatico.tab.c"
    break;

  case 105: /* expressao_posfixa: expressao_posfixa L_PAREN R_PAREN  */
#line 345 "sintatico.y"
                                        {}
#line 1995 "sintatico.tab.c"
    break;

  case 106: /* expressao_posfixa: expressao_posfixa L_PAREN atribuicao exp_posfixa_aux R_PAREN  */
#line 346 "sintatico.y"
                                                                   {}
#line 2001 "sintatico.tab.c"
    break;

  case 107: /* exp_posfixa_aux: COMMA atribuicao exp_posfixa_aux  */
#line 350 "sintatico.y"
                                     {}
#line 2007 "sintatico.tab.c"
    break;

  case 108: /* exp_posfixa_aux: %empty  */
#line 351 "sintatico.y"
      {}
#line 2013 "sintatico.tab.c"
    break;

  case 109: /* expressao_primaria: IDENTIFIER  */
#line 355 "sintatico.y"
               {}
#line 2019 "sintatico.tab.c"
    break;

  case 110: /* expressao_primaria: numero  */
#line 356 "sintatico.y"
             {}
#line 2025 "sintatico.tab.c"
    break;

  case 111: /* expressao_primaria: CHARACTER  */
#line 357 "sintatico.y"
                {}
#line 2031 "sintatico.tab.c"
    break;

  case 112: /* expressao_primaria: STRING  */
#line 358 "sintatico.y"
             {}
#line 2037 "sintatico.tab.c"
    break;

  case 113: /* expressao_primaria: L_PAREN expressao R_PAREN  */
#line 359 "sintatico.y"
                                {}
#line 2043 "sintatico.tab.c"
    break;

  case 114: /* numero: NUM_INTEGER  */
#line 363 "sintatico.y"
                {}
#line 2049 "sintatico.tab.c"
    break;

  case 115: /* numero: NUM_HEXA  */
#line 364 "sintatico.y"
               {}
#line 2055 "sintatico.tab.c"
    break;

  case 116: /* numero: NUM_OCTAL  */
#line 365 "sintatico.y"
                {}
#line 2061 "sintatico.tab.c"
    break;

  case 117: /* pointer: MULTIPLY pointer  */
#line 369 "sintatico.y"
                     {}
#line 2067 "sintatico.tab.c"
    break;

  case 118: /* pointer: %empty  */
#line 370 "sintatico.y"
      {}
#line 2073 "sintatico.tab.c"
    break;


#line 2077 "sintatico.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 374 "sintatico.y"


void yyerror(char* s){
	int i = 1;
	switch(yychar){
		case IDENTIFIER_TOO_LONG:
			printf("error:lexical:%d:%d: identifier too long", linha, coluna);
			break;

		case UNTERMINATED_COMMENT:
			printf("error:lexical:%d:%d: unterminated comment", linha, coluna);
			break;
		case OTHER:
			coluna -= strlen(yytext);
			printf("error:lexical:%d:%d: %s", linha, coluna, yytext);
			break;
		case END_OF_FILE:
			printf("error:syntax:%d:%d: expected declaration or statement at end of input\n", linha, coluna);
			print_line(input_file, linha);
			for(i; i < coluna; i++){ 
                printf(" "); 
            }
			printf("^");
			break;
		default:
			coluna -= strlen(yytext);
			printf("error:syntax:%d:%d: %s\n", linha, coluna, yytext);
			print_line(input_file, linha);
			for(i; i < coluna; i++){ 
                printf(" "); 
            }
			printf("^");
			break;
	}
}

int main(int argc, char** argv) {
    input_file = stdin;
    yyparse();

    return 0;
}
