#include "execute.h"
#include "../lexer.h"
#include "../parser.h"

using std::cout, std::endl;

Execute::Execute(string _path){
  path = _path;
};

void Execute::ejecutarComando(){
  if(path == ""){
    cout<<"Error, parametro obligatorio vacio"<<endl;
    return;
  }
  //validamos la ruta ingresada
  FILE *archivo;
  archivo = fopen(path.c_str(), "rb");

  if (archivo != NULL) {
    fclose(archivo);
  } else {
    cout << "Error en el parametro para la ruta" << endl;
    return;
  }
  ejecutarArchivo();
}

//metodo para ejecutar linea a linea el archivo leido
void Execute::ejecutarArchivo(){
  std::ifstream file;
    file.open(path);
    string line;

    while(getline(file, line)){
        if(line.length() > 0){
          //se imprime la linea
          cout << line << endl;
          //se analiza la linea
          yy_scan_string(line.c_str());
          yyparse();
        }
    }
    file.close();
}