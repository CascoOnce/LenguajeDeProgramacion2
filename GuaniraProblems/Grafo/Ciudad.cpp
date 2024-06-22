/* 
 * File:   Ciudad.cpp
 * Author: Casco
 * 
 */

#include "Ciudad.h"

Ciudad::Ciudad() {
    nombre.clear();
}

Ciudad::Ciudad(string nombre){
    this->nombre = nombre;
}

void Ciudad::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Ciudad::GetNombre() const {
    return nombre;
}

bool Ciudad::operator ==(Ciudad& orig){
    return 
}