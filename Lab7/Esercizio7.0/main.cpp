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
    midpoint Int(0, M_PI);
    double I = Int.Integra(nstep, f);

    cout << "Passi = " << nstep << endl;
    cout /*<< setprecision(10)*/ << "Integrale = " << I << endl << endl;

    
    
    
    TApplication app("app", 0, 0);

    TGraph graf1;
    
    int k = 100;
    for(int i=0 ; i<20 ; i++){
        midpoint Mid(0, M_PI);
        double inti = Mid.Integra(k, f);
        graf1.SetPoint(i, k, fabs(inti-2.));
        k *= 2;
    }
    
    TCanvas tela1;
    tela1.cd();

    graf1.SetTitle("Stima errori");
    graf1.GetXaxis()->SetTitle("n passi");
    graf1.GetYaxis()->SetTitle("errore");

    gPad -> SetLogx(1);
    gPad -> SetLogy(1);
    
    graf1.SetLineColor(2);
    graf1.SetMarkerStyle(20);

    graf1.Draw("ALP");
   
    //TLegend legenda(0.2,0.6,0.4,0.8);
    //legenda.AddEntry(&graf1,"Questo e' graf1","LP");
    //legenda.Draw();

    
    app.Run();
    

    return 0;

}
