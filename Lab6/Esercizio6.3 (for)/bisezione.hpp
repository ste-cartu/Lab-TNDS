#ifndef bisezione_hpp
#define bisezione_hpp

#include "solutore.hpp"

#include <float.h> // Serve per includere DBL_MAX
#include <iostream>
#include <cfloat>
#include <cmath>

#define _USE_MATH_DEFINES //M_PI

using namespace std;



void Intervallo(int n){
    if(n == 0) {cout << "[0, 𝛑/2]";}
    if(n == 1) {cout << "[𝛑, 3𝛑/2]";}
    else if(n != 0 && n != 1) {cout << "[" << n << "𝛑, " << (2*n)+1 << "𝛑/2]";}
}



class bisezione : public solutore {

public:

    // costruttori
    bisezione (): solutore() {;}
    bisezione (unsigned int n, double p): solutore (n, p) {;}
    bisezione (unsigned int n, double p, unsigned int nmax, unsigned int ni): solutore (n, p, nmax, ni) {;}

    ~bisezione () {;}

    vector<double> CercaZeri (unsigned int n,
                              const funzione& f,
                              double p = 1E-6,
                              unsigned int nmax = 100 ) override {
        
        vector<double> Z;
        bool esatto = false;
        double nan(const char* input);
        
        for(int j=0 ; j<n ; j++){
            
            double a = j*M_PI;
            double b = j*M_PI + (M_PI/2);
            
            if(sgn(f.Eval(a))*sgn(f.Eval(b)) > 0){
                cerr << "Errore! La funzione non ha zeri nell'intervallo ";
                    Intervallo(j);
                    cerr << "!" << endl << endl;
                Z.push_back(nan("NaN"));
                continue;
            }
            
            double z = (a+b)/2;
            
            for (int i=0 ; i<nmax ; i++){
                if(sgn(f.Eval(a))*sgn(f.Eval(b)) == 0){
                    if(f.Eval(a) == 0) {
                        Z.push_back(a);
                        esatto = true;
                    }
                    if(f.Eval(b) == 0) {
                        Z.push_back(b);
                        esatto = true;
                    }
                    if(f.Eval(a) == 0 && f.Eval(b) == 0){
                        cerr << "Errore! Sia " << a << " che " << b << " sono zeri della funzione nell'intervallo ";
                            Intervallo(j);
                            cerr << "!" << endl << endl;
                            Z.push_back(nan("NaN"));
                    }
                    break;
                }
                
                else /* if(sgn(f.Eval(a))*sgn(f.Eval(b)) < 0) */ {
                    esatto = false;
                    if(sgn(f.Eval(z)) == sgn(f.Eval(a))) {a = z;}
                    if(sgn(f.Eval(z)) == sgn(f.Eval(b))) {b = z;}
                }
                
                z = (a+b)/2;
                
                if((b-a)/2 <= p) {i = nmax;}
                if((b-a) <= z*DBL_EPSILON){
                    cerr << "Il programma ha superato la precisione massima accessibile al calcolatore (" << z*DBL_EPSILON << ") nell'intervallo ";
                        Intervallo(j);
                        cerr << "!" << endl << endl;
                    Z.push_back(nan("NaN"));
                    break;
                }
            }
            
            if(Z[j] == nan("Nan")) continue;
                
            if((b-a)/2 > p && esatto == false){
                cerr << "Nell'intervallo ";
                Intervallo(j);
                cerr << " è stato raggiunto il numero massimo di iterazioni (" << nmax << ")!" << endl << endl;
                cerr << "Lo zero non è stato trovato con sufficiente precisione!" << endl;
                cerr << "Semiampiezza dell'intervallo trovato: " << (b-a)/2 << endl;
                cerr << "Precisione richiesta: " << p << endl << endl;
                Z.push_back(nan("NaN"));
                continue;
            }

			if(esatto == false) {Z.push_back(z);}
        }
    
        return Z;

    }

};

#endif
