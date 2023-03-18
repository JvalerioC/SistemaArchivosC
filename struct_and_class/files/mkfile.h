#ifndef Mkfile__
#define Mkfile__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include "../method_and_function.h"

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
    void createFileW(std::vector<string>, string);
    void createFileS(std::vector<string>, string);
    void createFileB(std::vector<string>, string);
    //void relationship(B_INODO, int, FILE*, SUPERBLOQUE, string);
};

#endif