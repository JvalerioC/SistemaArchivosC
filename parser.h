/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_MKDISK = 258,                /* T_MKDISK  */
    T_RMDISK = 259,                /* T_RMDISK  */
    T_FDISK = 260,                 /* T_FDISK  */
    T_MOUNT = 261,                 /* T_MOUNT  */
    T_UNMOUNT = 262,               /* T_UNMOUNT  */
    T_MKFS = 263,                  /* T_MKFS  */
    T_LOGIN = 264,                 /* T_LOGIN  */
    T_LOGOUT = 265,                /* T_LOGOUT  */
    T_MKGRP = 266,                 /* T_MKGRP  */
    T_RMGRP = 267,                 /* T_RMGRP  */
    T_MKUSR = 268,                 /* T_MKUSR  */
    T_RMUSR = 269,                 /* T_RMUSR  */
    T_CHMOD = 270,                 /* T_CHMOD  */
    T_MKFILE = 271,                /* T_MKFILE  */
    T_CAT = 272,                   /* T_CAT  */
    T_REMOVE = 273,                /* T_REMOVE  */
    T_EDIT = 274,                  /* T_EDIT  */
    T_RENAME = 275,                /* T_RENAME  */
    T_MKDIR = 276,                 /* T_MKDIR  */
    T_COPY = 277,                  /* T_COPY  */
    T_MOVE = 278,                  /* T_MOVE  */
    T_FIND = 279,                  /* T_FIND  */
    T_CHOWN = 280,                 /* T_CHOWN  */
    T_CHGRP = 281,                 /* T_CHGRP  */
    T_PAUSE = 282,                 /* T_PAUSE  */
    T_RECOVERY = 283,              /* T_RECOVERY  */
    T_LOSS = 284,                  /* T_LOSS  */
    T_EXEC = 285,                  /* T_EXEC  */
    T_REP = 286,                   /* T_REP  */
    T_EXIT = 287,                  /* T_EXIT  */
    T_G_NAME = 288,                /* T_G_NAME  */
    T_G_ID = 289,                  /* T_G_ID  */
    T_G_PATH = 290,                /* T_G_PATH  */
    T_G_RUTA = 291,                /* T_G_RUTA  */
    T_G_DELETE = 292,              /* T_G_DELETE  */
    T_G_ADD = 293,                 /* T_G_ADD  */
    T_G_PASS = 294,                /* T_G_PASS  */
    T_G_USR = 295,                 /* T_G_USR  */
    T_G_GRP = 296,                 /* T_G_GRP  */
    T_G_UGO = 297,                 /* T_G_UGO  */
    T_G_TYPE = 298,                /* T_G_TYPE  */
    T_G_CONT = 299,                /* T_G_CONT  */
    T_G_FILE = 300,                /* T_G_FILE  */
    T_G_DESTINO = 301,             /* T_G_DESTINO  */
    T_G_FS = 302,                  /* T_G_FS  */
    T_G_S = 303,                   /* T_G_S  */
    T_G_F = 304,                   /* T_G_F  */
    T_G_U = 305,                   /* T_G_U  */
    T_G_T = 306,                   /* T_G_T  */
    T_G_R = 307,                   /* T_G_R  */
    T_G_P = 308,                   /* T_G_P  */
    T_FLECHA = 309,                /* T_FLECHA  */
    T_RUTA = 310,                  /* T_RUTA  */
    T_IGUAL = 311,                 /* T_IGUAL  */
    T_NUMERON = 312,               /* T_NUMERON  */
    T_NUMEROP = 313,               /* T_NUMEROP  */
    T_DIGITO = 314,                /* T_DIGITO  */
    T_CADENA = 315,                /* T_CADENA  */
    T_ARCHIVO = 316,               /* T_ARCHIVO  */
    T_ID = 317                     /* T_ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    char val[200];

#line 130 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
