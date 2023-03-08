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
#include <vector>

#include "./struct_and_class/mkdisk.h"
#include "./struct_and_class/rmdisk.h"
#include "./struct_and_class/fdisk.h"
#include "./struct_and_class/mount.h"
#include "./struct_and_class/unmount.h"
#include "./struct_and_class/mkfs.h"
#include "./struct_and_class/execute.h"
#include "./struct_and_class/loss.h"
#include "./struct_and_class/user_and_group/login.h"
#include "./struct_and_class/user_and_group/logout.h"
#include "./struct_and_class/user_and_group/rmgrp.h"
#include "./struct_and_class/user_and_group/rmusr.h"
#include "./struct_and_class/user_and_group/mkusr.h"
#include "./struct_and_class/user_and_group/mkgrp.h"
#include "./struct_and_class/files/cat.h"
#include "./struct_and_class/files/copy.h"
#include "./struct_and_class/files/edit.h"
#include "./struct_and_class/files/mkdir.h"
#include "./struct_and_class/files/mkfile.h"
#include "./struct_and_class/files/move.h"
#include "./struct_and_class/files/pause.h"
#include "./struct_and_class/files/remove.h"
#include "./struct_and_class/files/rename.h"

#include "./struct_and_class/rep.h"

extern char *yytext;

int yylex(void);
void yyerror(const char *);
//variables para el manejo de parametros
void limpiarVariables();
std::string size, fit, unit, path, tipo, borrar, name, add, nId, id, fs, ruta, user, pass, grp, ugo, r, cont,p, destino;
std::vector<std::string> nFile;
std::vector<std::string> paths;


