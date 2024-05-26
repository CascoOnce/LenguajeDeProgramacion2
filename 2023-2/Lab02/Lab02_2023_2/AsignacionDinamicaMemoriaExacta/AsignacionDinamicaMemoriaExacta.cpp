
#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>

using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#include "AperturaDeArchivos.h"
#include "funciones.h"

enum ProductosChar{COD, DES};
enum PedidosInt{DNI, CAN};

void lecturaDeProductos (const char *nameFile, char ***&productos, int *&stock, double *&precios){
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, nameFile);
    // BIT-434,Campana Extractora modelo Glass,375.09,10
    char **bufferProductos[500], *codigo, *descripcion, c;
    int bufferStock[500], stocki, cantDatos = 0;
    double bufferPrecios[500], precio;
    while (true){
        codigo = leerCadena(file, 8);
        if (file.eof()) break;
        descripcion = leerCadena(file);
        file >> precio >> c >> stocki;
        while (file.get()!='\n');
        bufferProductos[cantDatos] = regProducto(codigo, descripcion);
        bufferPrecios[cantDatos] = precio;
        bufferStock[cantDatos] = stocki;
        cantDatos++;
    }
    productos = new char **[cantDatos+1]{};
    stock = new int [cantDatos+1]{};
    precios = new double [cantDatos+1]{};
    for(int i = 0; i < cantDatos; i++){
        productos[i] = bufferProductos[i];
        stock[i] = bufferStock[i];
        precios[i] = bufferPrecios[i];
    }
}

char **regProducto(char *codigo, char *descripcion){
    char **producto = new char *[2];
    producto[COD] = codigo;
    producto[DES] = descripcion;
    return producto;
}

void pruebaDeLecturaDeProductos (const char *nameFile, char ***productos, const int *stock, const double *precios){
    ofstream file;
    AperturaDeUnArchivoDeTextosParaEscribir(file, nameFile);
    for (int i = 0; precios[i] != 0; i++){
        char **producto;
        producto = productos[i];
        file << i+1 << ')' << producto[COD] << ' ' << producto[DES] << ' ' << stock[i] << ' ' << precios[i] << endl;
    }
}

void lecturaDePedidos (const char *nameFile, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos){
    //JXD-139,50375303,6,24/08/2023
    ifstream file;
    AperturaDeUnArchivoDeTextosParaLeer(file, nameFile);
    int buffFechas[600]{}, nd[600]{}, cantDatos = 0, fecha, dni, cantidad, posicion;
    char *codigo;
    codigoPedidos = new char **[600]{};
    dniCantPedidos = new int **[600]{};
    while (true){
        lecturaDatos(file, codigo, dni, fecha, cantidad);
        if (file.eof()) break;
        posicion = busquedadFecha(buffFechas, fecha);
        if (posicion != - 1){ // Se encontro por lo tanto debo agregar los datos
            // Las fechas no necesitan modificarse
            char **regiCodigo = codigoPedidos[posicion];
            regiCodigo[nd[posicion]] = codigo;
            int **regiDni = dniCantPedidos[posicion];
            regiDni[nd[posicion]] = regDni(dni, cantidad);
            nd[posicion]++;
        }else{ //No se encontro por lo tanto debo inicializar los punteros y el buffer
            buffFechas[cantDatos] = fecha;
            codigoPedidos[cantDatos] = inicializarCodigo(codigo); //Inicializa el puntero
            dniCantPedidos[cantDatos] = inicializarDni(dni, cantidad); //Inicializa el puntero
            nd[cantDatos]++;
            cantDatos++;
        }
    }
    fechaPedidos = new int[cantDatos+1]{};
    for (int i = 0; i < cantDatos; i++){
        fechaPedidos[i] = buffFechas[i];
        arregloExactoCodigo(codigoPedidos[i], nd[i]);
        arregloDniExacto(dniCantPedidos[i], nd[i]);
    }
}

void lecturaDatos(ifstream &file, char *&codigo, int &dni, int &fecha, int &cantidad){
    int dd, mm, yy;
    char c;
    codigo = leerCadena(file, 8);
    if (file.eof()) return;
    file >> dni >> c >> cantidad >> c >> dd >> c >> mm >> c >> yy;
    while (file.get() != '\n');
    fecha = yy * 10000 + mm * 100 + dd;
}

int busquedadFecha(int *fechas, int fecha){
    for (int i = 0;fechas[i] != 0; i++){
        if (fechas[i] == fecha) return i;
    } return -1;
}

char **inicializarCodigo(char *codigo){
    char **reg = new char *[50]{};
    reg[0] = codigo;
    return reg;
}

int **inicializarDni(int dni, int cantidad){
    int **datosIntCliente = new int *[50]{};
    datosIntCliente[0] = regDni(dni, cantidad);
    return datosIntCliente;
}

int *regDni(int dni, int cantidad){
    int *datos = new int[2];
    datos[DNI] = dni;
    datos[CAN] = cantidad;
    return datos;
}

void arregloExactoCodigo(char **&arregloCodigos, int nd){
    char **auxiliar;
    if (nd > 0){
        auxiliar = new char*[nd+1]{};
        for (int i = 0; i < nd; i++){
            auxiliar[i] = new char[strlen(arregloCodigos[i])+1];
            strcpy(auxiliar[i],arregloCodigos[i]);
        }
        delete arregloCodigos;
        arregloCodigos = auxiliar;
    }else{
        delete arregloCodigos;
        arregloCodigos = nullptr;
    }
}

