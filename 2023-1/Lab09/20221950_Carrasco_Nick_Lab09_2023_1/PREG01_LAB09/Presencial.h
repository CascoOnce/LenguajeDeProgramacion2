/* 
 * File:   Presencial.h
 * Author: Casco
 *
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include "Alumno.h"
using namespace std;

class Presencial : public Alumno{
public:
    Presencial();
    virtual ~Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

