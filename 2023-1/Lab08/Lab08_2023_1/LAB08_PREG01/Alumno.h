/* 
 * File:   Alumno.h
 * Author: AdiosCasco
 *
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <fstream>
using namespace std;

class Alumno {
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leerAlumno(ifstream &file);
    void imprimirDatos(ofstream &file);
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
};

#endif /* ALUMNO_H */

