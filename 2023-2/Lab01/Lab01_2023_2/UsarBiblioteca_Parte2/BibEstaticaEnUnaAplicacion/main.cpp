/* 
 * File:   main.cpp
 * Author: AdiosCasco
 *
 */

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "OperadoresSobrecargados.h"

#define maxClientes 200

int main(int argc, char** argv) {
    struct Cliente arrClientes[700];
    struct Producto arrProductos[700];
    struct Pedido arrPedidos[700];
    ifstream lectClientes, lectProductos, lectPedidos;
    ofstream repClientes, repProd;
    AperturaDeUnArchivoDeTextosParaLeer(lectClientes, "Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(lectProductos, "Productos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(lectPedidos, "Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(repClientes, "ReporteClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(repProd, "ReporteProductos.txt");
    int pedidos;
    for (int i = 0; lectClientes >> arrClientes[i]; i++);
    for (int i = 0; lectProductos >> arrProductos[i]; i++);
    for (int i = 0; ; i++){
        if (lectPedidos >> arrPedidos[i]){
            if (arrProductos += arrPedidos[i]) arrClientes += arrPedidos[i];
        }else{
            break;
        }    
    }
    repClientes << setw((110+21)/2) << "LISTA DE LOS CLIENTES" << endl;
    repClientes << "Generada por AdiosCasco" << endl;
    repClientes << setfill('=') << setw(200) << '=' << setfill(' ') << endl;
    repClientes << left << setw(10) << "DNI" << ' '
            << left << setw(80) << "NOMBRE" << ' '
            << left << setw(10) << "TELEFONO" << ' '
            << left << setw(8) << "GASTO" << ' ' << endl;
    repClientes << setfill('=') << setw(200) << '=' << setfill(' ') << endl;
    for (int i = 0; arrClientes[i].dni != 0; i++){
        repClientes << arrClientes[i];
        repClientes << setfill('-') << setw(200) << '-' << setfill(' ') << endl;
    }
    
    repProd << setw((110+21)/2) << "LISTA DE LOS PRODUCTOS" << endl;
    repProd << "Generada por AdiosCasco" << endl;
    repProd << setfill('=') << setw(200) << '=' << setfill(' ') << endl;
    repProd << left << setw(10) << "Codigo" << ' '
            << left << setw(80) << "Descripcion" << ' '
            << left << setw(10) << "Precio" << ' '
            << right << setw(10) << "Stock" << ' ' << endl;
    repProd << setfill('=') << setw(200) << '=' << setfill(' ') << endl;
    for (int i = 0; arrClientes[i].dni != 0; i++){
        repProd << arrProductos[i];
        repProd << setfill('-') << setw(200) << '-' << setfill(' ') << endl;
    }
    
    return 0;
}

