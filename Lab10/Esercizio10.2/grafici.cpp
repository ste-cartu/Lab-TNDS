#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TF1.h"

#define _USE_MATH_DEFINES

using namespace std;




int main(int argc, char** argv){
    
    cout << endl;
    system("./myscript.sh");
    TApplication app ("app", 0, 0);
   
    vector<string> F1;
    vector<string> F2;
    ifstream in("indirizzi.dat");
    
    if(!in) {
        cout << "file indirizzi.dat non trovato!" << endl << endl;
        exit(0);
    }
    
    string nome;
    in >> nome;
    while(nome != '0') {
        F1.push_back(nome);
        in >> nome;
    }
    
    in >> nome;
    while(!in.eof() != 0) {
        F2.push_back(nome);
        in >> nome;
    }
    in.close();
    
    //for(int i=0 ; i<F1.size() ; i++) {cout << F1[i] << endl;}
    //cout << endl;
    //for(int i=0 ; i<F2.size() ; i++) {cout << F2[i] << endl;}
    
    
    
    vector<TH1F> G1;
    for(int i=0 ; i<F1.size() ; i++) {
        TH1F h("", "", 100, 0, 0);
        h.StatOverflows(kTRUE);
        h.SetCanExtend(TH1::kAllAxes);
        
        ifstream in(F1[i].c_str());
        string s;
        double x;
        in >> s >> x;
        while(!in.eof()) {
            h.Fill(x);
            in >> s >> x;
        }
        in.close();
        
        G1.push_back(h);
    }
    
    vector<TH1F> G2;
    for(int i=0 ; i<F2.size() ; i++) {
        TH1F h("", "", 100, 0, 0);
        h.StatOverflows(kTRUE);
        h.SetCanExtend(TH1::kAllAxes);
        
        ifstream in(F2[i].c_str());
        string s;
        double x;
        in >> s >> x;
        while(!in.eof()) {
            h.Fill(x);
            in >> s >> x;
        }
        in.close();
        
        G2.push_back(h);
    }
    
    TGraph gerr1;
    TGraph gerr2;
    
    
    TCanvas c1("c1", "Metodo della media", 1400, 1000);
    c1.Divide(3, 2, 0.01, 0.05);
    int np = 100;
    
    for(int i=0 ; i<G1.size() ; i++) {
        string titolo = to_string(np) + " punti";
        
        c1.cd(i+1);
        G1[i].SetTitle(titolo.c_str());
        G1[i].SetName(titolo.c_str());
        G1[i].GetXaxis()->SetTitle("valore dell'integrale [AU]");
        G1[i].GetYaxis()->SetTitle("frequenza assoluta");
        G1[i].Draw();
        
        gerr1.SetPoint(i, np, G1[i].GetRMS());
        
        if(i%2 == 0) {np *= 5;}
        else {np *= 2;}
    }
    
    
    TCanvas c2("c2", "Errori meotodo della media");
    c2.cd();
    string title1 = "Errori al variare del numero di punti";
    gerr1.SetTitle(title1.c_str());
    gerr1.GetXaxis()->SetTitle("N");
    gerr1.GetYaxis()->SetTitle("errore [AU]");
    gerr1.SetLineColor(kRed);
    gerr1.SetMarkerStyle(8);
    gerr1.Draw("ALP");
    
    TF1 fit1("fit1","[0]/sqrt(x)", 1, np);
    fit1.SetParameter(0, G1[0].GetRMS() * 10 );
    fit1.SetLineColor(kBlue);
    fit1.Draw("sameL");
    
    cout << "L'andamento dell'errore con il metodo della media è: sigma(N) = " << fit1.GetParameter(0) << "/sqrt(N)" << endl;
    double p = 0.001;
    cout << "Per ottenere una precisione di " << p << " è necessario utilizzare almeno " << round( pow(fit1.GetParameter(0)/p, 2) - 0.5) << " punti" << endl << endl;
    
    
    TCanvas c3("c3", "Metodo Hit or Miss", 1400, 1000);
    c3.Divide(3, 2, 0.01, 0.05);
    np = 100;
    
    for(int i=0 ; i<G2.size() ; i++) {
        string titolo = to_string(np) + " punti";
        
        c3.cd(i+1);
        G2[i].SetTitle(titolo.c_str());
        G2[i].SetName(titolo.c_str());
        G2[i].GetXaxis()->SetTitle("valore dell'integrale [AU]");
        G2[i].GetYaxis()->SetTitle("frequenza assoluta");
        G2[i].Draw();
        
        gerr2.SetPoint(i, np, G2[i].GetRMS());
        
        if(i%2 == 0) {np *= 5;}
        else {np *= 2;}
    }
    
    
    TCanvas c4("c4", "Errori meotodo Hit or Miss");
    c4.cd();
    string title2 = "Errori al variare del numero di punti";
    gerr2.SetTitle(title2.c_str());
    gerr2.GetXaxis()->SetTitle("N");
    gerr2.GetYaxis()->SetTitle("errore [AU]");
    gerr2.SetLineColor(kRed);
    gerr2.SetMarkerStyle(8);
    gerr2.Draw("ALP");
    
    TF1 fit2("fit2","[0]/sqrt(x)", 1, np);
    fit2.SetParameter(0, G2[0].GetRMS() * 10 );
    fit2.SetLineColor(kBlue);
    fit2.Draw("sameL");
    
    cout << "L'andamento dell'errore con il metodo Hit or Miss è: sigma(N) = " << fit2.GetParameter(0) << "/sqrt(N)" << endl;
    cout << "Per ottenere una precisione di " << p << " è necessario utilizzare almeno " << round( pow(fit2.GetParameter(0)/p, 2) - 0.5) << " punti" << endl;
    
    
    
    app.Run();
    
    return 0;
}
