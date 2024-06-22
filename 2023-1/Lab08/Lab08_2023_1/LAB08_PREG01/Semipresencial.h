/* 
 * File:   Semipresencial.h
 * Author: AdiosCasco
 *
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H

#include <fstream>
using namespace std;

#include "Alumno.h"

class Semipresencial: public Alumno {
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void leerAlumno(ifstream &file);
    void actualizar(double creditos);
    void imprimirDatos(ofstream &file);
    
private:
    double descuento;
    double total;
};

#endif /* SEMIPRESENCIAL_H */

