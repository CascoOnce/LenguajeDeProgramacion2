/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ciudad.h
 * Author: Casco
 *
 * Created on 19 de junio de 2024, 08:44 AM
 */

#ifndef CIUDAD_H
#define CIUDAD_H
#include <string>
using namespace std;
class Ciudad {
public:
    Ciudad(string nombre = "Sin Nombre");
    Ciudad(string nombre);
//    Ciudad(const Ciudad& orig);
    virtual ~Ciudad();
    bool operator == (const class Ciudad &orig);
    bool operator < (const class Ciudad &orig);
    void SetNombre(string nombre);
    string GetNombre() const;
    
private:
    string nombre;
};

#endif /* CIUDAD_H */

