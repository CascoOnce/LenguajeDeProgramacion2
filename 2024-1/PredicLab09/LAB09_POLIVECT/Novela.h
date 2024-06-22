/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.h
 * Author: Casco
 *
 * Created on 21 de junio de 2024, 12:00 AM
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"


class Novela : public Libro{
public:
    Novela();
    Novela(const Novela& orig);
    virtual ~Novela();
    void SetAutor(const char* autor);
    void GetAutor(char *autor) const;
private:
    char *autor;
};

#endif /* NOVELA_H */

