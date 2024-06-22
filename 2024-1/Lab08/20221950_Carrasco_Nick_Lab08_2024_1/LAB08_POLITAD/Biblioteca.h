/* 
 * File:   Biblioteca.h
 * Author: Casco
 *
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Estante.h"

using namespace std;

class Biblioteca {
public:
    void carga();
    void llena();
    void baja();
    void muestra();
private:
    class Estante AEstantes[10];
};

#endif /* BIBLIOTECA_H */

