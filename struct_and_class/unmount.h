#ifndef Unmount__
#define Unmount__
#include <cstring>
#include <iostream>
#include "structs.h"

using std::string;

class Unmount{
    private:
        string id;
    public:
        //id
        Unmount(string); //constructor
        void ejecutarComando();

        
};

#endif