#include "cat.h"

using std::cout, std::endl;

Cat::Cat(vector<string> _paths, vector<string> _files){
  paths = _paths;
  files = _files;
}

void Cat::ejecutarComando(){
  cout<<"entro al cat"<<endl;
}