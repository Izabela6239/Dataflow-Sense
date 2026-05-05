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
#line 1 "sql.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

int yylex();
void yyerror(const char *s);

char* textf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(NULL, 0, fmt, args);
    va_end(args);

    char* res = malloc(len + 1);
    if (!res) {
        fprintf(stderr, "Eroare de memorie.\n");
        exit(1);
    }

    va_start(args, fmt);
    vsnprintf(res, len + 1, fmt, args);
    va_end(args);
    return res;
}

char* append_text(char* left, const char* separator, char* right) {
    if (left == NULL || strlen(left) == 0) {
        return right ? strdup(right) : strdup("");
    }
    if (right == NULL || strlen(right) == 0) {
        return strdup(left);
    }
    return textf("%s%s%s", left, separator, right);
}

#line 109 "sql.tab.c"

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

#include "sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SELECT = 3,                     /* SELECT  */
  YYSYMBOL_DISTINCT = 4,                   /* DISTINCT  */
  YYSYMBOL_FROM = 5,                       /* FROM  */
  YYSYMBOL_WHERE = 6,                      /* WHERE  */
  YYSYMBOL_AND = 7,                        /* AND  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_NOT = 9,                        /* NOT  */
  YYSYMBOL_JOIN = 10,                      /* JOIN  */
  YYSYMBOL_INNER = 11,                     /* INNER  */
  YYSYMBOL_LEFT = 12,                      /* LEFT  */
  YYSYMBOL_RIGHT = 13,                     /* RIGHT  */
  YYSYMBOL_FULL = 14,                      /* FULL  */
  YYSYMBOL_OUTER = 15,                     /* OUTER  */
  YYSYMBOL_CROSS = 16,                     /* CROSS  */
  YYSYMBOL_ON = 17,                        /* ON  */
  YYSYMBOL_ORDER = 18,                     /* ORDER  */
  YYSYMBOL_BY = 19,                        /* BY  */
  YYSYMBOL_ASC = 20,                       /* ASC  */
  YYSYMBOL_DESC = 21,                      /* DESC  */
  YYSYMBOL_HAVING = 22,                    /* HAVING  */
  YYSYMBOL_LIKE = 23,                      /* LIKE  */
  YYSYMBOL_IN = 24,                        /* IN  */
  YYSYMBOL_BETWEEN = 25,                   /* BETWEEN  */
  YYSYMBOL_IS = 26,                        /* IS  */
  YYSYMBOL_NULL_T = 27,                    /* NULL_T  */
  YYSYMBOL_LIMIT = 28,                     /* LIMIT  */
  YYSYMBOL_OFFSET = 29,                    /* OFFSET  */
  YYSYMBOL_GROUP = 30,                     /* GROUP  */
  YYSYMBOL_AS = 31,                        /* AS  */
  YYSYMBOL_SUM = 32,                       /* SUM  */
  YYSYMBOL_AVG = 33,                       /* AVG  */
  YYSYMBOL_COUNT = 34,                     /* COUNT  */
  YYSYMBOL_MIN = 35,                       /* MIN  */
  YYSYMBOL_MAX = 36,                       /* MAX  */
  YYSYMBOL_INSERT = 37,                    /* INSERT  */
  YYSYMBOL_INTO = 38,                      /* INTO  */
  YYSYMBOL_VALUES = 39,                    /* VALUES  */
  YYSYMBOL_UPDATE = 40,                    /* UPDATE  */
  YYSYMBOL_SET = 41,                       /* SET  */
  YYSYMBOL_DELETE = 42,                    /* DELETE  */
  YYSYMBOL_CREATE = 43,                    /* CREATE  */
  YYSYMBOL_TABLE = 44,                     /* TABLE  */
  YYSYMBOL_DROP = 45,                      /* DROP  */
  YYSYMBOL_ALTER = 46,                     /* ALTER  */
  YYSYMBOL_ADD = 47,                       /* ADD  */
  YYSYMBOL_COLUMN = 48,                    /* COLUMN  */
  YYSYMBOL_PRIMARY = 49,                   /* PRIMARY  */
  YYSYMBOL_KEY = 50,                       /* KEY  */
  YYSYMBOL_FOREIGN = 51,                   /* FOREIGN  */
  YYSYMBOL_REFERENCES = 52,                /* REFERENCES  */
  YYSYMBOL_DEFAULT = 53,                   /* DEFAULT  */
  YYSYMBOL_CHECK = 54,                     /* CHECK  */
  YYSYMBOL_UNIQUE = 55,                    /* UNIQUE  */
  YYSYMBOL_EQ = 56,                        /* EQ  */
  YYSYMBOL_GT = 57,                        /* GT  */
  YYSYMBOL_LT = 58,                        /* LT  */
  YYSYMBOL_GE = 59,                        /* GE  */
  YYSYMBOL_LE = 60,                        /* LE  */
  YYSYMBOL_NE = 61,                        /* NE  */
  YYSYMBOL_WORD = 62,                      /* WORD  */
  YYSYMBOL_NUMBER = 63,                    /* NUMBER  */
  YYSYMBOL_STRING = 64,                    /* STRING  */
  YYSYMBOL_65_ = 65,                       /* '+'  */
  YYSYMBOL_66_ = 66,                       /* '-'  */
  YYSYMBOL_67_ = 67,                       /* '*'  */
  YYSYMBOL_68_ = 68,                       /* '/'  */
  YYSYMBOL_69_n_ = 69,                     /* '\n'  */
  YYSYMBOL_70_ = 70,                       /* ';'  */
  YYSYMBOL_71_ = 71,                       /* ','  */
  YYSYMBOL_72_ = 72,                       /* '('  */
  YYSYMBOL_73_ = 73,                       /* ')'  */
  YYSYMBOL_74_ = 74,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 75,                  /* $accept  */
  YYSYMBOL_input = 76,                     /* input  */
  YYSYMBOL_linie = 77,                     /* linie  */
  YYSYMBOL_statement = 78,                 /* statement  */
  YYSYMBOL_select_stmt = 79,               /* select_stmt  */
  YYSYMBOL_select_prefix = 80,             /* select_prefix  */
  YYSYMBOL_select_list = 81,               /* select_list  */
  YYSYMBOL_select_item = 82,               /* select_item  */
  YYSYMBOL_opt_alias = 83,                 /* opt_alias  */
  YYSYMBOL_insert_stmt = 84,               /* insert_stmt  */
  YYSYMBOL_update_stmt = 85,               /* update_stmt  */
  YYSYMBOL_delete_stmt = 86,               /* delete_stmt  */
  YYSYMBOL_create_stmt = 87,               /* create_stmt  */
  YYSYMBOL_drop_stmt = 88,                 /* drop_stmt  */
  YYSYMBOL_alter_stmt = 89,                /* alter_stmt  */
  YYSYMBOL_opt_column = 90,                /* opt_column  */
  YYSYMBOL_table_ref = 91,                 /* table_ref  */
  YYSYMBOL_join_list = 92,                 /* join_list  */
  YYSYMBOL_join_clause = 93,               /* join_clause  */
  YYSYMBOL_join_type = 94,                 /* join_type  */
  YYSYMBOL_opt_outer = 95,                 /* opt_outer  */
  YYSYMBOL_optional_where = 96,            /* optional_where  */
  YYSYMBOL_group_by_clause = 97,           /* group_by_clause  */
  YYSYMBOL_having_clause = 98,             /* having_clause  */
  YYSYMBOL_order_clause = 99,              /* order_clause  */
  YYSYMBOL_order_list = 100,               /* order_list  */
  YYSYMBOL_order_item = 101,               /* order_item  */
  YYSYMBOL_direction = 102,                /* direction  */
  YYSYMBOL_limit_clause = 103,             /* limit_clause  */
  YYSYMBOL_condition = 104,                /* condition  */
  YYSYMBOL_optional_not = 105,             /* optional_not  */
  YYSYMBOL_comparator = 106,               /* comparator  */
  YYSYMBOL_assignment_list = 107,          /* assignment_list  */
  YYSYMBOL_assignment = 108,               /* assignment  */
  YYSYMBOL_value_tuple_list = 109,         /* value_tuple_list  */
  YYSYMBOL_value_tuple = 110,              /* value_tuple  */
  YYSYMBOL_literal_list = 111,             /* literal_list  */
  YYSYMBOL_literal = 112,                  /* literal  */
  YYSYMBOL_expression_list = 113,          /* expression_list  */
  YYSYMBOL_opt_expression_list = 114,      /* opt_expression_list  */
  YYSYMBOL_expression = 115,               /* expression  */
  YYSYMBOL_function_call = 116,            /* function_call  */
  YYSYMBOL_aggregate_function = 117,       /* aggregate_function  */
  YYSYMBOL_column_list = 118,              /* column_list  */
  YYSYMBOL_column_def_list = 119,          /* column_def_list  */
  YYSYMBOL_column_def = 120,               /* column_def  */
  YYSYMBOL_data_type = 121,                /* data_type  */
  YYSYMBOL_column_attrs = 122,             /* column_attrs  */
  YYSYMBOL_column_attr = 123,              /* column_attr  */
  YYSYMBOL_identifier = 124                /* identifier  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      69,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      72,    73,    67,    65,    71,    66,    74,    68,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    70,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    68,    72,    73,    74,    75,    79,    80,
      81,    82,    83,    84,    85,    89,    96,    97,   101,   102,
     106,   107,   111,   112,   113,   117,   120,   126,   132,   138,
     144,   150,   153,   159,   160,   164,   168,   169,   173,   176,
     182,   183,   184,   185,   186,   190,   191,   195,   196,   200,
     201,   205,   206,   210,   211,   215,   216,   220,   224,   225,
     226,   230,   231,   232,   236,   237,   238,   239,   242,   243,
     244,   245,   246,   250,   251,   255,   256,   257,   258,   259,
     260,   264,   265,   269,   273,   274,   278,   282,   283,   287,
     288,   289,   293,   294,   298,   299,   303,   304,   305,   306,
     307,   308,   309,   310,   314,   317,   320,   323,   329,   330,
     331,   332,   336,   337,   341,   342,   346,   350,   351,   352,
     356,   357,   361,   362,   365,   368,   369,   370,   371,   375,
     376
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
  "\"end of file\"", "error", "\"invalid token\"", "SELECT", "DISTINCT",
  "FROM", "WHERE", "AND", "OR", "NOT", "JOIN", "INNER", "LEFT", "RIGHT",
  "FULL", "OUTER", "CROSS", "ON", "ORDER", "BY", "ASC", "DESC", "HAVING",
  "LIKE", "IN", "BETWEEN", "IS", "NULL_T", "LIMIT", "OFFSET", "GROUP",
  "AS", "SUM", "AVG", "COUNT", "MIN", "MAX", "INSERT", "INTO", "VALUES",
  "UPDATE", "SET", "DELETE", "CREATE", "TABLE", "DROP", "ALTER", "ADD",
  "COLUMN", "PRIMARY", "KEY", "FOREIGN", "REFERENCES", "DEFAULT", "CHECK",
  "UNIQUE", "EQ", "GT", "LT", "GE", "LE", "NE", "WORD", "NUMBER", "STRING",
  "'+'", "'-'", "'*'", "'/'", "'\\n'", "';'", "','", "'('", "')'", "'.'",
  "$accept", "input", "linie", "statement", "select_stmt", "select_prefix",
  "select_list", "select_item", "opt_alias", "insert_stmt", "update_stmt",
  "delete_stmt", "create_stmt", "drop_stmt", "alter_stmt", "opt_column",
  "table_ref", "join_list", "join_clause", "join_type", "opt_outer",
  "optional_where", "group_by_clause", "having_clause", "order_clause",
  "order_list", "order_item", "direction", "limit_clause", "condition",
  "optional_not", "comparator", "assignment_list", "assignment",
  "value_tuple_list", "value_tuple", "literal_list", "literal",
  "expression_list", "opt_expression_list", "expression", "function_call",
  "aggregate_function", "column_list", "column_def_list", "column_def",
  "data_type", "column_attrs", "column_attr", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -146,    35,  -146,   -57,    29,     8,    20,    82,    54,    58,
      62,  -146,  -146,   -50,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,    99,    20,    42,    89,    20,    20,    20,
      20,  -146,    68,  -146,  -146,  -146,    88,  -146,  -146,   -17,
    -146,  -146,  -146,   212,    -2,  -146,  -146,    74,  -146,    95,
    -146,   -13,    61,    20,   138,    96,  -146,    23,  -146,   190,
     212,   -36,    20,    99,   108,  -146,   212,   212,   212,   212,
    -146,   212,   100,    20,  -146,     0,  -146,   129,    57,  -146,
      20,   144,   144,   113,   193,   122,   124,   110,  -146,  -146,
     -22,  -146,  -146,    27,    27,  -146,  -146,   204,   -20,  -146,
      12,  -146,    20,  -146,   212,    57,    57,   120,   175,    30,
    -146,   133,  -146,    20,    20,  -146,  -146,   212,  -146,   198,
    -146,  -146,    51,  -146,    20,   163,  -146,   110,  -146,     3,
     123,    57,    57,   -20,   131,   212,   196,  -146,  -146,  -146,
    -146,  -146,  -146,   212,    20,  -146,   134,  -146,  -146,  -146,
     110,  -146,   203,   203,   203,   209,  -146,   211,   183,   -20,
    -146,  -146,   100,  -146,  -146,   220,  -146,   -20,    47,  -146,
     201,   110,  -146,   166,   102,  -146,  -146,  -146,  -146,    20,
      20,   218,   216,  -146,   178,  -146,    72,   212,  -146,    79,
     223,   205,   206,    20,   -20,   179,  -146,  -146,  -146,   246,
      20,    57,   247,   100,  -146,   110,   210,  -146,  -146,  -146,
     215,   192,  -146,    57,    57,   197,   120,   259,   251,  -146,
     207,    20,    20,     6,   120,   212,   219,  -146,  -146,   213,
     208,  -146,   217,  -146,    -5,   254,    20,  -146,   212,  -146,
    -146,  -146,   224,   221,  -146,  -146,  -146
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    16,     0,     0,     0,     0,     0,
       0,     4,     3,     0,     8,     9,    10,    11,    12,    13,
      14,     7,    17,     0,     0,   129,     0,     0,     0,     0,
       0,     5,     0,    91,   108,   109,     0,   110,   111,   129,
      90,    89,    20,     0,     0,    18,    97,    22,    98,     0,
      96,     0,     0,     0,    47,     0,    30,     0,     6,     0,
      94,     0,     0,     0,     0,    24,     0,     0,     0,     0,
      21,     0,     0,     0,   130,    47,    81,     0,     0,    28,
       0,    33,    33,     0,     0,    95,     0,    92,   103,    36,
      22,    19,    23,    99,   100,   101,   102,     0,     0,    25,
       0,   112,     0,    27,     0,     0,     0,    48,     0,     0,
     114,     0,    34,     0,     0,   106,   105,     0,   107,    47,
      35,   104,     0,    87,     0,     0,    82,    83,    69,     0,
       0,     0,     0,     0,     0,     0,    73,    75,    76,    77,
      78,    79,    80,     0,     0,    29,   117,   120,    32,    31,
      93,    41,    45,    45,    45,     0,    37,     0,    49,     0,
      86,   113,     0,    72,    70,    71,    65,     0,     0,    74,
       0,    64,   115,     0,   116,    46,    42,    43,    44,     0,
       0,     0,    51,    88,    26,    84,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,   126,   121,    39,     0,
       0,     0,    53,     0,    66,    67,     0,   118,   125,   122,
       0,     0,   127,     0,     0,    50,    52,     0,    61,    85,
       0,     0,     0,     0,    38,     0,     0,    15,   119,     0,
       0,   128,    54,    55,    58,    62,     0,   124,     0,    59,
      60,    57,     0,     0,    56,    63,   123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,  -146,  -146,   226,   200,  -146,
    -146,  -146,  -146,  -146,  -146,   214,   -21,  -146,  -146,  -146,
      11,   -67,  -146,  -146,  -146,  -146,    48,  -146,  -146,  -104,
    -146,  -146,  -146,   189,  -146,  -145,   125,   -94,  -146,  -146,
     -18,  -146,  -146,    93,  -146,   -80,  -146,  -146,  -146,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    12,    13,    14,    23,    44,    45,    70,    15,
      16,    17,    18,    19,    20,   113,    89,   119,   156,   157,
     176,    79,   182,   202,   218,   232,   233,   241,   227,   107,
     170,   143,    75,    76,   184,    99,   122,    46,    85,    86,
     108,    48,    49,   100,   109,   110,   147,   174,   197,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,   128,   129,    62,   123,    47,    78,    33,   103,    64,
     131,   132,    21,   131,   132,   239,   240,   185,    51,    31,
      32,    54,    55,    56,    57,    61,    72,   164,   165,    66,
      67,    68,    69,    22,   149,     2,     3,    88,     4,   166,
      65,    84,    87,    40,    41,    47,    24,    77,    93,    94,
      95,    96,   158,    97,   187,    60,    90,    52,   219,    73,
      66,    67,    68,    69,   172,   183,   105,   101,    81,    63,
      82,   102,     5,   123,   111,     6,   163,     7,     8,   231,
       9,    10,    25,   124,    33,   125,   127,    27,   130,    34,
      35,    36,    37,    38,    68,    69,    77,   216,    28,   150,
     212,   144,    29,   145,    11,    64,    30,   148,   111,   223,
     224,   190,    66,    67,    68,    69,    52,   168,   161,    39,
      40,    41,   159,    74,   160,   171,    33,   131,   132,   106,
      53,    34,    35,    36,    37,    38,    65,    58,   111,    66,
      67,    68,    69,   159,    78,   204,   133,   134,   135,   136,
     206,   191,   207,   192,   193,   194,   195,   196,   198,   199,
      59,    39,    40,    41,   177,   178,    42,    71,    80,   205,
      92,    43,    98,    90,    90,    66,    67,    68,    69,   137,
     138,   139,   140,   141,   142,   104,   115,   211,    66,    67,
      68,    69,   112,   117,   101,   146,    88,   118,   133,   134,
     135,   136,   162,   167,    78,   169,   173,   234,   -40,   151,
     152,   153,   154,   181,   155,   229,   230,    33,   175,   179,
     234,   180,    34,    35,    36,    37,    38,   131,   188,   189,
     243,   137,   138,   139,   140,   141,   142,   200,   201,    33,
      66,    67,    68,    69,    34,    35,    36,    37,    38,   203,
     208,   213,    39,    40,    41,   209,   210,    83,    66,    67,
      68,    69,    43,   214,   222,   217,   116,   221,   124,    66,
      67,    68,    69,   220,    39,    40,    41,   121,   225,   226,
     228,   237,   235,   242,    43,   236,   244,   245,   238,    91,
     120,   126,   186,   215,   246,     0,   114
};

static const yytype_int16 yycheck[] =
{
       6,   105,   106,     5,    98,    23,     6,    27,    75,    31,
       7,     8,    69,     7,     8,    20,    21,   162,    24,    69,
      70,    27,    28,    29,    30,    43,    39,   131,   132,    65,
      66,    67,    68,     4,   114,     0,     1,    73,     3,   133,
      62,    59,    60,    63,    64,    63,    38,    53,    66,    67,
      68,    69,   119,    71,     7,    72,    62,    74,   203,    72,
      65,    66,    67,    68,   144,   159,     9,    73,    45,    71,
      47,    71,    37,   167,    80,    40,    73,    42,    43,    73,
      45,    46,    62,    71,    27,    73,   104,     5,   106,    32,
      33,    34,    35,    36,    67,    68,   102,   201,    44,   117,
     194,    71,    44,    73,    69,    31,    44,   113,   114,   213,
     214,     9,    65,    66,    67,    68,    74,   135,   124,    62,
      63,    64,    71,    62,    73,   143,    27,     7,     8,    72,
      41,    32,    33,    34,    35,    36,    62,    69,   144,    65,
      66,    67,    68,    71,     6,    73,    23,    24,    25,    26,
      71,    49,    73,    51,    52,    53,    54,    55,   179,   180,
      72,    62,    63,    64,   153,   154,    67,    72,    72,   187,
      62,    72,    72,   179,   180,    65,    66,    67,    68,    56,
      57,    58,    59,    60,    61,    56,    73,   193,    65,    66,
      67,    68,    48,    71,   200,    62,    73,    73,    23,    24,
      25,    26,    39,    72,     6,     9,    72,   225,    10,    11,
      12,    13,    14,    30,    16,   221,   222,    27,    15,    10,
     238,    10,    32,    33,    34,    35,    36,     7,    27,    63,
     236,    56,    57,    58,    59,    60,    61,    19,    22,    27,
      65,    66,    67,    68,    32,    33,    34,    35,    36,    71,
      27,    72,    62,    63,    64,    50,    50,    67,    65,    66,
      67,    68,    72,    17,    72,    18,    73,    52,    71,    65,
      66,    67,    68,    63,    62,    63,    64,    73,    19,    28,
      73,    73,    63,    29,    72,    72,   238,    63,    71,    63,
      90,   102,   167,   200,    73,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    76,     0,     1,     3,    37,    40,    42,    43,    45,
      46,    69,    77,    78,    79,    84,    85,    86,    87,    88,
      89,    69,     4,    80,    38,    62,   124,     5,    44,    44,
      44,    69,    70,    27,    32,    33,    34,    35,    36,    62,
      63,    64,    67,    72,    81,    82,   112,   115,   116,   117,
     124,   124,    74,    41,   124,   124,   124,   124,    69,    72,
      72,   115,     5,    71,    31,    62,    65,    66,    67,    68,
      83,    72,    39,    72,    62,   107,   108,   124,     6,    96,
      72,    45,    47,    67,   115,   113,   114,   115,    73,    91,
     124,    82,    62,   115,   115,   115,   115,   115,    72,   110,
     118,   124,    71,    96,    56,     9,    72,   104,   115,   119,
     120,   124,    48,    90,    90,    73,    73,    71,    73,    92,
      83,    73,   111,   112,    71,    73,   108,   115,   104,   104,
     115,     7,     8,    23,    24,    25,    26,    56,    57,    58,
      59,    60,    61,   106,    71,    73,    62,   121,   124,   120,
     115,    11,    12,    13,    14,    16,    93,    94,    96,    71,
      73,   124,    39,    73,   104,   104,   112,    72,   115,     9,
     105,   115,   120,    72,   122,    15,    95,    95,    95,    10,
      10,    30,    97,   112,   109,   110,   111,     7,    27,    63,
       9,    49,    51,    52,    53,    54,    55,   123,    91,    91,
      19,    22,    98,    71,    73,   115,    71,    73,    27,    50,
      50,   124,   112,    72,    17,   118,   104,    18,    99,   110,
      63,    52,    72,   104,   104,    19,    28,   103,    73,   124,
     124,    73,   100,   101,   115,    63,    72,    73,    71,    20,
      21,   102,    29,   124,   101,    63,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    75,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    83,    84,    84,    85,    86,    87,
      88,    89,    89,    90,    90,    91,    92,    92,    93,    93,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   102,   102,
     102,   103,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   106,   106,   106,
     106,   107,   107,   108,   109,   109,   110,   111,   111,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   116,   116,   117,   117,
     117,   117,   118,   118,   119,   119,   120,   121,   121,   121,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   124,
     124
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,    11,     0,     1,     1,     3,
       1,     2,     0,     2,     1,     5,     8,     5,     4,     6,
       3,     6,     6,     0,     1,     2,     0,     2,     5,     3,
       0,     1,     2,     2,     2,     0,     1,     0,     2,     0,
       3,     0,     2,     0,     3,     1,     3,     2,     0,     1,
       1,     0,     2,     4,     3,     3,     5,     5,     4,     2,
       3,     3,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     1,     4,     6,
       0,     2,     2,     7,     5,     2,     1,     2,     4,     1,
       3
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
  case 5: /* linie: statement '\n'  */
