#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

//#define NDEBUG

#include <assert.h>


using namespace std;



class Vettore {
 public:

    Vettore();                                              //costruttore di default
	Vettore(unsigned int N);                                //costruttore con dimensione del vettore
    ~Vettore();                                             //distruttore
    
    Vettore(const Vettore&);                                //costruttore di copia
    
    Vettore& operator = (const Vettore&);                   //overloading dell'operatore di assegnazione
    
    unsigned int GetN() const {return m_N;};                //accede alla dimensione del vettore, funzione implementata in-line (si fa con funzioni brevi)
    
	void Set(unsigned int, double);                         //modifica la componente i-esima
    
    double Get(unsigned int) const;                         //accede alla componente i-esima
    
    void Scambia(unsigned int, unsigned int);
	

 private:

    unsigned int m_N;                                       //dimensione del vettore
    double* m_v;                                            //puntatore all'array di dati

};

#endif // __Vettore_h__
