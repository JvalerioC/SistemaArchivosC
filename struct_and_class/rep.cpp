#include "rep.h"
#include <fstream>


using std::cout, std::endl;


Rep::Rep(){

};

void Rep::ejecutarComando(){

    string dot = "digraph mkdisk {\n";
    dot += "node [shape=plaintext, fillcolor=\"green\"];\n";
    dot += "tabla [label=<\n";
    dot += "<TABLE BORDER=\"0\" CELLBORDER=\"1\" CELLSPACING=\"0\">\n";
    dot += "<TR>\n";
    dot += "  <TD PORT=\"port3\" BGCOLOR=\"#FFFC33\">MBR</TD>\n";
    dot += "  <TD PORT=\"port4\" BGCOLOR=\"#33FF83\">Particion 1</TD>\n";
    dot += "  <TD PORT=\"port4\" BGCOLOR=\"#33FF83\">Particion 2</TD>\n";
    dot += "  <TD PORT=\"port4\" BGCOLOR=\"#33FF83\">Particion 3</TD>\n";
    dot += "  <TD PORT=\"port4\" BGCOLOR=\"#33FF83\">Particion 4</TD>\n";
    dot += "</TR>\n";
    dot += "</TABLE>>];\n}";

    std::ofstream archivo("grafo.dot");
    if (archivo.is_open()) {
      archivo << dot;
      archivo.close();
      std::system("dot -Tpng grafo.dot -o grafo.png");
      cout << "Reporte generado exitosamente" << endl;
    } else {
      cout << "Error al abrir el archivo." << endl;
    }

}