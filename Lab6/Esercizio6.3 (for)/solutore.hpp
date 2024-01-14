#ifndef solutore_hpp
#define solutore_hpp

#include "funzione.hpp"

#include <vector>

using namespace std;



class solutore {

public:

    // Costruttori
    solutore() {m_n = 20; m_p = 1E-6; m_nmax = 100; m_ni = 0;}
    solutore(unsigned int n, double p) {m_n = n; m_p = p;}
    solutore(unsigned int n, double p, unsigned int nmax, unsigned int ni) {m_n = n; m_p = p; m_nmax = nmax; m_ni = ni;}

    // Distruttore virtuale
    virtual ~solutore() {;}

    
    virtual vector<double> CercaZeri (unsigned int n,
                                      const funzione& f,
                                      double p,
                                      unsigned int nmax) = 0;

    void SetP (double epsilon) {m_p = epsilon;}
    void SetNMax (unsigned int n) {m_nmax = n;}

    unsigned int GetNMax () {return m_nmax;}
    unsigned int GetN () {return m_n;}
    double GetP () {return m_p;}


protected:

    unsigned int m_n, m_nmax, m_ni;
    double m_p;
    
};


#endif
