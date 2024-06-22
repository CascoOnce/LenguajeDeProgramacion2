/* 
 * File:   main.cpp
 * Author: Casco
 *
 */

#include "Biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca bli;
    
    bli.carga();
    bli.llena();
    bli.baja();
    bli.muestra();
    
    return 0;
}
