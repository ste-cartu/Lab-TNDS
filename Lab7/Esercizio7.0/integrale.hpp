#ifndef integrale_hpp
#define integrale_hpp

#include <iostream>

#include "funzioni.hpp"
#include "libreria.hpp"

using namespace std;



//classe base: integratore generico
class integrale {

public:
  
    integrale (double a, double b){
        CheckInterval (a, b);
        nstep_ = 0;
        h_ = 0;
        somma_ = 0;
        val_ = 0;
    }

    virtual double Integra(unsigned int nstep, funzione& f) = 0;

protected:

    void CheckInterval (double a, double b){
        a_ = Min(a,b);
        b_ = Max(a, b);
        if(a > b ) sgn_ = -1;
        else if(a == b) sgn_ = 0;
        else sgn_ = 1;
    }

    unsigned int nstep_;
    double a_, b_;
    double somma_;
    double val_, h_;
    int sgn_;
    
};



//classe derivata: Midpoint
class midpoint: public integrale {

public:

    midpoint (double a, double b): integrale (a, b) {;};

    double Integra(unsigned int nstep, funzione& f) override{

        h_ = (b_-a_)/nstep;
        val_ = 0;
        if(sgn_ == 0) return 0;
        else{
            for(int i=0 ; i<nstep ; i++) {val_ += f.Eval(a_ + (i+0.5)*h_);}
            val_ *= sgn_*h_;
            
            return val_;
        }
    }

};

#endif
