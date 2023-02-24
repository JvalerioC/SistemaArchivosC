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
#line 1 "parser.y"

#include <iostream>
#include <cstdio>
#include <string>
#include "lexer.h"
#include "./struct_and_class/mkdisk.h"
#include "./struct_and_class/rmdisk.h"
#include "./struct_and_class/fdisk.h"
#include "./struct_and_class/mount.h"
#include "./struct_and_class/unmount.h"
#include "./struct_and_class/mkfs.h"
#include "./struct_and_class/execute.h"
#include "./struct_and_class/loss.h"

#include "./struct_and_class/rep.h"

extern char *yytext;

int yylex(void);
void yyerror(const char *);
//variables para el manejo de parametros
void limpiarVariables();
std::string size, fit, unit, path, tipo, borrar, name, add, nId, id, fs, ruta, user, pass, grp, ugo, r, cont, nFile, p, destino;


#line 97 "parser.cpp"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_MKDISK = 3,                   /* T_MKDISK  */
  YYSYMBOL_T_RMDISK = 4,                   /* T_RMDISK  */
  YYSYMBOL_T_FDISK = 5,                    /* T_FDISK  */
  YYSYMBOL_T_MOUNT = 6,                    /* T_MOUNT  */
  YYSYMBOL_T_UNMOUNT = 7,                  /* T_UNMOUNT  */
  YYSYMBOL_T_MKFS = 8,                     /* T_MKFS  */
  YYSYMBOL_T_LOGIN = 9,                    /* T_LOGIN  */
  YYSYMBOL_T_LOGOUT = 10,                  /* T_LOGOUT  */
  YYSYMBOL_T_MKGRP = 11,                   /* T_MKGRP  */
  YYSYMBOL_T_RMGRP = 12,                   /* T_RMGRP  */
  YYSYMBOL_T_MKUSR = 13,                   /* T_MKUSR  */
  YYSYMBOL_T_RMUSR = 14,                   /* T_RMUSR  */
  YYSYMBOL_T_CHMOD = 15,                   /* T_CHMOD  */
  YYSYMBOL_T_MKFILE = 16,                  /* T_MKFILE  */
  YYSYMBOL_T_CAT = 17,                     /* T_CAT  */
  YYSYMBOL_T_REMOVE = 18,                  /* T_REMOVE  */
  YYSYMBOL_T_EDIT = 19,                    /* T_EDIT  */
  YYSYMBOL_T_RENAME = 20,                  /* T_RENAME  */
  YYSYMBOL_T_MKDIR = 21,                   /* T_MKDIR  */
  YYSYMBOL_T_COPY = 22,                    /* T_COPY  */
  YYSYMBOL_T_MOVE = 23,                    /* T_MOVE  */
  YYSYMBOL_T_FIND = 24,                    /* T_FIND  */
  YYSYMBOL_T_CHOWN = 25,                   /* T_CHOWN  */
  YYSYMBOL_T_CHGRP = 26,                   /* T_CHGRP  */
  YYSYMBOL_T_PAUSE = 27,                   /* T_PAUSE  */
  YYSYMBOL_T_RECOVERY = 28,                /* T_RECOVERY  */
  YYSYMBOL_T_LOSS = 29,                    /* T_LOSS  */
  YYSYMBOL_T_EXEC = 30,                    /* T_EXEC  */
  YYSYMBOL_T_REP = 31,                     /* T_REP  */
  YYSYMBOL_T_EXIT = 32,                    /* T_EXIT  */
  YYSYMBOL_T_G_NAME = 33,                  /* T_G_NAME  */
  YYSYMBOL_T_G_ID = 34,                    /* T_G_ID  */
  YYSYMBOL_T_G_PATH = 35,                  /* T_G_PATH  */
  YYSYMBOL_T_G_RUTA = 36,                  /* T_G_RUTA  */
  YYSYMBOL_T_G_DELETE = 37,                /* T_G_DELETE  */
  YYSYMBOL_T_G_ADD = 38,                   /* T_G_ADD  */
  YYSYMBOL_T_G_PASS = 39,                  /* T_G_PASS  */
  YYSYMBOL_T_G_USR = 40,                   /* T_G_USR  */
  YYSYMBOL_T_G_GRP = 41,                   /* T_G_GRP  */
  YYSYMBOL_T_G_UGO = 42,                   /* T_G_UGO  */
  YYSYMBOL_T_G_TYPE = 43,                  /* T_G_TYPE  */
  YYSYMBOL_T_G_CONT = 44,                  /* T_G_CONT  */
  YYSYMBOL_T_G_FILE = 45,                  /* T_G_FILE  */
  YYSYMBOL_T_G_DESTINO = 46,               /* T_G_DESTINO  */
  YYSYMBOL_T_G_FS = 47,                    /* T_G_FS  */
  YYSYMBOL_T_G_S = 48,                     /* T_G_S  */
  YYSYMBOL_T_G_F = 49,                     /* T_G_F  */
  YYSYMBOL_T_G_U = 50,                     /* T_G_U  */
  YYSYMBOL_T_G_T = 51,                     /* T_G_T  */
  YYSYMBOL_T_G_R = 52,                     /* T_G_R  */
  YYSYMBOL_T_G_P = 53,                     /* T_G_P  */
  YYSYMBOL_T_FLECHA = 54,                  /* T_FLECHA  */
  YYSYMBOL_T_RUTA = 55,                    /* T_RUTA  */
  YYSYMBOL_T_IGUAL = 56,                   /* T_IGUAL  */
  YYSYMBOL_T_NUMERON = 57,                 /* T_NUMERON  */
  YYSYMBOL_T_NUMEROP = 58,                 /* T_NUMEROP  */
  YYSYMBOL_T_DIGITO = 59,                  /* T_DIGITO  */
  YYSYMBOL_T_CADENA = 60,                  /* T_CADENA  */
  YYSYMBOL_T_COMENTARIO = 61,              /* T_COMENTARIO  */
  YYSYMBOL_T_ARCHIVO = 62,                 /* T_ARCHIVO  */
  YYSYMBOL_T_ID = 63,                      /* T_ID  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_inicio = 65,                    /* inicio  */
  YYSYMBOL_mkdisk = 66,                    /* mkdisk  */
  YYSYMBOL_lp_mkdisk = 67,                 /* lp_mkdisk  */
  YYSYMBOL_p_mkdisk = 68,                  /* p_mkdisk  */
  YYSYMBOL_rmdisk = 69,                    /* rmdisk  */
  YYSYMBOL_p_rmdisk = 70,                  /* p_rmdisk  */
  YYSYMBOL_fdisk = 71,                     /* fdisk  */
  YYSYMBOL_lp_fdisk = 72,                  /* lp_fdisk  */
  YYSYMBOL_p_fdisk = 73,                   /* p_fdisk  */
  YYSYMBOL_mount = 74,                     /* mount  */
  YYSYMBOL_lp_mount = 75,                  /* lp_mount  */
  YYSYMBOL_p_mount = 76,                   /* p_mount  */
  YYSYMBOL_unmount = 77,                   /* unmount  */
  YYSYMBOL_mkfs = 78,                      /* mkfs  */
  YYSYMBOL_lp_mkfs = 79,                   /* lp_mkfs  */
  YYSYMBOL_p_mkfs = 80,                    /* p_mkfs  */
  YYSYMBOL_loss = 81,                      /* loss  */
  YYSYMBOL_execute = 82,                   /* execute  */
  YYSYMBOL_lp_execute = 83,                /* lp_execute  */
  YYSYMBOL_p_execute = 84,                 /* p_execute  */
  YYSYMBOL_rep = 85                        /* rep  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  115

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    82,    89,    90,    92,    93,    94,    95,    96,    97,
     100,   106,   107,   108,   111,   117,   118,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   133,   139,
     140,   142,   143,   144,   145,   148,   156,   162,   163,   165,
     166,   167,   170,   178,   184,   186,   187,   188,   194
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
  "\"end of file\"", "error", "\"invalid token\"", "T_MKDISK", "T_RMDISK",
  "T_FDISK", "T_MOUNT", "T_UNMOUNT", "T_MKFS", "T_LOGIN", "T_LOGOUT",
  "T_MKGRP", "T_RMGRP", "T_MKUSR", "T_RMUSR", "T_CHMOD", "T_MKFILE",
  "T_CAT", "T_REMOVE", "T_EDIT", "T_RENAME", "T_MKDIR", "T_COPY", "T_MOVE",
  "T_FIND", "T_CHOWN", "T_CHGRP", "T_PAUSE", "T_RECOVERY", "T_LOSS",
  "T_EXEC", "T_REP", "T_EXIT", "T_G_NAME", "T_G_ID", "T_G_PATH",
  "T_G_RUTA", "T_G_DELETE", "T_G_ADD", "T_G_PASS", "T_G_USR", "T_G_GRP",
  "T_G_UGO", "T_G_TYPE", "T_G_CONT", "T_G_FILE", "T_G_DESTINO", "T_G_FS",
  "T_G_S", "T_G_F", "T_G_U", "T_G_T", "T_G_R", "T_G_P", "T_FLECHA",
  "T_RUTA", "T_IGUAL", "T_NUMERON", "T_NUMEROP", "T_DIGITO", "T_CADENA",
  "T_COMENTARIO", "T_ARCHIVO", "T_ID", "$accept", "inicio", "mkdisk",
  "lp_mkdisk", "p_mkdisk", "rmdisk", "p_rmdisk", "fdisk", "lp_fdisk",
  "p_fdisk", "mount", "lp_mount", "p_mount", "unmount", "mkfs", "lp_mkfs",
  "p_mkfs", "loss", "execute", "lp_execute", "p_execute", "rep", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -3,   -18,   -26,   -27,    13,   -19,   -14,   -10,   -22,   -49,
      25,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
      -9,    -6,    -4,    -2,   -18,   -49,    -1,   -49,     0,     1,
       2,     3,     4,     5,     6,     7,   -27,   -49,     8,     9,
      13,   -49,    10,    11,    12,    14,   -14,   -49,    15,    16,
     -49,   -49,   -49,   -48,    -5,    17,    18,   -49,   -21,    19,
     -20,    20,   -39,    21,    27,    23,    24,   -49,    26,   -17,
     -49,    28,    29,    30,    31,   -49,    32,   -11,   -25,   -49,
     -49,   -49,   -49,   -49,    34,   -49,   -49,   -49,    35,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,    36,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,    37,   -49,   -49,
     -49,   -49,   -49,   -49,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
       0,     2,     6,     5,     7,     8,     9,    10,     3,     4,
       0,     0,     0,     0,    11,    13,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    26,     0,     0,
      38,    40,     0,     0,     0,     0,    46,    48,     0,     0,
      53,    54,     1,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
      39,     0,     0,     0,     0,    47,     0,     0,     0,    17,
      19,    14,    15,    16,     0,    21,    23,    29,     0,    31,
      33,    35,    37,    36,    34,    27,    28,    30,    44,     0,
      42,    41,    45,    49,    50,    51,    52,     0,    55,    57,
      18,    22,    32,    43,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,   -49,    45,   -49,   -49,   -49,   -49,    38,
     -49,   -49,    33,   -49,   -49,   -49,    42,   -49,   -49,   -49,
     -49,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    24,    25,    12,    27,    13,    36,    37,
      14,    40,    41,    15,    16,    46,    47,    17,    18,    50,
      51,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       1,     2,     3,     4,     5,     6,    28,    78,    29,    26,
      30,    31,    79,    49,    80,    42,    32,    20,    92,    93,
      43,    33,    34,    35,    48,    52,     7,     8,     9,    44,
      21,    22,    23,    45,    84,    88,     0,   110,    99,    85,
      89,    86,    90,   100,   107,   101,    38,    53,    39,   108,
      54,   109,    55,    81,    56,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    68,    69,    71,    72,    73,    57,
      74,    76,    77,    70,    67,     0,     0,     0,     0,     0,
      82,    83,    87,    91,    94,    95,    96,    97,    75,    98,
       0,   102,   103,   104,   105,   106,   111,   112,   113,   114
};

static const yytype_int8 yycheck[] =
{
       3,     4,     5,     6,     7,     8,    33,    55,    35,    35,
      37,    38,    60,    35,    62,    34,    43,    35,    57,    58,
      34,    48,    49,    50,    34,     0,    29,    30,    31,    43,
      48,    49,    50,    47,    55,    55,    -1,    62,    55,    60,
      60,    62,    62,    60,    55,    62,    33,    56,    35,    60,
      56,    62,    56,    58,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    24,
      56,    56,    56,    40,    36,    -1,    -1,    -1,    -1,    -1,
      63,    63,    63,    63,    63,    58,    63,    63,    46,    63,
      -1,    63,    63,    63,    63,    63,    62,    62,    62,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    29,    30,    31,
      65,    66,    69,    71,    74,    77,    78,    81,    82,    85,
      35,    48,    49,    50,    67,    68,    35,    70,    33,    35,
      37,    38,    43,    48,    49,    50,    72,    73,    33,    35,
      75,    76,    34,    34,    43,    47,    79,    80,    34,    35,
      83,    84,     0,    56,    56,    56,    56,    68,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    73,    56,    56,
      76,    56,    56,    56,    56,    80,    56,    56,    55,    60,
      62,    58,    63,    63,    55,    60,    62,    63,    55,    60,
      62,    63,    57,    58,    63,    58,    63,    63,    63,    55,
      60,    62,    63,    63,    63,    63,    63,    55,    60,    62,
      62,    62,    62,    62,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    70,    70,    70,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    76,    76,    76,    76,    77,    78,    79,    79,    80,
      80,    80,    81,    82,    83,    84,    84,    84,    85
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     3,     3,     3,     3,     4,     3,
       2,     3,     4,     3,     2,     2,     1,     3,     3,     3,
       3,     3,     4,     3,     3,     3,     3,     3,     2,     2,
       1,     3,     3,     4,     3,     4,     2,     2,     1,     3,
       3,     3,     4,     2,     1,     3,     4,     3,     1
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
  case 2: /* inicio: mkdisk  */
