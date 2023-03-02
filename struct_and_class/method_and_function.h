#ifndef Methods_Functions_
#define Methods_Functions_

#include <string>
#include <unistd.h>
#include <iostream>
#include "structs.h"

using std::string, std::cout, std::endl;

// se me salio el ingles en estas primeras 2 funciones :v
string replaceQuotesMarks(string);

bool fileExist(string);

string existeParticion(string, MBR);

// no se envia el tamaño porque este siempre sera 4
void ordenarTamanio(PARTITION[]);

//funcion para mostrar las particiones montadas
void imprimirParticionesMontadas();

#endif