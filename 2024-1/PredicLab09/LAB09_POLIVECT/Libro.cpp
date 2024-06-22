/* 
 * File:   Libro.cpp
 * Author: Casco
 * 
 */

#include <stddef.h>

#include "Libro.h"

Libro::Libro() {
    nombre = nullptr;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    if (nombre != nullptr) delete nombre;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Libro::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

