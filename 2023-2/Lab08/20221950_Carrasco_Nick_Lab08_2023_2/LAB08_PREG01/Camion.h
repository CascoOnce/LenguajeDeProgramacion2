/* 
 * File:   Camion.h
 * Author: Casco
 *
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"

class Camion: public Vehiculo{
public:
    Camion();
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream &);
private:
    int ejes;
    int llantas;
};

#endif /* CAMION_H */

