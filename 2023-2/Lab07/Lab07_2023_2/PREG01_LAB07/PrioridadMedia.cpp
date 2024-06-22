/* 
 * File:   PrioridadMedia.cpp
 * Author: AdiosCasco
 * 
 */

#include "PrioridadMedia.h"

PrioridadMedia::PrioridadMedia() {
}

PrioridadMedia::PrioridadMedia(const PrioridadMedia& orig) {
}

PrioridadMedia::~PrioridadMedia() {
}

void PrioridadMedia::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadMedia::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadMedia::SetDescripcion(const char* descripcion) {
    if (this->descripcion != nullptr) delete this->descripcion;
    this->descripcion = new char [strlen(descripcion)+1];
    strcpy(this->descripcion, descripcion);
}

void PrioridadMedia::GetDescripcion(char* descripcion) const {
    if (this->descripcion == nullptr) descripcion[0] = '\0';
    else strcpy(descripcion, this->descripcion);
}

void PrioridadMedia::lee(ifstream &file){
    char c;
    Pedido::lee(file);
    file >> c;
    SetDescripcion(c);
    while (file.get() != '\n');
}