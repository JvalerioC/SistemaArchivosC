#ifndef Fdisk__
#define Fdisk__
#include <cstring>
#include <iostream>
#include "structs.h"

using std::string;

class Fdisk{
    private:
        string size;
        string path;
        string name;
        string unit;
        string tipo;
        string fit;
        string borrar;
        string add;
    public:
        //orden size, unit, name, path, fit, type, borrar, add
        Fdisk(string, string, string, string, string, string, string, string); //constructor
        void ejecutarComando();
        void crearParticion(int, char, char, char); // size, unit, tipo
        void crearLogica(int, char);
        void eliminarParticion(); // ejecutamos la eliminacion
        void reducirParticion(char, int);
        void expandirParticion(char, int);
        int validarBfit(int);
        int validarFfit(int);
        int validarWfit(int);
};

#endif
