
/* 
 * File:   main.cpp
 * Author: AdiosCasco
 *
 */

#include <iostream>
#include <fstream>

using namespace std;
#include "AperturaDeArchivos.h"
#include "OperadoresSobrecargados.h"
#include "Estructuras.h"

int main(int argc, char** argv) {
    ifstream file, file2, file3;
    AperturaDeUnArchivoDeTextosParaLeer(file, "Clientes.csv");
    struct Cliente arrClientes[150];
    int i;
    for (i = 0;  ; i++){
        if (not (file >> arrClientes[i])) break;
    }
//    cout << arrClientes[i-1].nombre;
    AperturaDeUnArchivoDeTextosParaLeer(file3, "Productos.csv");
    struct Producto arrProductos[200];
    int k;
    for (k = 0; ; k++){
        if (not (file3 >> arrProductos[k])) break;
    }
//    cout << arrProductos[k-1].codigo;
    AperturaDeUnArchivoDeTextosParaLeer(file2, "Pedidos.csv");
    struct Pedido arrPedidos[700];
    int j;
    for (j = 0; ; j++){
        if (not (file2 >> arrPedidos[j])) break;
    }
//    cout << arrPedidos[j-1].CodigoProducto;
    arrClientes += arrPedidos[552];
    cout << arrClientes[i-1];
    arrProductos += arrPedidos[j-1];
    cout << arrProductos[33] << endl;
//    cout << arrProductos[33].cantidadClientesServidos;
    return 0;
}

