#ifndef particella_hpp
#define particella_hpp

#include <iostream>

#define el 1.60217653E-19
#define Me 9.1093826E-31
#define Mp 1.67262171E-27

using namespace std;






class particella{

public:
    
    particella();
    
    particella(double massa, double carica){
        m_massa = massa;
        m_carica = carica;
    }
    
    ~particella() {;}
    
    double getMassa() const {return m_massa;}
    
    double getCarica() const {return m_carica;}
    
    void Stampa() const {
        cout << "Particella:" << endl;
        cout << "\tm = " << m_massa << endl;
        cout << "\tq = " << m_carica << endl;
    }
    
protected:
    
    double m_massa;
    double m_carica;
    
};


#endif
