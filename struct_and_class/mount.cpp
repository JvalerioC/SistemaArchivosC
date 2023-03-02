#include "mount.h"
#include "method_and_function.h"

using std::string, std::cout, std::endl;

Mount::Mount(string _name, string _path){
  name = _name;
  path = replaceQuotesMarks(_path);
}

void Mount::ejecutarComando(){
  if(path == "" || name == ""){
    cout<<"Error, parametro obligatorio en comando mount vacio"<<endl;
    return;
  }

  bool flag = fileExist(path);
  if (!flag){
    cout<<"Error, el disco no existe"<<endl;
    return;
  }
  FILE *archivo = fopen(path.c_str(), "r+b");
  MBR mbr;
  fread(&mbr, sizeof(MBR), 1, archivo);
  itemMount i_mount;
  int contador_status_disco = 0;
  //convertimos a arreglo de particiones
  PARTITION arreglo[4];
  arreglo[0] = mbr.mbr_partition_1;
  arreglo[1] = mbr.mbr_partition_2;
  arreglo[2] = mbr.mbr_partition_3;
  arreglo[3] = mbr.mbr_partition_4;
  ordenarTamanio(arreglo);
  //verificamos si hay una particion con el nombre ingresado, a la vez que se verifica cuantas particiones hay en este disco ya montadas
  for (int i = 0; i < 4; i++) {
    if (name.compare(arreglo[i].part_name) == 0){
      if(arreglo[i].part_status == '1'){
        cout<<"Error, la particion ya esta montada"<<endl;
        return;
      }
      i_mount.part = arreglo[i];
      arreglo[i].part_status = '1';
    }
    if(arreglo[i].part_status == '1') {contador_status_disco++;};
  }

  if (i_mount.part.part_s == 0){
    cout<<"no existe una particion en el disco con el nombre ingresado."<<endl;
    return;
  }
  //obtener nombre del disco
  size_t pos1 = path.rfind("/");
  size_t pos2 = path.rfind(".");
  string disco = path.substr(pos1+1, pos2-(pos1+1));

  i_mount.mbr = mbr;
  i_mount.path = path;
  i_mount.id = "43"+std::to_string(contador_status_disco)+disco;
  particionMontada.push_back(i_mount);
  cout << "Particion montada exitosamente" << endl;

  //mostrar particiones montadas
  imprimirParticionesMontadas();
  //ahora reescribimos el mbr
  mbr.mbr_partition_1 = arreglo[0];
  mbr.mbr_partition_2 = arreglo[1];
  mbr.mbr_partition_3 = arreglo[2];
  mbr.mbr_partition_4 = arreglo[3];

  fseek(archivo, 0, SEEK_SET);
  fwrite(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);

}
