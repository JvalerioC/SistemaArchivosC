#include "pause.h"

using std::cout, std::endl;

Pausa::Pausa(){

}

void Pausa::ejecutarComando(){
  cout << "Presione Enter para continuar...\n";
  std::getchar();
}