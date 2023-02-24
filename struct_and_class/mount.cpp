#include "mount.h"
#include "method_and_function.h"

using std::string, std::cout, std::endl;

Mount::Mount(string _name, string _path){
  name = _name;
  path = replaceQuotesMarks(_path);
}

void Mount::ejecutarComando(){
  if(path == "" || name == ""){
    cout<<"Error, parametro obligatorio vacio"<<endl;
    return;
  }
  
}
