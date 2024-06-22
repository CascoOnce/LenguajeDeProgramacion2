/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: Casco
 * 
 * Created on 21 de junio de 2024, 12:25 AM
 */

#include "Estante.h"

Estante::Estante() {
    actCapacidad = 0;
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetActCapacidad(double actCapacidad) {
    this->actCapacidad = actCapacidad;
}

double Estante::GetActCapacidad() const {
    return actCapacidad;
}

void Estante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double Estante::GetCapacidad() const {
    return capacidad;
}

void Estante::SetId(int id) {
    this->id = id;
}

int Estante::GetId() const {
    return id;
}

void Estante::SetClase(char clase) {
    this->clase = clase;
}

char Estante::GetClase() const {
    return clase;
}

void Estante::leeEstante(ifstream& file) {
    char c;
    file >> c;
    if (file.eof()) return;
    SetClase(c);
    file.get();
    file >> id >> c >> capacidad >> ws;   
}