#line 49 "parser.y"
                    {  }
#line 1243 "parser.cpp"
    break;

  case 3: /* inicio: execute  */
#line 50 "parser.y"
                    {  }
#line 1249 "parser.cpp"
    break;

  case 4: /* inicio: rep  */
#line 51 "parser.y"
                    {  }
#line 1255 "parser.cpp"
    break;

  case 5: /* inicio: fdisk  */
#line 52 "parser.y"
                    {  }
#line 1261 "parser.cpp"
    break;

  case 6: /* inicio: rmdisk  */
#line 53 "parser.y"
                    {  }
#line 1267 "parser.cpp"
    break;

  case 7: /* inicio: mount  */
#line 54 "parser.y"
                    {  }
#line 1273 "parser.cpp"
    break;

  case 8: /* inicio: unmount  */
#line 55 "parser.y"
                    {  }
#line 1279 "parser.cpp"
    break;

  case 9: /* inicio: mkfs  */
#line 56 "parser.y"
                    {  }
#line 1285 "parser.cpp"
    break;

  case 10: /* inicio: loss  */
#line 57 "parser.y"
                    {  }
#line 1291 "parser.cpp"
    break;

  case 11: /* mkdisk: T_MKDISK lp_mkdisk  */
#line 82 "parser.y"
                             { 
Mkdisk mkdisk(size, fit, unit, path);
    //std::cout<<size<<fit<<unit<<path<<std::endl;
    mkdisk.ejecutarComando();
    limpiarVariables();
}
#line 1302 "parser.cpp"
    break;

  case 14: /* p_mkdisk: T_G_S T_IGUAL T_NUMEROP  */