#line 73 "sql.y"
                           { printf("\nTRADUCERE ANALITICA: %s\n\n", (yyvsp[-1].str)); }
#line 1407 "sql.tab.c"
    break;

  case 6: /* linie: statement ';' '\n'  */
#line 74 "sql.y"
                           { printf("\nTRADUCERE ANALITICA: %s\n\n", (yyvsp[-2].str)); }
#line 1413 "sql.tab.c"
    break;

  case 7: /* linie: error '\n'  */
#line 75 "sql.y"
                           { yyerrok; printf("Eroare de structura SQL detectata.\n"); }
#line 1419 "sql.tab.c"
    break;

  case 15: /* select_stmt: SELECT select_prefix select_list FROM table_ref join_list optional_where group_by_clause having_clause order_clause limit_clause  */
#line 89 "sql.y"
                                                                                                                                       {
          (yyval.str) = textf("Selecteaza %s%s din %s%s%s%s%s%s%s",
                     (yyvsp[-9].str), (yyvsp[-8].str), (yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
      }
#line 1428 "sql.tab.c"
    break;

  case 16: /* select_prefix: %empty  */
#line 96 "sql.y"
                { (yyval.str) = strdup(""); }
#line 1434 "sql.tab.c"
    break;

  case 17: /* select_prefix: DISTINCT  */
#line 97 "sql.y"
                { (yyval.str) = strdup("valorile distincte pentru "); }
#line 1440 "sql.tab.c"
    break;

  case 18: /* select_list: select_item  */
#line 101 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1446 "sql.tab.c"
    break;

  case 19: /* select_list: select_list ',' select_item  */
#line 102 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), ", ", (yyvsp[0].str)); }
#line 1452 "sql.tab.c"
    break;

  case 20: /* select_item: '*'  */
#line 106 "sql.y"
                                          { (yyval.str) = strdup("toate coloanele"); }
#line 1458 "sql.tab.c"
    break;

  case 21: /* select_item: expression opt_alias  */
#line 107 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-1].str), " ", (yyvsp[0].str)); }
#line 1464 "sql.tab.c"
    break;

  case 22: /* opt_alias: %empty  */
#line 111 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1470 "sql.tab.c"
    break;

  case 23: /* opt_alias: AS WORD  */
#line 112 "sql.y"
                                          { (yyval.str) = textf("cu aliasul %s", (yyvsp[0].str)); }
#line 1476 "sql.tab.c"
    break;

  case 24: /* opt_alias: WORD  */
#line 113 "sql.y"
                                          { (yyval.str) = textf("cu aliasul %s", (yyvsp[0].str)); }
#line 1482 "sql.tab.c"
    break;

  case 25: /* insert_stmt: INSERT INTO identifier VALUES value_tuple  */
#line 117 "sql.y"
                                                {
          (yyval.str) = textf("Insereaza in tabelul %s valorile %s", (yyvsp[-2].str), (yyvsp[0].str));
      }
#line 1490 "sql.tab.c"
    break;

  case 26: /* insert_stmt: INSERT INTO identifier '(' column_list ')' VALUES value_tuple_list  */
#line 120 "sql.y"
                                                                         {
          (yyval.str) = textf("Insereaza in tabelul %s, in coloanele %s, valorile %s", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[0].str));
      }
#line 1498 "sql.tab.c"
    break;

  case 27: /* update_stmt: UPDATE identifier SET assignment_list optional_where  */
#line 126 "sql.y"
                                                           {
          (yyval.str) = textf("Actualizeaza tabelul %s setand %s%s", (yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[0].str));
      }
#line 1506 "sql.tab.c"
    break;

  case 28: /* delete_stmt: DELETE FROM identifier optional_where  */
#line 132 "sql.y"
                                            {
          (yyval.str) = textf("Sterge randuri din tabelul %s%s", (yyvsp[-1].str), (yyvsp[0].str));
      }
#line 1514 "sql.tab.c"
    break;

  case 29: /* create_stmt: CREATE TABLE identifier '(' column_def_list ')'  */
#line 138 "sql.y"
                                                      {
          (yyval.str) = textf("Creeaza tabelul %s cu definitiile: %s", (yyvsp[-3].str), (yyvsp[-1].str));
      }
#line 1522 "sql.tab.c"
    break;

  case 30: /* drop_stmt: DROP TABLE identifier  */
#line 144 "sql.y"
                            {
          (yyval.str) = textf("Sterge tabelul %s", (yyvsp[0].str));
      }
#line 1530 "sql.tab.c"
    break;

  case 31: /* alter_stmt: ALTER TABLE identifier ADD opt_column column_def  */
#line 150 "sql.y"
                                                       {
          (yyval.str) = textf("Modifica tabelul %s adaugand coloana %s", (yyvsp[-3].str), (yyvsp[0].str));
      }
#line 1538 "sql.tab.c"
    break;

  case 32: /* alter_stmt: ALTER TABLE identifier DROP opt_column identifier  */
#line 153 "sql.y"
                                                        {
          (yyval.str) = textf("Modifica tabelul %s stergand coloana %s", (yyvsp[-3].str), (yyvsp[0].str));
      }
#line 1546 "sql.tab.c"
    break;

  case 33: /* opt_column: %empty  */
#line 159 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1552 "sql.tab.c"
    break;

  case 34: /* opt_column: COLUMN  */
#line 160 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1558 "sql.tab.c"
    break;

  case 35: /* table_ref: identifier opt_alias  */
#line 164 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-1].str), " ", (yyvsp[0].str)); }
#line 1564 "sql.tab.c"
    break;

  case 36: /* join_list: %empty  */
#line 168 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1570 "sql.tab.c"
    break;

  case 37: /* join_list: join_list join_clause  */
#line 169 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-1].str), "", (yyvsp[0].str)); }
#line 1576 "sql.tab.c"
    break;

  case 38: /* join_clause: join_type JOIN table_ref ON condition  */
#line 173 "sql.y"
                                            {
          (yyval.str) = textf(", combinat prin %s cu %s pe baza conditiei %s", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str));
      }
