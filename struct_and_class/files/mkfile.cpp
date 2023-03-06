#include "mkfile.h"

using std::cout, std::endl;

Mkfile::Mkfile(string _path, string _r, string _size, string _cont){
  path = _path;
  r = _r;
  size = _size;
  cont = _cont;
}

void Mkfile::ejecutarComando(){
  cout<<"entro al mkfile"<<endl;
  
}