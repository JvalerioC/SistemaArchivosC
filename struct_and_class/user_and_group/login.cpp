#include "login.h"
#include <sstream>

using std::cout, std::endl;

Login::Login(string _user, string _pass, string _id){
  user = _user;
  pass = _pass;
  id = _id;
}

void Login::ejecutarComando(){
  if(particionMontada.size() == 0){
    cout<<"Error, no hay particion montada"<<endl;
    return;
  }
  //se verifica que los parametros obligatorios no esten vacios
  if(user == "" || pass == "" || id == ""){
    cout<<"Error, parametro obligatorio vacio"<<endl;
    return;
  }
  //se verifica que no haya una sesion iniciada
  if(usuario_logueado.iniciado){
    cout<<"Error, ya hay un usuario logueado"<<endl;
    return;
  }
  //buscamos el id en las particiones montadas
  bool flag = false;
  itemMount item;
  for (size_t i = 0; i < particionMontada.size(); i++){
    if(particionMontada[i].id.compare(id) == 0){
      flag = true;
      item = particionMontada[i];
    }
  }
  if(!flag){
    cout<<"Error, el id de la particion montada no existe"<<endl;
    return;
  }
  //vamos a verificar si es el root
  if(user.compare("root")==0 && pass.compare("123") == 0){
    cout<<"Inicio de sesion exitoso, Bienvenido root"<<endl;
    usuario_logueado.iniciado = true;
    usuario_logueado.is_admin = 1;
    usuario_logueado.user = "root";
    usuario_logueado.loginItem = item;
    return;
  }else{
    //si no es el root se va a buscar al inodo de users.txt de la particion montada
    iniciarSesion(item);
  }

}

void Login::iniciarSesion(itemMount _item){
  //como ya se sabe que el inodo del archivo user es el 2 entonces vamos directo ahi
  FILE *archivo = fopen(_item.path.c_str(), "r+b");
  MBR mbr;
  fread(&mbr, sizeof(MBR), 1, archivo);
  fseek(archivo, _item.part.part_start, SEEK_SET);
  //se recupera el superbloque
  SUPERBLOQUE sb;
  fread(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  //leemos el inodo del archivo
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
  fclose(archivo);
  //aqui ya trabajamos con el contenido de archivo_usuarios
  
  std::stringstream au(archivo_usuarios);
  std::vector<string> parts;

  //separamos el saltos de linea
  string token;
  while (std::getline(au, token, '\n')) {
      parts.push_back(token);
  }

  // Imprimir las partes resultantes
  /* for (const auto& part : parts) {
      std::cout << part << std::endl;
  } */
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
  //imprimir las subpartes de las partes :v
  bool encontrado = false;
  for (const auto& parts_ : usuario_registrado) {
    /* for (const auto& part : parts_) {
      std::cout << part << std::endl;
    } */
    if(parts_[0] != "0"){
      if(parts_[1] == "U"){
        if(user == parts_[3] && pass == parts_[4]){
          encontrado = true;
        }
      }
    }
  }
  //en este punto se busca el usuario
  if(encontrado){
    cout<<"Inicio de Sesion Exitoso, Bienvenido "<<endl;
    usuario_logueado.iniciado = true;
    usuario_logueado.is_admin = 0;
    usuario_logueado.user = user;
    usuario_logueado.loginItem = _item;
  }else{
    cout<<"Error, el usuario no existe o contrasenia incorrecta"<<endl;
    
  }

}

