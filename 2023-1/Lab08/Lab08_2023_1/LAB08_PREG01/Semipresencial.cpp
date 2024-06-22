/* 
 * File:   Semipresencial.cpp
 * Author: AdiosCasco
 * 
 */
#include <iostream>
#include <iomanip>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0;
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::leerAlumno(ifstream& file){
    Alumno::leerAlumno(file);
    double dato;
    file >> dato;
    file.get();
    SetDescuento(dato);
}

void Semipresencial::actualizar(double creditos){
    double dato = (GetDescuento()*creditos)/100;
    Alumno::SetTotal(creditos-dato);
}

void Semipresencial::imprimirDatos(ofstream& file){
    Alumno::imprimirDatos(file);
    file << setprecision(2) << fixed;
    file << right << setw(40) << Alumno::GetTotal() << endl;
}