/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: alulab14
 *
 * Created on 19 de junio de 2024, 11:59 AM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include <fstream>
using namespace std;

class Lista {
public:
    Lista();
    Lista(const Lista& orig);
    void SetPeso(double peso);
    double GetPeso() const;
    void insertar(class Nodo *&auxiliar);
    void imprimeLista(ofstream &file);
    void actualizaVigencia();
private:
    double peso;
    class Nodo *ini;
};

#endif /* LISTA_H */

