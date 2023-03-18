#include "mkusr.h"

using std::cout, std::endl;

Mkusr::Mkusr(string _user, string _pass, string _grp){
  user = _user;
  pass = _pass;
  grp = _grp;
}

void Mkusr::ejecutarComando(){
  if(particionMontada.size() == 0){
    cout<<"Error, no hay particion montada"<<endl;
    return;
  }
  //se verifica que los parametros obligatorios no esten vacios
  if(user == "" || pass == "" || grp == ""){
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
  if(user.length()>10 || pass.length()>10 || grp.length() > 10){
    cout<<"Error, la longitud de un parametro es mayor a 10 caracteres"<<endl;
    return;
  }
  //ahora realizamos las validaciones para los parametros
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
  for (size_t i = 0; i < 15; i++){
    if(i == 14){
      //vamos al apuntador triple
      break;
    }else if(i == 13){
      //vamos al apuntador doble
      break;
    }else if(i == 12){
      //vamos al apuntador simple
      break;
    }else{
      if(inodo.i_block[i] != -1){
        B_ARCHIVO b_archivo;
        fseek(archivo, sb.s_block_start+(sb.s_block_s*inodo.i_block[i]), SEEK_SET);
        fread(&b_archivo, sizeof(B_ARCHIVO), 1, archivo);
        archivo_usuarios += std::string(b_archivo.b_content, std::strlen(b_archivo.b_content));
        
      }else{
        break;
      }
    } 
  }
  
  //se trabaja con el contenido de archivo_usuarios
  std::stringstream au(archivo_usuarios);
  std::vector<string> parts;

  //separamos el saltos de linea
  string token;
  while (std::getline(au, token, '\n')) {
      parts.push_back(token);
  }

  //ahora separamos por comas
  std::vector<std::vector<string>> usuario_registrado;
  std::vector<string> parts2;
  for (size_t i = 0; i < parts.size(); i++){
    std::stringstream subss(parts[i]);
    while (std::getline(subss, token, ',')) {
      parts2.push_back(token);
    }
    usuario_registrado.push_back(parts2);
    parts2.clear();
  }
  //buscamos si el grupo ya existe
  bool encontrado = false, encontrado2 = false;
  int contador_usuarios= 1;
  for (const auto& parts_ : usuario_registrado) {
    
    if(parts_[0] != "0"){
      if(parts_[1] == "G"){
        if(grp == parts_[2]){
          encontrado = true;
        }
      }else{
        contador_usuarios++;
        if(user == parts_[3]){
          encontrado2 == true;
        }
      }
    }else{
      if(parts_[1] == "U"){
        contador_usuarios++;
      }
    }
  }
  //en este punto se busca el usuario
  if(!encontrado){
    cout<<"Error, el nombre de grupo no existe"<<endl;
    return;
  }
  if(encontrado2){
    cout<<"Error, el nombre de usuario ya esta registrado"<<endl;
    return;
  }

  //se agrega el nuevo grupo a la variable a escribir en bloque
  string nueva = std::to_string(contador_usuarios);
  nueva+= ",U,";
  nueva+= grp;
  nueva+= ",";
  nueva+= user;
  nueva+= ",";
  nueva+= pass;
  nueva+= "\n";
  //se ve en el inodo del archivo 
  for (size_t i = 0; i < 16; i++){
  
    if(inodo.i_block[i] != -1){
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
        if(inodo.i_block[i+1] == -1){
          B_ARCHIVO b_archivo;
          fseek(archivo, sb.s_block_start+(sb.s_block_s*inodo.i_block[i]), SEEK_SET);
          fread(&b_archivo, sizeof(B_ARCHIVO), 1, archivo);
          if(std::strlen(b_archivo.b_content) + nueva.length() >= 64){
            //creamos un nuevo bloque
            B_ARCHIVO b_archivo_nuevo;
            fseek(archivo, sb.s_block_start+(sizeof(b_archivo_nuevo)*sb.s_first_blo), SEEK_SET);
            strcpy(b_archivo_nuevo.b_content, nueva.c_str());
            fwrite(&b_archivo_nuevo, sizeof(b_archivo_nuevo), 1, archivo);
            sb.s_free_blocks_count--;
            //escribimos en el bm de bloques
            fseek(archivo, sb.s_bm_block_start+sb.s_first_blo, SEEK_SET);
            char uno = '1';
            fwrite(&uno, 1, 1, archivo);
            //reescribimos el inodo
            inodo.i_block[i+1] = sb.s_first_blo;
            inodo.i_s = nueva.length();
            fseek(archivo, sb.s_inode_start+(sb.s_inode_s), SEEK_SET);
            fwrite(&inodo, sizeof(inodo), 1, archivo);
            sb.s_first_blo++;
            //reescribimos el superbloque
            fseek(archivo, usuario_logueado.loginItem.part.part_start, SEEK_SET);
            fwrite(&sb, sizeof(SUPERBLOQUE),1,archivo);
            cout<<"Usuario registrado con exito "<<endl;
            break;

          }else{
            archivo_usuarios += nueva;
            strcpy(b_archivo.b_content, archivo_usuarios.c_str());
            //actualizamos el b_archivo en el bloque y el inodo
            fseek(archivo, sb.s_block_start+(sb.s_block_s*inodo.i_block[i]), SEEK_SET);
            fwrite(&b_archivo, sizeof(b_archivo), 1, archivo);
            inodo.i_s += nueva.length();
            fseek(archivo, sb.s_inode_start+(sb.s_inode_s), SEEK_SET);
            fwrite(&inodo, sizeof(inodo), 1, archivo);
            cout<<"Usuario registrado con exito "<<endl;
            break;
          }
        }
      }

    }else{
      break;
    }
  }
  
}