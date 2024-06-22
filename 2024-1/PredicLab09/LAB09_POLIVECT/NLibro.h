/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NLibro.h
 * Author: Casco
 *
 * Created on 21 de junio de 2024, 12:24 AM
 */

#ifndef NLIBRO_H
#define NLIBRO_H

class NLibro {
public:
    NLibro();
    NLibro(const NLibro& orig);
    virtual ~NLibro();
private:
    class Libro *Nlibro;
};

#endif /* NLIBRO_H */

