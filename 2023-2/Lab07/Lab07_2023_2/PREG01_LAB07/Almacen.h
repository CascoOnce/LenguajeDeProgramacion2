/* 
 * File:   Almacen.h
 * Author: AdiosCasco
 * 
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "OrdenVenta.h"


class Almacen {
public:
    Almacen();
    Almacen(const Almacen& orig);
    virtual ~Almacen();
    void cargar_pedidos();
private:
    OrdenVenta ordenes[700];
    int cantidad_ordenes;
};

#endif /* ALMACEN_H */

