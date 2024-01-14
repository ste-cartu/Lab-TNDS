#ifndef bisezione_hpp
#define bisezione_hpp

#include "solutore.hpp"

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
                              double p = 0.000001,
                              unsigned int nmax = 100 ) override {
        
        vector<double> Z;
        bool esatto = false;
        double N = nan("NaN");
        
        for(int j=0 ; j<n ; j++){
            
            double a = j*M_PI;
            double b = j*M_PI + (M_PI/2);
            double z; // = (a+b)/2;
            int contatore = 0;
            cout << p << endl;
            
            if(sgn(f.Eval(a))*sgn(f.Eval(b)) > 0){
                cerr << "Errore! La funzione non ha zeri nell'intervallo ";
                    Intervallo(j);
                    cerr << "!" << endl << endl;
                Z.push_back(N);
                continue;
            }
            
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
                    Z.push_back(N);
                    continue;
                }
            }
            
            else /* if(sgn(f.Eval(a))*sgn(f.Eval(b)) < 0) */ {
                
                while((b-a)/2 > p){
                    esatto = false;
                    
                    if(sgn(f.Eval(z)) == sgn(f.Eval(a))) {a = z;}
                    if(sgn(f.Eval(z)) == sgn(f.Eval(b))) {b = z;}
                    
                    if(contatore == nmax) break;
                    z = (a+b)/2;
                    contatore++;
                    
                    if((b-a)/2 <= z*DBL_EPSILON){
                        cerr << "Il programma ha superato la precisione massima accessibile al calcolatore (" << z*DBL_EPSILON << ") nell'intervallo ";
                            Intervallo(j);
                        cerr << "!" << endl;
                        cerr << "\tSemiampiezza dell'intervallo trovato: " << (b-a)/2 << endl;
                        cerr << "\tNumero di iterazioni eseguite: " << contatore << endl << endl;
                        //Z.push_back(N);
                        //esatto = true;
                        //break;
                        exit(0);
                    }
                }
                
            }
                
            if((b-a)/2 > p && esatto == false){
                cerr << "Nell'intervallo ";
                Intervallo(j);
                cerr << " è stato raggiunto il numero massimo di iterazioni (" << contatore << ")" << endl << endl;
                cerr << "Lo zero non è stato trovato con sufficiente precisione!" << endl;
                cerr << "\tSemiampiezza dell'intervallo trovato: " << (b-a)/2 << endl;
                cerr << "\tPrecisione richiesta: " << p << endl << endl;
                Z.push_back(N);
                continue;
            }
            
            if(esatto == false) {Z.push_back(z);}
        }
    
        return Z;

    }

};

#endif
