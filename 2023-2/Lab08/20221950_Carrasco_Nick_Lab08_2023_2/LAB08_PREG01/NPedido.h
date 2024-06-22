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
    virtual ~NPedido();
    void SetSig(NPedido* sig);
    NPedido* GetSig() const;
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* codigo) const;
    
private:
    char *codigo;
    int cantidad;
    double peso;
    class NPedido *sig;
};

#endif /* NPEDIDO_H */

