#ifndef Mount__
#define Mount__
#include <cstring>
#include <iostream>
#include "structs.h"

using std::string;

class Mount{
    private:
        string id;
        string path;
        string name;
    public:
        //name, path
        Mount(string, string); //constructor
        void ejecutarComando();

        
};

#endif