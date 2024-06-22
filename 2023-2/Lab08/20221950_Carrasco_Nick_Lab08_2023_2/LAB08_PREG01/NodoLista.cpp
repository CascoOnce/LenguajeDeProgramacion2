/* 
 * File:   NodoLista.cpp
 * Author: Casco
 * 
 */

#include "NodoLista.h"

NodoLista::NodoLista() {
    unidad = nullptr;
    sig = nullptr;
}

NodoLista::~NodoLista() {
    if (unidad != nullptr) delete unidad;
    if (sig != nullptr) delete sig;
}

void NodoLista::asignarMemoria(char tipo){
    switch (tipo){
        case 'F':
            unidad = new class Furgon;
            break;
        case 'C':
            unidad = new class Camion;
            break;
    }
}

void NodoLista::cargarDatos(ifstream &file){
    unidad->lee(file);
}