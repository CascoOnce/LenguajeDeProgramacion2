/* 
 * File:   NVehiculo.h
 * Author: Casco
 *
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H

#include "Vehiculo.h"

class NVehiculo {
public:
    NVehiculo();
    NVehiculo(const NVehiculo& orig);
    virtual ~NVehiculo();
    void leeVehiculo(ifstream &file);
    void asignarMemoria(char c);
    void imprimirVehiculo(ofstream &file);
private:
    Vehiculo *unidad;
};

#endif /* NVEHICULO_H */

