%{
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
        | login     {  }
        | logout    {  }
        | mkgrp     {  }
        | rmgrp     {  }
        | mkusr     {  }
        | rmusr     {  }
        //| chmod     {  }
        | mkfile    {  }
        | cat       {  }
        | remove    {  }
        | edit      {  }
        | rename    {  }
        | mkdir     {  }
        | copy      {  }
        | move      {  }
        //| find      {  }
        //| chown     {  }
        //| chgrp     {  }
        | pause     {  }
        
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
        | T_G_RUTA T_IGUAL T_RUTA T_ARCHIVO { ruta = std::string($3) + std::string($4);} 

// los comentarios solo se imprimen
comentario: T_COMENTARIO { /*std::cout<<std::string($1)<<std::endl;*/};

//-------usuario  y grupos

//analisis para comando login
login:  T_LOGIN lp_login{
    Login login(user, pass, id);
    login.ejecutarComando();
    limpiarVariables();

};

lp_login:   lp_login p_login
            | p_login;

p_login:    T_G_USR T_IGUAL T_NUMEROP { user = std::string($3); }
            | T_G_USR T_IGUAL T_ID { user = std::string($3); }
            | T_G_PASS T_IGUAL T_NUMEROP { pass = std::string($3); }
            | T_G_PASS T_IGUAL T_ID { pass = std::string($3);}
            | T_G_ID T_IGUAL T_ID { id = std::string($3); }

//analisis para el comando logout
logout:     T_LOGOUT {
    Logout lout;
    lout.ejecutarComando();
};

//analisis para el comando mkgrp
mkgrp:  T_MKGRP T_G_NAME T_ID {
    id = std::string($3);
    Mkgrp mkgrp(id);
    mkgrp.ejecutarComando();
    limpiarVariables();
};

//analisis para el comando 
rmgrp:  T_RMGRP T_G_NAME T_ID{
    id = std::string($3);
    Rmgrp rmgrp(id);
    rmgrp.ejecutarComando();
    limpiarVariables();
};

//analisis para el comando mkusr
mkusr:  T_MKUSR lp_mkusr{
    Mkusr mkusr(user, pass, grp);
    mkusr.ejecutarComando();
    limpiarVariables();
};

lp_mkusr:   lp_mkusr p_mkusr
            | p_mkusr;

p_mkusr:    T_G_USR T_IGUAL T_ID { user = std::string($3); }
            | T_G_PASS T_IGUAL T_ID { pass = std::string($3);}
            | T_G_GRP T_IGUAL T_ID { grp = std::string($3); };

//analisis para el comando rmusr
rmusr:  T_RMUSR T_G_USR T_ID {
    user = std::string($3);
    Rmusr rmusr(user);
    rmusr.ejecutarComando();
    limpiarVariables();
};

//----------archivos y carpetas

//analisis para el comando mkfile
mkfile:     T_MKFILE lp_mkfile{
    Mkfile mkfile(path, r, size, cont);
    mkfile.ejecutarComando();
    limpiarVariables();
};

lp_mkfile:  lp_mkfile p_mkfile
            | p_mkfile;

p_mkfile:   T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_R { r = "1";}
            | T_G_S T_IGUAL T_NUMEROP { size = std::string($3); }
            | T_G_CONT T_IGUAL T_CADENA { cont = std::string($3);}
            | T_G_CONT T_IGUAL T_RUTA T_ARCHIVO { cont = std::string($3) + std::string($4);}
            | T_G_CONT T_IGUAL T_ARCHIVO { cont = std::string($3); };

//analisis para el comando cat
cat:    T_CAT lp_cat{
    Cat cat(nFile, paths);
    cat.ejecutarComando();
    limpiarVariables();
};

lp_cat: lp_cat p_cat
        | p_cat;

p_cat:  T_G_FILE T_NUMEROP T_IGUAL T_CADENA { paths.push_back(std::string($4));
 std::string arch = std::string($1) + std::string($2); nFile.push_back(arch);}
        | T_G_FILE T_NUMEROP T_IGUAL T_RUTA T_ARCHIVO { path = std::string($4) + std::string($5);
        std::string arch = std::string($1) + std::string($2); nFile.push_back(arch);
        paths.push_back(path);}
        | T_G_FILE T_NUMEROP T_IGUAL T_ARCHIVO { path = std::string($4); 
        paths.push_back(path);
        std::string arch = std::string($1) + std::string($2); nFile.push_back(arch);};

//analisis para el comando remove
remove: T_REMOVE lp_remove{
    Remove remove(path);
    remove.ejecutarComando();
    limpiarVariables();
};

lp_remove:  lp_remove p_remove
            | p_remove;

p_remove:   T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); };

//analisis para el comando edit
edit:     T_EDIT lp_edit{
    Edit edit(path, cont);
    edit.ejecutarComando();
    limpiarVariables();
};

lp_edit:    lp_edit p_edit
            | p_edit;

p_edit:     T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_CONT T_IGUAL T_CADENA { cont = std::string($3);}
            | T_G_CONT T_IGUAL T_RUTA T_ARCHIVO { cont = std::string($3) + std::string($4);}
            | T_G_CONT T_IGUAL T_ARCHIVO { cont = std::string($3); };

//analisis para el comando rename
rename:     T_RENAME lp_rename{
    Rename rename(path, name);
    rename.ejecutarComando();
    limpiarVariables();
};

lp_rename:    lp_rename p_rename
            | p_rename;

p_rename:     T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_NAME T_IGUAL T_CADENA { name = std::string($3);}
            | T_G_NAME T_IGUAL T_ARCHIVO { name = std::string($3); };

//analisis para el comando mkdir
mkdir:     T_MKDIR lp_mkdir{
    Mkdir mkdir(path, r);
    mkdir.ejecutarComando();
    limpiarVariables();
};

lp_mkdir:    lp_mkdir p_mkdir
            | p_mkdir;

p_mkdir:     T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_R { r = "1";};

//analisis para el comando copy
copy:     T_COPY lp_copy{
    Copy copy(path, destino);
    copy.ejecutarComando();
    limpiarVariables();
};

lp_copy:    lp_copy p_copy
            | p_copy;

p_copy:     T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_PATH T_IGUAL T_RUTA { path = std::string ($3); }
            | T_G_DESTINO T_IGUAL T_CADENA { destino = std::string($3);}
            | T_G_DESTINO T_IGUAL T_RUTA { destino = std::string ($3); };

//analisis para el comando move
move:     T_MOVE lp_move{
    Move move(path, destino);
    move.ejecutarComando();
    limpiarVariables();
};

lp_move:    lp_move p_move
            | p_move;

p_move:     T_G_PATH T_IGUAL T_CADENA { path = std::string($3);}
            | T_G_PATH T_IGUAL T_RUTA T_ARCHIVO { path = std::string($3) + std::string($4);}
            | T_G_PATH T_IGUAL T_ARCHIVO { path = std::string($3); }
            | T_G_PATH T_IGUAL T_RUTA { path = std::string ($3); }
            | T_G_DESTINO T_IGUAL T_CADENA { destino = std::string($3);}
            | T_G_DESTINO T_IGUAL T_RUTA { destino = std::string ($3); };

//analisis para el comando pause
pause: T_PAUSE {
    Pausa pausa;
    pausa.ejecutarComando();
}

%%

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

