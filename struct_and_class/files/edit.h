#ifndef Edit__
#define Edit__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Edit{
  private:
    string path;
    string cont;
  public:
    //path, cont
    Edit(string, string); //constructor
    void ejecutarComando();
};

#endif