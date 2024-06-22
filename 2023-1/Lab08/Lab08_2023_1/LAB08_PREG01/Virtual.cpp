/* 
 * File:   Virtual.cpp
 * Author: AdiosCasco
 * 
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
    total = 100.00;
}

Virtual::~Virtual() {
    if (licencia != nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char *licencia) {
    if (this->licencia != nullptr) this->licencia = nullptr;
    this->licencia = new char[strlen(licencia) + 1];
    strcpy(this->licencia, licencia);
}

void Virtual::GetLicencia(char *licencia) const {
    if (this->licencia == nullptr) licencia[0] = '\0';
    else strcpy(licencia, this->licencia);
}

void Virtual::leerAlumno(ifstream &file){
    char dato[60];
    Alumno::leerAlumno(file);
    file.getline(dato, 60);
    SetLicencia(dato);
}

void Virtual::actualizar(double credito){
    Alumno::SetTotal(total+credito);
}

void Virtual::imprimirDatos(ofstream& file){
    Alumno::imprimirDatos(file);
    char cadena[60];
    GetLicencia(cadena);
    file << setprecision(2) << fixed;
    file << setw(4) << ' '
            << left << setw(16) << cadena 
            << right << setw(20) << Alumno::GetTotal() << endl;
}