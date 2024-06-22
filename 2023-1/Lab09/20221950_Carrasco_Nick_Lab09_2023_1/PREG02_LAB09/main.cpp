/* 
 * File:   main.cpp
 * Author: AdiosCasco
 *
 */

#include <iostream>
#include "Tesoreria.h"
using namespace std;

int main(int argc, char** argv) {
    Tesoreria OTeso;
    OTeso.cargaescalas();
    OTeso.cargaalumnos();
    OTeso.actualizaboleta();
    OTeso.imprimeboleta();
    return 0;
}

