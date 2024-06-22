/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.h
 * Author: alulab14
 *
 * Created on 19 de junio de 2024, 12:01 PM
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include <fstream>
#include "Lista.h"
using namespace std;

class Estante {
public:
    Estante();
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    void leerEstante(ifstream &file);
    void agregarEst(class Nodo *&aux);
    double pesoActualEstante();
    bool existeEstante();
    void imprimeLibros(ofstream &file);
    void actulizaLibros();
private:
    char clase;
    int id;
    double capacidad;
    Lista Llibros;
};

#endif /* ESTANTE_H */

