#ifndef Mkdir__
#define Mkdir__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Mkdir{
  private:
    string path;
    string r;
  public:
    //path, r
    Mkdir(string, string); //constructor
    void ejecutarComando();
};

#endif