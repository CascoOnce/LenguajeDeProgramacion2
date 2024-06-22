/* 
 * File:   Revista.cpp
 * Author: Casco
 * 
 */

#include "Revista.h"

Revista::Revista() {
    vigencia = 1;
}

void Revista::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Revista::GetVigencia() const {
    return vigencia;
}

void Revista::SetNumero(int numero) {
    this->numero = numero;
}

int Revista::GetNumero() const {
    return numero;
}

void Revista::SetAnho(int anho) {
    this->anho = anho;
}

int Revista::GetAnho() const {
    return anho;
}

void Revista::SetISSN(int ISSN) {
    this->ISSN = ISSN;
}

int Revista::GetISSN() const {
    return ISSN;
}

void Revista::lee(ifstream& file){
    Libro::lee(file); // Educacion,48,0.18,
    file >> ISSN; //10199403,2024,6
    file.get();
    file >> anho;
    file.get();
    file >> numero;
    file.get();
}

void Revista::imprime(ofstream& file){
    Libro::imprime(file);
    file << setw(7) << ' ' << "ISSN:" << left << setw(10) << ISSN
            << setw(7) << ' ' << "Año: " << left << setw(10) << anho
            << setw(7) << ' ' << "Numero: " << left << setw(10) << numero
            << setw(7) << ' ' << "Vigencia: " << left << setw(10) << vigencia << endl;
}

void Revista::actualiza(){
    if (anho <= 2000) vigencia = 0;
}