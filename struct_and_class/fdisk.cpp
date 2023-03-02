#include "fdisk.h"
#include "method_and_function.h"
#include <algorithm>

using std::cout, std::endl;

Fdisk::Fdisk(string _size, string _unit, string _name, string _path, string _fit, string _type, string _delete, string _add){

    size = _size;
    // de una vez remplazamos las comillas si este las tiene
    path = replaceQuotesMarks(_path);
    name = _name;
    unit = _unit;
    fit = _fit;
    tipo = _type;
    borrar = _delete;
    add = _add;
};

void Fdisk::ejecutarComando(){

  if(path == "" || name == ""){
    cout<<"Error, parametro obligatorio vacio"<<endl;
    return;
  }
  //se le da prioridad al delete
  std::transform(borrar.begin(), borrar.end(), borrar.begin(), ::tolower);
  if (borrar != ""){
    if (borrar == "full"){
      eliminarParticion();
      return;
    }else{
      cout<<"Error, valor para parametro delete invalido"<<endl;
      return;
    }
    
  }
  //luego al add
  int agregar;
  if(add != ""){
    try{
      agregar = stoi(add);
    }catch(const std::exception& e){
      cout<<"Error, no se ingreso un valor numerico en el parametro size "<<endl;
      return;
    }
    //se verifica la unidad y se pasa a mayusculas y se verifica que este sea correcto
    char unit1;
    std::transform(unit.begin(), unit.end(), unit.begin(), ::toupper);
    if(unit.length() == 1){
      if(unit != "K" && unit != "M"&& unit != "B"){
        cout<<"Error, el valor ingresado para el parametro unit no es valido"<<endl;
        return;
      }else{ unit1 = unit[0]; }
    }else if(unit.length() == 0){ unit1 = 'K'; }
    else{
      cout<<"Error, el valor ingresado para el parametro unit no es valido"<<endl;
        return;}
    
    //se valida el parametro de add para vers i es negativo o positivo
    if (agregar > 0){
      expandirParticion(unit1, agregar);
      return;
    }else if (agregar < 0){
      reducirParticion(unit1, agregar);
      return;
    }else{
      cout<<"Error, El parametro es 0"<<endl;
      return;
    }
  }

  //en este punto ya validamos si hay un delete o un add porque se les da prioridad a estos comandos
  //ahora se validaran los parametros para crear disco
  int size1;
  char unit1;
  char tipo1;
  if(size== ""){
    cout<<"Error, parametro size obligatorio"<<endl;
    return;
  }
  try{
      size1 = stoi(size);
  }catch(std::invalid_argument ){
    cout<<"Error, no se ingreso un valor numerico en el parametro size "<<endl;
    return;
  }
  //validamos que el tamaño no sea menor que o igual a 0
  if(size1 < 1){
    cout<<"Error, el valor ingresado para el parametro size es menor a 0"<<endl;
    return;
  }
  //validamos los parametros opcionales unit, fit y type
  std::transform(fit.begin(), fit.end(), fit.begin(), ::toupper);
  if(fit.length()==2){
    if(fit != "BF" && fit != "FF" && fit != "WF"){
      cout<<"Error, el valor ingresado para el parametro fit no es valido"<<endl;
      return;
    }
  }else if(fit.length() == 0){
    fit = "WF";
  }else{
    cout<<"Error, el valor ingresado para el parametro fit no es valido"<<endl;
    return;
  }
  
  //se pasa a mayusculas el tipo y se verifica que sea correcto type
  std::transform(tipo.begin(), tipo.end(), tipo.begin(), ::toupper);
  if(tipo.length() == 1){
    if(tipo != "P" && tipo != "E" && tipo != "L"){
      cout<<"Error, el valor ingresado para el parametro type no es valido"<<endl;
      return;
    }else{ tipo1 = tipo[0]; }
  }else if(tipo.length() == 0){ tipo1 = 'P'; }
  else{
      cout<<"Error, el valor ingresado para el parametro type no es valido"<<endl;
        return;}

  //validamos que exista el disco
  bool flag = fileExist(path);
  if (!flag){
    cout<<"Error, el disco no existe"<<endl;
    return;
  } 
  //validamos el unit
  std::transform(unit.begin(), unit.end(), unit.begin(), ::toupper);
    if(unit.length() == 1){
      if(unit != "K" && unit != "M"&& unit != "B"){
        cout<<"Error, el valor ingresado para el parametro unit no es valido"<<endl;
        return;
      }else{ unit1 = unit[0]; }
    }else if(unit.length() == 0){ unit1 = 'K'; }
    else{
      cout<<"Error, el valor ingresado para el parametro unit no es valido"<<endl;
        return;}

  FILE *archivo = fopen(path.c_str(), "r+b");
  MBR mbr;
  fread(&mbr, sizeof(MBR), 1 , archivo);
  fclose(archivo);
  //Verificamos el nombre de la particion, que este no este en uso
  if (name.compare(mbr.mbr_partition_1.part_name) == 0){
    cout<<"Error, el nombre de la particion ya esta en uso"<<endl;
    return;
  }
  if (name.compare(mbr.mbr_partition_2.part_name) == 0){
    cout<<"Error, el nombre de la particion ya esta en uso"<<endl;
    return;
  }
  if (name.compare(mbr.mbr_partition_3.part_name) == 0){
    cout<<"Error, el nombre de la particion ya esta en uso"<<endl;
    return;
  }
  if (name.compare(mbr.mbr_partition_4.part_name) == 0){
    cout<<"Error, el nombre de la particion ya esta en uso"<<endl;
    return;
  }
  //validamos que sea posible insertar la particion, haya espacio
  int contadorPrimarias = 0;
  int contadorExtendidas = 0;
  int contadorParticiones = 0;
  //validamos las Primarias
  if(mbr.mbr_partition_1.part_type == 'E'){ contadorExtendidas++;  }
  if(mbr.mbr_partition_2.part_type == 'E'){ contadorExtendidas++;  }
  if(mbr.mbr_partition_3.part_type == 'E'){ contadorExtendidas++;  }
  if(mbr.mbr_partition_4.part_type == 'E'){ contadorExtendidas++;  }
  //validamos las extendidas
  if(mbr.mbr_partition_1.part_type == 'P'){ contadorPrimarias++;  }
  if(mbr.mbr_partition_2.part_type == 'P'){ contadorPrimarias++;  }
  if(mbr.mbr_partition_3.part_type == 'P'){ contadorPrimarias++;  }
  if(mbr.mbr_partition_4.part_type == 'P'){ contadorPrimarias++;  }
  contadorParticiones = contadorExtendidas+contadorPrimarias;

  if(contadorParticiones == 4){
    cout<<"Error, ya hay 4 particiones en el disco"<<endl;
    return;
  }
  

  if(tipo1 == 'P'){
    crearParticion(size1, unit1, tipo1, mbr.dsk_fit);
  }else if(tipo1 == 'E' && contadorExtendidas == 0){
    crearParticion(size1, unit1, tipo1, mbr.dsk_fit);
  }else if(tipo1 == 'E' && contadorExtendidas == 1){
    cout<<"Error, ya existe una particion extendida no se puede ingresar"<<endl;
    return;
  }else if(tipo1 == 'L' && contadorExtendidas == 0){
    cout<<"Error, no hay particion extendida para insertar una logica"<<endl;
    return;
  }else if(tipo1 == 'L' && contadorExtendidas == 1){
    crearLogica(size1, unit1);
  }
  
}

