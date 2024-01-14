#ifndef particella_hpp
#define particella_hpp

#include <iostream>

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
    
    void Print() const {
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
    
    elettrone(): particella(9.1093826E-31, -1.60217653E-19) {};
    
    ~elettrone() {};
    
    void Print() const {
        cout << "Elettrone:" << endl;
        cout << "\tm = " << m_massa << endl;
        cout << "\tq = " << m_carica << endl;
    }
};




#endif /* particella_hpp */
