/* 
 * File:   Pedido.cpp
 * Author: AdiosCasco
 * 
 */

#include <cstring>

#include "Pedido.h"

Pedido::Pedido() {
    estado = nullptr;
    codigo = nullptr;
    subtotal = 0;
    total = 0;
}

Pedido::Pedido(const Pedido& orig) {
}

Pedido::~Pedido() {
    if (estado != nullptr) delete estado;
    if (codigo != nullptr) delete codigo;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetEstado(const char* estado) {
    if (this->estado != nullptr) delete this->estado;
    this->estado = new char [strlen(estado)+1];
    strcpy(this->estado, estado);
}

void Pedido::GetEstado(char* estado) const {
    if (this->estado == nullptr) estado[0] = '\0';
    else strcpy(estado, this->estado);
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
    return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* codigo) {
    if (this->codigo != nullptr) delete this->codigo;
    this->codigo = new char [strlen(codigo)+1];
    strcpy(this->codigo, codigo);
}

void Pedido::GetCodigo(char* codigo) const {
    if (this->codigo == nullptr) codigo[0] = '\0';
    else strcpy(codigo, this->codigo);
}

void Pedido::lee(ifstream &file){
    //UWA-476,88956889,25.85,2023-11-27,
    int yy, mm, dd;
    char cadena[10], c;
    file.getline(cadena, 10, ',');
    SetCodigo(cadena);
    file >> codigo >> c >> subtotal >> c;
    file >> yy >> c >> mm >> c >> dd >> c;
    SetFecha(yy*10000 + mm*100 + dd);
}
