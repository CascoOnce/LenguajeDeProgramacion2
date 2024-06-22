/* 
 * File:   Escala.h
 * Author: AdiosCasco
 *
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
public:
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;
};

#endif /* ESCALA_H */

