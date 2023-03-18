#include "method_and_function.h"

//funcion que quita las comillas al inicio y al final de una cadena y la retorna
string replaceQuotesMarks(string cadena){
  // si la cadena no contiene comillas, no es necesario hacer ninguna modificación
  if (cadena.find("\"") == string::npos) {
    return cadena;
  }
  cadena.replace(cadena.find("\""), 1, "");
  cadena.replace(cadena.rfind("\""), 1, "");
  return cadena;
}

//funcion que permite saber si un archivo existe
bool fileExist(string path){
  if (access(path.c_str(), F_OK) != -1) {
    return true;
  }
  return false;
}
//funcion que compara el nombre de cada particion en el disco para saber si este nombre ya esta en uso
string existeParticion(string nombre, MBR mbr){
  if (nombre.compare(mbr.mbr_partition_1.part_name) == 0){
    return string(mbr.mbr_partition_1.part_name);
  }
  if (nombre.compare(mbr.mbr_partition_2.part_name) == 0){
    return string(mbr.mbr_partition_2.part_name);
  }
  if (nombre.compare(mbr.mbr_partition_3.part_name) == 0){
    return string(mbr.mbr_partition_3.part_name);;
  }
  if (nombre.compare(mbr.mbr_partition_4.part_name) == 0){
    return string(mbr.mbr_partition_4.part_name);
  }
  return "";
}

void ordenarTamanio(PARTITION arreglo[]){
  PARTITION temp;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j <3-i; j++){
      if((arreglo[j].part_start > arreglo[j+1].part_start)){
        temp = arreglo[j];
        arreglo[j] = arreglo[j+1];
        arreglo[j+1] = temp;
      } 
    }
  } 
}

void imprimirParticionesMontadas(){
  cout<<"\nParticiones montadas.."<<endl;
  cout<<"----------------------"<<endl;
  for(int i = 0; i<particionMontada.size();i++){
    cout<<particionMontada[i].id<<endl;
  }
}

int encontrarInodo(B_INODO inodo, SUPERBLOQUE sb, FILE *archivo, string name_carpeta){
  bool encontrado = false;
  int posicion = 0;
  if(inodo.i_type != '1'){
    B_CARPETA bc;
    for (size_t j = 0; j < 16; j++){
      if(inodo.i_block[j] == -1){
        break;
      }
      fseek(archivo, sb.s_block_start+(sizeof(bc)*inodo.i_block[j]), SEEK_SET);
      fread(&bc, sizeof(bc), 1, archivo);
      
      for (size_t k = 0; k < 4; k++){
        if(bc.b_content[k].b_inodo == -1){
          break;
        }
        if(name_carpeta.compare(bc.b_content[k].b_name) == 0){
          posicion = bc.b_content[k].b_inodo;
          encontrado = true;
          break;
        }
      }
    }
  }
  if (encontrado){
    return posicion;
  }else{
    return 0;
  }
}