//funcion en la que se crea el disco validando el espacio donde hay que insertarlo
void Fdisk::crearParticion(int _size, char _unit, char _tipo, char _diskFit){
  int posicion = 0;
  int tamanio = 0;
  if(_unit == 'B'){ tamanio = _size; }
  else if(_unit == 'K'){tamanio = _size*1024;}
  else if(_unit == 'M'){tamanio = _size*1024*1024;}

  if(_diskFit == 'B'){ posicion = validarBfit(tamanio); }
  else if(_diskFit == 'F'){ posicion = validarFfit(tamanio); }
  else if(_diskFit == 'W'){ posicion = validarWfit(tamanio); }
  //si se retorna cero no hay espacio
  if(posicion == 0){
    cout<<"Error, no es posible ingresar particion, no hay espacio disponible"<<endl;
    return;
  }else{
    MBR mbr;
    PARTITION part;
    FILE *archivo = fopen(path.c_str(), "r+b");
    fread(&mbr, sizeof(MBR), 1 , archivo);
    //como ya se valido que no hay 4 particiones usadas ahora buscamos la primera en la que podamos insertar
    part.part_status = '0';
    //si la particion es una particion extendida se ingresa un ebr vacio
    if(_tipo == 'E'){
      EBR ebr;
      fseek(archivo, posicion, SEEK_SET);
      fwrite(&ebr, sizeof(ebr), 1, archivo);
    }
    part.part_type = _tipo;
    part.part_fit = fit[0];
    std::strncpy(part.part_name, name.c_str(), sizeof(part.part_name) - 1);
    part.part_name[sizeof(part.part_name) - 1] = '\0';
    part.part_start = posicion;
    part.part_s = tamanio;

    if(mbr.mbr_partition_1.part_start == 0){
      mbr.mbr_partition_1 = part;
    }else if(mbr.mbr_partition_2.part_start == 0){
      mbr.mbr_partition_2 = part;
    }else if(mbr.mbr_partition_3.part_start == 0){
      mbr.mbr_partition_3 = part;
    }else if(mbr.mbr_partition_4.part_start == 0){
      mbr.mbr_partition_4 = part;
    }
    //volvemos a posicionarnos al inicio del archivo para sobreescribir el mbr
    fseek(archivo, 0, SEEK_SET);
    //escribimos el mbr
    fwrite(&mbr, sizeof(mbr), 1, archivo);
    fclose(archivo);
    cout<<"Particion creada exitosamente"<<endl;    
  }
}
//funcion que me devuleve el entero donde se puede insertar la particion teniendo en cuenta el BestFit
int Fdisk::validarBfit(int _tamanio){
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "r+b");
  fread(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);
  //si estan desordenadas las particiones entonces las ordenare para un mejor calculo del espacio disponible utilizando una estructura para manejarlo
  PARTITION arreglo[4];
  //copia de particiones a array
  arreglo[0] = mbr.mbr_partition_1;
  arreglo[1] = mbr.mbr_partition_2;
  arreglo[2] = mbr.mbr_partition_3;
  arreglo[3] = mbr.mbr_partition_4;
  
  ordenarTamanio(arreglo);
  int tamanio = 0, tamanio_temporal = 0;
  int posicion_final = sizeof(MBR);
  //ahora vemos si hay espacio entre las particiones
  int contador = 0, contador2 = 0;
  while (contador != 4){
    if(arreglo[contador].part_start != 0){
      if(posicion_final != arreglo[contador].part_start){
        //guardo en tamanio temporal un espacio encontrado en el disco
        tamanio_temporal = arreglo[contador].part_start - posicion_final;
        if (tamanio_temporal < 0){
          cout<<"Ocurrio un error desconocido, "<<endl;
          break;
        }
        //se valida que el tamaño dela posicion final y el tamaño de la nueva particion no supere el tamaño del disco, se multiplica por 1024 ya que este valor se guarda en kb
        if(posicion_final+_tamanio > mbr.mbr_tamano*1024){
          break;
        }
        //solo si se cumple esto se modifica el tamanio disponible, se verifica en todo el disco el menor espacio disponible
        if(tamanio != 0 && tamanio_temporal<tamanio && tamanio_temporal >= _tamanio){
          tamanio = tamanio_temporal;
        }else if(tamanio == 0 && tamanio_temporal >= _tamanio){
          tamanio = tamanio_temporal;
        }
        posicion_final = tamanio_temporal+posicion_final+arreglo[contador].part_s;
      }else{
        posicion_final = posicion_final + arreglo[contador].part_s;
      }
    }else{
      cout<<"cuantas veces entra aqui "<<posicion_final<<endl;
      contador2++; // este lo utilizo para saber si todas las particiones estan vacias
    }
    contador++;
  }
  // si las 4 particiones estan vacias y el tamanio es cero sera la primera particion a ingresar
  if(contador2 == 4){
    tamanio = sizeof(MBR);
  }else if(tamanio == 0 && (posicion_final+_tamanio)<(mbr.mbr_tamano*1024)){
    tamanio = posicion_final;
  }
  //se retorna donde se pueda ingresar la particion con Best fit
  return tamanio;

}

