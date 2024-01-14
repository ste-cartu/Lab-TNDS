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
        cerr << "Attenzione! Per utilizzare il programma servono: " << argv[0] << " <n passi>" << endl << endl;
        return -1;
    }

    unsigned int nstep = atoi(argv[1]);

    seno f;
    simpson Int(0, M_PI);
    double I = Int.Integra(nstep, f);

    cout << "Passi = " << nstep << endl;
    cout << /*setprecision(10) <<*/ "Integrale = " << I << endl << endl;

    
    
    
    TApplication app("app", 0, 0);

    TGraph graf1;
    
    int k = 2;
    for(int i=0 ; i<7 ; i++){
        simpson simp(0, M_PI);
        double inti = simp.Integra(k, f);
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
    funz.SetParameter(1, -4);
    
    graf1.Draw("ALP");
    graf1.Fit(&funz);
    cout << endl << "Esponente del fit: " << funz.GetParameter(1) << endl << endl;

   
    app.Run();
    

    return 0;

}

