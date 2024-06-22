/* 
 * File:   Vehiculo.cpp
 * Author: Casco
 * 
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa = nullptr;
    actcarga = 0;
}

Vehiculo::Vehiculo(const Vehiculo& orig) {
}

Vehiculo::~Vehiculo() {
    if (placa != nullptr) delete placa;
}

void Vehiculo::setActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::getActcarga() const {
    return actcarga;
}

void Vehiculo::setMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::getMaxcarga() const {
    return maxcarga;
}

void Vehiculo::setPlaca(const char* placa) {
    if (this->placa != nullptr) delete this->placa;
    this->placa = new char [strlen(placa) + 1];
    strcpy(this->placa, placa);
}

void Vehiculo::getPlaca(char* placa) const {
    if (this->placa == nullptr) placa[0] = 0;
    else strcpy(placa, this->placa);
}

void Vehiculo::setCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::getCliente() const {
    return cliente;
}

void Vehiculo::lee(ifstream& file) {
    // 79464412,K0D-676,300
    int dni;
    char plac[10];
    file >> dni;
    if (file.eof()) return;
    setCliente(dni);
    file.get();
    file.getline(plac, 10, ',');
    setPlaca(plac);
    file >> maxcarga;
    file.get();
}

void Vehiculo::imprime(ofstream& file) {
    char plac[10];
    getPlaca(plac);
    file << setprecision(2) << fixed;
    file << left << setw(20) << "Codigo Cliente:" << getCliente() << endl
            << left << setw(20) << "Placa:" << plac << endl
            << left << setw(20) << "Carga Maxima:" << maxcarga << endl
            << left << setw(20) << "Carga Actual:" << actcarga << endl;
}

