/* 
 * File:   Virtual.cpp
 * Author: Casco
 * 
 */

#include "Virtual.h"

Virtual::Virtual() {
    licencia = nullptr;
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

void Virtual::SetLicencia(const char* licencia) {
    if (this->licencia == nullptr) delete this->licencia;
    this->licencia = new char [strlen(licencia)];
    strcpy(this->licencia, licencia);
}

void Virtual::GetLicencia(char* licencia) const {
    if (this->licencia == nullptr) licencia[0] = '\0';
    else strcpy(licencia, this->licencia);
}

void Virtual::lee( ifstream &file){
    Alumno::lee(file); // 202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,20,
    char cadena[10];
    file.getline(cadena, 10, '\n'); //323R33-2
    SetLicencia(cadena);
}

void Virtual::imprime(ofstream &file){
    Alumno::imprime(file);
    file << left << setw(10) << licencia 
            << right << setw(15) << total << endl;
}