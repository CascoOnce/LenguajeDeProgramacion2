/* 
 * File:   Alumno.cpp
 * Author: Casco
 * 
 */

#include "Alumno.h"

Alumno::Alumno() {
    total = 0;
    nombre = nullptr;
}

Alumno::~Alumno() {
    if (nombre != nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* nombre) {
    if (this->nombre == nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre)];
    strcpy(this->nombre, nombre);
}

void Alumno::GetNombre(char* nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::lee(ifstream &file){
    // 202119153,MENDOZA/ARIAS/HENRY,4,19.5,
    char nombre[60];
    int numberInt;
    double numberDou;
    file >> numberInt;
    if (file.eof()) return;
    file.get();
    SetCodigo(numberInt);
    file.getline(nombre, 60, ',');
    SetNombre(nombre);
    file >> numberInt;
    file.get();
    SetEscala(numberInt);
    file >> numberDou;
    file.get();
    SetCreditos(numberDou);
}

void Alumno::imprime(ofstream &file){
    char name[60];
    GetNombre(name);
    file << setprecision(2) << fixed;
    file << right << setw(10) << GetCodigo() << setw(10) << ' '
            << left << setw(60) << name << setw(10) << ' '
            << right << setw(10) << GetEscala() << setw(10) << ' '
            << right << setw(10) << GetCreditos() << setw(10) << ' ';
}

void Alumno::actualizatotal(double pago){
    total = pago;
}