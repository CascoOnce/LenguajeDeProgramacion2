/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nota.cpp
 * Author: Casco
 * 
 * Created on 23 de mayo de 2024, 11:12 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Nota.h"
#include "AlumnoNota.h"

Nota::Nota() {
}

Nota::Nota(const Nota& orig) {
}

Nota::~Nota() {
}

void Nota::SetCodCurso(const char *codCurso) {
    if (this->codCurso != nullptr) delete this->codCurso;
    this->codCurso = new char[strlen(codCurso)+1];
    strcpy(this->codCurso, codCurso);
}

void Nota::GetCodCurso(char *codCurso) const {
    if (this->codCurso == nullptr) codCurso[0] = '\0';
    else strcpy(codCurso, this->codCurso);
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}

void Nota::SetNota(int nota) {
    this->nota = nota;
}

int Nota::GetNota() const {
    return nota;
}

void Nota::operator &(class AlumnoNota &a){
    char cadena[10];
    a.GetCodCurso(cadena);
    SetCodCurso(cadena);
    SetCiclo(a.GetCiclo());
    SetNota(a.GetNota());
}
