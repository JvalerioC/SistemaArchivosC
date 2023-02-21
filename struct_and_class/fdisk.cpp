#include "fdisk.h"

using std::cout, std::endl;

Fdisk::Fdisk(string _size, string _path, string _name, string _unit, string _fit, string _type){

    size = _size;
    path = _path;
    name = _name;
    unit = _unit;
    fit = _fit;
    tipo = _type;
};

void Fdisk::ejecutarComando(){
  
  cout<<"Particion creada exitosamente"<<endl;
}