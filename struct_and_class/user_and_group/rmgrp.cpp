#include "rmgrp.h"

using std::cout, std::endl;

Rmgrp::Rmgrp(string _name){
  name = _name;
}

void Rmgrp::ejecutarComando(){
  if(particionMontada.size() == 0){
    cout<<"Error, no hay particion montada"<<endl;
    return;
  }
  //se verifica que los parametros obligatorios no esten vacios
  if(name == "" ){
    cout<<"Error, parametro obligatorio vacio"<<endl;
    return;
  }
  if(!usuario_logueado.iniciado){
    cout<<"Error, no hay una sesion activa"<<endl;
    return;
  }
  if(usuario_logueado.is_admin == 0){
    cout<<"Error, el usuario no puede ejecutar este comando"<<endl;
    return;
  }
  //ahora buscamos en el archivo de user que no exista un grupo con ese nombre
  FILE *archivo = fopen(usuario_logueado.loginItem.path.c_str(), "r+b");
  MBR mbr;
  fread(&mbr, sizeof(MBR), 1, archivo);
  fseek(archivo, usuario_logueado.loginItem.part.part_start, SEEK_SET);

  //se recupera el superbloque
  SUPERBLOQUE sb;
  fread(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  //se lee el inodo del archivo
  fseek(archivo, sb.s_inode_start+(sb.s_inode_s), SEEK_SET);
  B_INODO inodo;
  fread(&inodo, sizeof(B_INODO), 1, archivo);

  //recuperamos el contenido del archivo
  string archivo_usuarios = "";
  bool encontrado = false;
  int posicion_bloque = 0;  
  B_ARCHIVO b_archivo;
  for (size_t i = 0; i < 16; i++){
    if(i == 15){
      //vamos al apuntador triple
      break;
    }else if(i == 14){
      //vamos al apuntador doble
      break;
    }else if(i == 13){
      //vamos al apuntador simple
      break;
    }else{
      if(inodo.i_block[i] != -1){
        fseek(archivo, sb.s_block_start+(sb.s_block_s*inodo.i_block[i]), SEEK_SET);
        fread(&b_archivo, sizeof(B_ARCHIVO), 1, archivo);
        archivo_usuarios = std::string(b_archivo.b_content, std::strlen(b_archivo.b_content));
        std::size_t pos = archivo_usuarios.find("G,"+name);
        if(pos != string::npos){
          b_archivo.b_content[pos-2] = '0';
          posicion_bloque = inodo.i_block[i];
          encontrado = true;
          break; 
        }
        
      }else{
        break;
      }
    } 
  }
  if(!encontrado){
    cout<<"Error, el grupo a eliminar no esta registrado"<<endl;
    return;
  }
  //actualizamos el bloque de contenido
  fseek(archivo, sb.s_block_start+(sb.s_block_s*posicion_bloque), SEEK_SET);
  fwrite(&b_archivo, sizeof(b_archivo), 1, archivo);
  fclose(archivo);
  cout<<"Grupo eliminado con exito"<<endl;
  
}