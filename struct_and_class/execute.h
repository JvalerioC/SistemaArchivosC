#ifndef Execute__
#define Execute__
#include <string>
#include <iostream>
#include "structs.h"
#include <fstream>

using std::string;

class Execute{
    private:
        string path;
    public:
        Execute(string); //constructor
        void ejecutarComando();
        void ejecutarArchivo();

};

#endif