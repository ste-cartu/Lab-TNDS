#ifndef solutore_hpp
#define solutore_hpp

#include "funzione.hpp"



class solutore {

public:

    // Costruttori
    solutore() {m_a = 0; m_b = 0; m_p = 0.001; m_nmax = 100; m_n = 0;}
    solutore(double a, double b, double p) {m_a = a; m_b = b; m_p = p;}
    solutore(double a, double b, double p, unsigned int nmax, unsigned int n) {m_a = a; m_b = b; m_p = p; m_nmax = nmax; m_n = n;}

    // Distruttore virtuale
    virtual ~solutore() {;}

    
    virtual double CercaZeri (double xmin,
                              double xmax,
                              const funzione& f,
                              double p,
                              unsigned int nmax) = 0;

    void SetP (double epsilon) {m_p = epsilon;}
    void SetNMax (unsigned int n) {m_nmax = n;}

    unsigned int GetNMax () {return m_nmax;}
    unsigned int GetN () {return m_n;}
    double GetP () {return m_p;}


protected:

    double m_a, m_b;
    double m_p;
    unsigned int m_nmax, m_n;

};


#endif
