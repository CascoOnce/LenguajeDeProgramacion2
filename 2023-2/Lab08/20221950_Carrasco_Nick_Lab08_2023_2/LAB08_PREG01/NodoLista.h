/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoLista.h
 * Author: Casco
 *
 * Created on 13 de junio de 2024, 11:08 PM
 */

#include "Vehiculo.h"
#include "LVehiculos.h"

#ifndef NODOLISTA_H
#define NODOLISTA_H

class NodoLista {
public:
    NodoLista();
    virtual ~NodoLista();
    void asignarMemoria(char);
    void cargarDatos(ifstream &);
    friend class LVehiculos;
private:
    class Vehiculo *unidad;
    class NodoLista *sig;
};

#endif /* NODOLISTA_H */

