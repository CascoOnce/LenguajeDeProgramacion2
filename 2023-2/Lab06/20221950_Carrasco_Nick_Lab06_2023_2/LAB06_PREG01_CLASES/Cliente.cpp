/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: Casco
 * 
 * Created on 24 de mayo de 2024, 05:24 AM
 */
#include <fstream>
#include <cstring>
using namespace std;

#include "Cliente.h"
#include "funciones.h"

Cliente::Cliente() {
    nombre = nullptr;
}

Cliente::Cliente(const Cliente& orig) {
}

Cliente::~Cliente() {
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::SetNombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Cliente::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

bool operator >> (ifstream &file, class Cliente &cl){
    //79464412,PORTUGAL RAFFO ALEXANDER,3902394
    int dni, telefono;
    char *name, c;
    file >> dni >> c;
    if (file.eof()) return false;
    name = leerCadena(file, 60, ',');
    file >> telefono;
    while (file.get()!= '\n');
    cl.SetDni(dni);
    cl.SetNombre(name);
    cl.SetTelefono(telefono);
    //cl.SetCantidad_productos_entregados(0);
    //cl.SetMonto_total(0);
    return true;
}
