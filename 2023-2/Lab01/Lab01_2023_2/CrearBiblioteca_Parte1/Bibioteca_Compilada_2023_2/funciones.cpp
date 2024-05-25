
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char *leerCadena(ifstream &file, int maximo, char delimitador){
    char *cadena, auxiliar[maximo+1];
    file.getline(auxiliar, maximo, delimitador);
    cadena = new char[strlen(auxiliar)+1];
    strcpy(cadena, auxiliar);
    return cadena;
}