void arregloDniExacto(int **&arregloInt, int nd){
    int **auxiliar;
    if (nd > 0){
        auxiliar = new int *[nd+1]{};
        for (int i = 0; i < nd; i++){
            auxiliar[i] = arregloInt[i];
        }
        delete arregloInt;
        arregloInt = auxiliar;
    }else{
        delete arregloInt;
        arregloInt = nullptr;
    }
}

void reporteDeEnvioDePedidos(const char *nameFile, char ***&productos, int *&stock, double *&precios, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos){
    int dd, mm, yy, posProducto;
    double totalPedidoFaltaStock = 0, totalIngresado = 0, totalPerdido = 0, totalGanadoMes = 0;
    ofstream file;
    AperturaDeUnArchivoDeTextosParaEscribir(file, nameFile);
    file << setprecision(2) << fixed;
    file << setw((120+29)/2) <<  "REPORTE DE ENTREGA DE PEDIDOS" << endl;
    for (int i = 0; fechaPedidos[i] != 0; i++){
        totalPedidoFaltaStock = 0;
        totalIngresado = 0;
        char **productosDia = codigoPedidos[i];
        int **pedidosDia = dniCantPedidos[i];
        imprimirFecha(file, fechaPedidos[i]);
        imprimirCabecera(file);
        imprimirDia(file, productosDia, productos, pedidosDia, precios, stock, totalIngresado, totalPedidoFaltaStock);
        imprimirLinea(file, '-');
        imprimirIngreso(file, totalIngresado, totalPedidoFaltaStock);
        totalGanadoMes += totalIngresado;
        totalPerdido += totalPedidoFaltaStock;
    }
    imprimirLinea(file, '=');
    imprimirResume(file,totalGanadoMes, totalPedidoFaltaStock);
    imprimirLinea(file, '=');
}

void pruebaDeLecturaDePedidos(const char *nameFile, const int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos){
    ofstream file;
    AperturaDeUnArchivoDeTextosParaEscribir(file, nameFile);
    for (int i = 0; fechaPedidos[i] != 0; i++){
        file << fechaPedidos[i] << ' ' << endl;
        char **arrCodPedidos = codigoPedidos[i];
        int **arrDniPedidos = dniCantPedidos[i];
        for (int j = 0; arrDniPedidos[j] != 0; j++){
            int *datosClientePedido = arrDniPedidos[j]; 
            file << setw(7) << ' ' << arrCodPedidos[j] << ' ' << datosClientePedido[COD] << ' ' << datosClientePedido[CAN] << endl;
        }
    }
}

int posicionProducto(char ***&productos, char *codigoProducto){
    for (int i = 0; productos[i] != nullptr; i++){
        char **datosProductos = productos[i];
        if (strcmp(datosProductos[COD], codigoProducto) == 0) return i; 
    }
    return -1;
}

void imprimirCabecera(ofstream &file){
    //No. DNI Producto Cantidad Precio Total de ingresos
    file << right << setw(4) << "No." << ' ' 
        << left << setw(10) << "DNI" << ' '
        << left << setw(69) << "Producto" << ' '
        << right << setw(8) << "Cantidad" << ' ' 
        << right << setw(10) << "Precio" << ' '
        << right << setw(24) << "Total de ingresos" << endl;
    imprimirLinea(file, '-');
}

void imprimirDia(ofstream &file, char **productosDia, char ***productos, int **pedidosDia, double *precios, int *stock, double &totalIngresado, double &totalPedidoFaltaStock){
    double pago;
    for(int j = 0; productosDia[j] != nullptr; j++){
        int posProducto = posicionProducto(productos, productosDia[j]);
        if (posProducto != -1){
            char **datosProducto = productos[posProducto];
            int *datosPedido = pedidosDia[j];
            file << right << setw(3) << j+1 << ')' << ' ' 
                    << left << setw(10) << datosPedido[DNI] << ' '
                    << left << setw(8) << datosProducto[COD] << ' ' << setw(60) << datosProducto[DES] << ' '
                    << right << setw(8) << datosPedido[CAN] << ' ' 
                    << right << setw(10) << precios[posProducto] << ' ';
            pago = datosPedido[CAN]*precios[posProducto];
            if (stock[posProducto] >= datosPedido[CAN]){
                file << setw(24) << pago << endl;
                stock[posProducto] -= datosPedido[CAN];
                totalIngresado += pago;
            }else{
                file << setw(24) << "SIN STOCK" << endl;
                totalPedidoFaltaStock += pago;
            }
        }
    }
}

void imprimirIngreso(ofstream &file, double totalIngresado, double totalPedidoFaltaStock){
    file << left << setw(40) << "Total ingresado:" << right << setw(90) << totalIngresado << endl; 
    file << left << setw(40) << "Total perdido por falta de stock" << right << setw(90) << totalPedidoFaltaStock << endl; 
}

void imprimirResume(ofstream &file, double totalGanadoMes, double totalPedidoFaltaStock){
    file << "RESUMEN DE INGRESOS:" << endl;
    file << left << setw(40) << "Total de ingresos en el periodo:" << right << setw(90) << totalGanadoMes << endl;
    file << left << setw(40) << "Total perdido por falta de stock: " << right << setw(90) << totalPedidoFaltaStock << endl;
}