#line 116 "parser.cpp"

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
  YYSYMBOL_rep = 85,                       /* rep  */
  YYSYMBOL_lp_rep = 86,                    /* lp_rep  */
  YYSYMBOL_p_rep = 87,                     /* p_rep  */
  YYSYMBOL_comentario = 88,                /* comentario  */
  YYSYMBOL_login = 89,                     /* login  */
  YYSYMBOL_lp_login = 90,                  /* lp_login  */
  YYSYMBOL_p_login = 91,                   /* p_login  */
  YYSYMBOL_logout = 92,                    /* logout  */
  YYSYMBOL_mkgrp = 93,                     /* mkgrp  */
  YYSYMBOL_rmgrp = 94,                     /* rmgrp  */
  YYSYMBOL_mkusr = 95,                     /* mkusr  */
  YYSYMBOL_lp_mkusr = 96,                  /* lp_mkusr  */
  YYSYMBOL_p_mkusr = 97,                   /* p_mkusr  */
  YYSYMBOL_rmusr = 98,                     /* rmusr  */
  YYSYMBOL_mkfile = 99,                    /* mkfile  */
  YYSYMBOL_lp_mkfile = 100,                /* lp_mkfile  */
  YYSYMBOL_p_mkfile = 101,                 /* p_mkfile  */
  YYSYMBOL_cat = 102,                      /* cat  */
  YYSYMBOL_lp_cat = 103,                   /* lp_cat  */
  YYSYMBOL_p_cat = 104,                    /* p_cat  */
  YYSYMBOL_remove = 105,                   /* remove  */
  YYSYMBOL_lp_remove = 106,                /* lp_remove  */
  YYSYMBOL_p_remove = 107,                 /* p_remove  */
  YYSYMBOL_edit = 108,                     /* edit  */
  YYSYMBOL_lp_edit = 109,                  /* lp_edit  */
  YYSYMBOL_p_edit = 110,                   /* p_edit  */
  YYSYMBOL_rename = 111,                   /* rename  */
  YYSYMBOL_lp_rename = 112,                /* lp_rename  */
  YYSYMBOL_p_rename = 113,                 /* p_rename  */
  YYSYMBOL_mkdir = 114,                    /* mkdir  */
  YYSYMBOL_lp_mkdir = 115,                 /* lp_mkdir  */
  YYSYMBOL_p_mkdir = 116,                  /* p_mkdir  */
  YYSYMBOL_copy = 117,                     /* copy  */
  YYSYMBOL_lp_copy = 118,                  /* lp_copy  */
  YYSYMBOL_p_copy = 119,                   /* p_copy  */
  YYSYMBOL_move = 120,                     /* move  */
  YYSYMBOL_lp_move = 121,                  /* lp_move  */
  YYSYMBOL_p_move = 122,                   /* p_move  */
  YYSYMBOL_pause = 123                     /* pause  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  135
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

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
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    85,    86,
      87,    88,    89,    90,    91,    92,    96,   101,   108,   109,
     111,   112,   113,   114,   115,   116,   119,   125,   126,   127,
     130,   136,   137,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   152,   158,   159,   161,   162,   163,
     164,   167,   175,   181,   182,   184,   185,   186,   189,   197,
     203,   205,   206,   207,   210,   216,   217,   219,   220,   221,
     222,   223,   224,   225,   226,   229,   234,   241,   242,   244,
     245,   246,   247,   248,   251,   257,   265,   273,   279,   280,
     282,   283,   284,   287,   297,   303,   304,   306,   307,   308,
     309,   310,   311,   312,   313,   316,   322,   323,   325,   327,
     330,   335,   341,   342,   344,   345,   346,   349,   355,   356,
     358,   359,   360,   361,   362,   363,   366,   372,   373,   375,
     376,   377,   378,   379,   382,   388,   389,   391,   392,   393,
     394,   397,   403,   404,   406,   407,   408,   409,   410,   411,
     414,   420,   421,   423,   424,   425,   426,   427,   428,   431
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
  "p_mkfs", "loss", "execute", "lp_execute", "p_execute", "rep", "lp_rep",
  "p_rep", "comentario", "login", "lp_login", "p_login", "logout", "mkgrp",
  "rmgrp", "mkusr", "lp_mkusr", "p_mkusr", "rmusr", "mkfile", "lp_mkfile",
  "p_mkfile", "cat", "lp_cat", "p_cat", "remove", "lp_remove", "p_remove",
  "edit", "lp_edit", "p_edit", "rename", "lp_rename", "p_rename", "mkdir",
  "lp_mkdir", "p_mkdir", "copy", "lp_copy", "p_copy", "move", "lp_move",
  "p_move", "pause", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-24)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,     0,   -23,    -4,    95,    -9,     8,    83,   -24,   -11,
       4,    98,     3,   -12,    39,    22,    12,   107,   -14,    -5,
      17,   -24,    38,    63,   100,   -24,    76,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,    29,    51,    85,    89,     0,   -24,    90,   -24,
      91,    92,    93,    94,    96,    97,    99,   101,    -4,   -24,
     102,   103,    95,   -24,   104,   105,   106,   108,     8,   -24,
     109,   110,   111,    83,   -24,   -10,    43,   112,   113,   114,
      98,   -24,    88,   115,   116,   117,   -24,   -12,   -24,    36,
      39,   -24,   118,    22,   -24,   119,   120,    12,   -24,   121,
     122,   107,   -24,   123,   -24,   -14,   -24,   124,   125,    -5,
     -24,   126,   127,    17,   -24,   128,   129,   -24,   -24,   130,
     131,   132,   133,   100,   -24,   -24,     5,   134,   135,   136,
     -24,     6,   137,     9,   138,    86,   139,   145,   141,   142,
     -24,   143,    15,   -24,   144,   146,   147,   148,   -24,   149,
      62,    66,   -24,   -24,   -24,   150,   151,   152,   -24,   -24,
      18,    19,   158,   -24,   140,   -24,    27,   -24,    28,    31,
     -24,    56,    37,   -24,    40,   -24,    41,    71,   -24,    49,
      72,   -24,   154,    50,   155,   156,    53,    -1,   -24,   159,
     -24,   -24,   -24,   -24,   -24,   160,   -24,   -24,   -24,   161,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     162,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   163,   -24,   -24,   164,   -24,
     -24,   -24,    59,   165,   -24,   -24,   166,   -24,   -24,   167,
     -24,   -24,   -24,   -24,   168,   -24,   -24,   169,   -24,   -24,
     170,   -24,   -24,   -24,   -24,   171,   -24,   -24,   -24,   -24,
     -24,   172,   -24,   -24,   -24,   -24,   173,   -24,   -24,   174,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   175,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,     0,     0,     0,    85,     0,     2,     6,     5,
       7,     8,     9,    10,     3,     4,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,     0,     0,     0,    27,    29,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    42,
       0,     0,    54,    56,     0,     0,     0,     0,    62,    64,
       0,     0,     0,    86,    88,     0,     0,     0,     0,     0,
      97,    99,     0,     0,     0,     0,   110,   104,   106,     0,
     115,   117,     0,   121,   123,     0,     0,   127,   129,     0,
       0,   136,   138,     0,   150,   144,   146,     0,     0,   151,
     153,     0,     0,   160,   162,     0,     0,    69,    70,     0,
       0,     0,     0,    74,    76,     1,     0,     0,     0,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,    55,     0,     0,     0,     0,    63,     0,
       0,     0,    87,    95,    96,     0,     0,     0,    98,   103,
       0,     0,     0,   105,     0,   116,     0,   122,     0,     0,
     128,     0,     0,   137,     0,   145,     0,     0,   152,     0,
       0,   161,     0,     0,     0,     0,     0,     0,    75,     0,
      33,    35,    30,    31,    32,     0,    37,    39,    45,     0,
      47,    49,    51,    53,    52,    50,    43,    44,    46,    60,
       0,    58,    57,    61,    65,    66,    67,    93,    91,    92,
      89,    90,   101,   100,   102,     0,   107,   109,     0,   112,
     114,   111,     0,     0,   124,   126,     0,   130,   132,     0,
     133,   135,   142,   143,     0,   139,   141,     0,   147,   149,
     157,   154,   156,   159,   158,   166,   163,   165,   168,   167,
      68,     0,    71,    73,    77,    81,     0,    78,    80,     0,
      83,    82,    34,    38,    48,    59,   108,   113,     0,   118,
     120,   125,   131,   134,   140,   148,   155,   164,    72,    79,
      84,   119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -24,   -24,   -24,   -24,   182,   -24,   -24,   -24,   -24,   176,
     -24,   -24,    82,   -24,   -24,   -24,    78,   -24,   -24,   -24,
     -24,   -24,   -24,    30,   -24,   -24,   -24,   157,   -24,   -24,
     -24,   -24,   -24,   153,   -24,   -24,   -24,   177,   -24,   -24,
     178,   -24,   -24,    87,   -24,   -24,    84,   -24,   -24,   179,
     -24,   -24,    79,   -24,   -24,    74,   -24,   -24,   180,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    26,    27,    56,    57,    28,    59,    29,    68,    69,
      30,    72,    73,    31,    32,    78,    79,    33,    34,   127,
     128,    35,   133,   134,    36,    37,    83,    84,    38,    39,
      40,    41,    90,    91,    42,    43,    97,    98,    44,   100,
     101,    45,   103,   104,    46,   107,   108,    47,   111,   112,
      48,   115,   116,    49,   119,   120,    50,   123,   124,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    58,    13,    14,    15,    16,    17,    18,    19,
      20,   113,    85,    93,    21,    74,    22,    23,    24,    60,
     117,    61,    94,    62,    63,    52,    95,    86,   114,    64,
      96,   118,    75,    92,    65,    66,    67,   105,    53,    54,
      55,    76,   121,   163,   279,    77,   106,   102,    25,   280,
     199,   205,   281,   122,   209,   200,   206,   201,   207,   210,
     220,   211,   125,   235,   238,   221,   135,   222,   236,   239,
     237,   240,   243,   246,    99,   136,   249,   244,   247,   245,
     248,   250,   254,   251,   174,   257,   260,   255,   126,   256,
     258,   261,   259,   262,   265,   271,   164,   137,   276,   266,
     272,   267,   273,   277,   288,   278,   252,    80,   253,   289,
     228,   290,    81,    82,   230,   229,   263,   268,    70,   231,
      71,   264,   269,   129,   130,   131,   132,    87,    88,    89,
     109,   138,   110,   213,   214,   139,   141,   142,   143,   144,
     145,   169,   146,   147,   153,   148,   158,   149,   151,   152,
     154,   155,   156,   198,   157,   159,   160,   161,   165,   166,
     167,   170,   171,   172,   176,   178,   179,   181,   182,   184,
     186,   187,   189,   190,   192,   193,   194,   195,   196,   197,
     177,   180,   202,   188,   185,     0,   242,     0,   203,   204,
     208,   212,   215,   216,   217,   218,   219,   223,     0,   224,
     225,   226,   227,   232,   233,   234,   241,   270,   274,   275,
       0,   282,   283,   284,   285,   286,   287,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   140,     0,
     162,     0,     0,   168,   150,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    35,    16,    17,    18,    19,    20,    21,    22,
      23,    35,    33,    35,    27,    34,    29,    30,    31,    33,
      35,    35,    44,    37,    38,    35,    48,    33,    52,    43,
      52,    46,    34,    40,    48,    49,    50,    35,    48,    49,
      50,    43,    35,    63,    55,    47,    44,    35,    61,    60,
      55,    55,    63,    46,    55,    60,    60,    62,    62,    60,
      55,    62,    34,    55,    55,    60,     0,    62,    60,    60,
      62,    62,    55,    55,    45,    56,    55,    60,    60,    62,
      62,    60,    55,    62,    58,    55,    55,    60,    35,    62,
      60,    60,    62,    62,    55,    55,    63,    56,    55,    60,
      60,    62,    62,    60,    55,    62,    60,    34,    62,    60,
      58,    62,    39,    40,    58,    63,    55,    55,    33,    63,
      35,    60,    60,    33,    34,    35,    36,    39,    40,    41,
      33,    56,    35,    57,    58,    56,    56,    56,    56,    56,
      56,    63,    56,    56,    72,    56,    78,    56,    56,    56,
      56,    56,    56,   133,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
     103,   107,    58,   119,   115,    -1,    56,    -1,    63,    63,
      63,    63,    63,    58,    63,    63,    63,    63,    -1,    63,
      63,    63,    63,    63,    63,    63,    58,    63,    63,    63,
      -1,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    56,    -1,
      83,    -1,    -1,    90,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    27,    29,    30,    31,    61,    65,    66,    69,    71,
      74,    77,    78,    81,    82,    85,    88,    89,    92,    93,
      94,    95,    98,    99,   102,   105,   108,   111,   114,   117,
     120,   123,    35,    48,    49,    50,    67,    68,    35,    70,
      33,    35,    37,    38,    43,    48,    49,    50,    72,    73,
      33,    35,    75,    76,    34,    34,    43,    47,    79,    80,
      34,    39,    40,    90,    91,    33,    33,    39,    40,    41,
      96,    97,    40,    35,    44,    48,    52,   100,   101,    45,
     103,   104,    35,   106,   107,    35,    44,   109,   110,    33,
      35,   112,   113,    35,    52,   115,   116,    35,    46,   118,
     119,    35,    46,   121,   122,    34,    35,    83,    84,    33,
      34,    35,    36,    86,    87,     0,    56,    56,    56,    56,
      68,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      73,    56,    56,    76,    56,    56,    56,    56,    80,    56,
      56,    56,    91,    63,    63,    56,    56,    56,    97,    63,
      56,    56,    56,   101,    58,   104,    56,   107,    56,    56,
     110,    56,    56,   113,    56,   116,    56,    56,   119,    56,
      56,   122,    56,    56,    56,    56,    56,    56,    87,    55,
      60,    62,    58,    63,    63,    55,    60,    62,    63,    55,
      60,    62,    63,    57,    58,    63,    58,    63,    63,    63,
      55,    60,    62,    63,    63,    63,    63,    63,    58,    63,
      58,    63,    63,    63,    63,    55,    60,    62,    55,    60,
      62,    58,    56,    55,    60,    62,    55,    60,    62,    55,
      60,    62,    60,    62,    55,    60,    62,    55,    60,    62,
      55,    60,    62,    55,    60,    55,    60,    62,    55,    60,
      63,    55,    60,    62,    63,    63,    55,    60,    62,    55,
      60,    63,    62,    62,    62,    62,    62,    62,    55,    60,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    70,    70,    70,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    75,    75,    76,    76,    76,
      76,    77,    78,    79,    79,    80,    80,    80,    81,    82,
      83,    84,    84,    84,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    89,    90,    90,    91,
      91,    91,    91,    91,    92,    93,    94,    95,    96,    96,
      97,    97,    97,    98,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   103,   103,   104,   104,
     104,   105,   106,   106,   107,   107,   107,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   111,   112,   112,   113,
     113,   113,   113,   113,   114,   115,   115,   116,   116,   116,
     116,   117,   118,   118,   119,   119,   119,   119,   119,   119,
     120,   121,   121,   122,   122,   122,   122,   122,   122,   123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       3,     3,     3,     3,     4,     3,     2,     3,     4,     3,
       2,     2,     1,     3,     3,     3,     3,     3,     4,     3,
       3,     3,     3,     3,     2,     2,     1,     3,     3,     4,
       3,     4,     2,     2,     1,     3,     3,     3,     4,     2,
       1,     3,     4,     3,     2,     2,     1,     3,     3,     4,
       3,     3,     3,     3,     4,     1,     2,     2,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     2,     2,     1,
       3,     3,     3,     3,     2,     2,     1,     3,     4,     3,
       1,     3,     3,     4,     3,     2,     2,     1,     4,     5,
       4,     2,     2,     1,     3,     4,     3,     2,     2,     1,
       3,     4,     3,     3,     4,     3,     2,     2,     1,     3,
       4,     3,     3,     3,     2,     2,     1,     3,     4,     3,
       1,     2,     2,     1,     3,     4,     3,     3,     3,     3,
       2,     2,     1,     3,     4,     3,     3,     3,     3,     1
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
#line 68 "parser.y"
                    {  }
#line 1444 "parser.cpp"
    break;

  case 3: /* inicio: execute  */
