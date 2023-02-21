#include "mkdisk.h"
#include <algorithm>
#include <sys/stat.h>


using std::cout, std::endl;

Mkdisk::Mkdisk(string _size, string _fit, string _unit, string _path){

    size = _size;
    path = _path;
    fit = _fit;
    unit = _unit;
};



void Mkdisk::ejecutarComando(){
  int size1;
  char unit1;
  //se valida que los parametros obligatorios no esten vacios
  if (size == "" || path == ""){
    cout<<"Error, parametro obligatorio vacio"<<endl;
    return;
  }
  // se convierte la cadena a numero, si este no es numerico generara un error
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
  //pasamos la variable fit a minusculas, se valida que sea menor a longitud 3 y que 
  std::transform(fit.begin(), fit.end(), fit.begin(), ::toupper);
  if(fit.length()==2){
    if(fit != "BF" || fit != "FF" || fit != "WF"){
      cout<<"Error, el valor ingresado para el parametro fit no es valido"<<endl;
      return;
    }
  }else if(fit.length() == 0){
    fit = "FF";
  }
  //se para a mayusculas y se verifica que este sea correcto
  std::transform(unit.begin(), unit.end(), unit.begin(), ::toupper);
  if(unit.length() == 1){
    if(unit != "K" && unit != "M"){
      cout<<"Error, el valor ingresado para el parametro unit no es valido"<<endl;
      return;
    }else{ unit1 = unit[0]; }
  }else if(unit.length() == 0){ unit1 = 'M'; }

  //validamos la ruta ingresada, creamos los directorios si estos no existen
  size_t pos = 0;
  string delimiter = "/";
  string token, token2 = "";
  string pathTemporal = path;
  while ((pos = pathTemporal.find(delimiter)) != string::npos) {
    token = pathTemporal.substr(0, pos);
    token2 += token;
    mkdir(token2.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    pathTemporal.erase(0, pos + delimiter.length());
    if(token != ""){
      token2 += "/";
    }
  }
  path.erase(0,1);
  FILE *archivo;
  archivo = fopen(path.c_str(), "wb");

  if (archivo != NULL) {
    fclose(archivo);
  } else {
    cout << "Error en el parametro para la ruta" << endl;
    return;
  }
  //cuando no hayan errores se llamara a la funcion para la creacion del disco
  crearDisco(size1, unit1);
}
//con esto se crea el disco y se escribe el mbr
void Mkdisk::crearDisco(int _size1, char _unit1){
  MBR mbr;
  FILE *archivo = fopen(path.c_str(), "wb");
  mbr.mbr_tamano = _size1;
  char k[1024];
  int size1 = _size1*1024;
  int inicio = 0;
  while(inicio != size1){
    fwrite(&k, 1024, 1, archivo);
    inicio++;
  }
  srand(time(0));
  auto t_actual = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(t_actual);
  mbr.mbr_fecha_creacion = t;
  mbr.mbr_dsk_signature = rand()+1;
  fseek(archivo, 0, SEEK_SET);
  fwrite(&mbr, sizeof(mbr), 1, archivo);
  fclose(archivo);

  cout<<"Disco creado Exitosamente"<<endl;



}