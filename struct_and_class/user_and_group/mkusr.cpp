#include "mkusr.h"

using std::cout, std::endl;

Mkusr::Mkusr(string _user, string _pass, string _grp){
  user = _user;
  pass = _pass;
  grp = _grp;
}

void Mkusr::ejecutarComando(){
  cout<<"entro al mkusr"<<endl;
  
}