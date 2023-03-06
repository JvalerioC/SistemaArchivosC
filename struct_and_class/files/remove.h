#ifndef Remove__
#define Remove__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Remove{
  private:
    string path;
  public:
    //path
    Remove(string); //constructor
    void ejecutarComando();
};

#endif