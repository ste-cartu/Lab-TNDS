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
    if(argc != 2) {
        cerr << "Attenzione! Per utilizzare il programma servono: " << argv[0]  << " <passo_di_integrazione> " << endl << endl;
        return -1;
    }
    

    TApplication app("app", 0, 0);

    runkut rk;
    oscar o(1.);
    
    double tf = 70.;
    double h = atof(argv[1]);
    vector<double> V {0., 1.};
    double t = 0.;
    int n = static_cast<int>(tf/h + 0.5);
    
    TGraph gsol;
    TGraph grifa;
    for (int i=0 ; i<n; i++){
        gsol.SetPoint(i, t, V[0]);
        grifa.SetPoint(i, V[0], V[1]);
        V = rk.Passo(t, V, h, o);
        t += h;
    }
    
    TGraph gerr;
    double H = 0.1;
    for (int j=0 ; j<7 ; j++){
        vector<double> W {0., 1.};
        n = static_cast<int>(tf/H + 0.5);
        t = 0;
        for (int i=0 ; i<n; i++){
            W = rk.Passo(t, W, H, o);
            t += H;
        }
        gerr.SetPoint(j, H, fabs(W[0] - sin(t)));
        H /= 5;
    }
    
    TF1 X("X", "0", 0, tf);
    X.SetLineColor(kBlack);
    
    TF1 f1("f1", "1", 0, tf);
    f1.SetLineColor(kBlack);
    
    TF1 f2("f2", "-1", 0, tf);
    f2.SetLineColor(kBlack);
    

    TCanvas c1("c1", "c1", 1300, 500);
    c1.Divide(2, 1, 0.03, 0.05);
    
    c1.cd(1);
    string title1 = "Oscillatore armonico (Runge-Kutta, h = " + to_string(h) + ")";
    gsol.SetTitle(title1.c_str());
    gsol.GetXaxis()->SetTitle("t [s]");
    gsol.GetYaxis()->SetTitle("x(t) [m]");
    gsol.SetLineColor(7);
    gsol.Draw("AL");
    X.Draw("same");
    f1.Draw("same");
    f2.Draw("same");
    
    
    c1.cd(2);
    string title2 = "Ritratto di fase (Runge-Kutta, h = " + to_string(h) + ")";
    grifa.SetTitle(title2.c_str());
    grifa.GetXaxis()->SetTitle("x(t) [m]");
    grifa.GetYaxis()->SetTitle("v(t) [m/s]");
    grifa.SetLineColor(3);
    grifa.Draw("AL");
    
    TCanvas c2("c2", "c2");
    c2.cd();
    gerr.SetTitle("Errore al variare di h");
    gerr.GetXaxis()->SetTitle("passo h [s]");
    gerr.GetYaxis()->SetTitle("errore a 70s [m]");
    gPad -> SetLogx(1);
    gPad -> SetLogy(1);
    gerr.SetLineColor(2);
    gerr.SetMarkerStyle(20);
    gerr.Draw("ALP");
    

    app.Run();

    return 0;
}