#line 1584 "sql.tab.c"
    break;

  case 39: /* join_clause: CROSS JOIN table_ref  */
#line 176 "sql.y"
                           {
          (yyval.str) = textf(", combinat cartezian cu %s", (yyvsp[0].str));
      }
#line 1592 "sql.tab.c"
    break;

  case 40: /* join_type: %empty  */
#line 182 "sql.y"
                                          { (yyval.str) = strdup("JOIN"); }
#line 1598 "sql.tab.c"
    break;

  case 41: /* join_type: INNER  */
#line 183 "sql.y"
                                          { (yyval.str) = strdup("INNER JOIN"); }
#line 1604 "sql.tab.c"
    break;

  case 42: /* join_type: LEFT opt_outer  */
#line 184 "sql.y"
                                          { (yyval.str) = strdup("LEFT JOIN"); }
#line 1610 "sql.tab.c"
    break;

  case 43: /* join_type: RIGHT opt_outer  */
#line 185 "sql.y"
                                          { (yyval.str) = strdup("RIGHT JOIN"); }
#line 1616 "sql.tab.c"
    break;

  case 44: /* join_type: FULL opt_outer  */
#line 186 "sql.y"
                                          { (yyval.str) = strdup("FULL JOIN"); }
#line 1622 "sql.tab.c"
    break;

  case 45: /* opt_outer: %empty  */
