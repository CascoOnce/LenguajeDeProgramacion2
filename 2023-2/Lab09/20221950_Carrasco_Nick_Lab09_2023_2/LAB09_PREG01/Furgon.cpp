/* 
 * File:   Furgon.cpp
 * Author: Casco
 * 
 */

#include "Furgon.h"

Furgon::Furgon() {
}

Furgon::Furgon(const Furgon& orig) {
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

void Furgon::lee(ifstream& file) {
    Vehiculo::lee(file); //16552775,S7E-946,300,2,3
    file >> filas;
    file.get();
    file >> puertas >> ws;
}

void Furgon::imprime(ofstream& file) {
    Vehiculo::imprime(file);
    file << left << setw(20) << "#Filas:" << filas <<endl
            << left << setw(20) << "#Puertas:" << puertas << endl;
}
