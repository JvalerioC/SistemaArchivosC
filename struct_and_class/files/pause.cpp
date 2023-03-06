#include "pause.h"

using std::cout, std::endl;

Pausa::Pausa(){

}

void Pausa::ejecutarComando(){
  cout << "Presione cualquier tecla para continuar...\n";
  std::getchar();
}