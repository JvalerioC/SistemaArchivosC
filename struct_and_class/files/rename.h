#ifndef Rename__
#define Rename__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Rename{
  private:
    string path;
    string name;
  public:
    //path, name
    Rename(string, string); //constructor
    void ejecutarComando();
};

#endif