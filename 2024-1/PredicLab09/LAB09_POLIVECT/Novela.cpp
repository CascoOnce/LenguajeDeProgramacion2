/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Novela.cpp
 * Author: Casco
 * 
 * Created on 21 de junio de 2024, 12:00 AM
 */

#include "Novela.h"

Novela::Novela() {
}

Novela::Novela(const Novela& orig) {
}

Novela::~Novela() {
}

void Novela::SetAutor(const char* autor) {
    if (this->autor != nullptr) delete this->autor;
    this->autor = new char [strlen(autor) + 1];
    strcpy(this->autor, autor);
}

void Novela::GetAutor(char* autor) const {
    if (this->autor == nullptr) autor[0] = '\0';
    else strcpy(autor, this->autor);
}