#line 69 "parser.y"
                    {  }
#line 1450 "parser.cpp"
    break;

  case 4: /* inicio: rep  */
#line 70 "parser.y"
                    {  }
#line 1456 "parser.cpp"
    break;

  case 5: /* inicio: fdisk  */
#line 71 "parser.y"
                    {  }
#line 1462 "parser.cpp"
    break;

  case 6: /* inicio: rmdisk  */
#line 72 "parser.y"
                    {  }
#line 1468 "parser.cpp"
    break;

  case 7: /* inicio: mount  */
#line 73 "parser.y"
                    {  }
#line 1474 "parser.cpp"
    break;

  case 8: /* inicio: unmount  */
#line 74 "parser.y"
                    {  }
#line 1480 "parser.cpp"
    break;

  case 9: /* inicio: mkfs  */
#line 75 "parser.y"
                    {  }
#line 1486 "parser.cpp"
    break;

  case 10: /* inicio: loss  */
#line 76 "parser.y"
                    {  }
#line 1492 "parser.cpp"
    break;

  case 11: /* inicio: comentario  */
#line 77 "parser.y"
                    {  }
#line 1498 "parser.cpp"
    break;

  case 12: /* inicio: login  */
#line 78 "parser.y"
                    {  }
#line 1504 "parser.cpp"
    break;

  case 13: /* inicio: logout  */
