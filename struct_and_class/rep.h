#ifndef Rep__
#define Rep__
#include <cstring>
#include <iostream>
#include "structs.h"
#include "method_and_function.h"
#include <sstream>

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
        void reporteSuperbloque(itemMount);
        void reporteBMInodo(itemMount);
        void reporteBMBloque(itemMount);
        void reporteInodo(itemMount);
        void reporteBloque(itemMount);
        void reporteFile(itemMount);
        
};

#endif