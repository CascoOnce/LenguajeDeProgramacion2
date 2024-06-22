/* 
 * File:   Biblioteca.cpp
 * Author: Casco
 * 
 */

#include "AperturaDeArchivos.h"
#include "Biblioteca.h"

void Biblioteca::carga(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Estantes2.csv");
    for (int i = 0; not file.eof(); i++) AEstantes[i].leerEstante(file);
}

void Biblioteca::llena(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Libros3.csv");
    //Variables:
    class Nodo *auxiliar; // Para poder leer los datos en una variable temporal
    int i = 0; // Posicion del Estanto
    while (AEstantes[i].existeEstante() and not file.eof()){ // Mientras exista un estante y no se haya terminado el archivo, se ejecutará el programa
        auxiliar = new class Nodo;
        auxiliar -> leerLibro(file);
        if (AEstantes[i].GetCapacidad() < AEstantes[i].pesoActualEstante() + auxiliar->pesoNodo()) // Supera la capacidad
            if (not AEstantes[++i].existeEstante()) break; // Se descarta el siguiente si este no existe;
        AEstantes[i].agregarEst(auxiliar);
//        delete auxiliar;
    }
}

void Biblioteca::muestra(){
    ofstream file("Reporte.txt", ios::out);
    file << setw(7) << ' ' << "ESTANTES:" << endl;
    file << setw(7) << ' ' << setw(7) << setfill('=') << setw(80) << '=' << endl << setfill(' ') << endl;
    for (int i = 0; AEstantes[i].existeEstante(); i++){
        file << setw(7) << ' ' << "Id: " << AEstantes[i].GetId() << endl;
        file << setw(7) << ' ' << "Tipo: ";
        if (AEstantes[i].GetClase() == 'H') file << "Horizontal" << endl;
        else file << "Vertical" << endl;
        file << setw(7) << ' ' << "Capacidad: " << AEstantes[i].GetCapacidad() << endl;
        file << setw(7) << ' ' << "Libros Contenidos: " << endl;
        file << setfill('-') << setw(80) << '-' << endl << setfill(' ');
        AEstantes[i].imprimeLibros(file);
        file << setfill('=') << setw(80) << '=' << endl << setfill(' ');
    }
}

void Biblioteca::baja(){
    for (int i = 0; AEstantes[i].existeEstante(); i++) AEstantes[i].actulizaLibros(); //Actualiza cada biblioteca
}