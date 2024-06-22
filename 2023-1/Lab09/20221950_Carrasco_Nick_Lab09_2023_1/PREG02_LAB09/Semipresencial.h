/* 
 * File:   Semipresencial.h
 * Author: Casco
 *
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include "Alumno.h"
using namespace std;

class Semipresencial : public Alumno{
public:
    Semipresencial();
    virtual ~Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &);
    void imprime(ofstream &);
    void actualizatotal(double);
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

