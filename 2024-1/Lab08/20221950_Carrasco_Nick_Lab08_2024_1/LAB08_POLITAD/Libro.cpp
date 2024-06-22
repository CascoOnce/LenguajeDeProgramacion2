/* 
 * File:   Libro.cpp
 * Author: Casco
 * 
 */

#include "Libro.h"
#include <cstring>
#include <iomanip>
using namespace std;

Libro::Libro() {
    nombre = nullptr;
}

Libro::Libro(const Libro& orig) {
}

Libro::~Libro() {
    delete nombre;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPaginas(int paginas) {
    this->paginas = paginas;
}

int Libro::GetPaginas() const {
    return paginas;
}

void Libro::SetNombre(const char* nombre) {
    if (this->nombre != nullptr) delete this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Libro::GetNombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Libro::lee(ifstream& file){
    //Diamantes y pedernales,120,0.4,Jose Maria Arguedas,
    char nombre[100];
    file.getline(nombre, 100, ',');
    if (file.eof()) return;
    SetNombre(nombre);
    file.get();
    file >> paginas;
    file.get();
    file >> peso;
    file.get();
}

void Libro::imprime(ofstream& file){
    char name[100];
    GetNombre(name);
    file << setprecision(2) << fixed;
    file << setw(7) << ' ' << "Titulo:" << name << endl
            << setw(7) << ' ' << "Peso: " << peso << endl;
}