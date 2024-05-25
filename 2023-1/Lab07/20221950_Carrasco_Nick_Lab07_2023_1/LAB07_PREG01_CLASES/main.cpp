/* 
 * File:   main.cpp
 * Author: AdiosCasco 20221950
 *
 * Created on 23 de mayo de 2024, 11:09 PM
 */

#include <iostream>
#include <fstream>

using namespace std;
#include "Alumno.h"
#include "AlumnoNota.h"
#include "Nota.h"

int main(int argc, char** argv) {
    ifstream file ("Alumnos.csv", ios::in);
    ifstream notas ("Notas.csv", ios::in);
    ofstream elif ("reporte.txt", ios::out);
    class Alumno arrAlumnos[100];
    class AlumnoNota notaIndi;
    class Nota notaCamb;
    int i, pos = 0;
    for (i = 0; file >> arrAlumnos[i];i++);
    while (notas >> notaIndi){
        pos = 0;
        for (int j = 0; j < i; j++){
             if (arrAlumnos[j].GetCodigo() == notaIndi.GetCodigo()){
                  pos = j;
                  break;
             }
        }
        if (pos != 0){
            notaCamb & notaIndi;
            arrAlumnos[pos] += notaCamb;
        }
    }
    for (int j = 0; j < i; j++) elif << arrAlumnos[j]; 
    return 0;
}

