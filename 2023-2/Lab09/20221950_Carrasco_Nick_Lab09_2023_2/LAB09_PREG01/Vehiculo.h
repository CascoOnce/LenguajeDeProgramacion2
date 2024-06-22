/* 
 * File:   Vehiculo.h
 * Author: Casco
 *
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <map>
#include <list>
#include <vector>

#include "NPedido.h"

using namespace std;

class Vehiculo {
public:
    Vehiculo();
    Vehiculo(const Vehiculo& orig);
    virtual ~Vehiculo();
    void setActcarga(double actcarga);
    double getActcarga() const;
    void setMaxcarga(double maxcarga);
    double getMaxcarga() const;
    void setPlaca(const char *placa);
    void getPlaca(char *placa) const;
    void setCliente(int cliente);
    int getCliente() const;
    virtual void lee(ifstream &file);
    virtual void imprime(ofstream &file);
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga; // debe ser menor a maxcarga
};

#endif /* VEHICULO_H */

