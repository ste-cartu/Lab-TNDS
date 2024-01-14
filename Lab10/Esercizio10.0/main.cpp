#include <iostream>
#include <string>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TF1.h"

#include "random.hpp"

using namespace std;


int main(int argc, char** argv){
    
    cout << endl;
    if(argc != 2) {
        cout << "Attenzione! Per utilizzare il programma servono: " << argv[0]  << " <seme>" << endl << endl;
        return -1;
    }
    
    unsigned int s = atoi(argv[1]);
    
    TApplication app("app",0,0);
    
    randomgen gen(s);
    int nmax = 10000;
    
    float xmin = 5.;
    float xmax = 10.;
    int nbin = 100;
    TH1F gunif("Uniforme", "Uniforme", nbin, xmin-0.0001, xmax+0.0001);
    string title1 = "Distrubuzione uniforme tra " + to_string(xmin) + " e " + to_string(xmax) + " (seme: " + to_string(s) + ")";
    for (int i=0 ; i<nmax ; i++) {gunif.Fill(gen.Unif(xmin, xmax));}
    gen.Reset();
    
    float a = nmax/nbin;
    TF1 f1("f1", to_string(a).c_str(), xmin-0.0001, xmax+0.0001);
    
    float k = 1;
    TH1F gesp("Esponenziale", "Esponenziale", 100, 0, 10);
    string title2 = "Distrubuzione esponenziale (seme: " + to_string(s) + ")";
    for (int i=0 ; i<nmax ; i++) {gesp.Fill(gen.Exp(k));}
    gen.Reset();
    
    double media = 1, devst = 1;
    TH1F ggabom("Gauss Box Muller", "Gauss Box Muller", 100, -4, 6);
    string title3_1 = "Distrubuzione gaussiana (Box Muller - seme: " + to_string(s) + ")";
    for (int i=0 ; i<nmax/2 ; i++) {
        ggabom.Fill(gen.GaussBM(media, devst)[0]);
        ggabom.Fill(gen.GaussBM(media, devst)[1]);
    }
    gen.Reset();
    
    TH1F ggar("Gauss Accept-Reject", "Gauss Accept-Reject", 100, media - 5*devst, media + 5*devst);
    string title3_2 = "Distrubuzione gaussiana (Accept-Reject - seme: " + to_string(s) + ")";
    for (int i=0 ; i<nmax ; i++) {ggar.Fill(gen.GaussAR(media, devst));}
    gen.Reset();
    
    
    
    TCanvas can1("Uniforme", "Uniforme");
    can1.cd();
    gunif.SetTitle(title1.c_str());
    gunif.GetXaxis()->SetTitle("x [AU]");
    gunif.GetYaxis()->SetTitle("N");
    gunif.Draw();
    f1.Draw("same");
    
    TCanvas can2("Esponenziale", "Esponenziale");
    can2.cd();
    gesp.SetTitle(title2.c_str());
    gesp.GetXaxis()->SetTitle("x [AU]");
    gesp.GetYaxis()->SetTitle("N");
    gesp.Draw();
    
    TCanvas can3("Gauss", "Gauss", 1200, 500);
    can3.Divide(2, 1, 0.01, 0.05);
    
    can3.cd(1);
    ggabom.SetTitle(title3_1.c_str());
    ggabom.GetXaxis()->SetTitle("x [AU]");
    ggabom.GetYaxis()->SetTitle("N");
    ggabom.Draw();
    
    can3.cd(2);
    ggar.SetTitle(title3_2.c_str());
    ggar.GetXaxis()->SetTitle("x [AU]");
    ggar.GetYaxis()->SetTitle("N");
    ggar.Draw();
    
    app.Run();
    
    return 0;
    
}
