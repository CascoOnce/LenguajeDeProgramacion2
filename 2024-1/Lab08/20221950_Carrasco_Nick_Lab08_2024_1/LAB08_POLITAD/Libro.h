/* 
 * File:   Libro.h
 * Author: Casco
 *
 */

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#ifndef LIBRO_H
#define LIBRO_H

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
    virtual void lee(ifstream &file);
    virtual void imprime(ofstream &file);
    virtual void actualiza() = 0;
private:
    char *nombre; //titulo;
    int paginas;
    double peso;
};

#endif /* LIBRO_H */

