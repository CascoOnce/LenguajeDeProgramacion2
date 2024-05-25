/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.h
 * Author: Casco
 *
 * Created on 23 de mayo de 2024, 11:12 PM
 */

#ifndef NOTA_H
#define NOTA_H

class Nota {
private:
    char *codCurso;
    int ciclo;
    int nota;
public:
    Nota();
    Nota(const Nota& orig);
    virtual ~Nota();
    void SetCodCurso(const char *codCurso);
    void GetCodCurso(char *codCurso) const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    void SetNota(int nota);
    int GetNota() const;
    
    void operator &(class AlumnoNota &a);
};

#endif /* NOTA_H */