#line 190 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1628 "sql.tab.c"
    break;

  case 46: /* opt_outer: OUTER  */
#line 191 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1634 "sql.tab.c"
    break;

  case 47: /* optional_where: %empty  */
#line 195 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1640 "sql.tab.c"
    break;

  case 48: /* optional_where: WHERE condition  */
#line 196 "sql.y"
                                          { (yyval.str) = textf(" unde %s", (yyvsp[0].str)); }
#line 1646 "sql.tab.c"
    break;

  case 49: /* group_by_clause: %empty  */
#line 200 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1652 "sql.tab.c"
    break;

  case 50: /* group_by_clause: GROUP BY column_list  */
#line 201 "sql.y"
                                          { (yyval.str) = textf(", grupat dupa %s", (yyvsp[0].str)); }
#line 1658 "sql.tab.c"
    break;

  case 51: /* having_clause: %empty  */
#line 205 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1664 "sql.tab.c"
    break;

  case 52: /* having_clause: HAVING condition  */
#line 206 "sql.y"
                                          { (yyval.str) = textf(", pastrand grupurile unde %s", (yyvsp[0].str)); }
#line 1670 "sql.tab.c"
    break;

  case 53: /* order_clause: %empty  */
#line 210 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1676 "sql.tab.c"
    break;

  case 54: /* order_clause: ORDER BY order_list  */
