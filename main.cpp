#include <iostream>
#include <string>
#include "lexer.h"
#include "parser.h"

using namespace std;

int main(){
    string entrada;
    bool flag = true;
    cout << "**********************************************************" << endl;
    cout << "*                  201905743 - PROYECTO 1                *" << endl;
    cout << "**********************************************************" << endl;
    while(flag){
        cout << "201905743@P1:~$ ";
        getline(cin, entrada);
        if (entrada == "exit"){
            flag = false;
            cout<<"Saliendo de la aplicacion...\n"<<endl;
            continue;
        }
        yy_scan_string(entrada.c_str());
        yyparse();
    }

    return 0;
}

//comando para flex
//flex -o lexer.cpp --header-file=lexer.h lexer.l
//comando para bison
//bison -d parser.y
//comando para compilar ./compile.sh