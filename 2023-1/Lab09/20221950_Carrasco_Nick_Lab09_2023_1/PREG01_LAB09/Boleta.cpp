/* 
 * File:   Boleta.cpp
 * Author: Casco
 * 
 */

#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    if (pboleta != nullptr) delete pboleta;
}

void Boleta::asignarMemoria(char tipoDato) {
    switch (tipoDato){
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
}

void Boleta::leerAlumno(ifstream &file){
    pboleta->lee(file);
}

void Boleta::imprimeBoleta(ofstream &file){
    pboleta->imprime(file);
}

bool Boleta::existe(){
    if (pboleta != nullptr) return true;
    return false;
}