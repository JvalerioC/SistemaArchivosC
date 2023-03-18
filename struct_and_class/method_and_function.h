#ifndef Methods_Functions_
#define Methods_Functions_

#include <cstring>
#include <unistd.h>
#include <iostream>
#include "structs.h"
#include <algorithm>

using std::string, std::cout, std::endl;

// se me salio el ingles en estas primeras 2 funciones :v
string replaceQuotesMarks(string);

bool fileExist(string);

string existeParticion(string, MBR);

// no se envia el tamaño porque este siempre sera 4
void ordenarTamanio(PARTITION[]);

//funcion para mostrar las particiones montadas
void imprimirParticionesMontadas();

//funcion para encontrar un inodo
int encontrarInodo(B_INODO, SUPERBLOQUE, FILE*, string);

//funcion para crear un inodo (carpeta con el primer bloque)
void crearInodo(SUPERBLOQUE*, FILE*, string, B_INODO, int);

//funcion para crear un inodo (archivo con su contenido)
void crearInodoArchivo(SUPERBLOQUE*, FILE*, string, B_INODO, int, string);

#endif