//funcion para validar espacion en disco con Worst Fit
int Fdisk::validarWfit(int _tamanio){
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "r+b");
  fread(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);
  //si estan desordenadas las particiones entonces las ordenare para un mejor calculo del espacio disponible utilizando una estructura para manejarlo
  PARTITION arreglo[4];
  //copia de particiones a array
  arreglo[0] = mbr.mbr_partition_1;
  arreglo[1] = mbr.mbr_partition_2;
  arreglo[2] = mbr.mbr_partition_3;
  arreglo[3] = mbr.mbr_partition_4;
  
  ordenarTamanio(arreglo);
  int tamanio = 0, tamanio_temporal = 0;
  int posicion_final = sizeof(MBR);
  //ahora vemos si hay espacio entre las particiones
  int contador = 0, contador2 = 0;
  while (contador != 4){
    if(arreglo[contador].part_start != 0){
      if(posicion_final != arreglo[contador].part_start){
        //guardo en tamanio temporal un espacio encontrado en el disco
        tamanio_temporal = arreglo[contador].part_start - posicion_final;
        if (tamanio_temporal < 0){
          cout<<"Ocurrio un error desconocido, "<<endl;
          break;
        }
        //se valida que el tamaño dela posicion final y el tamaño de la nueva particion no supere el tamaño del disco, se multiplica por 1024 ya que este valor se guarda en kb
        if(posicion_final+_tamanio > mbr.mbr_tamano*1024){
          break;
        }
        //solo si se cumple esto se modifica el tamanio disponible, se verifica en todo el disco el menor espacio disponible
        if(tamanio != 0 && tamanio_temporal>tamanio && tamanio_temporal >= _tamanio){
          tamanio = tamanio_temporal;
        }else if(tamanio == 0 && tamanio_temporal >= _tamanio){
          tamanio = tamanio_temporal;
        }
        posicion_final = tamanio_temporal+posicion_final+arreglo[contador].part_s;
      }else{
        posicion_final = posicion_final + arreglo[contador].part_s;
      }
    }else{
      contador2++; // este lo utilizo para saber si todas las particiones estan vacias
    }
    contador++;
  }
  // si las 4 particiones estan vacias y el tamanio es cero sera la primera particion a ingresar
  if(contador2 == 4){
    tamanio = sizeof(MBR);
  }else if(tamanio == 0 && (posicion_final+_tamanio)<(mbr.mbr_tamano*1024)){
    tamanio = posicion_final;
  }
  //se retorna donde se pueda ingresar la particion con Best fit
  return tamanio;

}

