/* 
 * File:   PrioridadAlta.h
 * Author: AdiosCasco
 *
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H

#include "Pedido.h"


class PrioridadAlta: public Pedido {
public:
    PrioridadAlta();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &file);
private:
    double recargo;
    double total;
};

#endif /* PRIORIDADALTA_H */

