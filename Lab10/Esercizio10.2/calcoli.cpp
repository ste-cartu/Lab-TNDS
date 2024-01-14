#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "integrale.MC.hpp"
#include "libreria.hpp"

#define _USE_MATH_DEFINES

using namespace std;


//Il programma calcola 10000 volte il valore dell'integrale di sin(x) tra [0,π] utilizzando il metodo della media a N punti con N pari a 100, 500, 1000, 5000, 10000 punti, e salva i risultati su 5 files, chiamati media_i.dat con i = 1, ..., 5


int main(int argc, char** argv){
    
    cout << endl;
    if(argc != 4) {
        cerr << "Attenzione! Per utilizzare il programma servono: " << argv[0]  << " <numero_di_punti> <numero_di_iterazioni_nell'integrale> <numero_di_cicli>" << endl << endl;
        return -1;
    }
    
    unsigned int np = atoi(argv[1]);
    unsigned int ni = atoi(argv[2]);
    unsigned int nc = atoi(argv[3]);
    unsigned int seed = 1;
    double err = 0.01;
    unsigned int nbin = 100;
    
    seno sin(1,1,0);
    integraleMC inte(seed, err);
    
    
    for(int i=0 ; i<nc ; i++){
        string titolo1 = "media_" + to_string(i+1) + ".dat";
        ofstream out1(titolo1);
        
        string titolo2 = "hitmiss_" + to_string(i+1) + ".dat";
        ofstream out2(titolo2);
        
        for(int j=0 ; j<ni ; j++){
            double I1 = inte.Average(0., M_PI, sin, np);
            out1 << j+1 << ")" << "\t" << I1 << endl;
            
            double I2 = inte.HitMiss(0., M_PI, 1, sin, np);
            out2 << j+1 << ")" << "\t" << I2 << endl;
        }
        
        if(i%2 == 0) {np *= 5;}
        else {np *= 2;}
        
        out1.close();
        out2.close();
    }
    
    
    
    return 0;

}