//funcion para validar espacio en disco con First Fit
int Fdisk::validarFfit(int _tamanio){
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "r+b");
  fread(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);
  //si estan desordenadas las particiones entonces las ordenare para un mejor calculo del espacio disponible utilizando una estructura para manejarlo
  PARTITION arreglo[4];
  //copia de particiones a array
  arreglo[0] = mbr.mbr_partition_1;
  arreglo[1] = mbr.mbr_partition_2;
  arreglo[2] = mbr.mbr_partition_3;
  arreglo[3] = mbr.mbr_partition_4;
  
  ordenarTamanio(arreglo);
  int tamanio=0, tamanio_temporal=0;
  int posicion_final = sizeof(MBR);
  //ahora vemos si hay espacio entre las particiones
  int contador=0, contador2 = 0;
  while (contador != 4){
    if(arreglo[contador].part_start != 0){
      if(posicion_final != arreglo[contador].part_start){
        //guardo en tamanio temporal un espacio encontrado en el disco
        tamanio_temporal = arreglo[contador].part_start - posicion_final;
        if (tamanio_temporal < 0){
          cout<<"Ocurrio un error desconocido, "<<endl;
          break;
        }
        //se valida que el tamaño dela posicion final y el tamaño de la nueva particion no supere el tamaño del disco, se multiplica por 1024 ya que este valor se guarda en kb
        if((posicion_final+_tamanio) > (mbr.mbr_tamano*1024)){
          break;
        }
        //solo si se cumple esto se modifica el tamanio disponible, se verifica en todo el disco el menor espacio disponible
        if(tamanio_temporal>=_tamanio){
          tamanio = tamanio_temporal;
          break;
        }
        posicion_final = tamanio_temporal+posicion_final+arreglo[contador].part_s;
      }else{
        posicion_final = posicion_final + arreglo[contador].part_s;

      }
    }else{
      contador2++; // este lo utilizo para saber si todas las particiones estan vacias
    }
    contador++;
  }
  // si las 4 particiones estan vacias y el tamanio es cero sera la primera particion a ingresar
  if(contador2 == 4){
    tamanio = sizeof(MBR);
  }else if(tamanio == 0 && (posicion_final+_tamanio)<(mbr.mbr_tamano*1024)){
    tamanio = posicion_final;
  }
  //se retorna donde se pueda ingresar la particion con Best fit al final es una posicion
  return tamanio;
}


