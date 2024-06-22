/* 
 * File:   Alumno.cpp
 * Author: AdiosCasco
 * 
 */

#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    codigo = 0;
    total = 0.0;
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

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Alumno::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::leerAlumno(ifstream &file){
    //202123703,GAMARRA/TABORI/PAUL-RONAL,5,
    int codigo, escala;
    char nombre[60], c;
    file >> codigo >> c;
    file.getline(nombre, 60, ',');
    file >> escala >> c;
    SetCodigo(codigo);
    SetNombre(nombre);
    SetEscala(escala);
}

void Alumno::imprimirDatos(ofstream &file){
    char cadena[60];
    GetNombre(cadena);
    file << setprecision(2) << fixed;
    file << left << setw(10) << GetCodigo() << setw(20) << ' ' 
            << left << setw(60) << cadena << setw(10) << ' '
            << right << setw(4) << GetEscala() << setw(6) << ' ';
}