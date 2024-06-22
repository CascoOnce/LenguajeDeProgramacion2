/* 
 * File:   Presencial.cpp
 * Author: AdiosCasco
 * 
 * Created on 30 de mayo de 2024, 01:17 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Presencial.h"

Presencial::Presencial() {
    total = 0;
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::leerAlumno(ifstream& file){
    //30
    double dato;
    Alumno::leerAlumno(file);
    file >> dato;
    file.get();
    SetRecargo(dato);
}

void Presencial::actualizar(double creditos){
    double dato = creditos*GetRecargo()/100;
    Alumno::SetTotal(creditos + dato);
}

void Presencial::imprimirDatos(ofstream &file){
    Alumno::imprimirDatos(file);
    file << setprecision(2) << fixed;
    file << right << setw(40) << Alumno::GetTotal() << endl; 
}