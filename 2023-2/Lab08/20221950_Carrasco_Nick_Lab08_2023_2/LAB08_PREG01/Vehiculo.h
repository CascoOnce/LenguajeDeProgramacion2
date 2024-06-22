/* 
 * File:   Vehiculo.h
 * Author: Casco
 *
 */

#ifndef VEHICULO_H
#define VEHICULO_H

#include "NPedido.h"
#include "AperturaDeArchivos.h"
#include <fstream>
using namespace std;

class Vehiculo {
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetPed(NPedido* ped);
    NPedido* GetPed() const;
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char* placa) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &);
private:
    int codigo;
    char *placa;
    double maxcarga;
    double actcarga;
    NPedido *ped;
};

#endif /* VEHICULO_H */

