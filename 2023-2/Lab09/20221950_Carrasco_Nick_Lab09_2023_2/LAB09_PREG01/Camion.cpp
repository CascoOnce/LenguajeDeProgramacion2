/* 
 * File:   Camion.cpp
 * Author: Casco
 * 
 */

#include "Camion.h"

Camion::Camion() {
}

Camion::Camion(const Camion& orig) {
}

Camion::~Camion() {
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}

void Camion::lee(ifstream& file) {
    Vehiculo::lee(file); // 79464412,K0D-676,300,1,3
    file >> ejes;
    file.get();
    file >> llantas >> ws;
}

void Camion::imprime(ofstream& file) {
    Vehiculo::imprime(file);
    file << left << setw(20) << "#Ejes:" << ejes << endl
            << left << setw(20) << "#Llantas:" << llantas << endl;
}
