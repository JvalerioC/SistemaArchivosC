#include "move.h"

using std::cout, std::endl;

Move::Move(string _path, string _destino){
  path = _path;
  destino = _destino;
}

void Move::ejecutarComando(){
  cout<<"entro al move"<<endl;
  
}