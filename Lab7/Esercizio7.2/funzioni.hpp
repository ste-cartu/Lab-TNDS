#ifndef funzioni_hpp
#define funzioni_hpp

#include <cmath>

#include "libreria.hpp"

using namespace std;




class funzione {

public:
    
    funzione() {m_a = 0;}
    virtual double Eval(double) const = 0;
    virtual ~funzione() {;}

protected:
    
    double m_a;
    
};



//FUNZIONI PARTICOLARI
//y = a*x^2 + b*x + c
class parabola : public funzione {

public:

    parabola() {m_a=0.; m_b=0.; m_c=0.;}
    parabola(double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
    ~parabola() {;}
    double Eval (double x) const override {return m_a*x*x + m_b*x + m_c;}
    void SetA (double a) {m_a=a;}
    double GetA () const {return m_a;}
    void SetB (double b) {m_b=b;}
    double GetB () const {return m_b;}
    void SetC (double c) {m_c=c;};
    double GetC () const {return m_c;}

private:

    double m_a, m_b, m_c;

};



//y = a*sin(b*x) + c
class seno : public funzione {

public:

    seno() {m_a=1; m_b=1.; m_c=0.;}
    seno(double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
    ~seno() {;}
    double Eval (double x) const override {return m_a*sin(m_b*x) + m_c;}
    void SetA (double a) {m_a=a;}
    double GetA () const {return m_a;}
    void SetB (double b) {m_b=b;}
    double GetB () const {return m_b;}
    void SetC (double c) {m_c=c;};
    double GetC () const {return m_c;}

private:

    double m_a, m_b, m_c;

};




#endif
