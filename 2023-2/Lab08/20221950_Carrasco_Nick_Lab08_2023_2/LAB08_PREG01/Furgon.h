/* 
 * File:   Furgon.h
 * Author: Casco
 *
 */

#ifndef FURGON_H
#define FURGON_H

#include "Vehiculo.h"


class Furgon : public Vehiculo{
public:
    Furgon();
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &);
private:
    int filas;
    int puertas;
};

#endif /* FURGON_H */

