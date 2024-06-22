/* 
 * File:   NPedido.h
 * Author: Casco
 *
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H

class NPedido {
public:
    NPedido();
    NPedido(const NPedido& orig);
    virtual ~NPedido();
private:
    char *codigo;
    int cantidad;
    double peso;
};

#endif /* NPEDIDO_H */