#line 211 "sql.y"
                                          { (yyval.str) = textf(", sortat dupa %s", (yyvsp[0].str)); }
#line 1682 "sql.tab.c"
    break;

  case 55: /* order_list: order_item  */
#line 215 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1688 "sql.tab.c"
    break;

  case 56: /* order_list: order_list ',' order_item  */
#line 216 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), ", ", (yyvsp[0].str)); }
#line 1694 "sql.tab.c"
    break;

  case 57: /* order_item: expression direction  */
#line 220 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-1].str), " ", (yyvsp[0].str)); }
#line 1700 "sql.tab.c"
    break;

  case 58: /* direction: %empty  */
#line 224 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1706 "sql.tab.c"
    break;

  case 59: /* direction: ASC  */
#line 225 "sql.y"
                                          { (yyval.str) = strdup("crescator"); }
#line 1712 "sql.tab.c"
    break;

  case 60: /* direction: DESC  */
#line 226 "sql.y"
                                          { (yyval.str) = strdup("descrescator"); }
#line 1718 "sql.tab.c"
    break;

  case 61: /* limit_clause: %empty  */
#line 230 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1724 "sql.tab.c"
    break;

  case 62: /* limit_clause: LIMIT NUMBER  */
#line 231 "sql.y"
                                          { (yyval.str) = textf(", limitat la %s randuri", (yyvsp[0].str)); }