#line 79 "parser.y"
                    {  }
#line 1510 "parser.cpp"
    break;

  case 14: /* inicio: mkgrp  */
#line 80 "parser.y"
                    {  }
#line 1516 "parser.cpp"
    break;

  case 15: /* inicio: rmgrp  */
#line 81 "parser.y"
                    {  }
#line 1522 "parser.cpp"
    break;

  case 16: /* inicio: mkusr  */
#line 82 "parser.y"
                    {  }
#line 1528 "parser.cpp"
    break;

  case 17: /* inicio: rmusr  */
#line 83 "parser.y"
                    {  }
#line 1534 "parser.cpp"
    break;

  case 18: /* inicio: mkfile  */
#line 85 "parser.y"
                    {  }
#line 1540 "parser.cpp"
    break;

  case 19: /* inicio: cat  */
#line 86 "parser.y"
                    {  }
#line 1546 "parser.cpp"
    break;

  case 20: /* inicio: remove  */
#line 87 "parser.y"
                    {  }
#line 1552 "parser.cpp"
    break;

  case 21: /* inicio: edit  */
#line 88 "parser.y"
                    {  }
#line 1558 "parser.cpp"
    break;

  case 22: /* inicio: rename  */
#line 89 "parser.y"
                    {  }
#line 1564 "parser.cpp"
    break;

  case 23: /* inicio: mkdir  */
#line 90 "parser.y"
                    {  }
#line 1570 "parser.cpp"
    break;

  case 24: /* inicio: copy  */
#line 91 "parser.y"
                    {  }
#line 1576 "parser.cpp"
    break;

  case 25: /* inicio: move  */
#line 92 "parser.y"
                    {  }
#line 1582 "parser.cpp"
    break;

  case 26: /* inicio: pause  */
#line 96 "parser.y"
                    {  }
#line 1588 "parser.cpp"
    break;

  case 27: /* mkdisk: T_MKDISK lp_mkdisk  */
#line 101 "parser.y"
                             { 
Mkdisk mkdisk(size, fit, unit, path);
    //std::cout<<size<<fit<<unit<<path<<std::endl;
    mkdisk.ejecutarComando();
    limpiarVariables();
}
#line 1599 "parser.cpp"
    break;

  case 30: /* p_mkdisk: T_G_S T_IGUAL T_NUMEROP  */
#line 111 "parser.y"
                                    { size = std::string((yyvsp[0].val));  }
#line 1605 "parser.cpp"
    break;

  case 31: /* p_mkdisk: T_G_F T_IGUAL T_ID  */
#line 112 "parser.y"
                                 { fit = std::string((yyvsp[0].val));}
#line 1611 "parser.cpp"
    break;

  case 32: /* p_mkdisk: T_G_U T_IGUAL T_ID  */
#line 113 "parser.y"
                                 { unit = std::string((yyvsp[0].val));}
#line 1617 "parser.cpp"
    break;

  case 33: /* p_mkdisk: T_G_PATH T_IGUAL T_CADENA  */
#line 114 "parser.y"
                                        { path = std::string((yyvsp[0].val));}
