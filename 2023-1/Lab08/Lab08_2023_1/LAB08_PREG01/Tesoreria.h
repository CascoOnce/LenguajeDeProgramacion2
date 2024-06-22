/* 
 * File:   Tesoreria.h
 * Author: AdiosCasco
 *
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"


class Tesoreria {
public:
    void cargaEscalas();
    void cargaAlumnos();
    void actualizar(double creditos);
    void imprime();
private:
    Presencial lpresencial[50];
    Semipresencial lsemipresencial[50];
    Virtual lvirtual[50];
    Escala lescala[10];
};

#endif /* TESORERIA_H */