//funcion para eliminar particion
void Fdisk::eliminarParticion(){
  
  //se verifica que exista el disco
  bool flag = fileExist(path);
  if(!flag){
    cout << "Error, el disco no existe." << endl;
    return;
  }
  std::transform(borrar.begin(), borrar.end(), borrar.begin(), ::tolower);
  if (borrar != "full"){
    cout << "Error, el parametro para eliminar no es valido" << endl;
    return;
  }
  // si el disco existe comenzamos a buscar la particion
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "r+b");
  fread(&mbr, sizeof(MBR), 1, archivo);
  // por si las moscas volvemos a ponernos al inicio del archivo
  fseek(archivo, 0, SEEK_SET);
  //declaramos las variables de las dimensiones de la particion e iniciamos una nueva para cololar en el mbr y sobreescribir la que se va a eliminar
  int inicioBorrar;
  int finBorrar;
  PARTITION particion; 
  //se recuperan los valores de inicio y fin de la particion, y se limpia la particion, en este caso se limpian los valores
  if (name.compare(mbr.mbr_partition_1.part_name) == 0){
    mbr.mbr_partition_1 = particion;
    inicioBorrar = mbr.mbr_partition_1.part_start; 
    finBorrar = mbr.mbr_partition_1.part_s;
  }else if (name.compare(mbr.mbr_partition_2.part_name) == 0){
    mbr.mbr_partition_1 = particion;
    inicioBorrar = mbr.mbr_partition_2.part_start;
    finBorrar = mbr.mbr_partition_2.part_s;
  }else if (name.compare(mbr.mbr_partition_3.part_name) == 0){
    mbr.mbr_partition_1 = particion;
    inicioBorrar = mbr.mbr_partition_3.part_start;
    finBorrar = mbr.mbr_partition_3.part_s;
  }else if (name.compare(mbr.mbr_partition_4.part_name) == 0){
    mbr.mbr_partition_1 = particion;
    inicioBorrar = mbr.mbr_partition_4.part_start;
    finBorrar = mbr.mbr_partition_4.part_s;
  }else{
    cout << "Error, no existe particion con el nombre ingresado" << endl;
    return;
  }
  //comenzamos a escribir los ceros donde estaba la particion
  char k[1]; //esto es un byte
  fseek(archivo, inicioBorrar, SEEK_SET);
  int inicio = 0;
  for(int i = inicioBorrar; i<finBorrar;i++){
    fwrite(&k, 1,1,archivo);
  }
  //reescribimos el mbr
  fseek(archivo, 0, SEEK_SET);
  fwrite(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);
  cout << "Particion eliminada exitosamente" << endl;

  
}

