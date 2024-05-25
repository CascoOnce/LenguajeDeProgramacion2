/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: Casco
 * 
 * Created on 24 de mayo de 2024, 05:33 AM
 */

#include <cstring>

#include "Producto.h"

Producto::Producto() {
    nombre = nullptr;
    descripcion = nullptr;
}

Producto::Producto(const Producto& orig) {
}

Producto::~Producto() {
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(const char *descripcion) {
    if (this->descripcion != nullptr) delete this->descripcion;
    this->descripcion = new char [strlen(descripcion)+1];
    strcpy(this->descripcion, descripcion);
}

void Producto::GetDescripcion(char *descripcion) const {
    if (this->descripcion == nullptr) descripcion[0] = '\0';
    else strcpy(descripcion, this->descripcion);
}

void Producto::SetNombre(const char *nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre, nombre);
}

void Producto::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

