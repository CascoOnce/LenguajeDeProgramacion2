/* 
 * File:   Almacen.cpp
 * Author: AdiosCasco
 * 
 */

#include "Almacen.h"
#include "AperturaDeArchivos.h"

Almacen::Almacen() {
    cantidad_ordenes = 0;
}

void Almacen::cargar_pedidos(){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Pedidos.csv");
    //B,JXD-139,50375303,64.82,2023-12-01,5
    //M,CRU-009,50375303,49.38,2023-11-26,1
    //A,YYK-309,22777006,69.37,2023-11-11,7
    char c;
    
    while (true){
        file >> c;
        file.get();
        if (file.eof()) break;
        switch(c){
            case 'A':
                ordenes[cantidad_ordenes] = new class PrioridadAlta;
                ordenes[cantidad_ordenes].
                break;
        }
        
    }
    
}