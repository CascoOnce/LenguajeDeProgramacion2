/* 
 * File:   Presencial.h
 * Author: AdiosCasco
 *
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H

#include <fstream>
using namespace std;
#include "Alumno.h"

class Presencial: public Alumno{
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    void leerAlumno(ifstream &file);
    void actualizar(double creditos);
    void imprimirDatos(ofstream &file);
private:
    double recargo;
    double total;
};

#endif /* PRESENCIAL_H */