void crearInodo(SUPERBLOQUE* sb, FILE *archivo, string nombre, B_INODO inodo, int posi){
  auto t_actual = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(t_actual);

  //primero asignamos al inodo anterior el bloque y al bloque el nuevo inodo
  B_CARPETA bc1;
  for (size_t j = 0; j < 16; j++){
    if(inodo.i_block[j] == -1){
      //creamos nuevo bloque;
      bc1.b_content[0].b_inodo = (*sb).s_firts_ino;
      strcpy(bc1.b_content[0].b_name, nombre.c_str());
      fseek(archivo, (*sb).s_block_start+(sizeof(bc1)*(*sb).s_first_blo), SEEK_SET);
      fwrite(&bc1, sizeof(bc1), 1, archivo);
      inodo.i_block[j] = (*sb).s_first_blo;
      //reescribimos el inodo
      fseek(archivo, (*sb).s_inode_start+(sizeof(inodo)*posi), SEEK_SET);
      fwrite(&inodo, sizeof(inodo), 1, archivo);
      //escribimos el bloque en el bitmap
      fseek(archivo, (*sb).s_bm_block_start+(*sb).s_first_blo, SEEK_SET);
      char uno = '1';
      fwrite(&uno, 1, 1, archivo);
      (*sb).s_free_blocks_count--;
      (*sb).s_first_blo++;
      break;
    }else{
      fseek(archivo, (*sb).s_block_start+(sizeof(bc1)*inodo.i_block[j]), SEEK_SET);
      fread(&bc1, sizeof(bc1), 1, archivo);
      bool flag = false;
      for (size_t k = 0; k < 4; k++){
        cout<<bc1.b_content[k].b_inodo<<k<<endl;
        if(bc1.b_content[k].b_inodo == -1){
          //insertamos el nuevo inodo
          bc1.b_content[k].b_inodo = (*sb).s_firts_ino;
          strcpy(bc1.b_content[k].b_name, nombre.c_str());
          fseek(archivo, (*sb).s_block_start+(sizeof(bc1)*inodo.i_block[j]), SEEK_SET);
          fwrite(&bc1, sizeof(bc1), 1, archivo);
          flag = true;
          break;
        }
      }
      if(flag){
        break;
      }

    }
    
  }
  cout<<"primer inodo lbre: "<<(*sb).s_firts_ino<<endl;
  cout<<"primer bloque libre: "<<(*sb).s_first_blo<<endl;

  B_INODO bi;
  bi.i_uid = 1;
  bi.i_gid = 1;
  bi.i_s = 0;
  bi.i_atime = t;
  bi.i_ctime = t;
  bi.i_mtime = t;
  bi.i_type = '0';
  bi.i_perm = 664;
 
  B_CARPETA bc; //primer bloque donde se inserta el . y ..
  bc.b_content[0].b_inodo = 0;
  string padre = ".";
  strcpy(bc.b_content[0].b_name, padre.c_str());
  bc.b_content[1].b_inodo = 0;
  padre = "..";
  strcpy(bc.b_content[1].b_name, padre.c_str());

  (*sb).s_free_blocks_count--;
  (*sb).s_free_inodes_count--;
  bi.i_block[0] = (*sb).s_first_blo;
  //se insertar el inodo y bloque de la nueva carpeta
  fseek(archivo, (*sb).s_inode_start+(sizeof(B_INODO)*(*sb).s_firts_ino), SEEK_SET);
  fwrite(&bi, sizeof(bi), 1, archivo);

  fseek(archivo, (*sb).s_block_start+(sizeof(bc)*(*sb).s_first_blo), SEEK_SET);
  fwrite(&bc, sizeof(bc), 1, archivo);
  //se agregan los datos al bitmap de inodos y bloques
  fseek(archivo, (*sb).s_bm_inode_start+(*sb).s_firts_ino, SEEK_SET);
  char uno = '1';
  fwrite(&uno, 1, 1, archivo);
  fseek(archivo, (*sb).s_bm_block_start+(*sb).s_first_blo, SEEK_SET);
  fwrite(&uno, 1,1,archivo);

  //se escribe esto en el archivo, superbloque
  (*sb).s_first_blo++;
  (*sb).s_firts_ino++;
  fseek(archivo, usuario_logueado.loginItem.part.part_start, SEEK_SET);
  fwrite(&(*sb), sizeof(SUPERBLOQUE), 1, archivo);
  cout<<"primer inodo lbre: "<<(*sb).s_firts_ino<<endl;
  cout<<"primer bloque libre: "<<(*sb).s_first_blo<<endl;

}

