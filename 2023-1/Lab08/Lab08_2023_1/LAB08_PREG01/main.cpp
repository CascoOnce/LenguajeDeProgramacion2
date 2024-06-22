/* 
 * File:   main.cpp
 * Author: AdiosCasco
 *
 */

#include <iostream>

using namespace std;

#include "Tesoreria.h"

int main(int argc, char** argv) {
    Tesoreria caja;
    caja.cargaEscalas();
    caja.cargaAlumnos();
    caja.actualizar(20);
    caja.imprime();
    return 0;
}

