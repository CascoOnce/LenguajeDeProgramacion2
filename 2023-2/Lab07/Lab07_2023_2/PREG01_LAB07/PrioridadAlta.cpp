/* 
 * File:   PrioridadAlta.cpp
 * Author: AdiosCasco
 * 
 */

#include "PrioridadAlta.h"

PrioridadAlta::PrioridadAlta() {
    total = 0;
}

void PrioridadAlta::SetTotal(double total) {
    this->total = total;
}

double PrioridadAlta::GetTotal() const {
    return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
    return recargo;
}

void PrioridadAlta::lee(ifstream &file){
    Pedido::lee(file);
    file >> recargo;
    while (file.get != '\n');
}