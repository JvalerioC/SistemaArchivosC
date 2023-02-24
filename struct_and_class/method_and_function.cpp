#include "method_and_function.h"

//funcion que quita las comillas al inicio y al final de una cadena y la retorna
string replaceQuotesMarks(string cadena){
  // si la cadena no contiene comillas, no es necesario hacer ninguna modificación
  if (cadena.find("\"") == string::npos) {
    return cadena;
  }
  cadena.replace(cadena.find("\""), 1, "");
  cadena.replace(cadena.rfind("\""), 1, "");
  return cadena;
}

//funcion que permite saber si un archivo existe
bool fileExist(string path){
  if (access(path.c_str(), F_OK) != -1) {
    return true;
  }
  return false;
}
//funcion que compara el nombre de cada particion en el disco para saber si este nombre ya esta en uso
string existeParticion(string nombre, MBR mbr){
  if (nombre.compare(mbr.mbr_partition_1.part_name) == 0){
    return string(mbr.mbr_partition_1.part_name);
  }
  if (nombre.compare(mbr.mbr_partition_2.part_name) == 0){
    return string(mbr.mbr_partition_2.part_name);
  }
  if (nombre.compare(mbr.mbr_partition_3.part_name) == 0){
    return string(mbr.mbr_partition_3.part_name);;
  }
  if (nombre.compare(mbr.mbr_partition_4.part_name) == 0){
    return string(mbr.mbr_partition_4.part_name);
  }
  return "";
}

void ordenarTamanio(PARTITION arreglo[]){
  PARTITION temp;
  for (int i = 0; i < 3; i++){
    for (int j = 0; j <3-i; j++){
      if(arreglo[j].part_start > arreglo[j+1].part_start){
        temp = arreglo[j];
        arreglo[j] = arreglo[j+1];
        arreglo[j+1] = temp;
      } 
    }
  } 
}