void crearInodoArchivo(SUPERBLOQUE *sb, FILE *archivo, string contenido, B_INODO inodo, int posi, string nombre){
  auto t_actual = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(t_actual);

  B_CARPETA bc1;
  for (size_t j = 0; j < 16; j++){
    if(inodo.i_block[j] == -1){
      //creamos nuevo bloque;
      bc1.b_content[0].b_inodo = (*sb).s_firts_ino;
      strcpy(bc1.b_content[0].b_name, nombre.c_str());
      fseek(archivo, (*sb).s_block_start+(sizeof(bc1)*(*sb).s_first_blo), SEEK_SET);
      fwrite(&bc1, sizeof(bc1), 1, archivo);
      inodo.i_block[j] = (*sb).s_first_blo;
      //reescribimos el inodo
      fseek(archivo, (*sb).s_inode_start+(sizeof(inodo)*posi), SEEK_SET);
      fwrite(&inodo, sizeof(inodo), 1, archivo);
      //escribimos el bloque en el bitmap
      fseek(archivo, (*sb).s_bm_block_start+(*sb).s_first_blo, SEEK_SET);
      char uno = '1';
      fwrite(&uno, 1, 1, archivo);
      (*sb).s_free_blocks_count--;
      (*sb).s_first_blo++;
      break;
    }else{
      fseek(archivo, (*sb).s_block_start+(sizeof(bc1)*inodo.i_block[j]), SEEK_SET);
      fread(&bc1, sizeof(bc1), 1, archivo);
      bool flag = false;
      for (size_t k = 0; k < 4; k++){
        if(bc1.b_content[k].b_inodo == -1){
          //insertamos el nuevo inodo
          bc1.b_content[k].b_inodo = (*sb).s_firts_ino;
          strcpy(bc1.b_content[k].b_name, nombre.c_str());
          fseek(archivo, (*sb).s_block_start+(sizeof(bc1)*inodo.i_block[j]), SEEK_SET);
          fwrite(&bc1, sizeof(bc1), 1, archivo);
          flag = true;
          break;
        }
      }
      if(flag){
        break;
      }
    }
    
  }
  cout<<"primer inodo lbre: "<<(*sb).s_firts_ino<<endl;
  cout<<"primer bloque libre: "<<(*sb).s_first_blo<<endl;

  B_INODO bi;
  bi.i_uid = 1;
  bi.i_gid = 1;
  bi.i_atime = t;
  bi.i_ctime = t;
  bi.i_mtime = t;
  bi.i_type = '1';
  bi.i_perm = 664;

  int pos = 0;
  int count = 0;
  char uno = '1';
  while (pos < contenido.length()) {
    if (count == 13){
      //debemos ir a los apuntadores
      break;
    }
    string block = contenido.substr(pos, 63);
    B_ARCHIVO b_archivo_nuevo;
    fseek(archivo, (*sb).s_block_start+(sizeof(b_archivo_nuevo)*(*sb).s_first_blo), SEEK_SET);
    strcpy(b_archivo_nuevo.b_content, block.c_str());
    pos += 63;
    b_archivo_nuevo.b_content[block.length()] = '\0';
    fwrite(&b_archivo_nuevo, sizeof(b_archivo_nuevo), 1, archivo);
    bi.i_block[count] = (*sb).s_first_blo;
    //ahora insertamos en el bitmap de bloques
    fseek(archivo, (*sb).s_bm_block_start+bi.i_block[count], SEEK_SET);
    fwrite(&uno, 1, 1, archivo);
    (*sb).s_first_blo++;
    (*sb).s_free_blocks_count--;
    count++;
  }
  //ingresamos el inodo
  fseek(archivo, (*sb).s_inode_start+(sizeof(bi)*(*sb).s_firts_ino), SEEK_SET);
  fwrite(&bi, sizeof(bi), 1, archivo);
  
  //modificado el inodo ahora modificamos el bitmap de inodos;
  fseek(archivo, (*sb).s_bm_inode_start+(*sb).s_firts_ino, SEEK_SET);
  bi.i_s=contenido.length();
  fwrite(&uno, 1, 1, archivo);
  (*sb).s_firts_ino++;
  (*sb).s_free_inodes_count--;
  //actualizamos el superbloque
  fseek(archivo, usuario_logueado.loginItem.part.part_start, SEEK_SET);
  fwrite(&(*sb), sizeof(SUPERBLOQUE), 1, archivo);
  cout<<"primer inodo lbre: "<<(*sb).s_firts_ino<<endl;
  cout<<"primer bloque libre: "<<(*sb).s_first_blo<<endl;
  
}











