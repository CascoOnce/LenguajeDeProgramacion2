/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnoNota.h
 * Author: Casco
 *
 * Created on 23 de mayo de 2024, 11:10 PM
 */

#include <fstream>
using namespace std;

#ifndef ALUMNONOTA_H
#define ALUMNONOTA_H

class AlumnoNota {
private:
    int codigo;
    char *codCurso;
    int ciclo;
    int nota;
public:
    AlumnoNota();
    AlumnoNota(const AlumnoNota& orig);
    virtual ~AlumnoNota();
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void SetCodCurso(const char *CodCurso);
    void GetCodCurso(char *CodCurso) const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetNota(int nota);
    int GetNota() const;
    
};

bool operator >> (ifstream &file, class AlumnoNota &dato);

#endif /* ALUMNONOTA_H */

