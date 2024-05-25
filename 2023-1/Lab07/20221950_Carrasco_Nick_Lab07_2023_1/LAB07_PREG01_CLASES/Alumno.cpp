/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Casco
 * 
 * Created on 23 de mayo de 2024, 11:13 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Alumno.h"
#include "funcionesAuxiliares.h"

using namespace std;

Alumno::Alumno() {
    nombre = nullptr;
}

Alumno::Alumno(const Alumno& orig) {
}

Alumno::~Alumno() {
}

//CODIGO
    void Alumno::SetCodigo(int codigo) {
        this->codigo = codigo;
    }

    int Alumno::GetCodigo() const {
        return codigo;
    }
//NOMBRE
    void Alumno::SetNombre(const char *nombre) {
        if (this->nombre != nullptr) delete this->nombre;
        this->nombre = new char[strlen(nombre)+1];
        strcpy(this->nombre, nombre);
    }

    void Alumno::GetNombre(char *nombre) const {
        if (this->nombre == nullptr) nombre[0] = '\0';
        else strcpy(nombre, this->nombre);
    }
//NUMCURSOS
    void Alumno::SetNumCursos(int numCursos) {
        this->numCursos = numCursos;
    }

    int Alumno::GetNumCursos() const {
        return numCursos;
    }

// No utiles aún
    void Alumno::SetNumAprobados(int numAprobados) {
        this->numAprobados = numAprobados;
    }

    int Alumno::GetNumAprobados() const {
        return numAprobados;
    }
    
    void Alumno::SetNumPrimera(int numPrimera) {
        this->numPrimera = numPrimera;
    }

    int Alumno::GetNumPrimera() const {
        return numPrimera;
    }
    
    void Alumno::SetNumSegunda(int numSegunda) {
        this->numSegunda = numSegunda;
    }

    int Alumno::GetNumSegunda() const {
        return numSegunda;
    }
    
    void Alumno::SetNumTercera(int numTercera) {
        this->numTercera = numTercera;
    }

    int Alumno::GetNumTercera() const {
        return numTercera;
    }

void Alumno::operator +=(class Nota &n){
    lNotas[numCursos] = n;
    numCursos++;
}

ofstream &operator << (ofstream &out, class Alumno &alumno){
    out << "Codigo del Alumno: " << alumno.GetCodigo() << endl;
    char nombre[60];
    alumno.GetNombre(nombre);
    out << "Nombre del Alumno: " << nombre << endl;
    out << "Detalle de Cursos: " << endl;
    out << left;
    out << setw(15) <<  "Cursados" << setw(15) << "Aprobados" << setw(15) << "1ra vez" 
            << setw(15) << "2da vez" << setw(15) << "3ra vez" << endl;
    out << setw(15) <<  alumno.GetNumCursos() << setw(15) << alumno.GetNumAprobados() << setw(15) << alumno.GetNumPrimera() 
            << setw(15) << alumno.GetNumSegunda() << setw(15) << alumno.GetNumTercera() << endl;
    return out;
}
    
bool operator >> (ifstream &in, class Alumno &alumno){
    //202123703,GAMARRA TABORI PAUL RONAL,S,30,G5
    int cod;
    char *name, c;
    in >> cod >> c;
    if (in.eof()) return false;
    name = leerCadena(in);
    while (in.get() != '\n');
    alumno.SetCodigo(cod);
    alumno.SetNombre(name);
    alumno.SetNumAprobados(0);
    alumno.SetNumCursos(0);
    alumno.SetNumPrimera(0);
    alumno.SetNumSegunda(0);
    alumno.SetNumTercera(0);
    return true;
}
//ofstream &operator >>