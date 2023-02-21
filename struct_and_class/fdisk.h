#ifndef Fdisk__
#define Fdisk__
#include <string>
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
    public:
        //oprden size, unit, path, name, fit, type
        Fdisk(string, string, string, string, string, string); //constructor
        void ejecutarComando();
        void crearParticion();


        
};

#endif
