// Complete the code. Use as reference
// http://labmaster.mi.infn.it/Laboratorio2/labTNDS/lectures_1819/lezione9_1819_vector.html

#include <iostream>
#include <string>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h" 
#include "TGraph.h"
#include "TAxis.h"
#include "TF1.h"

#include "equ.diff.hpp"
#include "libreria.hpp"

using namespace std;



int main(int argc, char** argv){
  
    cout << endl;
    if(argc != 3) {
        cerr << "Attenzione! Per utilizzare il programma servono: " << argv[0]  << " <passo_di_integrazione> <ampiezza_di_oscillazione> " << endl << endl;
        return -1;
    }

    TApplication app("app", 0, 0);

    runkut rk;
    pendolo p(1.);
    
    double tf = 70.;
    double h = atof(argv[1]);
    double A = atof(argv[2]);
    vector<double> V {-A, 0.};
    double t = 0.;
    int n = static_cast<int>(tf/h + 0.5);
    
    TGraph gsol;
    TGraph grifa;
    for (int i=0 ; i<n; i++){
        gsol.SetPoint(i, t, V[0]);
        grifa.SetPoint(i, V[0], V[1]);
        V = rk.Passo(t, V, h, p);
        t += h;
    }
    

    TGraph gper;
    double a = 0.1;
    double T = 0.;
    for(int i=0 ; i<30 ; i++){
        vector<double> W {-a, 0.};
        t = 0.;
        double v = 0.;
        
        while(W[1] >= 0.){
            v = W[1];
            t += h;
            W = rk.Passo(t, W, h, p);
        }
        
        T = 2. * (t-h - (v*h)/(W[1]-v));
        gper.SetPoint(i, a, T);
        a += 0.1;
    }

    
    TF1 X("X", "0", 0, tf);
    X.SetLineColor(kBlack);
    
    //TF1 cos("X", "3*cos(x)", 0, tf);
    //cos.SetLineColor(kBlack);
    

    TCanvas c1("c1", "c1", 1300, 500);
    c1.Divide(2, 1, 0.03, 0.05);
    
    c1.cd(1);
    string title1 = "Pendolo semplice (Runge-Kutta, h = " + to_string(h) + ")";
    gsol.SetTitle(title1.c_str());
    gsol.GetXaxis()->SetTitle("t [s]");
    gsol.GetYaxis()->SetTitle("angolo [rad]");
    gsol.SetLineColor(7);
    gsol.Draw("AL");
    X.Draw("same");
    //cos.Draw("same");
    
    c1.cd(2);
    string title2 = "Ritratto di fase (Runge-Kutta, h = " + to_string(h) + ")";
    grifa.SetTitle(title2.c_str());
    grifa.GetXaxis()->SetTitle("angolo [rad]");
    grifa.GetYaxis()->SetTitle("velocita' angolare [rad/s]");
    grifa.SetLineColor(3);
    grifa.Draw("AL");

    TCanvas c2("c2", "c2");
    c2.cd();
    gper.SetTitle("Periodo del pendolo al variare dell'ampiezza iniziale");
    gper.GetXaxis()->SetTitle("angolo iniziale [rad]");
    gper.GetYaxis()->SetTitle("periodo T [s]");
    gper.SetLineColor(2);
    gper.SetMarkerStyle(20);
    gper.Draw("ALP");


    app.Run();

    return 0;
}
