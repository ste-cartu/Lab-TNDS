#ifndef integrale_MC_hpp
#define integrale_MC_hpp

#include <iostream>
#include <vector>

#include "random.hpp"
#include "libreria.hpp"



class integraleMC {

public:
    
    integraleMC() : gen_(1) {err_ = 0.;}
    integraleMC(unsigned int seed, double err) : gen_(seed) {err_ = err;}
    ~integraleMC() {;}
    
    void SetErr(double e) {err_ = e;}
    
    double HitMiss(double a, double b, double max, funzione& f, unsigned int ntot){
        if(a > b){
            cout << "Attenzione! L'intervallo inserito nel metodo Hit or Miss è invalido!" << endl;
            exit(0);
        }
        
        unsigned int n = 0;
        for(int i=0 ; i<ntot ; i++){
            double x = gen_.Unif(a,b);
            double y = gen_.Unif(0, max);
            
            if(y < f(x)) {n++;}
        }
        
        return (b-a)*max*((double)n/ntot);
    }
    
    double Average(double a, double b, funzione& f, unsigned int ntot){
        if(a > b){
            cout << "Attenzione! L'intervallo inserito nel metodo della media è invalido!" << endl;
            exit(0);
        }
        
        vector<long double> V;
        for(int i=0 ; i<ntot ; i++){
            long double x = gen_.Unif(a,b);
            V.push_back(f(x));
        }
        
        return (b-a)*Media(V);
        
    }
    
        
    
private:
    
    randomgen gen_;
    double err_;
    unsigned int N_;
    
};





#endif
