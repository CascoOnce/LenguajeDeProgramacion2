/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: Casco
 *
 * Created on 24 de mayo de 2024, 05:24 AM
 */

#include <fstream>
using namespace std;
#include "ProductoEntregado.h"

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
public:
    Cliente();
    Cliente(const Cliente& orig);
    virtual ~Cliente();
    void SetDni(int dni);
    int GetDni() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
    void SetTelefono(int telefono);
    int GetTelefono() const;
    void SetCantidad_productos_entregados(int cantidad_productos_entregados);
    int GetCantidad_productos_entregados() const;
    void SetMonto_total(double monto_total);
    double GetMonto_total() const;
    
private:
    int dni;
    char *nombre;
    int telefono;
    class ProductoEntregado productos_entregados[100];
    int cantidad_productos_entregados;
    double monto_total;
};

bool operator >> (ifstream &file, class Cliente &c);

#endif /* CLIENTE_H */

