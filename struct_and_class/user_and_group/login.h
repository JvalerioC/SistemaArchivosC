#ifndef Login__
#define Login__
#include <cstring>
#include <iostream>
#include "../structs.h"
#include <algorithm>
#include <cmath>

using std::string;

class Login{
  private:
    string user;
    string pass;
    string id;
  public:
    //user, pass, id
    Login(string, string, string); //constructor
    void ejecutarComando();
    void iniciarSesion(itemMount);
    string contenidoArchivo(int);
};

#endif