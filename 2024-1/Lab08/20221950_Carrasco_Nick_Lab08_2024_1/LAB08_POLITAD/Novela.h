/* 
 * File:   Novela.h
 * Author: Casco
 *
 */

#ifndef NOVELA_H
#define NOVELA_H

#include "Libro.h"

class Novela : public Libro{
public:
    Novela();
    virtual ~Novela();
    void SetAutor(const char *autor);
    void GetAutor(char *autor) const;
    void lee(ifstream& file);
    void imprime(ofstream& file);
    void actualiza();

private:
    char *autor;
};

#endif /* NOVELA_H */

