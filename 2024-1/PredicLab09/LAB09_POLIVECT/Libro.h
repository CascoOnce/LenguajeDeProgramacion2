/* 
 * File:   Libro.h
 * Author: Casco
 *
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>

#include "AperturaDeArchivos.h"
using namespace std;

class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
private:
    char *nombre;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