#line 92 "parser.y"
                                    { size = std::string((yyvsp[0].val));  }
#line 1308 "parser.cpp"
    break;

  case 15: /* p_mkdisk: T_G_F T_IGUAL T_ID  */
#line 93 "parser.y"
                                 { fit = std::string((yyvsp[0].val));}
#line 1314 "parser.cpp"
    break;

  case 16: /* p_mkdisk: T_G_U T_IGUAL T_ID  */
#line 94 "parser.y"
                                 { unit = std::string((yyvsp[0].val));}
#line 1320 "parser.cpp"
    break;

  case 17: /* p_mkdisk: T_G_PATH T_IGUAL T_CADENA  */
#line 95 "parser.y"
                                        { path = std::string((yyvsp[0].val));}
#line 1326 "parser.cpp"
    break;

  case 18: /* p_mkdisk: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 96 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1332 "parser.cpp"
    break;

  case 19: /* p_mkdisk: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 97 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1338 "parser.cpp"
    break;

  case 20: /* rmdisk: T_RMDISK p_rmdisk  */
#line 100 "parser.y"
                              {
    Rmdisk rmdisk(path);
    rmdisk.ejecutarComando();
    limpiarVariables();
}
#line 1348 "parser.cpp"
    break;

  case 21: /* p_rmdisk: T_G_PATH T_IGUAL T_CADENA  */
