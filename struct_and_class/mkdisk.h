#ifndef Mkdisk__
#define Mkdisk__
#include <string>
#include <iostream>
#include "structs.h"

using std::string;

class Mkdisk{
    private:
        string size;
        string path;
        string fit;
        string unit;
    public:
        //orden size, fit, unit, path
        Mkdisk(string, string, string, string); //constructor
        void ejecutarComando();
        void crearDisco(int, char);
        //void crearMBR();



        
};

#endif
