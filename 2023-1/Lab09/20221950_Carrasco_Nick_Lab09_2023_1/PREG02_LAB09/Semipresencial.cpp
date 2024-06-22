/* 
 * File:   Semipresencial.cpp
 * Author: Casco
 * 
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
}

Semipresencial::~Semipresencial() {
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

void Semipresencial::lee(ifstream &file){
    Alumno::lee(file); // 202123703,GAMARRA/TABORI/PAUL-RONAL,5,20,
    double number;
    file >> number; //30
    SetDescuento(number);
    while (file.get() != '\n');
}

void Semipresencial::imprime(ofstream &file){
    Alumno::imprime(file);
    file << right << setw(25) << total << endl;
}

void Semipresencial::actualizatotal(double precio){
    double valor;
    total = precio*GetCreditos();
    valor = descuento*total/100;
    this->SetTotal(total - valor);
    Alumno::actualizatotal(total);
}