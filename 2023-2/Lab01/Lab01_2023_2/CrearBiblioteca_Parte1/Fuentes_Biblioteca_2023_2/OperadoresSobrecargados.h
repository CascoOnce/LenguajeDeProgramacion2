/* 
 * File:   OperadoresSobrecargados.h
 * Author: AdiosCasco
 *
 */

#include <fstream>
using namespace std;

#include "Estructuras.h"

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H

bool operator >> (ifstream &file, struct Cliente &cliente);
bool operator >> (ifstream &file, struct Producto &producto);
bool operator >> (ifstream &file, struct Pedido &pedido);

void operator += (struct Cliente *arregloClientes, const struct Pedido pedido);
bool operator += (struct Producto *arregloProductos, struct Pedido &pedido);

ofstream &operator <<(ostream &file, const struct Cliente cliente);
ofstream &operator <<(ostream &file, const struct Producto producto);

#endif /* OPERADORESSOBRECARGADOS_H */

