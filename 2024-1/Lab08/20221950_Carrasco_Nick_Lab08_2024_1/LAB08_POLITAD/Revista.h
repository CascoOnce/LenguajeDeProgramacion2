/* 
 * File:   Revista.h
 * Author: Casco
 *
 */

#ifndef REVISTA_H
#define REVISTA_H

#include "Libro.h"

class Revista : public Libro{
public:
    Revista();
    void SetVigencia(int vigencia);
    int GetVigencia() const;
    void SetNumero(int numero);
    int GetNumero() const;
    void SetAnho(int anho);
    int GetAnho() const;
    void SetISSN(int ISSN);
    int GetISSN() const;
    void lee(ifstream &file);
    void imprime(ofstream &file);
    void actualiza();

private:
    int ISSN;
    int anho;
    int numero;
    int vigencia;
};

#endif /* REVISTA_H */

