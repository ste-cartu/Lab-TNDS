#ifndef __vettore_h__
#define __vettore_h__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

//#define NDEBUG

#include <assert.h>


using namespace std;



class vettore {
 public:

    vettore();                                              //costruttore di default
	vettore(unsigned int N);                                //costruttore con dimensione del vettore
    ~vettore();                                             //distruttore
    
    vettore(const vettore&);                                //costruttore di copia
    
    vettore& operator = (const vettore&);                   //overloading dell'operatore di assegnazione
    
    unsigned int GetN() const {return m_N;};                //accede alla dimensione del vettore, funzione implementata in-line (si fa con funzioni brevi)
    
	void Set(unsigned int, double);                         //modifica la componente i-esima
    
    double Get(unsigned int) const;                         //accede alla componente i-esima
    
    void Scambia(unsigned int, unsigned int);
    
    double& operator [] (unsigned int);
	

 private:

    unsigned int m_N;                                       //dimensione del vettore
    
    double* m_v;                                            //puntatore all'array di dati

};

#endif // __vettore_h__
