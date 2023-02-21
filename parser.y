%{
#include <iostream>
#include <cstdio>
#include <string>
#include "lexer.h"
#include "./struct_and_class/mkdisk.h"
#include "./struct_and_class/rep.h"
#include "./struct_and_class/execute.h"
#include "./struct_and_class/fdisk.h"

extern char *yytext;

int yylex(void);
void yyerror(const char *);
//variables para el manejo de parametros
void limpiarVariables();
std::string size, fit, unit, path, t, borrar, name, add_, nId, id, tipo, fs, ruta, user, pass, grp, ugo, r, cont, nFile, p, destino;

%}
%defines "parser.h"
%output "parser.cpp"

%union{
    char val[200];
}

%token<val> T_MKDISK T_RMDISK T_FDISK T_MOUNT T_UNMOUNT T_MKFS
%token<val> T_LOGIN T_LOGOUT T_MKGRP T_RMGRP T_MKUSR T_RMUSR
%token<val> T_CHMOD T_MKFILE T_CAT T_REMOVE T_EDIT T_RENAME T_MKDIR 
%token<val> T_COPY T_MOVE T_FIND T_CHOWN T_CHGRP T_PAUSE
%token<val> T_RECOVERY T_LOSS T_EXEC T_REP T_EXIT
%token<val> T_G_NAME T_G_ID T_G_PATH T_G_RUTA T_G_DELETE T_G_ADD T_G_PASS
%token<val> T_G_USR T_G_GRP T_G_UGO T_G_TYPE T_G_CONT T_G_FILE T_G_DESTINO
%token<val> T_G_FS T_G_S T_G_F T_G_U T_G_T T_G_R T_G_P T_FLECHA T_RUTA T_IGUAL
%token<val> T_NUMERON T_NUMEROP T_DIGITO 
%token<val> T_CADENA
%token<val> T_ARCHIVO T_ID

%start inicio

%%

inicio: mkdisk      {  }
        | execute   {  }
        | rep       {  }
        | fdisk     {  }
        /*| rmdisk    {  }
        | mount     {  }
        | unmount   {  }
        | mkfs      {  }
        | login     {  }
        | logout    {  }
        | mkgrp     {  }
        | rmgrp     {  }
        | mkusr     {  }
        | rmust     {  }
        | chmod     {  }
        | mkfile    {  }
        | cat       {  }
        | remove    {  }
        | edit      {  }
        | rename    {  }
        | mkdir     {  }
        | copy      {  }
        | move      {  }
        | find      {  }
        | chown     {  }
        | chgrp     {  }
        | pause     {  }
        | loss      {  }*/
;

// analisis para el comando mkdisk
mkdisk: T_MKDISK lp_mkdisk   { 
    Mkdisk mkdisk(size, fit, unit, path);
    //std::cout<<size<<fit<<unit<<path<<std::endl;
    mkdisk.ejecutarComando();
    limpiarVariables();
};

lp_mkdisk:   lp_mkdisk p_mkdisk
            | p_mkdisk ;

p_mkdisk:   T_G_S T_IGUAL T_NUMEROP { size = std::string($3);  }
            | T_G_F T_IGUAL T_ID { fit = std::string($3);}
            | T_G_U T_IGUAL T_ID { unit = std::string($3);}
            | T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); };

// analisis para el comando rmdisk

// analisis para el comando execute
execute:    T_EXEC lp_execute {
    Execute execute(path);
    execute.ejecutarComando();
    limpiarVariables();
}

lp_execute: p_execute;
            
p_execute:  T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); };


// analisis para el comando fdisk
fdisk:      T_FDISK lp_fdisk {
    Fdisk fdisk(size, unit, path, name, fit, tipo);
    fdisk.ejecutarComando();
    limpiarVariables();
} 

lp_fdisk:   lp_fdisk p_fdisk
            | p_fdisk ;

p_fdisk:    T_G_S T_IGUAL T_NUMEROP { size = std::string($3); }
            | T_G_F T_IGUAL T_ID { fit = std::string($3);}
            | T_G_NAME T_IGUAL T_ID { name = std::string($3);}
            | T_G_U T_IGUAL T_ID { unit = std::string($3);}
            | T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); };
            | T_G_TYPE T_IGUAL T_ID { tipo = std::string($3); };

// analisis para el comando rep
rep: T_REP {
    Rep rep; rep.ejecutarComando(); 
}


%%

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
    add_ = "";
    nId = "";
    id = "";
    tipo = "";
    fs = "";
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

