
#include <fstream>
#include <cstring>

using namespace std;

char *leerCadena(ifstream &file, int maximo, char caracter){
    char cadena[maximo], *cad;
    file.getline(cadena, maximo, caracter);
    cad = new char [strlen(cadena)+1];
    strcpy(cad, cadena);
    return cad;
}