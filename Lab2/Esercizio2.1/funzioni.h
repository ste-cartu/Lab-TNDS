#ifndef funzioni_h
#define funzioni_h

#include <iostream>
#include <cmath>
#include <fstream>
#include "vettore.h"

using namespace std;



void Leggi(vettore&, const char*);

void Stampa(vettore);

double Media(const vettore&);

double Varianza(const vettore&);

void Swap(double&, double&);

void Ordina(vettore&);

void Stampa(vettore, const char*);

double Mediana(vettore);



#endif /* funzioni_h */

