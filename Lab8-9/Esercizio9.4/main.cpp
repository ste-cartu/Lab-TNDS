#include <iostream>
#include <string>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TF1.h"

#include "libreria.hpp"
#include "equ.diff.hpp"

using namespace std;



int main(int argc, char** argv){
    
    cout << endl;
    if(argc != 4) {
        cerr << "Attenzione! Per utilizzare il programma servono: " << argv[0]  << " <passo_di_integrazione> <pulsazione_forzante> <tempo_di_evoluzione_della_soluzioine>" << endl << endl;
        return -1;
    }
    
    TApplication app("app", 0, 0);
    
    double alpha = 1./30;
    double pulsazione = 10.;
    double w = atof(argv[2]);
    
    runkut rk;
    oscarsf o(pulsazione, alpha, w);
    
    double tf = atof(argv[3]);
    double h = atof(argv[1]);
    vector<double> V {0., 0.};
    double t = 0.;
    int n = static_cast<int>(tf/h + 0.5);
    
    TGraph gsol;
    TGraph grifa;
    for (int i=0 ; i<n ; i++){
        gsol.SetPoint(i, t, V[0]);
        grifa.SetPoint(i, V[0], V[1]);
        V = rk.Passo(t, V, h, o);
        t += h;
    }
    
    
    TGraph gris;
    w = pulsazione - 1;
    
    for(int i=0 ; i<100 ; i++){
        o.SetW(w);
        t = 0.;
        vector<double> Z {0., 0.};
        vector<double> Y {0., 0.};
        
        while(t < 10*(1/alpha) || Z[1] < 0.) {
            Z = rk.Passo(t, Z, h, o);
            t += h;
        }
        while(Z[1] >= 0.){
            Y = Z;
            Z = rk.Passo(t, Z, h, o);
            t += h;
        }
    
        gris.SetPoint(i, w, Max(Y[0], Z[0]));
        
        w += 0.02;
     }
     
    
    
    
/*
    TGraph gper;
    double a = 0.1;
    double T = 0.;
    vector<double> W {-a, 0.};
    for(int i=0 ; i<30 ; i++){
        t = 0.;
        double v = 0.;
        
        while(W[1] >= 0.){
            v = W[1];
            W = rk.Passo(t, W, h, p);
            t += h;
        }
        
        T = 2. * (t-h - (v*h)/(W[1]-v));
        gper.SetPoint(i, a, T);
        
        a += 0.1;
        W[0] = -a;
        W[1] = 0.;
    }
 */

    
    TF1 X("X", "0", 0, tf);
    X.SetLineColor(kBlack);

    

    TCanvas c1("c1", "c1", 1200, 400);
    c1.Divide(2, 1, 0.01, 0.05);
    
    c1.cd(1);
    string title1 = "Oscillatore armonico smorzato-forzato (Runge-Kutta, h = " + to_string(h) + ")";
    gsol.SetTitle(title1.c_str());
    gsol.GetXaxis()->SetTitle("t [s]");
    gsol.GetYaxis()->SetTitle("x(t) [m]");
    gsol.SetLineColor(7);
    gsol.Draw("AL");
    X.Draw("same");
    
    c1.cd(2);
    string title2 = "Ritratto di fase (Runge-Kutta, h = " + to_string(h) + ")";
    grifa.SetTitle(title2.c_str());
    grifa.GetXaxis()->SetTitle("x(t) [m]");
    grifa.GetYaxis()->SetTitle("v(t) [m/s]");
    grifa.SetLineColor(3);
    grifa.Draw("AL");

    TCanvas c2("c2", "c2");
    c2.cd();
    gris.SetTitle("Lorentziana di risonanza");
    gris.GetXaxis()->SetTitle("pulsazione forzante [rad/s]");
    gris.GetYaxis()->SetTitle("ampiezza a regime [m]");
    gris.SetLineColor(2);
    gris.SetMarkerStyle(20);
    gris.Draw("ACP");


    app.Run();
    
    
    return 0;
    
}
