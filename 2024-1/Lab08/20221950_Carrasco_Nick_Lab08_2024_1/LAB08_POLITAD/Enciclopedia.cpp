/* 
 * File:   Enciclopedia.cpp
 * Author: casco
 * 
 */

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {
    vigencia = 1;
}

void Enciclopedia::SetVigencia(int vigencia) {
    this->vigencia = vigencia;
}

int Enciclopedia::GetVigencia() const {
    return vigencia;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}

void Enciclopedia::lee(ifstream& file){
    Libro::lee(file);
    file >> sku;
    file.get();
    file >> anho;
    file.get();
}

void Enciclopedia::imprime(ofstream& file){
    Libro::imprime(file);
    file << setw(7) << ' ' << "SKU:" << left << setw(10) << sku
            << setw(7) << ' ' << "Año: " << left << setw(10) << anho
            << setw(7) << ' ' << "Vigencia: " << left << setw(10) << vigencia << endl;
}

void Enciclopedia::actualiza(){
    if (anho <= 2000) vigencia = 0;
}