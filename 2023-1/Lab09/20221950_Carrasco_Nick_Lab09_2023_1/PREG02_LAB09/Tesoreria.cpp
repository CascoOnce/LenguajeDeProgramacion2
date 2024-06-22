/* 
 * File:   Tesoreria.cpp
 * Author: Casco
 * 
 */

#include "Tesoreria.h"
#include "AperturaDeArchivos.h"

void Tesoreria::cargaescalas(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "escalas.csv");
    int pos;
    double precio;
    while (true){
        file >> pos;// 5,666.90
        if (file.eof()) break;
        file.get();
        file >> precio;
        lescala[pos - 1].SetCodigo(pos);
        lescala[pos - 1].SetPrecio(precio);
    }
}

void Tesoreria::cargaalumnos(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Alumnos.csv");
    char tipoDato;
    int pos = 0;
    while (true) {
        file >> tipoDato; //S,
        if (file.eof()) break;
        file.get();
        lboleta[pos].asignarMemoria(tipoDato);
        lboleta[pos].leerAlumno(file);
        pos++;
    }
}

void Tesoreria::imprimeboleta(){
    ofstream file;
    AperturaDeUnArchivoDeTextosParaEscribir(file, "reporte.txt");
    file << left << setw(10) << " Codigo" << setw(10) << ' '
            << left << setw(60) << "Nombre" << setw(10) << ' '
            << right << setw(10) << "Escala" << setw(10) << ' '
            << right << setw(10) << "Creditos" << setw(10) << ' '
            << left << setw(10) << "Licencia" 
            << right << setw(15) << "Total" << endl;
    file << setfill('=') << setw(180) << '=' << setfill(' ') << endl;
    for (int i = 0; lboleta[i].existe(); i++){
        lboleta[i].imprimeBoleta(file);
    }
}

void Tesoreria::actualizaboleta(){
    for (int i = 0; lboleta[i].existe(); i++){
        lboleta[i].actualizarTotal(lescala[lboleta[i].obtenerEscala()-1].GetPrecio());
    }
}