#line 106 "parser.y"
                                      { path = std::string((yyvsp[0].val)); }
#line 1354 "parser.cpp"
    break;

  case 22: /* p_rmdisk: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 107 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val)); }
#line 1360 "parser.cpp"
    break;

  case 23: /* p_rmdisk: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 108 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1366 "parser.cpp"
    break;

  case 24: /* fdisk: T_FDISK lp_fdisk  */
#line 111 "parser.y"
                             {
    Fdisk fdisk(size, unit, name, path, fit, tipo, borrar, add);
    fdisk.ejecutarComando();
    limpiarVariables();
}
#line 1376 "parser.cpp"
    break;

  case 27: /* p_fdisk: T_G_S T_IGUAL T_NUMEROP  */
#line 120 "parser.y"
                                    { size = std::string((yyvsp[0].val)); }
#line 1382 "parser.cpp"
    break;

  case 28: /* p_fdisk: T_G_F T_IGUAL T_ID  */
#line 121 "parser.y"
                                 { fit = std::string((yyvsp[0].val));}
#line 1388 "parser.cpp"
    break;

  case 29: /* p_fdisk: T_G_NAME T_IGUAL T_ID  */
#line 122 "parser.y"
                                    { name = std::string((yyvsp[0].val));}
#line 1394 "parser.cpp"
    break;

  case 30: /* p_fdisk: T_G_U T_IGUAL T_ID  */
