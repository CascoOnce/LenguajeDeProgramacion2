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
    Furgon(const Furgon& orig);
    virtual ~Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream& file);
    void imprime(ofstream& file);

private:
    int filas;
    int puertas;
    list<class NPedido>pdeposito;
};

#endif /* FURGON_H */

