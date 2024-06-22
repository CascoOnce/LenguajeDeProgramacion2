/* 
 * File:   Tesoreria.cpp
 * Author: AdiosCasco
 * 
 */

#include "Tesoreria.h"
#include "AperturaDeArchivos.h"

void Tesoreria::cargaEscalas(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "escalas.csv");
    int codigo;
    char c;
    double precio;
    
    while(true){
        //3,454.20
        file >> codigo >> c;
        if (file.eof()) break;
        file >> precio;
        while(file.get() != '\n');
        lescala[codigo - 1].SetCodigo(codigo);
        lescala[codigo - 1].SetPrecio(precio);
    }
}

void Tesoreria::cargaAlumnos(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Alumnos.csv");
    
    char tipo, c;
    int cP = 0, cS = 0, cV = 0;
//    S,202123703,GAMARRA/TABORI/PAUL-RONAL,5,30
//    P,202119153,MENDOZA/ARIAS/HENRY,4,10
//    V,202318072,RIVERA/MONTERO/GLORIA-OFELIA,3,323R33-2
    while(true){
        file >> tipo >> c;
        if (file.eof()) break;
        switch (tipo){
            case 'P':
                lpresencial[cP].leerAlumno(file);
                cP++;
                break;
            case 'S':
                lsemipresencial[cS].leerAlumno(file);
                cS++;
                break;
            case 'V':
                lvirtual[cV].leerAlumno(file);
                cV++;
                break;
        }
    }
}

void Tesoreria::actualizar(double creditos) {
    int esc = 0;
    double precEsc = 0;
    for(int i = 0; lpresencial[i].GetCodigo() != 0 ; i++){
        esc = lpresencial[i].GetEscala();
        precEsc = lescala[esc - 1].GetPrecio();
        lpresencial[i].actualizar(precEsc*creditos);
    }
    for(int i = 0; lsemipresencial[i].GetCodigo() != 0 ; i++){
        esc = lsemipresencial[i].GetEscala();
        precEsc = lescala[esc - 1].GetPrecio();
        lsemipresencial[i].actualizar(precEsc*creditos);
    }
    for(int i = 0; lvirtual[i].GetCodigo() != 0 ; i++){
        esc = lvirtual[i].GetEscala();
        precEsc = lescala[esc - 1].GetPrecio();
        lvirtual[i].actualizar(precEsc*creditos);
    }
}


void Tesoreria::imprime(){
    ofstream file;
    AperturaDeUnArchivoDeTextosParaEscribir(file, "reportePrueba.txt");
    for(int i = 0; lpresencial[i].GetCodigo() != 0 ; i++){
        lpresencial[i].imprimirDatos(file);
    }
    for(int i = 0; lsemipresencial[i].GetCodigo() != 0 ; i++){
        lsemipresencial[i].imprimirDatos(file);
    }
    for(int i = 0; lvirtual[i].GetCodigo() != 0 ; i++){
        lvirtual[i].imprimirDatos(file);
    }
}