void Fdisk::reducirParticion(char _unit, int dimension){
  //se verifica que exista el disco
  bool flag = fileExist(path);
  if(!flag){
    cout << "Error, el disco no existe." << endl;
    return;
  }
  int tamanio;
  if (_unit == 'B'){ tamanio = dimension; }
  else if (_unit == 'K'){ tamanio = dimension * 1024;}
  else if (_unit == 'M'){ tamanio = dimension*1024*1024;}
  // si el disco existe comenzamos a buscar la particion
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "r+b");
  fread(&mbr, sizeof(MBR), 1, archivo);
  // por si las moscas volvemos a ponernos al inicio del archivo
  fseek(archivo, 0, SEEK_SET);
  
  //se recuperan los valores de inicio y fin de la particion, y se limpia la particion, en este caso se limpian los valores
  int nuevaDimension;
  if (name.compare(mbr.mbr_partition_1.part_name) == 0){
    mbr.mbr_partition_1.part_s += tamanio;
    nuevaDimension = mbr.mbr_partition_1.part_s;
  }else if (name.compare(mbr.mbr_partition_2.part_name) == 0){
    mbr.mbr_partition_2.part_s += tamanio;
    nuevaDimension = mbr.mbr_partition_2.part_s;
  }else if (name.compare(mbr.mbr_partition_3.part_name) == 0){
    mbr.mbr_partition_3.part_s += tamanio;
    nuevaDimension = mbr.mbr_partition_3.part_s;
  }else if (name.compare(mbr.mbr_partition_4.part_name) == 0){
    mbr.mbr_partition_4.part_s += tamanio;
    nuevaDimension = mbr.mbr_partition_4.part_s;
  }else{
    cout << "Error, no existe particion con el nombre ingresado" << endl;
    return;
  }

  //validamos que la dimension no sea menor que o
  if(nuevaDimension <= 0){
    cout << "Error, no es posible reducir el tamaño de la particion" << endl;
    return;
  }
  //reescribimos el mbr
  fseek(archivo, 0, SEEK_SET);
  fwrite(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);
  cout << "Particion reducida exitosamente" << endl;
}

void Fdisk::expandirParticion(char _unit, int dimension){
  //se verifica que exista el disco
  bool flag = fileExist(path);
  if(!flag){
    cout << "Error, el disco no existe." << endl;
    return;
  }
  int tamanio;
  if (_unit == 'B'){ tamanio = dimension; }
  else if (_unit == 'K'){ tamanio = dimension * 1024;}
  else if (_unit == 'M'){ tamanio = dimension*1024*1024;}
  // si el disco existe comenzamos a buscar la particion
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "r+b");
  fread(&mbr, sizeof(MBR), 1, archivo);
  // por si las moscas volvemos a ponernos al inicio del archivo
  fseek(archivo, 0, SEEK_SET);
  
  //se recuperan los valores de inicio y fin de la particion, y se limpia la particion, en este caso se limpian los valores
  int nuevaDimension;
  PARTITION arreglo[4];
  int siguiente;
  //copia de particiones a array
  arreglo[0] = mbr.mbr_partition_1;
  arreglo[1] = mbr.mbr_partition_2;
  arreglo[2] = mbr.mbr_partition_3;
  arreglo[3] = mbr.mbr_partition_4;
  ordenarTamanio(arreglo);

  if (name.compare(arreglo[0].part_name) == 0){
    arreglo[0].part_s += tamanio;
    nuevaDimension = arreglo[0].part_s;
    siguiente = arreglo[1].part_start;
  }else if (name.compare(mbr.mbr_partition_2.part_name) == 0){
    arreglo[1].part_s += tamanio;
    nuevaDimension = arreglo[1].part_s;
    siguiente = arreglo[2].part_start;
  }else if (name.compare(mbr.mbr_partition_3.part_name) == 0){
    arreglo[2].part_s += tamanio;
    nuevaDimension = arreglo[2].part_s;
    siguiente = arreglo[3].part_start;
  }else if (name.compare(mbr.mbr_partition_4.part_name) == 0){
    arreglo[3].part_s += tamanio;
    nuevaDimension = arreglo[3].part_s;
    siguiente = mbr.mbr_tamano*1024;
  }else{
    cout << "Error, no existe particion con el nombre ingresado" << endl;
    return;
  }
  //validamos que la dimension no se escriba sobre otra que o
  if(nuevaDimension > siguiente){
    cout << "Error, no es posible expandir el tamaño de la particion" << endl;
    return;
  }
  //reasignamos las particiones para mejor orden
  mbr.mbr_partition_1 = arreglo[0];
  mbr.mbr_partition_2 = arreglo[1];
  mbr.mbr_partition_3 = arreglo[2];
  mbr.mbr_partition_4 = arreglo[3];
  //reescribimos el mbr
  fseek(archivo, 0, SEEK_SET);
  fwrite(&mbr, sizeof(MBR), 1, archivo);
  fclose(archivo);
  cout << "Particion reducida exitosamente" << endl;
}

