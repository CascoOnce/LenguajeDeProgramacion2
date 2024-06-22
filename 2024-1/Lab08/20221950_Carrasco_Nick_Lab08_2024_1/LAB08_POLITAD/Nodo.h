/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: alulab14
 *
 * Created on 19 de junio de 2024, 11:34 AM
 */

#ifndef NODO_H
#define NODO_H

#include "Libro.h"
#include "Novela.h"
#include "Enciclopedia.h"
#include "Revista.h"
#include <fstream>
using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    void leerLibro(ifstream &file);
    void asignarMemoria(char c);
    double pesoNodo();
    void imprimeNodo(ofstream &file);
    void actualizaNodo();
    friend class Lista;
private:
    Libro *plibro;
    Nodo *sig;
};

#endif /* NODO_H */

