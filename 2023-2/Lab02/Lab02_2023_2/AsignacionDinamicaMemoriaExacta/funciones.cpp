
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "funciones.h"
char *leerCadena(ifstream &file, int maximo, char culminador){
    char *cadena, auxiliar[maximo];
    file.getline(auxiliar, maximo, culminador);
    cadena = new char[strlen(auxiliar)+1];
    strcpy(cadena, auxiliar);
    return cadena;
}

void imprimirLinea(ofstream &file, char caracter, int maximo){
    file << setfill(caracter) << setw(maximo) << caracter << setfill(' ') << endl;
}

void imprimirFecha(ofstream &file, int fecha){
    //20230815
    int yy, mm, dd;
    yy = fecha/10000;
    fecha = fecha % 10000;
    mm = fecha/100;
    fecha = fecha % 100;
    dd = fecha;
    imprimirLinea(file, '=');
    file << "FECHA: " << setfill('0') << setw(2) << dd << '/' << setw(2) << mm << '/' << setw(4) << yy << setfill(' ') << endl;
    imprimirLinea(file, '=');
}