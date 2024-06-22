/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Casco
 * 
 * Created on 21 de junio de 2024, 12:39 AM
 */

#include <vector>

#include "Libro.h"
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
}

Biblioteca::Biblioteca(const Biblioteca& orig) {
}

Biblioteca::~Biblioteca() {
}

void Biblioteca::carga() {
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Estantes2.csv");
    Estante aux;
    while(true){
        if (file.eof()) break;
        aux.leeEstante(file);
        AEstantes.push_back(aux);
    }
    cout << AEstantes.size() << endl;
}
