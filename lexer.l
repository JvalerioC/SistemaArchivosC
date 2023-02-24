%{
#include <iostream>
#include <cstring>
#include <string>
#include "parser.h"
using namespace std;
%}

%option noyywrap
%option nounput
DIGITO      [0-9]
NUMEROP     {DIGITO}+
NUMERON     -{DIGITO}+
ARCHIVO     {ID}[.]{ID}
CADENA      ([\"][^\"]*[\"])
ID          [_a-zA-Z0-9]+
RUTA        [/]({ID}[/])*
COMENTARIO  [#].*

%%


"mkdisk"    { strcpy(yylval.val, yytext); return T_MKDISK; }
"rmdisk"    { strcpy(yylval.val, yytext); return T_RMDISK; }
"fdisk"     { strcpy(yylval.val, yytext); return T_FDISK; }
"mount"     { strcpy(yylval.val, yytext); return T_MOUNT; }
"unmount"   { strcpy(yylval.val, yytext); return T_UNMOUNT; }
"mkfs"      { strcpy(yylval.val, yytext); return T_MKFS; }

"login"     { strcpy(yylval.val, yytext); return T_LOGIN; }
"logout"    { strcpy(yylval.val, yytext); return T_LOGOUT; }
"mkgrp"     { strcpy(yylval.val, yytext); return T_MKGRP; }
"rmgrp"     { strcpy(yylval.val, yytext); return T_RMGRP; }
"mkusr"     { strcpy(yylval.val, yytext); return T_MKUSR; }
"rmusr"     { strcpy(yylval.val, yytext); return T_RMUSR; }

"chmod"     { strcpy(yylval.val, yytext); return T_CHMOD; }
"mkfile"    { strcpy(yylval.val, yytext); return T_MKFILE; }
"cat"       { strcpy(yylval.val, yytext); return T_CAT; }
"remove"    { strcpy(yylval.val, yytext); return T_REMOVE; }
"edit"      { strcpy(yylval.val, yytext); return T_EDIT; }
"rename"    { strcpy(yylval.val, yytext); return T_RENAME; }
"mkdir"     { strcpy(yylval.val, yytext); return T_MKDIR; }
"copy"      { strcpy(yylval.val, yytext); return T_COPY; }
"move"      { strcpy(yylval.val, yytext); return T_MOVE; }
"find"      { strcpy(yylval.val, yytext); return T_FIND; }
"chown"     { strcpy(yylval.val, yytext); return T_CHOWN; }
"chgrp"     { strcpy(yylval.val, yytext); return T_CHGRP; }
"pause"     { strcpy(yylval.val, yytext); return T_PAUSE; }

"recovery"  { strcpy(yylval.val, yytext); return T_RECOVERY; }
"loss"      { strcpy(yylval.val, yytext); return T_LOSS; }
"execute"   { strcpy(yylval.val, yytext); return T_EXEC; }
"rep"       { strcpy(yylval.val, yytext); return T_REP; }
"exit"      { strcpy(yylval.val, yytext); return T_EXIT; }

">name"     { strcpy(yylval.val, yytext); return T_G_NAME; }
">id"       { strcpy(yylval.val, yytext); return T_G_ID; }
">path"     { strcpy(yylval.val, yytext); return T_G_PATH; }
">ruta"     { strcpy(yylval.val, yytext); return T_G_RUTA; }
">delete"   { strcpy(yylval.val, yytext); return T_G_DELETE; }
">add"      { strcpy(yylval.val, yytext); return T_G_ADD; }
">pass"     { strcpy(yylval.val, yytext); return T_G_PASS; }
">usr"      { strcpy(yylval.val, yytext); return T_G_USR; }
">grp"      { strcpy(yylval.val, yytext); return T_G_GRP; }
">ugo"      { strcpy(yylval.val, yytext); return T_G_UGO; }
">type"     { strcpy(yylval.val, yytext); return T_G_TYPE; }
">cont"     { strcpy(yylval.val, yytext); return T_G_CONT; }
">file"     { strcpy(yylval.val, yytext); return T_G_FILE; }
">destino"  { strcpy(yylval.val, yytext); return T_G_DESTINO; }
">fs"       { strcpy(yylval.val, yytext); return T_G_FS; }
">size"     { strcpy(yylval.val, yytext); return T_G_S; }
">fit"      { strcpy(yylval.val, yytext); return T_G_F; }
">unit"     { strcpy(yylval.val, yytext); return T_G_U; }
">t"        { strcpy(yylval.val, yytext); return T_G_T; }
">r"        { strcpy(yylval.val, yytext); return T_G_R; }
">p"        { strcpy(yylval.val, yytext); return T_G_P; }


{NUMEROP}     { strcpy(yylval.val, yytext); return T_NUMEROP; }
{NUMERON}     { strcpy(yylval.val, yytext); return T_NUMERON; }
{ARCHIVO}     { strcpy(yylval.val, yytext); return T_ARCHIVO; }
{CADENA}      { strcpy(yylval.val, yytext); return T_CADENA; }
{ID}          { strcpy(yylval.val, yytext); return T_ID; }
{RUTA}        { strcpy(yylval.val, yytext); return T_RUTA; }
">"           { strcpy(yylval.val, yytext); return T_FLECHA; }
"="           { strcpy(yylval.val, yytext); return T_IGUAL;}
{COMENTARIO}  { strcpy(yylval.val, yytext); return T_COMENTARIO;}
"\n"          {}
[[:blank:]]   {}
.             { cout << "Hay un error en la entrada, token no valido" << endl; }
<<EOF>>       { yyterminate(); }

%%