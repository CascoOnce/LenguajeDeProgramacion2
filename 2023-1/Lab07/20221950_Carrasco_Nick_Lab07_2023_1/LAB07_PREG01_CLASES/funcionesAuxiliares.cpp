/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <fstream>
#include <cstring>
using namespace std;

char *leerCadena(ifstream &file, int maximo, int culminador){
    char *cadena, chain[maximo+1];
    file.getline(chain, maximo, culminador);
    cadena = new char[strlen(chain)+1];
    strcpy (cadena, chain);
    return cadena;
}