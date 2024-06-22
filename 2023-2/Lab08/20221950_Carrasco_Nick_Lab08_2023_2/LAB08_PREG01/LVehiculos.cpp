/* 
 * File:   LVehiculos.cpp
 * Author: Casco
 * 
 */

#include "LVehiculos.h"
#include "NodoLista.h"

LVehiculos::LVehiculos() {
    lini = nullptr;
    lfin = nullptr;
}

LVehiculos::~LVehiculos() {
    if (lini != nullptr) delete lini;
    if (lfin != nullptr) delete lfin;
}

void LVehiculos::crear(ifstream &file){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Vehiculos.csv");
    NodoLista auxiliar;
    char c;
    while (true){
        file >> c; //F,16552775,S7E-946,300,2,3
        if (file.eof()) break;
        file.get();
        auxiliar.asignarMemoria(c);
        auxiliar.cargarDatos(file);
        
    }
}

void LVehiculos::asignar(NodoLista dato){
    class NodoLista *recorrido = lini, *ant = nullptr, *nuevo;
    ;
    while (true){
        if (NodoLista.)
    }
}