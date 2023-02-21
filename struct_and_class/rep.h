#ifndef Rep__
#define Rep__
#include <string>
#include <iostream>
#include "structs.h"

using std::string;

class Rep{
    private:
        string size;
        string path;
        string fit;
        string unit;
    public:
        Rep(); //constructor
        void ejecutarComando();
        //void crearReporte();



        
};

#endif