#line 1623 "parser.cpp"
    break;

  case 34: /* p_mkdisk: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 115 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1629 "parser.cpp"
    break;

  case 35: /* p_mkdisk: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 116 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1635 "parser.cpp"
    break;

  case 36: /* rmdisk: T_RMDISK p_rmdisk  */
#line 119 "parser.y"
                              {
    Rmdisk rmdisk(path);
    rmdisk.ejecutarComando();
    limpiarVariables();
}
#line 1645 "parser.cpp"
    break;

  case 37: /* p_rmdisk: T_G_PATH T_IGUAL T_CADENA  */
#line 125 "parser.y"
                                      { path = std::string((yyvsp[0].val)); }
#line 1651 "parser.cpp"
    break;

  case 38: /* p_rmdisk: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 126 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val)); }
#line 1657 "parser.cpp"
    break;

  case 39: /* p_rmdisk: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 127 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1663 "parser.cpp"
    break;

  case 40: /* fdisk: T_FDISK lp_fdisk  */
#line 130 "parser.y"
                             {
    Fdisk fdisk(size, unit, name, path, fit, tipo, borrar, add);
    fdisk.ejecutarComando();
    limpiarVariables();
}
#line 1673 "parser.cpp"
    break;

  case 43: /* p_fdisk: T_G_S T_IGUAL T_NUMEROP  */
#line 139 "parser.y"
                                    { size = std::string((yyvsp[0].val)); }
#line 1679 "parser.cpp"
    break;

  case 44: /* p_fdisk: T_G_F T_IGUAL T_ID  */
#line 140 "parser.y"
                                 { fit = std::string((yyvsp[0].val));}
#line 1685 "parser.cpp"
    break;

  case 45: /* p_fdisk: T_G_NAME T_IGUAL T_ID  */
#line 141 "parser.y"
                                    { name = std::string((yyvsp[0].val));}
#line 1691 "parser.cpp"
    break;

  case 46: /* p_fdisk: T_G_U T_IGUAL T_ID  */
#line 142 "parser.y"
                                 { unit = std::string((yyvsp[0].val));}
#line 1697 "parser.cpp"
    break;

  case 47: /* p_fdisk: T_G_PATH T_IGUAL T_CADENA  */
#line 143 "parser.y"
                                        { path = std::string((yyvsp[0].val));}
#line 1703 "parser.cpp"
    break;

  case 48: /* p_fdisk: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 144 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1709 "parser.cpp"
    break;

  case 49: /* p_fdisk: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 145 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1715 "parser.cpp"
    break;

  case 50: /* p_fdisk: T_G_TYPE T_IGUAL T_ID  */
#line 146 "parser.y"
                                    { tipo = std::string((yyvsp[0].val)); }
#line 1721 "parser.cpp"
    break;

  case 51: /* p_fdisk: T_G_DELETE T_IGUAL T_ID  */
#line 147 "parser.y"
                                      { tipo = std::string((yyvsp[0].val));}
#line 1727 "parser.cpp"
    break;

  case 52: /* p_fdisk: T_G_ADD T_IGUAL T_NUMEROP  */
#line 148 "parser.y"
                                        { add = std::string((yyvsp[0].val));}
#line 1733 "parser.cpp"
    break;

  case 53: /* p_fdisk: T_G_ADD T_IGUAL T_NUMERON  */
#line 149 "parser.y"
                                        { add = std::string((yyvsp[0].val));}
#line 1739 "parser.cpp"
    break;

  case 54: /* mount: T_MOUNT lp_mount  */
#line 152 "parser.y"
                            {
    Mount mount(name, path);
    mount.ejecutarComando();
    limpiarVariables();
}
#line 1749 "parser.cpp"
    break;

  case 57: /* p_mount: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 161 "parser.y"
                                       { path = std::string((yyvsp[0].val)); }
#line 1755 "parser.cpp"
    break;

  case 58: /* p_mount: T_G_PATH T_IGUAL T_CADENA  */
#line 162 "parser.y"
                                        { path = std::string((yyvsp[0].val));}
#line 1761 "parser.cpp"
    break;

  case 59: /* p_mount: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 163 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1767 "parser.cpp"
    break;

  case 60: /* p_mount: T_G_NAME T_IGUAL T_ID  */
#line 164 "parser.y"
                                    { name = std::string((yyvsp[0].val)); }
#line 1773 "parser.cpp"
    break;

  case 61: /* unmount: T_UNMOUNT T_G_ID T_IGUAL T_ID  */
#line 167 "parser.y"
                                       {
    id = std::string((yyvsp[0].val));
    Unmount unmount(id);
    unmount.ejecutarComando();
    limpiarVariables();
}
#line 1784 "parser.cpp"
    break;

  case 62: /* mkfs: T_MKFS lp_mkfs  */
#line 175 "parser.y"
                          {
    Mkfs mkfs(id, tipo, fs);
    mkfs.ejecutarComando();
    limpiarVariables();
}
#line 1794 "parser.cpp"
    break;

  case 65: /* p_mkfs: T_G_ID T_IGUAL T_ID  */
#line 184 "parser.y"
                                { id = std::string((yyvsp[0].val)); }
#line 1800 "parser.cpp"
    break;

  case 66: /* p_mkfs: T_G_TYPE T_IGUAL T_ID  */
#line 185 "parser.y"
                                   { tipo = std::string((yyvsp[0].val));}
#line 1806 "parser.cpp"
    break;

  case 67: /* p_mkfs: T_G_FS T_IGUAL T_ID  */
#line 186 "parser.y"
                                 { tipo = std::string((yyvsp[0].val)); }
