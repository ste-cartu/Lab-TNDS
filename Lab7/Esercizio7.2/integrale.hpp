#ifndef integrale_hpp
#define integrale_hpp

#include <iostream>

#include "funzioni.hpp"
#include "libreria.hpp"

using namespace std;



//classe base: integratore generico
class integrale {

public:
  
    integrale (funzione& f, double a, double b){
        CheckInterval (a, b);
        n_ = 0;
        h_ = 0;
        val_ = 0;
        somma_ = 0;
        f_ = &f;
    }
    
    virtual double Integra(unsigned int nstep) = 0;
    virtual double Integra(double p) = 0;
    
    unsigned int GetN() {return n_;}

protected:

    void CheckInterval (double a, double b){
        a_ = Min(a, b);
        b_ = Max(a, b);
        if(a > b ) sgn_ = -1;
        else if(a == b) sgn_ = 0;
        else sgn_ = 1;
    }

    unsigned int n_;
    double a_, b_;
    double val_, somma_;
    double h_;
    int sgn_;
    funzione* f_;
    
};



//classe derivata: Midpoint
class midpoint: public integrale {

public:

    midpoint (funzione& f, double a, double b): integrale (f, a, b) {;}

    double Integra(unsigned int nstep) override{
        h_ = (b_-a_)/nstep;
        val_ = 0;
        if(sgn_ == 0) return val_;
        
        else{
            for(int i=0 ; i<nstep ; i++) {val_ += f_ -> Eval(a_ + (i+0.5)*h_);}
            val_ *= sgn_*h_;
            
            return val_;
        }
    }
    
    double Integra(double p) override {
        cout << "Errore, utilizzare un algoritmo a numero di passi fissato per il metodo del midpoint!" << endl;
        cout << "Exiting..." << endl << endl;
        exit(0);
    }
    
};



//classe derivata: Simpson
class simpson: public integrale {

public:

    simpson (funzione& f, double a, double b): integrale (f, a, b) {;}

    double Integra(unsigned int nstep) override{
        
        while(nstep % 2 != 0) {
            cout << "Errore! Il metodo di Simpson prevede un numero pari di iterazioni!" << endl;
            cout << "Reinserire il numero di iterazioni: ";
            cin >> nstep;
            cout << endl;
        }
        
        h_ = (b_-a_)/nstep;
        val_ = 0;
        if(sgn_ == 0) return val_;
        
        else{
            val_ += (1./3) * f_ -> Eval(a_);
            for (int i=1 ; i<nstep-1 ; i++) {
                if(i % 2 != 0) {val_ += (4./3) * f_ -> Eval(a_ + i*h_);}
                else /*if(i % 2 == 0)*/ {val_ += (2./3) * f_ -> Eval(a_ + i*h_);}
            }
            val_ += ((1./3) * f_ -> Eval(b_));
            val_ *= h_;
            
            return val_*sgn_;
        }
        
    }
    
    double Integra(double p) override {
        cout << "Errore, utilizzare un algoritmo a numero di passi fissato per il metodo dei Simpson!" << endl;
        cout << "Exiting..." << endl << endl;
        exit(0);
    }
    
};




//classe derivata: Trapezoidi
class trapez: public integrale {

public:

    trapez (funzione& f, double a, double b): integrale (f, a, b) {}

    double Integra(unsigned int nstep) override {
        
        n_ = nstep;
        somma_ = (f_ -> Eval(a_) + f_ -> Eval(b_))/2.;
        h_ = (b_-a_)/n_;
        //h_ /= nstep;
        
        if(sgn_ == 0) {return val_;}
       
        else{
            for (int i=1 ; i<nstep ; i++) {somma_ += f_ -> Eval(a_ + i*h_);}
            val_ = somma_*h_;

            return val_*sgn_;
        }
        
    }
    
    double Integra(double p) override{
        
        somma_ = (f_ -> Eval(a_) + f_ -> Eval(b_))/2.;
        h_ = (b_-a_);
        
        if(sgn_ == 0) {return val_;}
        
        else{
            n_ = 1;
            //h_ = (b_-a_)/n_;
            val_ = p + (somma_*h_);
            
            while((4./3)*fabs((somma_*h_) - val_) > p) {
                val_ = somma_*h_;
                n_ *= 2;
                h_ = (b_-a_)/n_;
                
                for (int i=1 ; i<n_ ; i++) {
                    if(i%2 != 0) somma_ += f_ -> Eval(a_ + (i*h_));
                    
                }
            }
            val_ = somma_*h_;
            
            return val_*sgn_;
        }
        
    }
    
};




/*
//classe derivata: Trapezoidi
class trapez: public integrale {

public:

    trapez (funzione& f, double a, double b): integrale (f, a, b) {
        n_ = 2;
        h_ = (b_-a_)/100;
    }
    
    double Integra(unsigned int nstep) override {
        cout << "Errore, utilizzare un algoritmo a precisione fissata per il metodo dei trapezoidi!" << endl;
        cout << "Exiting..." << endl << endl;
        exit(0);
        
    }

    double Integra(double p) override{
        
        //somma_ = (f_ -> Eval(a_) + f_ -> Eval(b_))/2;

        if(sgn_ == 0) {return val_;}
//
//        else{
//            do {
//                val_ = somma_*h_;
//                h_ /= 2;
//                for(int i=1 ; i<n_ && i%2 != 0 ; i++) {somma_ += f_ -> Eval(a_ + i*h_);}
//                n_ *= 2;
//            } while(fabs(val_ - (somma_*h_)) > p);
//
//            val_ = somma_*h_;
//
//            return val_;
//        }

        
        else{
            somma_ += 0.5 * (f_ -> Eval(a_));
            for (int i=1 ; i<100 ; i++) {somma_ += f_ -> Eval(a_ + i*h_);}
            somma_ += 0.5 * (f_ -> Eval(b_));
            val_ = somma_*h_;

            return val_;
        }
        
    }
};
*/


#endif
