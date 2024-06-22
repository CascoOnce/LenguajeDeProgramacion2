/* 
 * File:   Escala.h
 * Author: Casco
 *
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala {
public:
    Escala();
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
private:
    int codigo;
    double precio;
};  

#endif /* ESCALA_H */