#line 1812 "parser.cpp"
    break;

  case 68: /* loss: T_LOSS T_G_ID T_IGUAL T_ID  */
#line 189 "parser.y"
                                       {
    id = std::string((yyvsp[0].val));
    Loss loss(id);
    loss.ejecutarComando();
    limpiarVariables();
}
#line 1823 "parser.cpp"
    break;

  case 69: /* execute: T_EXEC lp_execute  */
#line 197 "parser.y"
                              {
    Execute execute(path);
    execute.ejecutarComando();
    limpiarVariables();
}
#line 1833 "parser.cpp"
    break;

  case 71: /* p_execute: T_G_PATH T_IGUAL T_CADENA  */
#line 205 "parser.y"
                                      { path = std::string((yyvsp[0].val));}
#line 1839 "parser.cpp"
    break;

  case 72: /* p_execute: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 206 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1845 "parser.cpp"
    break;

  case 73: /* p_execute: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 207 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 1851 "parser.cpp"
    break;

  case 74: /* rep: T_REP lp_rep  */
#line 210 "parser.y"
                 {
    Rep rep(name, path, id, ruta); 
    rep.ejecutarComando(); 
    limpiarVariables();
}
#line 1861 "parser.cpp"
    break;

  case 77: /* p_rep: T_G_NAME T_IGUAL T_ID  */
#line 219 "parser.y"
                              { name = std::string((yyvsp[0].val)); }
#line 1867 "parser.cpp"
    break;

  case 78: /* p_rep: T_G_PATH T_IGUAL T_CADENA  */
#line 220 "parser.y"
                                    { path = std::string((yyvsp[0].val));}
#line 1873 "parser.cpp"
    break;

  case 79: /* p_rep: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 221 "parser.y"
                                            { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1879 "parser.cpp"
    break;

  case 80: /* p_rep: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 222 "parser.y"
                                     { path = std::string((yyvsp[0].val)); }
#line 1885 "parser.cpp"
    break;

  case 81: /* p_rep: T_G_ID T_IGUAL T_ID  */
#line 223 "parser.y"
                              { id = std::string((yyvsp[0].val)); }
#line 1891 "parser.cpp"
    break;

  case 82: /* p_rep: T_G_RUTA T_IGUAL T_ID  */
#line 224 "parser.y"
                                {ruta = std::string((yyvsp[0].val));}
#line 1897 "parser.cpp"
    break;

  case 83: /* p_rep: T_G_RUTA T_IGUAL T_CADENA  */
#line 225 "parser.y"
                                    {ruta = std::string((yyvsp[0].val));}
#line 1903 "parser.cpp"
    break;

  case 84: /* p_rep: T_G_RUTA T_IGUAL T_RUTA T_ARCHIVO  */
