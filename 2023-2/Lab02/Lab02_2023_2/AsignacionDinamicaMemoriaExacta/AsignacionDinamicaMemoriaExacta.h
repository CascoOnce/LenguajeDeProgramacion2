/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: AdiosCasco
 *
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void lecturaDeProductos (const char *nameFile, char ***&productos, int *&stock, double *&precios);
    char **regProducto (char *codigo, char *descripcion);
void pruebaDeLecturaDeProductos (const char *nameFile, char ***productos, const int *stock, const double *precios);

void lecturaDePedidos (const char *nameFile, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos);
    void lecturaDatos(ifstream &file, char *&codigo, int &dni, int &fecha, int &cantidad);
    int busquedadFecha(int *fechas, int fecha);
    char **inicializarCodigo(char *codigo);
    int **inicializarDni(int dni, int cantidad);
        int *regDni(int dni, int cantidad);
    void arregloExactoCodigo(char **&arregloCodigos, int nd);
    void arregloDniExacto(int **&arregloInt, int nd);
void pruebaDeLecturaDePedidos(const char *nameFile, const int *fechaPedidos, char ***codigoPedidos, int ***dniCantPedidos);

void reporteDeEnvioDePedidos(const char *nameFile, char ***&productos, int *&stock, double *&precios, int *&fechaPedidos, char ***&codigoPedidos, int ***&dniCantPedidos);
    int posicionProducto(char ***&productos, char *codigoProducto);
    void imprimirCabecera(ofstream &file);
    void imprimirDia(ofstream &file, char **productosDia, char ***productos, int **pedidosDia, double *precios, int *stock, double &totalIngresado, double &totalPedidoFaltaStock);
    void imprimirIngreso(ofstream &file, double totalIngresado, double totalPedidoFaltaStock);
    void imprimirResume(ofstream &file, double totalGanadoMes, double totalPedidoFaltaStock);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

