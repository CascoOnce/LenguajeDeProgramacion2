/* 
 * File:   PrioridadBaja.cpp
 * Author: AdiosCasco
 * 
 */

#include "PrioridadBaja.h"

PrioridadBaja::PrioridadBaja() {
    nueva_fecha_entrega = 0;
}

void PrioridadBaja::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::SetDias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::GetDias_espera() const {
    return dias_espera;
}

void PrioridadBaja::lee(ifstream &file){
    Pedido::lee(file);
    file >> dias_espera;
    while (file.get() != '\n');
}