#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TF1.h"
#include "TGraph.h"
#include "TLegend.h"

#include "random.hpp"

using namespace std;


int main(int argc, char** argv){
    
    cout << endl;
    if(argc != 3) {
        cout << "Attenzione! Per utilizzare il programma servono: " << argv[0]  << " <numero_dati> <numero_dati_da_sommare>" << endl << endl;
        return -1;
    }
    
    unsigned int nmax = atoi(argv[1]);
    unsigned int ns = atoi(argv[2]);
    
    randomgen gen(1);
    vector<long double> D;
    long double x;
    
    TApplication app("app", 0, 0);
    
    TH1F gdati("Dati", "Dati", 100, 0-0.0001, 1+0.0001);
    string title1 = "Distrubuzione dei dati";
    
    TH1F gsomme("Somme", "Somme", 100, 0-0.0001, ns+0.0001);
    string title2 = "Distrubuzione delle somme";
    
    TGraph gvarsomme;
    
    
    for(int i=0 ; i<nmax ; i++){
        x = gen.Rand();
        D.push_back(x);
        gdati.Fill(x);
    }
    
    int j=0;
    for(int n=ns ; n < 100*ns ; n+=ns){
        
        for(auto it = D.begin(); it < D.end()-n+1 ; it += n){
            long double s = accumulate(it, it+ns, (long double) 0.);
            gsomme.Fill(s);
        }
        
        gvarsomme.SetPoint(j, n, gsomme.GetStdDev());
        j++;
    }
    
    
    //cout << gdati.GetMean()<< endl;
    //cout << gdati.GetStdDev()<< endl;
    
    
    float a = nmax/100;
    TF1 f1("f1", to_string(a).c_str(), 0-0.0001, 1+0.0001);
    
    TCanvas can1("c1", "Dati e somme finali", 1000, 450);
    can1.Divide(2, 1, 0.01, 0.07);
    
    can1.cd(1);
        gdati.SetTitle(title1.c_str());
        gdati.GetXaxis()->SetTitle("x [AU]");
        gdati.GetYaxis()->SetTitle("N");
        gdati.Draw();
        f1.Draw("same");
    
    can1.cd(2);
        gsomme.SetTitle(title2.c_str());
        gsomme.GetXaxis()->SetTitle("x [AU]");
        gsomme.GetYaxis()->SetTitle("N");
        gsomme.Draw();
    
    
    TCanvas can2("c2", "Varianza delle somme al variare di n");
    can2.cd();
        
        gvarsomme.SetTitle("Varianza delle somme al variare di n");
        gvarsomme.GetXaxis()->SetTitle("n [AU]");
        gvarsomme.GetYaxis()->SetTitle("varianza [AU]");
        gvarsomme.SetLineColor(kBlack);
       
        gvarsomme.Draw("AL");
    
    
    app.Run();
    
    return 0;
    
}
