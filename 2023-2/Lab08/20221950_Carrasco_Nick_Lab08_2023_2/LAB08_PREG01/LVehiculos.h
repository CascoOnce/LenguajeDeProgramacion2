/* 
 * File:   LVehiculos.h
 * Author: Casco
 
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H

#include "Vehiculo.h"

class LVehiculos {
public:
    LVehiculos();
    virtual ~LVehiculos();
    void crear(ifstream &);
    
private:
    class NodoLista *lini;
    class NodoLista *lfin;
    void asignar(class NodoLista);
};

#endif /* LVEHICULOS_H */

