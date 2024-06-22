/* 
 * File:   Virtual.h
 * Author: Casco
 *
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include "Alumno.h"
using namespace std;

class Virtual : public Alumno{
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char* licencia) const;
    void lee(ifstream &);
    void imprime(ofstream &);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