#line 226 "parser.y"
                                            { ruta = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 1909 "parser.cpp"
    break;

  case 85: /* comentario: T_COMENTARIO  */
#line 229 "parser.y"
                         { /*std::cout<<std::string($1)<<std::endl;*/}
#line 1915 "parser.cpp"
    break;

  case 86: /* login: T_LOGIN lp_login  */
#line 234 "parser.y"
                        {
    Login login(user, pass, id);
    login.ejecutarComando();
    limpiarVariables();

}
#line 1926 "parser.cpp"
    break;

  case 89: /* p_login: T_G_USR T_IGUAL T_NUMEROP  */
#line 244 "parser.y"
                                      { user = std::string((yyvsp[0].val)); }
#line 1932 "parser.cpp"
    break;

  case 90: /* p_login: T_G_USR T_IGUAL T_ID  */
#line 245 "parser.y"
                                   { user = std::string((yyvsp[0].val)); }
#line 1938 "parser.cpp"
    break;

  case 91: /* p_login: T_G_PASS T_IGUAL T_NUMEROP  */
#line 246 "parser.y"
                                         { pass = std::string((yyvsp[0].val)); }
#line 1944 "parser.cpp"
    break;

  case 92: /* p_login: T_G_PASS T_IGUAL T_ID  */
#line 247 "parser.y"
                                    { pass = std::string((yyvsp[0].val));}
#line 1950 "parser.cpp"
    break;

  case 93: /* p_login: T_G_ID T_IGUAL T_ID  */
#line 248 "parser.y"
                                  { id = std::string((yyvsp[0].val)); }
#line 1956 "parser.cpp"
    break;

  case 94: /* logout: T_LOGOUT  */
#line 251 "parser.y"
                     {
    Logout lout;
    lout.ejecutarComando();
}
#line 1965 "parser.cpp"
    break;

  case 95: /* mkgrp: T_MKGRP T_G_NAME T_ID  */
#line 257 "parser.y"
                              {
    id = std::string((yyvsp[0].val));
    Mkgrp mkgrp(id);
    mkgrp.ejecutarComando();
    limpiarVariables();
}
#line 1976 "parser.cpp"
    break;

  case 96: /* rmgrp: T_RMGRP T_G_NAME T_ID  */
#line 265 "parser.y"
                             {
    id = std::string((yyvsp[0].val));
    Rmgrp rmgrp(id);
    rmgrp.ejecutarComando();
    limpiarVariables();
}
#line 1987 "parser.cpp"
    break;

  case 97: /* mkusr: T_MKUSR lp_mkusr  */
#line 273 "parser.y"
                        {
    Mkusr mkusr(user, pass, grp);
    mkusr.ejecutarComando();
    limpiarVariables();
}
#line 1997 "parser.cpp"
    break;

  case 100: /* p_mkusr: T_G_USR T_IGUAL T_ID  */
#line 282 "parser.y"
                                 { user = std::string((yyvsp[0].val)); }
#line 2003 "parser.cpp"
    break;

  case 101: /* p_mkusr: T_G_PASS T_IGUAL T_ID  */
#line 283 "parser.y"
                                    { pass = std::string((yyvsp[0].val));}
#line 2009 "parser.cpp"
    break;

  case 102: /* p_mkusr: T_G_GRP T_IGUAL T_ID  */
#line 284 "parser.y"
                                   { grp = std::string((yyvsp[0].val)); }
#line 2015 "parser.cpp"
    break;

  case 103: /* rmusr: T_RMUSR T_G_USR T_ID  */
#line 287 "parser.y"
                             {
    user = std::string((yyvsp[0].val));
    Rmusr rmusr(user);
    rmusr.ejecutarComando();
    limpiarVariables();
}
#line 2026 "parser.cpp"
    break;

  case 104: /* mkfile: T_MKFILE lp_mkfile  */
#line 297 "parser.y"
                              {
    Mkfile mkfile(path, r, size, cont);
    mkfile.ejecutarComando();
    limpiarVariables();
}
#line 2036 "parser.cpp"
    break;

  case 107: /* p_mkfile: T_G_PATH T_IGUAL T_CADENA  */
#line 306 "parser.y"
                                      { path = std::string((yyvsp[0].val));}
#line 2042 "parser.cpp"
    break;

  case 108: /* p_mkfile: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 307 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2048 "parser.cpp"
    break;

  case 109: /* p_mkfile: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 308 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 2054 "parser.cpp"
    break;

  case 110: /* p_mkfile: T_G_R  */
#line 309 "parser.y"
                    { r = "1";}
#line 2060 "parser.cpp"
    break;

  case 111: /* p_mkfile: T_G_S T_IGUAL T_NUMEROP  */
#line 310 "parser.y"
                                      { size = std::string((yyvsp[0].val)); }
#line 2066 "parser.cpp"
    break;

  case 112: /* p_mkfile: T_G_CONT T_IGUAL T_CADENA  */
#line 311 "parser.y"
                                        { cont = std::string((yyvsp[0].val));}
#line 2072 "parser.cpp"
    break;

  case 113: /* p_mkfile: T_G_CONT T_IGUAL T_RUTA T_ARCHIVO  */
#line 312 "parser.y"
                                                { cont = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2078 "parser.cpp"
    break;

  case 114: /* p_mkfile: T_G_CONT T_IGUAL T_ARCHIVO  */
#line 313 "parser.y"
                                         { cont = std::string((yyvsp[0].val)); }
#line 2084 "parser.cpp"
    break;

  case 115: /* cat: T_CAT lp_cat  */
#line 316 "parser.y"
                    {
    Cat cat(nFile, paths);
    cat.ejecutarComando();
    limpiarVariables();
}
#line 2094 "parser.cpp"
    break;

  case 118: /* p_cat: T_G_FILE T_NUMEROP T_IGUAL T_CADENA  */
#line 325 "parser.y"
                                            { paths.push_back(std::string((yyvsp[0].val)));
 std::string arch = std::string((yyvsp[-3].val)) + std::string((yyvsp[-2].val)); nFile.push_back(arch);}
#line 2101 "parser.cpp"
    break;

  case 119: /* p_cat: T_G_FILE T_NUMEROP T_IGUAL T_RUTA T_ARCHIVO  */
#line 327 "parser.y"
                                                      { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));
        std::string arch = std::string((yyvsp[-4].val)) + std::string((yyvsp[-3].val)); nFile.push_back(arch);
        paths.push_back(path);}
#line 2109 "parser.cpp"
    break;

  case 120: /* p_cat: T_G_FILE T_NUMEROP T_IGUAL T_ARCHIVO  */
#line 330 "parser.y"
                                               { path = std::string((yyvsp[0].val)); 
        paths.push_back(path);
        std::string arch = std::string((yyvsp[-3].val)) + std::string((yyvsp[-2].val)); nFile.push_back(arch);}
#line 2117 "parser.cpp"
    break;

  case 121: /* remove: T_REMOVE lp_remove  */
#line 335 "parser.y"
                          {
    Remove remove(path);
    remove.ejecutarComando();
    limpiarVariables();
}
#line 2127 "parser.cpp"
    break;

  case 124: /* p_remove: T_G_PATH T_IGUAL T_CADENA  */
#line 344 "parser.y"
                                      { path = std::string((yyvsp[0].val));}
#line 2133 "parser.cpp"
    break;

  case 125: /* p_remove: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 345 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2139 "parser.cpp"
    break;

  case 126: /* p_remove: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 346 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 2145 "parser.cpp"
    break;

  case 127: /* edit: T_EDIT lp_edit  */
#line 349 "parser.y"
                        {
    Edit edit(path, cont);
    edit.ejecutarComando();
    limpiarVariables();
}
#line 2155 "parser.cpp"
    break;

  case 130: /* p_edit: T_G_PATH T_IGUAL T_CADENA  */
#line 358 "parser.y"
                                      { path = std::string((yyvsp[0].val));}
#line 2161 "parser.cpp"
    break;

  case 131: /* p_edit: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 359 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2167 "parser.cpp"
    break;

  case 132: /* p_edit: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 360 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 2173 "parser.cpp"
    break;

  case 133: /* p_edit: T_G_CONT T_IGUAL T_CADENA  */
#line 361 "parser.y"
                                        { cont = std::string((yyvsp[0].val));}
#line 2179 "parser.cpp"
    break;

  case 134: /* p_edit: T_G_CONT T_IGUAL T_RUTA T_ARCHIVO  */
