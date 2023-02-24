#include "mkfs.h"
#include "method_and_function.h"

using std::string, std::cout, std::endl;

Mkfs::Mkfs(string _id, string _tipo, string _fs){
  id = _id;
  tipo = _tipo;
  fs = _fs;
}

void Mkfs::ejecutarComando(){
  int a = 0;
}
