/* 
 * File:   OrdenVenta.h
 * Author: AdiosCasco
 * 
 */

#include "Pedido.h"

#ifndef ORDENVENTA_H
#define ORDENVENTA_H

class OrdenVenta {
public:
    OrdenVenta();
    OrdenVenta(const OrdenVenta& orig);
    virtual ~OrdenVenta();
private:
    Pedido *ptr_orden;
};

#endif /* ORDENVENTA_H */

