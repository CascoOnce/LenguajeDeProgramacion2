/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arista.h
 * Author: Casco
 *
 * Created on 19 de junio de 2024, 08:52 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ARISTA_H
#define ARISTA_H

class Arista {
public:
    Arista();
    Arista(double longitud, const class Ciudad &destino);
    Arista(const Arista& orig);
//    void operator = (const class Ciudad &orig);
    void imprimeArista();
private:
    double longitud;
    class Ciudad destino;
};

#endif /* ARISTA_H */

