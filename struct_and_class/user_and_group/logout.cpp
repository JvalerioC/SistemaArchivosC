#include "logout.h"

using std::cout, std::endl;

Logout::Logout(){
  
}

void Logout::ejecutarComando(){
  if(usuario_logueado.iniciado){
    usuario_logueado.iniciado = false;
    usuario_logueado.is_admin = 0;
    usuario_logueado.user = "";
    cout<<"Cierre de sesion exitosa"<<endl;
  }else{
    cout<<"Error, no hay una sesion iniciada"<<endl;
  }
  
}