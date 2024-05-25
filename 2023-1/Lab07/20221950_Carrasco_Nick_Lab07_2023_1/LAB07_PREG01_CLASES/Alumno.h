/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.h
 * Author: Casco
 *
 * Created on 23 de mayo de 2024, 11:13 PM
 */
#include <fstream>
using namespace std;
#include "Nota.h"

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo;
    char *nombre;
    int numCursos;
    int numAprobados;
    int numPrimera;
    int numSegunda;
    int numTercera;
    class Nota lNotas[100];
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetNombre(const char *nombre);
    void GetNombre(char *nombre) const;
    void SetNumCursos(int numCursos);
    int GetNumCursos() const;
    
    void SetNumTercera(int numTercera);
    int GetNumTercera() const;
    void SetNumSegunda(int numSegunda);
    int GetNumSegunda() const;
    void SetNumPrimera(int numPrimera);
    int GetNumPrimera() const;
    void SetNumAprobados(int numAprobados);
    int GetNumAprobados() const;
    
    void operator +=(class Nota &n);
    
};

bool operator >> (ifstream &in, class Alumno &alumno);
ofstream &operator << (ofstream &out, class Alumno &alumno);

#endif /* ALUMNO_H */