#line 362 "parser.y"
                                                { cont = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2185 "parser.cpp"
    break;

  case 135: /* p_edit: T_G_CONT T_IGUAL T_ARCHIVO  */
#line 363 "parser.y"
                                         { cont = std::string((yyvsp[0].val)); }
#line 2191 "parser.cpp"
    break;

  case 136: /* rename: T_RENAME lp_rename  */
#line 366 "parser.y"
                              {
    Rename rename(path, name);
    rename.ejecutarComando();
    limpiarVariables();
}
#line 2201 "parser.cpp"
    break;

  case 139: /* p_rename: T_G_PATH T_IGUAL T_CADENA  */
#line 375 "parser.y"
                                        { path = std::string((yyvsp[0].val));}
#line 2207 "parser.cpp"
    break;

  case 140: /* p_rename: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 376 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2213 "parser.cpp"
    break;

  case 141: /* p_rename: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 377 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 2219 "parser.cpp"
    break;

  case 142: /* p_rename: T_G_NAME T_IGUAL T_CADENA  */
#line 378 "parser.y"
                                        { name = std::string((yyvsp[0].val));}
#line 2225 "parser.cpp"
    break;

  case 143: /* p_rename: T_G_NAME T_IGUAL T_ARCHIVO  */
#line 379 "parser.y"
                                         { name = std::string((yyvsp[0].val)); }
#line 2231 "parser.cpp"
    break;

  case 144: /* mkdir: T_MKDIR lp_mkdir  */
#line 382 "parser.y"
                           {
    Mkdir mkdir(path, r);
    mkdir.ejecutarComando();
    limpiarVariables();
}
#line 2241 "parser.cpp"
    break;

  case 147: /* p_mkdir: T_G_PATH T_IGUAL T_CADENA  */
#line 391 "parser.y"
                                       { path = std::string((yyvsp[0].val));}
#line 2247 "parser.cpp"
    break;

  case 148: /* p_mkdir: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 392 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2253 "parser.cpp"
    break;

  case 149: /* p_mkdir: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 393 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 2259 "parser.cpp"
    break;

  case 150: /* p_mkdir: T_G_R  */
#line 394 "parser.y"
                    { r = "1";}
#line 2265 "parser.cpp"
    break;

  case 151: /* copy: T_COPY lp_copy  */
#line 397 "parser.y"
                        {
    Copy copy(path, destino);
    copy.ejecutarComando();
    limpiarVariables();
}
#line 2275 "parser.cpp"
    break;

  case 154: /* p_copy: T_G_PATH T_IGUAL T_CADENA  */
#line 406 "parser.y"
                                      { path = std::string((yyvsp[0].val));}
#line 2281 "parser.cpp"
    break;

  case 155: /* p_copy: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 407 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2287 "parser.cpp"
    break;

  case 156: /* p_copy: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 408 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 2293 "parser.cpp"
    break;

  case 157: /* p_copy: T_G_PATH T_IGUAL T_RUTA  */
#line 409 "parser.y"
                                      { path = std::string ((yyvsp[0].val)); }
#line 2299 "parser.cpp"
    break;

  case 158: /* p_copy: T_G_DESTINO T_IGUAL T_CADENA  */
#line 410 "parser.y"
                                           { destino = std::string((yyvsp[0].val));}
#line 2305 "parser.cpp"
    break;

  case 159: /* p_copy: T_G_DESTINO T_IGUAL T_RUTA  */
#line 411 "parser.y"
                                         { destino = std::string ((yyvsp[0].val)); }
#line 2311 "parser.cpp"
    break;

  case 160: /* move: T_MOVE lp_move  */
#line 414 "parser.y"
                        {
    Move move(path, destino);
    move.ejecutarComando();
    limpiarVariables();
}
#line 2321 "parser.cpp"
    break;

  case 163: /* p_move: T_G_PATH T_IGUAL T_CADENA  */
#line 423 "parser.y"
                                      { path = std::string((yyvsp[0].val));}
#line 2327 "parser.cpp"
    break;

  case 164: /* p_move: T_G_PATH T_IGUAL T_RUTA T_ARCHIVO  */
#line 424 "parser.y"
                                                { path = std::string((yyvsp[-1].val)) + std::string((yyvsp[0].val));}
#line 2333 "parser.cpp"
    break;

  case 165: /* p_move: T_G_PATH T_IGUAL T_ARCHIVO  */
#line 425 "parser.y"
                                         { path = std::string((yyvsp[0].val)); }
#line 2339 "parser.cpp"
    break;

  case 166: /* p_move: T_G_PATH T_IGUAL T_RUTA  */
#line 426 "parser.y"
                                      { path = std::string ((yyvsp[0].val)); }
#line 2345 "parser.cpp"
    break;

  case 167: /* p_move: T_G_DESTINO T_IGUAL T_CADENA  */
#line 427 "parser.y"
                                           { destino = std::string((yyvsp[0].val));}
#line 2351 "parser.cpp"
    break;

  case 168: /* p_move: T_G_DESTINO T_IGUAL T_RUTA  */
#line 428 "parser.y"
                                         { destino = std::string ((yyvsp[0].val)); }
#line 2357 "parser.cpp"
    break;

  case 169: /* pause: T_PAUSE  */
#line 431 "parser.y"
               {
    Pausa pausa;
    pausa.ejecutarComando();
}
#line 2366 "parser.cpp"
    break;


#line 2370 "parser.cpp"

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

#line 436 "parser.y"


void yyerror(const char *s) {
    std::cout << "Error parametro no valido "<< s<<std::endl;
};

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
    id = "";
    user = "";
    pass = "";
    grp = "";
    ruta = "";
    r = "";
    cont = "";
    nFile.clear();
    paths.clear();
    nId = "";
    ugo = "";
    p = "";
    destino = "";
    }

