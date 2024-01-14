#include <cmath>
#include <iostream>
#include <iomanip>

#include "funzioni.hpp"
#include "integrale.hpp"
#include "libreria.hpp"

#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TApplication.h"
#include "TAxis.h"
#include "TLegend.h"
#include "TPad.h"

#define _USE_MATH_DEFINES

using namespace std;



int main(int argc, char** argv) {
    
    cout << endl;
    if (argc != 2) {
        cerr << "Attenzione! Per eseguire il programma scrivere: " << argv[0] << " <precisione>" << endl << endl;
        return -1;
    }

    double p = atof(argv[1]);
    
    seno f;
    
    trapez tra(f, 0, M_PI);
    double I = tra.Integra(p);
    
    cout << "Passi: " << tra.GetN() << endl;
    cout << "Precisione: " << p << endl;
    cout << /*setprecision(10) <<*/ "Integrale: " << I << endl << endl;
    

    
    
    TApplication app("app", 0, 0);

    TGraph graf1;
    
    unsigned int k = 2;
    for(int i=0 ; i<7 ; i++){
        trapez trap(f, 0, M_PI);
        double inti = trap.Integra(k);
        graf1.SetPoint(i, k, fabs(inti-2.));
        k *= 2;
    }
    
    TCanvas tela1;
    tela1.cd();

    graf1.SetTitle("Stima errori");
    graf1.GetXaxis()->SetTitle("n passi");
    graf1.GetYaxis()->SetTitle("errore");

    graf1.SetLineColor(3);
    graf1.SetMarkerStyle(20);
    
    gPad -> SetLogx(0);
    gPad -> SetLogy(0);
    
    TF1 funz("funz","[0]*pow(x,[1])",0,300);
    funz.SetParameter(1,-2);
    
    graf1.Draw("ALP");
    graf1.Fit(&funz);
    cout << endl << "Esponente del fit: " << funz.GetParameter(1) << endl;

   
    app.Run();
    

    return 0;

}
