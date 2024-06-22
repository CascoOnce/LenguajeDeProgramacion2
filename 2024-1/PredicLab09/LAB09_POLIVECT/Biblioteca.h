/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: Casco
 *
 * Created on 21 de junio de 2024, 12:39 AM
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estante.h"


class Biblioteca {
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    void carga();
private:
    vector<class Estante>AEstantes;
};

#endif /* BIBLIOTECA_H */

