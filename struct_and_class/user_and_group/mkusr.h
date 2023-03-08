#ifndef Mkusr__
#define Mkusr__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>
#include <sstream>

using std::string;

class Mkusr{
    private:
        string user;
        string pass;
        string grp;
    public:
        //user, pass, grp
        Mkusr(string, string, string); //constructor
        void ejecutarComando();

        
};

#endif