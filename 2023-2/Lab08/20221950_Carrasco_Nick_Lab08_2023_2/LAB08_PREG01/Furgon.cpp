/* 
 * File:   Furgon.cpp
 * Author: Casco
 * 
 */

#include "Furgon.h"

Furgon::Furgon() {
}

Furgon::~Furgon() {
}

void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}

void Furgon::lee(ifstream &file){
    Vehiculo::lee(file); //16552775,S7E-946,300,
    file >> filas;
    file.get();
    file >> puertas; //2,3
    while (file.get() != '\n');
}
