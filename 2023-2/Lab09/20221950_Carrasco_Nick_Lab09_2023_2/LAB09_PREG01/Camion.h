/* 
 * File:   Camion.h
 * Author: Casco
 *
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"

class Camion : public Vehiculo{
public:
    Camion();
    Camion(const Camion& orig);
    virtual ~Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;
    void lee(ifstream& file);
    void imprime(ofstream& file);

private:
    int ejes;
    int llantas;
    map<int, class NPedido> mdeposito;
};

#endif /* CAMION_H */

