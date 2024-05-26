
/* 
 * File:   funciones.h
 * Author: AdiosCasco
 *
 */

#include <fstream>
using namespace std;

#ifndef FUNCIONES_H
#define FUNCIONES_H

char *leerCadena(ifstream &file, int maximo = 60, char culminador = ',');
void imprimirLinea(ofstream &file, char caracter, int maximo = 130);
void imprimirFecha(ofstream &file, int fecha);

#endif /* FUNCIONES_H */

