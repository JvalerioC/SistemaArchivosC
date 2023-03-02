#ifndef Rep__
#define Rep__
#include <string>
#include <iostream>
#include "structs.h"
#include "method_and_function.h"

using std::string;

class Rep{
    private:
        string name;
        string path;
        string id;
        string rutaf;
    public:
    //orden name, path, id, ruta
        Rep(string, string, string, string); //constructor
        void ejecutarComando();
        void crearReporte(string, string);
        void reporteMBR(itemMount);
        void reporteDisk(itemMount);



        
};

#endif