#line 123 "parser.y"
                                 { unit = std::string((yyvsp[0].val));}
#line 1400 "parser.cpp"
    break;

  case 31: /* p_fdisk: T_G_PATH T_IGUAL T_CADENA  */
#line 124 "parser.y"
                                        { path = std::string((yyvsp[0].val));}
#line 1406 "parser.cpp"
    break;

  case 32: /* p_fdisk: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 125 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1412 "parser.cpp"
    break;

  case 33: /* p_fdisk: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 126 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1418 "parser.cpp"
    break;

  case 34: /* p_fdisk: T_G_TYPE T_IGUAL T_ID  */
#line 127 "parser.y"
                                    { tipo = std::string((yyvsp[0].val)); }
#line 1424 "parser.cpp"
    break;

  case 35: /* p_fdisk: T_G_DELETE T_IGUAL T_ID  */
#line 128 "parser.y"
                                      { tipo = std::string((yyvsp[0].val));}
#line 1430 "parser.cpp"
    break;

  case 36: /* p_fdisk: T_G_ADD T_IGUAL T_NUMEROP  */
#line 129 "parser.y"
                                        { add = std::string((yyvsp[0].val));}
#line 1436 "parser.cpp"
    break;

  case 37: /* p_fdisk: T_G_ADD T_IGUAL T_NUMERON  */
