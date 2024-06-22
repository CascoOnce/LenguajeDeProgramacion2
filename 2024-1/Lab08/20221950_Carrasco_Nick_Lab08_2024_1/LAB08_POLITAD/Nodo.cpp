/* 
 * File:   Nodo.cpp
 * Author: Casco
 * 
 */

#include "Nodo.h"

Nodo::Nodo() {
    plibro = nullptr;
    sig = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
    delete plibro;
    delete sig;
}

void Nodo::leerLibro(ifstream &file){
    char c;
    file >> c;
    if (file.eof()) return;
    file.get();
    asignarMemoria(c);
    plibro->lee(file);
}

void Nodo::asignarMemoria(char c){
    switch (c){
        case 'N':
            plibro = new class Novela;
            break;
        case 'E':
            plibro = new class Enciclopedia;
            break;
        case 'R':
            plibro = new class Revista;
            break;
    }
}

double Nodo::pesoNodo(){
    return plibro->GetPeso();
}

void Nodo::imprimeNodo(ofstream& file){
    plibro->imprime(file);
}

void Nodo::actualizaNodo(){
    plibro->actualiza();
}