/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.cpp
 * Author: Casco
 * 
 * Created on 24 de mayo de 2024, 05:15 AM
 */

#include <string.h>

#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado() {
    codigo = nullptr;
    precio = 0;
}

ProductoEntregado::ProductoEntregado(const ProductoEntregado& orig) {
}

ProductoEntregado::~ProductoEntregado() {
}

void ProductoEntregado::SetCodigo(const char* codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char [strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}

void ProductoEntregado::GetCodigo(char *codigo) const {
    if (this->codigo == nullptr) codigo[0] = '\0';
    else strcpy(codigo, this->codigo);
}

void ProductoEntregado::SetPrecio(double precio) {
    this->precio = precio;
}

double ProductoEntregado::GetPrecio() const {
    return precio;
}





