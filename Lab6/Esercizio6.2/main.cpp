#include "parabola.hpp"
#include "bisezione.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TEllipse.h"

using namespace std;

//il programma calcola lo zero della parabola y = 3x^2 + 5x -2, dati da linea di comando l'intervallo di ricerca, la precisione e il numero massimo di iterazioni


int main(int argc, char** argv){
    cout << endl;
    
    if(argc != 5){
        cerr << "Attenzione!" << endl;
        cerr << "Per usare il programma servono: " << argv[0] << " <xmin> <xmax> <precisione> <nmax iterazioni>" << endl << endl;
        exit(0);
    }
    
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double p = atof(argv[3]);
    int nmax = atoi(argv[4]);
    
    parabola P(3, 5, -2);
   
    bisezione B;
    double z = B.CercaZeri(a, b, P, p, nmax);
    
    //cifre significative
    int cifre = -log10(p);

    cout << "Lo zero della funzione nell'intervallo [" << a << ", " << b <<"] è: " << fixed << setprecision(cifre) << z  << " ± " << p << endl << endl;
    cout << "Il valore della funzione nello zero trovato è: " << "f(" << z << ") = " << P(z) << endl << endl;
    
    
    //diesgno con root l'intersezione tra la parabola e l'asse X
    TApplication app("app", 0, 0);
    
    TCanvas c1;
    
    TF1 f("f", "3*x^2 + 5*x -2", -7, 7);
    TF1 X("X", "0", -7, 7);
    X.SetLineColor(kBlack);
    TEllipse Z(z, 0, 0.07, 1);
    Z.SetFillColor(4);
    
    f.Draw();
    X.Draw("same");
    Z.Draw("same");
    
    app.Run();
    
    return 0;
    
}
