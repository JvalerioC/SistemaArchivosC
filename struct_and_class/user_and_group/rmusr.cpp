#include "rmusr.h"

using std::cout, std::endl;

Rmusr::Rmusr(string _user){
  user = _user;
}

void Rmusr::ejecutarComando(){
  if(particionMontada.size() == 0){
    cout<<"Error, no hay particion montada"<<endl;
    return;
  }
  //se verifica que los parametros obligatorios no esten vacios
  if(user == "" ){
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
  //ahora buscamos en el archivo de user 
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
        //en el contenido del bloque se busca la posicion de l usuario
        std::size_t pos = archivo_usuarios.find(user);
        if(pos != string::npos){ 
          posicion_bloque = inodo.i_block[i];
          encontrado = true;
          //ya encontrado buscamos el ultimo salto de linea en el contenido para obtener la posicion del uid y reescribirla
          int pos2 = archivo_usuarios.find_last_of("\n", pos);
          if (pos2 != std::string::npos) {
            b_archivo.b_content[pos2+1] = '0';
          }else{
            b_archivo.b_content[0] = '0';
          }
          break;
        }
        
      }else{
        break;
      }
    } 
  }
  if(!encontrado){
    cout<<"Error, el usuario a eliminar no esta registrado"<<endl;
    return;
  }
  //actualizamos el bloque de contenido
  fseek(archivo, sb.s_block_start+(sb.s_block_s*posicion_bloque), SEEK_SET);
  fwrite(&b_archivo, sizeof(b_archivo), 1, archivo);
  fclose(archivo);
  cout<<"Usuario eliminado con exito"<<endl;
  
}