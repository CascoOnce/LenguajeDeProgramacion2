/* 
 * File:   Flota.h
 * Author: Casco
 *
 */

#ifndef FLOTA_H
#define FLOTA_H

#include "NVehiculo.h"
#include "Vehiculo.h"

class Flota {
public:
    Flota();
    Flota(const Flota& orig);
    virtual ~Flota();
    void cargaflota();
    void muestracarga();
private:
    vector<class NVehiculo>vflota;
};

#endif /* FLOTA_H */

