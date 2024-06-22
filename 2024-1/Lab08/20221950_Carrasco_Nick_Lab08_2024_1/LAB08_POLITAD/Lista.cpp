/* 
 * File:   Lista.cpp
 * Author: Casco
 * 
 */

#include "Lista.h"

Lista::Lista() {
    ini = nullptr;
    peso = 0;
}

Lista::Lista(const Lista& orig) {
}

void Lista::SetPeso(double peso) {
    this->peso = peso;
}

double Lista::GetPeso() const {
    return peso;
}

void Lista::insertar(Nodo*& auxiliar){
    class Nodo *p = ini, *ant = nullptr, *nuevo;
    nuevo = new class Nodo;
    nuevo = auxiliar;
    while(p != nullptr){
        ant = p;
        p = p->sig;
    }
    if (ant != nullptr) ant->sig = nuevo;
    else ini = nuevo;
    peso += auxiliar->pesoNodo();
}

void Lista::imprimeLista(ofstream& file){
    class Nodo *p = ini;
    while(p != nullptr){
        p->imprimeNodo(file);
        file << endl;
        p = p->sig;
    }
}

void Lista::actualizaVigencia(){
    class Nodo *p = ini;
    while (p != nullptr){
        p->actualizaNodo();
        p = p->sig;
    }
}