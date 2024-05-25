

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;

#include "OperadoresSobrecargados.h"
#include "Estructuras.h"
#include "funciones.h"

bool operator >> (ifstream &file, struct Cliente &cliente){
    //79464412,PORTUGAL RAFFO ALEXANDER,3902394
    int dni, telefono;
    char *nombre, c;
    file >> dni >> c;
    if (file.eof()){
        cliente.dni = 0;
        return false;
    }
    nombre = leerCadena(file);
    file >> telefono;
    while(file.get() != '\n');
    cliente.dni = dni;
    strcpy(cliente.nombre, nombre);
    cliente.telefono = telefono;
    cliente.cantidadProductosEntrgados = 0;
    cliente.montoTotal = 0;
    return true;
}

bool operator >> (ifstream &file, struct Producto &producto){
    //BIT-434,Campana Extractora modelo Glass,375.09,10
    int stock;
    double precio;
    char *codigo, *descripcion, c;
    codigo = leerCadena(file, 8);
    if (file.eof()){
        strcpy(producto.codigo, "XXXXXXX");
        return false;
    }
    descripcion = leerCadena(file);
    file >> precio >> c >> stock;
    while (file.get() != '\n');
    strcpy(producto.codigo, codigo);
    strcpy(producto.descripcion, descripcion);
    producto.precio = precio;
    producto.stock = stock;
    producto.cantidadClientesServidos = 0;
    producto.cantidadClientesNoServidos = 0;
    return true;
}

bool operator >> (ifstream &file, struct Pedido &pedido){
    //JXD-139,50375303
    char *codigo, c;
    int dni;
    codigo = leerCadena(file, 8);
    if (file.eof()) return false;
    file >> dni;
    while (file.get() != '\n');
    pedido.dniCliente = dni;
    strcpy(pedido.CodigoProducto, codigo);
    pedido.precioProducto = 0;
    return true;
}

void operator += (struct Cliente *arregloClientes, const struct Pedido pedido){
    int dniPedido = pedido.dniCliente;
    int posCliente;
    for (posCliente = 0; arregloClientes[posCliente].dni != 0; posCliente++){
        if (arregloClientes[posCliente].dni == dniPedido) break;
    }
    if (arregloClientes[posCliente].dni == 0) return;
    int entregados = arregloClientes[posCliente].cantidadProductosEntrgados;
    strcpy(arregloClientes[posCliente].productosEntregados[entregados].codigo, pedido.CodigoProducto);
    arregloClientes[posCliente].productosEntregados[entregados].precio = pedido.precioProducto;
    arregloClientes[posCliente].montoTotal += pedido.precioProducto;
    arregloClientes[posCliente].cantidadProductosEntrgados++;
}

bool operator += (struct Producto *arregloProductos, struct Pedido &pedido){
    char codProducto[8];
    strcpy(codProducto, pedido.CodigoProducto);
    int posProd;
    for (posProd = 0; strcmp(arregloProductos[posProd].codigo, "XXXXXXX") != 0; posProd++){
        if (strcmp(arregloProductos[posProd].codigo, pedido.CodigoProducto) == 0) break;
    }
    if (strcmp(arregloProductos[posProd].codigo, "XXXXXXX") == 0) return false;
    int stock = arregloProductos[posProd].stock, posCliente = 0;
    pedido.precioProducto = arregloProductos[posProd].precio;
    if (stock > 0){
        posCliente = arregloProductos[posProd].cantidadClientesServidos;
        arregloProductos[posProd].clientesServidos[posCliente] = pedido.dniCliente;
        arregloProductos[posProd].cantidadClientesServidos++;
    }else{
        posCliente = arregloProductos[posProd].cantidadClientesNoServidos;
        arregloProductos[posProd].clientesNoServidos[posCliente] = pedido.dniCliente;
        arregloProductos[posProd].cantidadClientesNoServidos++;
        return false;
    }
    arregloProductos[posProd].stock--;
    return true;
}

ofstream &operator <<(ostream &file, const struct Cliente cliente){
    file << setprecision(2) << fixed;
    file << left << setw(10) << cliente.dni << ' '
            << left << setw(80) << cliente.nombre << ' '
            << right << setw(10) << cliente.telefono << ' '
            << right << setw(8) << cliente.montoTotal << ' ' << endl;
    if (cliente.cantidadProductosEntrgados == 0){
        file << "NO SE LE ENTREGARON PRODUCTOS" << endl;
    }else{
        file << "Productos entregados: " << endl;
        for (int i = 0; i < cliente.cantidadProductosEntrgados; i++){
            file << left << setw(22) << ' ' << setw(10) << cliente.productosEntregados[i].codigo << endl;
        }
    }
    
}

ofstream &operator <<(ostream &file, const struct Producto producto){
//    SJD-818 Refrigeradora CoolStyle 281A Steel 3387.75 15
//    Cilentes atendidos: 54761731 94326707 (*)
//    Clientes no atendidos: 71984468 46462527 22280452 (**)
    file << left << setw(10) << producto.codigo << ' ' 
            << left << setw(80) << producto.descripcion << ' '
            << right << setw(10) << producto.precio << ' '
            << right << setw(10) << producto.stock << ' ' << endl;
    
    if (producto.cantidadClientesServidos == 0) file << "NO SE ATENDIERON PEDIDOS" << endl;
    else {
        file << "Cliente atendidos: " << endl;
        for (int i = 0; i < producto.cantidadClientesServidos; i++){
            file << setw(23) << ' ' << producto.clientesServidos[i] << ' ' << endl;
        }
    }
    if (producto.cantidadClientesNoServidos == 0) file << "NO HAY CLIENTES SIN ATENDER" << endl;
    else{
        file << "Clientes no atendidos: " << endl;
        for (int i = 0; i < producto.cantidadClientesNoServidos; i++){
            file << setw(23) << ' ' << producto.clientesNoServidos[i] << ' ' << endl;
        }
    }
}