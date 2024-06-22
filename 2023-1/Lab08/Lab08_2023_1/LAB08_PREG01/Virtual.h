/* 
 * File:   Virtual.h
 * Author: AdiosCasco
 *
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H

#include <fstream>
using namespace std;

#include "Alumno.h"

class Virtual: public Alumno {
public:
    Virtual();
    virtual ~Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char *licencia);
    void GetLicencia(char *licencia) const;
    void leerAlumno(ifstream &file);
    void actualizar(double credito);
    void imprimirDatos(ofstream &file);
private:
    char *licencia;
    double total;
};

#endif /* VIRTUAL_H */

