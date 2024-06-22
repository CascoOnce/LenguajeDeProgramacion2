/* 
 * File:   NVehiculo.cpp
 * Author: Casco
 * 
 */

#include "Camion.h"
#include "Furgon.h"
#include "NVehiculo.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

NVehiculo::NVehiculo(const NVehiculo& orig) {
    unidad = nullptr;
    *this = orig;
}

NVehiculo::~NVehiculo() {
//    if (unidad != nullptr) delete unidad;
}

void NVehiculo::leeVehiculo(ifstream& file) {
    char c;
    file >> c;
    if (file.eof()) return;
    file.get();
    asignarMemoria(c);
    unidad->lee(file);
}

void NVehiculo::asignarMemoria(char c) {
    switch(c){
        case 'F':
            unidad = new class Furgon;
            break;
        case 'C':
            unidad = new class Camion;
            break;
    }
}

void NVehiculo::imprimirVehiculo(ofstream& file) {
    unidad->imprime(file);
}
