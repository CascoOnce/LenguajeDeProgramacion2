/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ProductoEntregado.h
 * Author: Casco
 *
 * Created on 24 de mayo de 2024, 05:15 AM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
    void SetCodigo(const char *codigo);
    void GetCodigo(char *codigo) const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_H */

