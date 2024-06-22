/* 
 * File:   Pedido.h
 * Author: AdiosCasco
 *
 */

#include <fstream>
using namespace std;

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido {
public:
    Pedido();
    Pedido(const Pedido& orig);
    virtual ~Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEstado(const char* estado);
    void GetEstado(char* estado) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* codigo) const;
    void lee(ifstream &file);
private:
    char *codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char *estado;
    double total;
};

#endif /* PEDIDO_H */

