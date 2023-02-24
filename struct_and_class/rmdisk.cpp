#include "rmdisk.h"
#include "method_and_function.h"

using std::cout, std::endl;

Rmdisk::Rmdisk(string _path){
  path = _path;
}

void Rmdisk::ejecutarComando(){
  string path1 = replaceQuotesMarks(path);
  path = path1;
  bool flag = fileExist(path);
  if(flag){
    eliminarDisco();
  }else{
    cout<<"Error, el disco no existe "<<endl;
  }
}

void Rmdisk::eliminarDisco(){
  if (remove(path.c_str()) != 0) {
    cout << "No se pudo eliminar el disco." << endl;
  } else {
    cout << "El disco se ha eliminado existosamente." << endl;
  }
}