/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estante.h
 * Author: Casco
 *
 * Created on 21 de junio de 2024, 12:25 AM
 */

#ifndef ESTANTE_H
#define ESTANTE_H

#include "Libro.h"

class Estante {
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetActCapacidad(double actCapacidad);
    double GetActCapacidad() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    void SetClase(char clase);
    char GetClase() const;
    void leeEstante(ifstream &file);
private:
    char clase;
    int id;
    double capacidad;
    double actCapacidad;
    vector<class Libro>Llibros;
};

#endif /* ESTANTE_H */

