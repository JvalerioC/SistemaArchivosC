#include "mkfile.h"
#include <ios>

using std::cout, std::endl;

Mkfile::Mkfile(string _path, string _r, string _size, string _cont){
  path = replaceQuotesMarks(_path);
  r = _r;
  size = _size;
  cont = replaceQuotesMarks(_cont);
}

void Mkfile::ejecutarComando(){
  
  if(!usuario_logueado.iniciado){
    cout<<"Error, no hay una sesion activa"<<endl;
    return;
  }

  if(path == ""){
    cout<<"Error, parametro obligatorio vacio"<<endl;
    return;
  }
  std::vector<string> carpetas;
  string separador = "/";
  size_t pos = 0;
  string pathTemporal = path;
  // se separa la ruta del nombre del archivo
  while ((pos = pathTemporal.find(separador)) != string::npos) {
    string carpeta = pathTemporal.substr(0, pos);
    carpetas.push_back(carpeta);
    pathTemporal.erase(0, pos + separador.length());
  }
  carpetas.erase(carpetas.begin());

  pos = path.find_last_of("/"); 
  string nombre_archivo = path.substr(pos + 1); 

  if(cont != ""){
    createFileW(carpetas, nombre_archivo);
    return;
  }

  if(size != ""){
    createFileS(carpetas, nombre_archivo);
    return;
  }
  createFileB(carpetas, nombre_archivo);

  
}

/* void relationship(B_INODO inodo, int number_inodo, FILE *archivo, SUPERBLOQUE sb, string nombre){
  for (size_t i = 0; i < 16; i++){
      B_CARPETA bc;
    if(inodo.i_block[i] == -1){
      fseek(archivo, sb.s_block_start+(sizeof(B_CARPETA)*(number_inodo)), SEEK_SET);
      inodo.i_block[i] = number_block;
      fseek(archivo, sb.s_inode_start+(sizeof(B_INODO)*(sb.s_firts_ino-1)), SEEK_SET);
      fwrite(&inodo, sizeof(B_INODO), 1, archivo);
      break;
    }else{
      fseek(archivo, sb.s_block_start+(sizeof(B_CARPETA)*(inodo.i_block[i])), SEEK_SET);
      fread(&bc, sizeof(B_CARPETA), 1, archivo);
      for (size_t j = 0; j < 4; j++){
        if(bc.b_content[j].b_inodo == -1){
          bc.b_content[j].b_inodo = number_inodo;
          fseek(archivo, sb.s_block_start+(sizeof(B_CARPETA)*(inodo.i_block[i])), SEEK_SET);
          fwrite(&bc, sizeof(B_CARPETA), 1, archivo);
          break;
        }
      }
    }
  }
  
} */

void Mkfile::createFileW(std::vector<string> _carpetas, string _name_file){
  FILE *archivo = fopen(usuario_logueado.loginItem.path.c_str(), "r+b");
  MBR mbr;
  fread(&mbr, sizeof(MBR), 1, archivo);
  fseek(archivo, usuario_logueado.loginItem.part.part_start, SEEK_SET);

  //se recupera el superbloque
  SUPERBLOQUE sb;
  fread(&sb, sizeof(SUPERBLOQUE), 1, archivo);
  //se lee el inodo del raiz
  fseek(archivo, sb.s_inode_start, SEEK_SET);
  B_INODO inodo, inodo1;
  fread(&inodo, sizeof(B_INODO), 1, archivo);
  inodo1 = inodo;
  int posicion_inodo = sb.s_inode_start;
  for (size_t i = 0; i < _carpetas.size() ; i++){
    inodo = inodo1;
    int e = encontrarInodo(inodo, sb, archivo, _carpetas[i]);
    cout<<" valor de e: "<<e<<endl;
    if(e == 0){
      if(r == "1"){
        cout<<"entramos a crear carpetas"<<endl;
        //hay que crear el inodo de la carpeta
        crearInodo(&sb, archivo, _carpetas[i], inodo, posicion_inodo);
        fseek(archivo, sb.s_inode_start+(sizeof(B_INODO)*(sb.s_firts_ino-1)), SEEK_SET);
        fread(&inodo1, sizeof(B_INODO), 1, archivo);
        posicion_inodo = sb.s_firts_ino-1;
        cout<<"posicion inodo: "<<posicion_inodo<<endl;
      }else{
        cout<<"Error, la carpeta no existe, esta no se puede crear"<<endl;
        return;
      }
    }else{
      //se encontro el inodo de la carpeta
      cout<<"la carpeta si existe"<<endl;
      fseek(archivo, sb.s_inode_start+(sizeof(B_INODO)*(e)), SEEK_SET);
      fread(&inodo1, sizeof(B_INODO), 1, archivo);
      posicion_inodo = e;
    }
  }
  //en este punto ya se tiene el inodo donde se va a crear el archivo, esta en inodo1

  //se lee el contenido del archivo en la pc
  std::ifstream file;
  file.open(cont);
  string content, line;

  while (getline(file, line)) {
      content += line;
      content += '\n'; 
  }
  file.close();

  //se busca en el inodo el primer espacio donde se pueda insertar el archivo
  B_CARPETA bc;
  
  for (size_t i = 0; i < 16; i++){
    //aqui se crea el archivo
    if(inodo1.i_block[i] == -1){
      crearInodoArchivo(&sb, archivo, content, inodo1, posicion_inodo, _name_file);

      cout<<"El archivo ha sido creado. "<<endl;
      break;
      
    }else{ // en este punto se busca si el archivo existe
      fseek(archivo, sb.s_block_start+(sizeof(B_CARPETA)*(inodo1.i_block[i])), SEEK_SET);
      fread(&bc, sizeof(B_CARPETA), 1, archivo);
      for (size_t j = 0; j < 4; j++){
        if(bc.b_content[j].b_inodo != -1){
          if(_name_file.compare(bc.b_content[j].b_name) == 0){
            cout << "Desea sobreescribir el archivo, Y/N ";
            string entrada;
            getline(std::cin, entrada);
            if(entrada == "Y"){
              crearInodoArchivo(&sb, archivo, content, inodo1, posicion_inodo, _name_file);
              cout<<"El archivo ha sido sobreescribido. "<<endl;
              i = 16;
              break;
            }else if(entrada == "N"){
              cout<<"No se sobreescribira el archivo. "<<endl;
              return;
            }else{
              cout<<"La opcion no es valida, no se sobreescribira el archivo"<<endl;
              return;
            }
          }
        }else{
          crearInodoArchivo(&sb, archivo, content, inodo1, posicion_inodo, _name_file);
          cout<<"El archivo ha sido creado. "<<endl;
          i = 16;
          break;
        }
      }
    }
  }
  fclose(archivo);

}

void Mkfile::createFileS(std::vector<string> _carpetas, string _name_file){
  cout<<"b"<<endl;
}

void Mkfile::createFileB(std::vector<string> _carpetas, string _name_file){
  cout<<"c"<<endl;
}