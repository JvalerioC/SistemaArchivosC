#include "unmount.h"
#include "method_and_function.h"

using std::string, std::cout, std::endl;


Unmount::Unmount(string _id){
  id = _id;
}

void Unmount::ejecutarComando(){
  bool flag = false;
  for(int i = 0; i<particionMontada.size(); i++){
    if (id.compare(particionMontada[i].id) == 0){
      flag = true;
      desmontarParticion(i);
      break;
    }
  }
  if(!flag){
    cout<<"Error, no existe una particion con ese id"<<endl;
    return;
  }
}


void Unmount::desmontarParticion(int _pos){
  //
  FILE *archivo = fopen(particionMontada[_pos].path.c_str(), "r+b");
  MBR mbr;
  fread(&mbr, sizeof(MBR), 1, archivo);
  PARTITION arreglo[4];
  arreglo[0] = mbr.mbr_partition_1;
  arreglo[1] = mbr.mbr_partition_2;
  arreglo[2] = mbr.mbr_partition_3;
  arreglo[3] = mbr.mbr_partition_4;

  for (size_t i = 0; i < 4; i++){
    if(strcmp(arreglo[i].part_name, particionMontada[_pos].part.part_name)==0){
      arreglo[i].part_status = '0';
      cout<<"entra a cambiar el status"<<endl;
    }

  }
  mbr.mbr_partition_1 = arreglo[0];
  mbr.mbr_partition_2 = arreglo[1];
  mbr.mbr_partition_3 = arreglo[2];
  mbr.mbr_partition_4 = arreglo[3];
  //reescribimos el mbr
  fseek(archivo, 0, SEEK_SET);
  fwrite(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);
  particionMontada.erase(particionMontada.begin()+_pos);
  cout<<"Particion desmontada con exito"<<endl;
  imprimirParticionesMontadas();

}
