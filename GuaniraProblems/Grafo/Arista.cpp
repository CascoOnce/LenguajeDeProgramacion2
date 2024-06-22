/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arista.cpp
 * Author: Casco
 * 
 * Created on 19 de junio de 2024, 08:52 AM
 */

#include "Arista.h"
#include "Ciudad.h"

Arista::Arista() {
    longitud = 0;
}

Arista::
Arista::Arista(double longitud, Ciudad& destino) {
    this->longitud = longitud;
    this->destino = destino;
}

Arista::Arista(const Arista& orig) {
    this->longitud = longitud;
    this->destino = destino;
}

void Arista::imprimeArista(){
    cout << setprecision(2) << fixed;
    cout << "Longitud: " << longitud << endl << cout << "Destino: " << destino.GetNombre() << endl;
}