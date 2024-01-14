#ifndef part_elett_hpp
#define part_elett_hpp

#include <iostream>

#define e 1.60217653E-19
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
    
    ~particella() {};
    
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






class elettrone: public particella{
    
public:
    
    elettrone(): particella(Me, -e) {};
    
    ~elettrone() {};
    
    void Stampa() const {
        cout << "Elettrone:" << endl;
        cout << "\tm = " << m_massa << endl;
        cout << "\tq = " << m_carica << endl;
    }
};




#endif
