/* 
 * File:   Tesoreria.h
 * Author: Casco
 *
 */

#ifndef TESORERIA_H
#define TESORERIA_H

#include "Boleta.h"
#include "Escala.h"


class Tesoreria {
public:
    void cargaescalas();
    void cargaalumnos();
    void imprimeboleta();
    void actualizaboleta();
private:
    class Boleta lboleta[100];
    class Escala lescala[10];
};

#endif /* TESORERIA_H */

