#ifndef Cat__
#define Cat__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>
#include <vector>

using std::string, std::vector;

class Cat{
  private:
    vector <string> paths;
    vector <string> files;
  public:
    //paths, files
    Cat(vector <string>, vector <string>); //constructor
    void ejecutarComando();
};

#endif