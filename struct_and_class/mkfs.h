#ifndef Mkfs__
#define Mkfs__
#include <cstring>
#include <iostream>
#include "structs.h"

using std::string;

class Mkfs{
    private:
        string id;
        string tipo;
        string fs;
    public:
        //id, tipo, fs
        Mkfs(string, string, string); //constructor
        void ejecutarComando();

        
};

#endif