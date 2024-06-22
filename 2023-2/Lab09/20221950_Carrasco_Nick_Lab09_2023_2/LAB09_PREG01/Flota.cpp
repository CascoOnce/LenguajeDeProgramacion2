/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.cpp
 * Author: Casco
 * 
 * Created on 20 de junio de 2024, 09:45 PM
 */

#include "Vehiculo.h"
#include "Flota.h"
#include "AperturaDeArchivos.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
//    *this = orig;
}

Flota::~Flota() {
}

void Flota::cargaflota(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Vehiculos.csv");
    class NVehiculo auxiliar;
    while (true){
        if (file.eof()) break;
        auxiliar.leeVehiculo(file);
        vflota.push_back(auxiliar);
    }
//    for(vector<NVehiculo>::iterator it = vflota.begin(); it != vflota.end() - 1; it++);
//    vector<NVehiculo>::iterator it2 = vflota.begin();
//    vflota.erase(it2);
}

void Flota::muestracarga() {
    ofstream file;
    AperturaDeUnArchivoDeTextosParaEscribir(file, "MuestraVehículos.txt");
    for(NVehiculo Aux: vflota){
        Aux.imprimirVehiculo(file);
    }
}
