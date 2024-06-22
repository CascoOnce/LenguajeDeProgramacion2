/* 
 * File:   Presencial.cpp
 * Author: Casco
 * 
 */

#include "Presencial.h"

Presencial::Presencial() {
}

Presencial::~Presencial() {
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

void Presencial::lee(ifstream &file){
    Alumno::lee(file); //202119153,MENDOZA/ARIAS/HENRY,4,19.5,
    double number;
    file >> number; // 10
    SetRecargo(number);
    while (file.get() != '\n');
}

void Presencial::imprime(ofstream &file){
    Alumno::imprime(file);
    file << right << setw(25) << GetTotal() << endl;
}

void Presencial::actualizatotal(double precio){
    double valor;
    total = precio*GetCreditos();
    valor = recargo*total/100;
    this->SetTotal(total + valor);
    Alumno::actualizatotal(total);
}