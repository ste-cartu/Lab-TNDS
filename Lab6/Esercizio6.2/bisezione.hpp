#ifndef bisezione_hpp
#define bisezione_hpp

#include "solutore.hpp"

#include <float.h> // Serve per includere DBL_MAX
#include <iostream>
#include <cfloat>

using namespace std;



class bisezione : public solutore {

public:

    // costruttori
    bisezione (): solutore() {;}
    bisezione (double a, double b, double p): solutore (a, b, p) {;}
    bisezione (double a, double b, double p, unsigned int nmax, unsigned int n): solutore (a, b, p, nmax, n) {;}

    ~bisezione () {;}

    double CercaZeri (double a,
                      double b,
                      const funzione& f,
                      double p = 0.001,
                      unsigned int nmax = 100 ) override {
        
        if(a > b) {
            cerr << "Errore! xmin > xmax" << endl << endl;
            exit(0);
        }
        
        if(sgn(f.Eval(a))*sgn(f.Eval(b)) > 0){
            cout << "La funzione non ha zeri nell'intervallo [" << a << ", " << b << "]!" << endl << endl;
            exit(0);
        }
        
        double z;
        bool esatto = false;
         
        for (int i=0 ; i<nmax ; i++){
            if(sgn(f.Eval(a))*sgn(f.Eval(b)) == 0){
                if(f.Eval(a) == 0) {
                    z = a;
                    esatto = true;
                }
                if(f.Eval(b) == 0) {
                    z = b;
                    esatto = true;
                }
                if(f.Eval(a) == 0 && f.Eval(b) == 0){
                    cerr << "Errore! Sia " << a << " che " << b << " sono zeri della funzione!" << endl << endl;
                    exit(0);
                }
                break;
            }
            
            else /* if(sgn(f.Eval(a))*sgn(f.Eval(b)) < 0) */ {
                double c = (a+b)/2;
                if(sgn(f.Eval(c)) == sgn(f.Eval(a))) {a = c;}
                if(sgn(f.Eval(c)) == sgn(f.Eval(b))) {b = c;}
            }
                       
            z = (b+a)/2;
            if((b-a)/2 <= z*DBL_EPSILON){
                cerr << "Il programma ha superato la precisione massima accessibile al calcolatore (" << z*DBL_EPSILON << ")!" << endl << endl;
                exit(0);
            }
            if((b-a)/2 <= p) break;
        }
            
        if((b-a)/2 > p && esatto == false){
            cout << "Raggiunto il numero massimo di ierazioni (" << nmax << ")" << endl << endl;
            cout << "Lo zero non è stato trovato con sufficiente precisione!" << endl;
            cout << "Semiampiezza dell'intervallo trovato: " << (b-a)/2 << endl;
            cout << "Precisione richiesta: " << p << endl << endl;
            exit(0);
        }
    
        return z;
        
    }

};

#endif
