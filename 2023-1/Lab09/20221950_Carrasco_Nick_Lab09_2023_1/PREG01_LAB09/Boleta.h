/* 
 * File:   Boleta.h
 * Author: Casco
 *
 */

#ifndef BOLETA_H
#define BOLETA_H

#include "Alumno.h"


class Boleta {
public:
    Boleta();
    virtual ~Boleta();
    void asignarMemoria(char tipoDato);
    void leerAlumno(ifstream &);
    void imprimeBoleta(ofstream &);
    bool existe();
private:
    class Alumno *pboleta;
};

#endif /* BOLETA_H */

