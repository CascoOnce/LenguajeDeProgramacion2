/* 
 * File:   Alumno.h
 * Author: Casco
 *
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Alumno {
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char* nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    virtual void lee(ifstream &);
    virtual void imprime(ofstream &);
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
};

#endif /* ALUMNO_H */

