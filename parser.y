%{
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
%token<val> T_CADENA T_COMENTARIO
%token<val> T_ARCHIVO T_ID

%start inicio

%%

inicio: mkdisk      {  }
        | execute   {  }
        | rep       {  }
        | fdisk     {  }
        | rmdisk    {  }
        | mount     {  }
        | unmount   {  }
        | mkfs      {  }
        | loss      {  }
        | comentario{  }
        /*
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
        | comentario{  }*/
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
rmdisk:     T_RMDISK p_rmdisk {
    Rmdisk rmdisk(path);
    rmdisk.ejecutarComando();
    limpiarVariables();
};

p_rmdisk:   T_G_PATH T_IGUAL T_CADENA { path = std::string($3); }
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4); }
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); };

// analisis para el comando fdisk
fdisk:      T_FDISK lp_fdisk {
    Fdisk fdisk(size, unit, name, path, fit, tipo, borrar, add);
    fdisk.ejecutarComando();
    limpiarVariables();
}; 

lp_fdisk:   lp_fdisk p_fdisk
            | p_fdisk ;

p_fdisk:    T_G_S T_IGUAL T_NUMEROP { size = std::string($3); }
            | T_G_F T_IGUAL T_ID { fit = std::string($3);}
            | T_G_NAME T_IGUAL T_ID { name = std::string($3);}
            | T_G_U T_IGUAL T_ID { unit = std::string($3);}
            | T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_TYPE T_IGUAL T_ID { tipo = std::string($3); }
            | T_G_DELETE T_IGUAL T_ID { tipo = std::string($3);}
            | T_G_ADD T_IGUAL T_NUMEROP { add = std::string($3);}
            | T_G_ADD T_IGUAL T_NUMERON { add = std::string($3);};

//analisis para el comando mount
mount:      T_MOUNT lp_mount{
    Mount mount(name, path);
    mount.ejecutarComando();
    limpiarVariables();
};

lp_mount:   lp_mount p_mount
            | p_mount;

p_mount:    T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_NAME T_IGUAL T_ID { name = std::string($3); };

//analisis para el comando unmount
unmount: T_UNMOUNT T_G_ID T_IGUAL T_ID {
    id = std::string($4);
    Unmount unmount(id);
    unmount.ejecutarComando();
    limpiarVariables();
}

//analisis para el comando mkfs
mkfs:       T_MKFS lp_mkfs{
    Mkfs mkfs(id, tipo, fs);
    mkfs.ejecutarComando();
    limpiarVariables();
};

lp_mkfs:       lp_mkfs p_mkfs
            | p_mkfs;

p_mkfs:     T_G_ID T_IGUAL T_ID { id = std::string($3); }
            | T_G_TYPE T_IGUAL T_ID{ tipo = std::string($3);}
            | T_G_FS T_IGUAL T_ID{ tipo = std::string($3); };

//analisis para el comando loss
loss:       T_LOSS T_G_ID T_IGUAL T_ID {
    id = std::string($4);
    Loss loss(id);
    loss.ejecutarComando();
    limpiarVariables();
};

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

// analisis para el comando rep
rep: T_REP lp_rep{
    Rep rep(name, path, id, ruta); 
    rep.ejecutarComando(); 
    limpiarVariables();
}

lp_rep: lp_rep p_rep 
        | p_rep;

p_rep:  T_G_NAME T_IGUAL T_ID { name = std::string($3); }
        | T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
        | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
        | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
        | T_G_ID T_IGUAL T_ID { id = std::string($3); }
        | T_G_RUTA T_IGUAL T_ID {ruta = std::string($3);}
        | T_G_RUTA T_IGUAL T_CADENA {ruta = std::string($3);}; 

comentario: T_COMENTARIO { std::cout<<std::string($1)<<std::endl;}


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
    add = "";
    fs = "";
    id = "";

    nId = "";
    
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

