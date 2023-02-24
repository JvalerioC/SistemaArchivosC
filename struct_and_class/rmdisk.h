#ifndef Rmdisk__
#define Rmdisk__
#include <string>
#include <iostream>
#include "structs.h"

using std::string;

class Rmdisk{
    private:
        string path;
    public:
        //orden path
        Rmdisk(string); //constructor
        void ejecutarComando();
        void eliminarDisco();
       
};

#endif
