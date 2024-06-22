/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Revista.h
 * Author: Casco
 *
 * Created on 21 de junio de 2024, 12:07 AM
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"


class Revista : public Libro{
public:
    Revista();
    Revista(const Revista& orig);
    virtual ~Revista();
private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
};

#endif /* REVISTA_H */