void Fdisk::crearLogica(int _size, char _unit){
  int tamanio=0, tamanio_particion=0;
  int posicion=0, posicion_anterior=0;
  if(_unit == 'B'){ tamanio = _size; }
  else if(_unit == 'K'){tamanio = _size*1024;}
  else if(_unit == 'M'){tamanio = _size*1024*1024;}

  //buscamos la particion extendida y la iniciamos
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "r+b");
  fread(&mbr, sizeof(MBR), 1 , archivo);
  if(mbr.mbr_partition_1.part_type == 'E'){
    posicion = mbr.mbr_partition_1.part_start;
    tamanio_particion = mbr.mbr_partition_1.part_s;
  }else if(mbr.mbr_partition_2.part_type == 'E'){
    posicion = mbr.mbr_partition_2.part_start;
    tamanio_particion = mbr.mbr_partition_2.part_s;
  }else if(mbr.mbr_partition_3.part_type == 'E'){
    posicion = mbr.mbr_partition_3.part_start;
    tamanio_particion = mbr.mbr_partition_3.part_s;
  }else if(mbr.mbr_partition_4.part_type == 'E'){
    posicion = mbr.mbr_partition_4.part_start;
    tamanio_particion = mbr.mbr_partition_4.part_s;
  }
  posicion_anterior = posicion;
  //como se sabe que siempre va a haber un ebr en una particion extendida este se recupera
  EBR ebr, ebr1;
  fseek(archivo, posicion, SEEK_SET);
  fread(&ebr, sizeof(EBR), 1, archivo);
  bool flag1 = false;
  //validamos si el primer ebr esta usado o no
  if(ebr.part_next == 0 && ebr.part_s == 0){
    ebr.part_fit = fit[0];
    ebr.part_start = posicion;
    ebr.part_s = tamanio;
    std::strncpy(ebr.part_name, name.c_str(), sizeof(ebr.part_name) - 1);
    ebr.part_name[sizeof(ebr.part_name) - 1] = '\0';
    fseek(archivo, posicion, SEEK_SET);
    fwrite(&ebr, sizeof(EBR), 1, archivo);
    fclose(archivo);
    cout<<"Particion logica creada exitosamente"<<endl;
    return;
  }else if(ebr.part_next == 0 && ebr.part_s != 0){
    //se guardan estos valores para sobreescribirlos en en disco
    ebr.part_next = posicion + ebr.part_s;
    posicion_anterior = posicion;
    flag1 = true;
    //se usa otro ebr para insertarlo
    posicion = posicion + ebr.part_s;
    ebr1.part_fit = fit[0];
    ebr1.part_start = posicion;
    ebr1.part_s = tamanio;
    std::strncpy(ebr1.part_name, name.c_str(), sizeof(ebr1.part_name) - 1);
    ebr1.part_name[sizeof(ebr1.part_name) - 1] = '\0';
  }else{
    while(ebr.part_next != 0 ){
      posicion_anterior = posicion;
      posicion = posicion + ebr.part_s;
      fseek(archivo, posicion, SEEK_SET);
      fread(&ebr, sizeof(EBR), 1, archivo);
    }
    ebr.part_next = posicion + ebr.part_s;
    posicion_anterior = posicion;
    flag1 = true;
    //se usa otro ebr para insertarlo
    posicion = posicion + ebr.part_s;
    ebr1.part_fit = fit[0];
    ebr1.part_start = posicion;
    ebr1.part_s = tamanio;
    std::strncpy(ebr1.part_name, name.c_str(), sizeof(ebr1.part_name) - 1);
    ebr1.part_name[sizeof(ebr1.part_name) - 1] = '\0';
  }
  // si hay que sobreescribir el next del ebr se hace
  if(flag1){
    fseek(archivo, posicion_anterior, SEEK_SET);
    fwrite(&ebr, sizeof(EBR), 1, archivo);
  }
  cout<<posicion_anterior<<endl;
  cout<<posicion<<endl;
  cout<<tamanio<<endl;
  
  //se escribe el ebr actual
  ebr1.part_start = posicion;
  ebr1.part_s = tamanio;
  ebr1.part_fit = fit[0];
  std::strncpy(ebr1.part_name, name.c_str(), sizeof(ebr1.part_name) - 1);
  ebr1.part_name[sizeof(ebr1.part_name) - 1] = '\0';
  fseek(archivo, posicion, SEEK_SET);
  fwrite(&ebr1, sizeof(EBR), 1, archivo);
  fclose(archivo);
  cout<<"Particion logica creada exitosamente"<<endl; 
}