#line 1730 "sql.tab.c"
    break;

  case 63: /* limit_clause: LIMIT NUMBER OFFSET NUMBER  */
#line 232 "sql.y"
                                          { (yyval.str) = textf(", limitat la %s randuri cu offset %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1736 "sql.tab.c"
    break;

  case 64: /* condition: expression comparator expression  */
#line 236 "sql.y"
                                          { (yyval.str) = textf("%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1742 "sql.tab.c"
    break;

  case 65: /* condition: expression LIKE literal  */
#line 237 "sql.y"
                                          { (yyval.str) = textf("%s seamana cu %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1748 "sql.tab.c"
    break;

  case 66: /* condition: expression IN '(' literal_list ')'  */
#line 238 "sql.y"
                                          { (yyval.str) = textf("%s este in lista (%s)", (yyvsp[-4].str), (yyvsp[-1].str)); }
#line 1754 "sql.tab.c"
    break;

  case 67: /* condition: expression BETWEEN expression AND expression  */
#line 239 "sql.y"
                                                   {
          (yyval.str) = textf("%s este intre %s si %s", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[0].str));
      }
#line 1762 "sql.tab.c"
    break;

  case 68: /* condition: expression IS optional_not NULL_T  */
#line 242 "sql.y"
                                          { (yyval.str) = textf("%s este %sNULL", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1768 "sql.tab.c"
    break;

  case 69: /* condition: NOT condition  */
#line 243 "sql.y"
                                          { (yyval.str) = textf("NU (%s)", (yyvsp[0].str)); }
#line 1774 "sql.tab.c"
    break;

  case 70: /* condition: condition AND condition  */
#line 244 "sql.y"
                                          { (yyval.str) = textf("%s SI %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1780 "sql.tab.c"
    break;

  case 71: /* condition: condition OR condition  */
#line 245 "sql.y"
                                          { (yyval.str) = textf("%s SAU %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1786 "sql.tab.c"
    break;

  case 72: /* condition: '(' condition ')'  */
#line 246 "sql.y"
                                          { (yyval.str) = textf("(%s)", (yyvsp[-1].str)); }
#line 1792 "sql.tab.c"
    break;

  case 73: /* optional_not: %empty  */
#line 250 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1798 "sql.tab.c"
    break;

  case 74: /* optional_not: NOT  */
#line 251 "sql.y"
                                          { (yyval.str) = strdup("NOT "); }
#line 1804 "sql.tab.c"
    break;

  case 75: /* comparator: EQ  */
#line 255 "sql.y"
                                          { (yyval.str) = strdup("egal cu"); }
#line 1810 "sql.tab.c"
    break;

  case 76: /* comparator: GT  */
#line 256 "sql.y"
                                          { (yyval.str) = strdup("mai mare decat"); }
#line 1816 "sql.tab.c"
    break;

  case 77: /* comparator: LT  */
#line 257 "sql.y"
                                          { (yyval.str) = strdup("mai mic decat"); }
#line 1822 "sql.tab.c"
    break;

  case 78: /* comparator: GE  */
#line 258 "sql.y"
                                          { (yyval.str) = strdup("mai mare sau egal cu"); }
#line 1828 "sql.tab.c"
    break;

  case 79: /* comparator: LE  */
#line 259 "sql.y"
                                          { (yyval.str) = strdup("mai mic sau egal cu"); }
#line 1834 "sql.tab.c"
    break;

  case 80: /* comparator: NE  */
#line 260 "sql.y"
                                          { (yyval.str) = strdup("diferit de"); }
#line 1840 "sql.tab.c"
    break;

  case 81: /* assignment_list: assignment  */
#line 264 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1846 "sql.tab.c"
    break;

  case 82: /* assignment_list: assignment_list ',' assignment  */
#line 265 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), ", ", (yyvsp[0].str)); }
#line 1852 "sql.tab.c"
    break;

  case 83: /* assignment: identifier EQ expression  */
#line 269 "sql.y"
                                          { (yyval.str) = textf("%s la %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1858 "sql.tab.c"
    break;

  case 84: /* value_tuple_list: value_tuple  */
#line 273 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1864 "sql.tab.c"
    break;

  case 85: /* value_tuple_list: value_tuple_list ',' value_tuple  */
#line 274 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), "; ", (yyvsp[0].str)); }
#line 1870 "sql.tab.c"
    break;

  case 86: /* value_tuple: '(' literal_list ')'  */
#line 278 "sql.y"
                                          { (yyval.str) = textf("(%s)", (yyvsp[-1].str)); }
#line 1876 "sql.tab.c"
    break;

  case 87: /* literal_list: literal  */
#line 282 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1882 "sql.tab.c"
    break;

  case 88: /* literal_list: literal_list ',' literal  */
#line 283 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), ", ", (yyvsp[0].str)); }
#line 1888 "sql.tab.c"
    break;

  case 89: /* literal: STRING  */
#line 287 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1894 "sql.tab.c"
    break;

  case 90: /* literal: NUMBER  */
#line 288 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1900 "sql.tab.c"
    break;

  case 91: /* literal: NULL_T  */
#line 289 "sql.y"
                                          { (yyval.str) = strdup("NULL"); }
#line 1906 "sql.tab.c"
    break;

  case 92: /* expression_list: expression  */
#line 293 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1912 "sql.tab.c"
    break;

  case 93: /* expression_list: expression_list ',' expression  */
#line 294 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), ", ", (yyvsp[0].str)); }
#line 1918 "sql.tab.c"
    break;

  case 94: /* opt_expression_list: %empty  */
#line 298 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 1924 "sql.tab.c"
    break;

  case 95: /* opt_expression_list: expression_list  */
#line 299 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1930 "sql.tab.c"
    break;

  case 96: /* expression: identifier  */
#line 303 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1936 "sql.tab.c"
    break;

  case 97: /* expression: literal  */
#line 304 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1942 "sql.tab.c"
    break;

  case 98: /* expression: function_call  */
#line 305 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 1948 "sql.tab.c"
    break;

  case 99: /* expression: expression '+' expression  */
#line 306 "sql.y"
                                          { (yyval.str) = textf("%s plus %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1954 "sql.tab.c"
    break;

  case 100: /* expression: expression '-' expression  */
#line 307 "sql.y"
                                          { (yyval.str) = textf("%s minus %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1960 "sql.tab.c"
    break;

  case 101: /* expression: expression '*' expression  */
#line 308 "sql.y"
                                          { (yyval.str) = textf("%s inmultit cu %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1966 "sql.tab.c"
    break;

  case 102: /* expression: expression '/' expression  */
#line 309 "sql.y"
                                          { (yyval.str) = textf("%s impartit la %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1972 "sql.tab.c"
    break;

  case 103: /* expression: '(' expression ')'  */
#line 310 "sql.y"
                                          { (yyval.str) = textf("(%s)", (yyvsp[-1].str)); }
#line 1978 "sql.tab.c"
    break;

  case 104: /* function_call: aggregate_function '(' expression ')'  */
#line 314 "sql.y"
                                            {
          (yyval.str) = textf("%s pentru %s", (yyvsp[-3].str), (yyvsp[-1].str));
      }
#line 1986 "sql.tab.c"
    break;

  case 105: /* function_call: COUNT '(' expression ')'  */
#line 317 "sql.y"
                               {
          (yyval.str) = textf("numarul de valori pentru %s", (yyvsp[-1].str));
      }
#line 1994 "sql.tab.c"
    break;

  case 106: /* function_call: COUNT '(' '*' ')'  */
#line 320 "sql.y"
                        {
          (yyval.str) = strdup("numarul total de inregistrari");
      }
#line 2002 "sql.tab.c"
    break;

  case 107: /* function_call: WORD '(' opt_expression_list ')'  */
#line 323 "sql.y"
                                       {
          (yyval.str) = textf("functia %s aplicata pe %s", (yyvsp[-3].str), strlen((yyvsp[-1].str)) ? (yyvsp[-1].str) : "fara argumente");
      }
#line 2010 "sql.tab.c"
    break;

  case 108: /* aggregate_function: SUM  */
#line 329 "sql.y"
                                          { (yyval.str) = strdup("suma"); }
#line 2016 "sql.tab.c"
    break;

  case 109: /* aggregate_function: AVG  */
#line 330 "sql.y"
                                          { (yyval.str) = strdup("media"); }
#line 2022 "sql.tab.c"
    break;

  case 110: /* aggregate_function: MIN  */
#line 331 "sql.y"
                                          { (yyval.str) = strdup("valoarea minima"); }
#line 2028 "sql.tab.c"
    break;

  case 111: /* aggregate_function: MAX  */
#line 332 "sql.y"
                                          { (yyval.str) = strdup("valoarea maxima"); }
#line 2034 "sql.tab.c"
    break;

  case 112: /* column_list: identifier  */
#line 336 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 2040 "sql.tab.c"
    break;

  case 113: /* column_list: column_list ',' identifier  */
#line 337 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), ", ", (yyvsp[0].str)); }
#line 2046 "sql.tab.c"
    break;

  case 114: /* column_def_list: column_def  */
#line 341 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 2052 "sql.tab.c"
    break;

  case 115: /* column_def_list: column_def_list ',' column_def  */
#line 342 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-2].str), "; ", (yyvsp[0].str)); }
#line 2058 "sql.tab.c"
    break;

  case 116: /* column_def: identifier data_type column_attrs  */
#line 346 "sql.y"
                                          { (yyval.str) = textf("%s de tip %s%s%s", (yyvsp[-2].str), (yyvsp[-1].str), strlen((yyvsp[0].str)) ? " " : "", (yyvsp[0].str)); }
#line 2064 "sql.tab.c"
    break;

  case 117: /* data_type: WORD  */
#line 350 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 2070 "sql.tab.c"
    break;

  case 118: /* data_type: WORD '(' NUMBER ')'  */
#line 351 "sql.y"
                                          { (yyval.str) = textf("%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2076 "sql.tab.c"
    break;

  case 119: /* data_type: WORD '(' NUMBER ',' NUMBER ')'  */
#line 352 "sql.y"
                                          { (yyval.str) = textf("%s(%s,%s)", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2082 "sql.tab.c"
    break;

  case 120: /* column_attrs: %empty  */
#line 356 "sql.y"
                                          { (yyval.str) = strdup(""); }
#line 2088 "sql.tab.c"
    break;

  case 121: /* column_attrs: column_attrs column_attr  */
#line 357 "sql.y"
                                          { (yyval.str) = append_text((yyvsp[-1].str), " ", (yyvsp[0].str)); }
#line 2094 "sql.tab.c"
    break;

  case 122: /* column_attr: PRIMARY KEY  */
#line 361 "sql.y"
                                          { (yyval.str) = strdup("cheie primara"); }
#line 2100 "sql.tab.c"
    break;

  case 123: /* column_attr: FOREIGN KEY REFERENCES identifier '(' identifier ')'  */
#line 362 "sql.y"
                                                           {
          (yyval.str) = textf("cheie straina catre %s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));
      }
#line 2108 "sql.tab.c"
    break;

  case 124: /* column_attr: REFERENCES identifier '(' identifier ')'  */
#line 365 "sql.y"
                                               {
          (yyval.str) = textf("referinta catre %s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));
      }
#line 2116 "sql.tab.c"
    break;

  case 125: /* column_attr: NOT NULL_T  */
#line 368 "sql.y"
                                          { (yyval.str) = strdup("obligatorie"); }
#line 2122 "sql.tab.c"
    break;

  case 126: /* column_attr: UNIQUE  */
#line 369 "sql.y"
                                          { (yyval.str) = strdup("unica"); }
#line 2128 "sql.tab.c"
    break;

  case 127: /* column_attr: DEFAULT literal  */
#line 370 "sql.y"
                                          { (yyval.str) = textf("cu valoare implicita %s", (yyvsp[0].str)); }
#line 2134 "sql.tab.c"
    break;

  case 128: /* column_attr: CHECK '(' condition ')'  */
#line 371 "sql.y"
                                          { (yyval.str) = textf("cu verificarea %s", (yyvsp[-1].str)); }
#line 2140 "sql.tab.c"
    break;

  case 129: /* identifier: WORD  */
#line 375 "sql.y"
                                          { (yyval.str) = strdup((yyvsp[0].str)); }
#line 2146 "sql.tab.c"
    break;

  case 130: /* identifier: WORD '.' WORD  */
#line 376 "sql.y"
                                          { (yyval.str) = textf("%s.%s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2152 "sql.tab.c"
    break;


#line 2156 "sql.tab.c"

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

#line 379 "sql.y"


void yyerror(const char *s) {
    fprintf(stderr, "Eroare de sintaxa SQL: %s\n", s);
}

int main() {
    printf("DataFlow Sense (V5.0 Extended SQL) - Introduceti SQL:\n");
    yyparse();
    return 0;
}
