/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AlumnoNota.cpp
 * Author: Casco
 * 
 * Created on 23 de mayo de 2024, 11:10 PM
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AlumnoNota.h"
#include "funcionesAuxiliares.h"

AlumnoNota::AlumnoNota() {
    codCurso = nullptr;
}

AlumnoNota::AlumnoNota(const AlumnoNota& orig) {
}

AlumnoNota::~AlumnoNota() {
}

void AlumnoNota::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int AlumnoNota::GetCodigo() const {
    return codigo;
}

void AlumnoNota::SetCodCurso(const char* codCurso) {
    if (this->codCurso != nullptr) delete this->codCurso;
    this->codCurso = new char[strlen(codCurso)+1];
    strcpy(this->codCurso, codCurso);
}

void AlumnoNota::GetCodCurso(char* codCurso) const {
    if (this->codCurso == nullptr) codCurso[0] = '\0';
    else strcpy(codCurso, this->codCurso);
}

void AlumnoNota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int AlumnoNota::GetCiclo() const {
    return ciclo;
}

void AlumnoNota::SetNota(int nota) {
    this->nota = nota;
}

int AlumnoNota::GetNota() const {
    return nota;
}

bool operator >> (ifstream &file, class AlumnoNota &dato){
    //202123703,MEC270,202302,14
    int codAlu, ciclo, nota;
    char *codCurso, c;
    file >> codAlu >> c;
    if (file.eof()) return false;
    codCurso = leerCadena(file, 8, ',');
    file >> ciclo >> c >> nota;
    while (file.get() != '\n');
    dato.SetCodigo(codAlu);
    dato.SetCodCurso(codCurso);
    dato.SetCiclo(ciclo);
    dato.SetNota(nota);
    return true;
}

