/* 
 * File:   Vehiculo.cpp
 * Author: Casco
 * 
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    placa = nullptr;
}

Vehiculo::~Vehiculo() {
    if (placa != nullptr) delete placa;
}

void Vehiculo::SetPed(NPedido* ped) {
    this->ped = ped;
}

NPedido* Vehiculo::GetPed() const {
    return ped;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(const char* placa) {
    if (this->placa != nullptr) delete this->placa;
    this->placa = new char[strlen(placa) + 1];
    strcpy(this->placa, placa);
}

void Vehiculo::GetPlaca(char* placa) const {
    if (this->placa == nullptr) placa[0] = '\0';
    else strcpy(placa, this->placa);
}

void Vehiculo::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Vehiculo::GetCodigo() const {
    return codigo;
}

void Vehiculo::lee(ifstream &file){
    // 79464412,K0D-676,300,
    char placaFake[10];
    file >> codigo;
    file.get();
    file.getline(placaFake, 10, ',');
    SetPlaca(placaFake);
    file >> maxcarga;
    file.get;
}