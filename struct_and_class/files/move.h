#ifndef Move__
#define Move__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Move{
  private:
    string path;
    string destino;
  public:
    //path, destino
    Move(string, string); //constructor
    void ejecutarComando();
};

#endif