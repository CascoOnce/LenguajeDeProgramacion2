/* 
 * File:   Novela.cpp
 * Author: Casco
 * 
 */

#include <cstring>
using namespace std;
#include "Novela.h"
#include "Nodo.h"

Novela::Novela() {
    autor = nullptr;
}

Novela::~Novela() {
    delete autor;
}

void Novela::SetAutor(const char* autor) {
    if (this->autor != nullptr) delete this->autor;
    this->autor = new char[strlen(autor) + 1];
    strcpy(this->autor, autor);
}

void Novela::GetAutor(char *autor) const {
    if (this->autor == nullptr) autor[0] = '\0';
    else strcpy(autor, this->autor);
}

void Novela::lee(ifstream& file){
    Libro::lee(file);
    char aut[50];
    file.getline(aut, 50, '\n');
    SetAutor(aut);
}

void Novela::imprime(ofstream& file){
    Libro::imprime(file);
    char aut[100];
    GetAutor(aut);
    file << setw(7) << ' ' << "Autor:" << aut << endl;
}

void Novela::actualiza(){
    return;
}