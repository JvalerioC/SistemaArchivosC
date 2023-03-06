#ifndef Mkfile__
#define Mkfile__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Mkfile{
  private:
    string path;
    string r;
    string size;
    string cont;
  public:
    //path, r, s, cont
    Mkfile(string, string, string, string); //constructor
    void ejecutarComando();
};

#endif