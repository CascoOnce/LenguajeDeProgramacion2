/* 
 * File:   Camion.cpp
 * Author: Casco
 * 
 * Created on 13 de junio de 2024, 10:59 PM
 */

#include "Camion.h"

Camion::Camion() {
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

void Camion::lee(ifstream &file){
    Vehiculo::lee(file);
    // 1,3
    file >> ejes;
    file.get();
    file >> llantas;
    while (file.get() != '\n');
}