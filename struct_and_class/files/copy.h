#ifndef Copy__
#define Copy__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Copy{
  private:
    string path;
    string destino;
  public:
    //path, destino
    Copy(string, string); //constructor
    void ejecutarComando();
};

#endif