#line 130 "parser.y"
                                        { add = std::string((yyvsp[0].val));}
#line 1442 "parser.cpp"
    break;

  case 38: /* mount: T_MOUNT lp_mount  */
#line 133 "parser.y"
                            {
    Mount mount(name, path);
    mount.ejecutarComando();
    limpiarVariables();
}
#line 1452 "parser.cpp"
    break;

  case 41: /* p_mount: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 142 "parser.y"
                                       { path = std::string((yyvsp[0].val)); }
#line 1458 "parser.cpp"
    break;

  case 42: /* p_mount: T_G_PATH T_IGUAL T_CADENA  */
#line 143 "parser.y"
                                        { path = std::string((yyvsp[0].val));}
#line 1464 "parser.cpp"
    break;

  case 43: /* p_mount: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 144 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1470 "parser.cpp"
    break;

  case 44: /* p_mount: T_G_NAME T_IGUAL T_ID  */
#line 145 "parser.y"
                                    { name = std::string((yyvsp[0].val)); }
#line 1476 "parser.cpp"
    break;

  case 45: /* unmount: T_UNMOUNT T_G_ID T_IGUAL T_ID  */
#line 148 "parser.y"
                                       {
    id = std::string((yyvsp[0].val));
    Unmount unmount(id);
    unmount.ejecutarComando();
    limpiarVariables();
}
#line 1487 "parser.cpp"
    break;

  case 46: /* mkfs: T_MKFS lp_mkfs  */
#line 156 "parser.y"
                          {
    Mkfs mkfs(id, tipo, fs);
    mkfs.ejecutarComando();
    limpiarVariables();
}
#line 1497 "parser.cpp"
    break;

  case 49: /* p_mkfs: T_G_ID T_IGUAL T_ID  */
#line 165 "parser.y"
                                { id = std::string((yyvsp[0].val)); }
#line 1503 "parser.cpp"
    break;

  case 50: /* p_mkfs: T_G_TYPE T_IGUAL T_ID  */
#line 166 "parser.y"
                                   { tipo = std::string((yyvsp[0].val));}
#line 1509 "parser.cpp"
    break;

  case 51: /* p_mkfs: T_G_FS T_IGUAL T_ID  */
#line 167 "parser.y"
                                 { tipo = std::string((yyvsp[0].val)); }
#line 1515 "parser.cpp"
    break;

  case 52: /* loss: T_LOSS T_G_ID T_IGUAL T_ID  */
#line 170 "parser.y"
                                       {
    id = std::string((yyvsp[0].val));
    Loss loss(id);
    loss.ejecutarComando();
    limpiarVariables();
}
#line 1526 "parser.cpp"
    break;

  case 53: /* execute: T_EXEC lp_execute  */
#line 178 "parser.y"
                              {
    Execute execute(path);
    execute.ejecutarComando();
    limpiarVariables();
}
#line 1536 "parser.cpp"
    break;

  case 55: /* p_execute: T_G_PATH T_IGUAL T_CADENA  */
#line 186 "parser.y"
                                      { path = std::string((yyvsp[0].val));}
#line 1542 "parser.cpp"
    break;

  case 56: /* p_execute: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 187 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1548 "parser.cpp"
    break;

  case 57: /* p_execute: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 188 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1554 "parser.cpp"
    break;

  case 58: /* rep: T_REP  */
#line 194 "parser.y"
           {
    Rep rep; rep.ejecutarComando(); 
}
#line 1562 "parser.cpp"
    break;


#line 1566 "parser.cpp"

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

#line 199 "parser.y"


void yyerror(const char *s) {
    std::cout << "Error parametro no valido "<< s<<std::endl;
}

void limpiarVariables(){
    size = "";
    fit = "";
    unit = "";
    path = "";
    tipo = "";
    borrar = "";
    name = "";
    add = "";
    fs = "";

    nId = "";
    id = "";
    ruta = "";
    user = "";
    pass = "";
    grp = "";
    ugo = "";
    r = "";
    cont = "";
    nFile = "";
    p = "";
    destino = "";
    }

