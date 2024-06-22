/* 
 * File:   PrioridadMedia.h
 * Author: AdiosCasco
 * 
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H

#include "Pedido.h"

class PrioridadMedia: public Pedido{
public:
    PrioridadMedia();
    PrioridadMedia(const PrioridadMedia& orig);
    virtual ~PrioridadMedia();
    void SetNueva_fecha_entrega(int nueva_fecha_entrega);
    int GetNueva_fecha_entrega() const;
    void SetDescripcion(const char* descripcion);
    void GetDescripcion(char* descripcion) const;
    void lee(ifstream &file);
private:
    char *descripcion;
    int nueva_fecha_entrega;
};

#endif /* PRIORIDADMEDIA_H */

