/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.cpp
 * Author: alulab14
 * 
 * Created on 19 de junio de 2024, 12:01 PM
 */

#include "Estante.h"

Estante::Estante() {
    clase = '\0';
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

void Estante::leerEstante(ifstream& file){
    //H,1,20
    char c;
    int numberInt;
    double numberD;
    file >> c;
    if (file.eof()) return;
    SetClase(c);
    file.get();
    file >> numberInt >> c >> numberD; //1,20
    file >> ws; //\n
    SetId(numberInt);
    SetCapacidad(numberD);
}

double Estante::pesoActualEstante(){
    return Llibros.GetPeso();
}

void Estante::agregarEst(class Nodo *& aux){
    Llibros.insertar(aux);
}

bool Estante::existeEstante(){
    if (clase == '\0') return false;
    else return true;
}

void Estante::imprimeLibros(ofstream& file){
    Llibros.imprimeLista(file);
}

void Estante::actulizaLibros(){
    Llibros.actualizaVigencia();
}