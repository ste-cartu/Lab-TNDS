#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TAxis.h"

#include "prisma.hpp"

using namespace std;



int main(int argc, char** argv){
    
    cout << endl;
    if(argc != 2) {
        cout << "Attenzione! Per utilizzare il programma servono: " << argv[0]  << " <n_ripetizioni_esperimento>" << endl << endl;
        return -1;
    }
    
    //creazione variabili
    
    TApplication app("app", 0, 0);
    
    prisma P(1, M_PI/2. /*0*/);
    int N = atoi(argv[1]);
    
    double X[3]={0,0,0}, Y[3]={0,0,0}, X2[3]={0,0,0}, Y2[3]={0,0,0}, XY[3]={0,0,0}, C[3]={0,0,0};
    
    vector<TH1F> H;
    vector<TH2F> B;
    
    for (int i=0 ; i<9 ; i++){
        TH1F h("", "", 300, 0, 0);
        h.StatOverflows(kTRUE);
        h.SetCanExtend(TH1::kAllAxes);
        H.push_back(h);
    }
    
    for (int i=0 ; i<3 ; i++){
        TH2F b("", "", 300, 0, 0, 300, 0, 0);
        b.StatOverflows(kTRUE);
        b.SetCanExtend(TH2::kAllAxes);
        B.push_back(b);
    }
    

    
    //ciclo misura-analisi
    
    for (int i=0 ; i<N ; i++){
        P.Misura();
        P.Analisi();
        
        //T0.push_back(P.Gett0Mis());
        //T1.push_back(P.Gett1Mis());
        //T2.push_back(P.Gett2Mis());
        
        H[0].Fill(P.Gett0Mis());
        H[1].Fill(P.Gett1Mis());
        H[2].Fill(P.Gett2Mis());
        
        
        double dm1 = P.Getdt1Mis() - P.Getdt1();
        double dm2 = P.Getdt2Mis() - P.Getdt2();
        H[3].Fill(dm1);
        H[4].Fill(dm2);
        B[0].Fill(dm1, dm2);
        
        X[0] += dm1;
        Y[0] += dm2;
        X2[0] += dm1*dm1;
        Y2[0] += dm2*dm2;
        XY[0] += dm1*dm2;
        
        
        double n1 = P.Getn1Mis() - P.Getn1();
        double n2 = P.Getn2Mis() - P.Getn2();
        H[5].Fill(n1);
        H[6].Fill(n2);
        B[1].Fill(n1, n2);
        
        X[1] += n1;
        Y[1] += n2;
        X2[1] += n1*n1;
        Y2[1] += n2*n2;
        XY[1] += n1*n2;
        
        
        double a = P.GetAMis() - P.GetA();
        double b = P.GetBMis() - P.GetB();
        H[7].Fill(a);
        H[8].Fill(b);
        B[2].Fill(a, b);
        
        X[2] += a;
        Y[2] += b;
        X2[2] += a*a;
        Y2[2] += b*b;
        XY[2] += a*b;
    }
    
    
    
    //calcolo dei coefficienti di correlazione
    
    for(int i=0 ; i<3 ; i++) {
        X[i] /= N;
        Y[i] /= N;
        X2[i] /= N;
        Y2[i] /= N;
        XY[i] /= N;
        
        C[i] = (XY[i] - (X[i]*Y[i])) / ( sqrt(X2[i] - (X[i]*X[i])) * sqrt(Y2[i] - (Y[i]*Y[i])) );
    }
    
    
    
    
    //grafici relativi agli angoli misurati direttamente
    
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    string tit = "Angoli misurati direttamente:";
    cout << tit << endl;
    TCanvas c1("c1", tit.c_str(), 1400, 500);
    c1.Divide(3, 1, 0.01, 0.05);
    
    for(int i=0 ; i<3 ; i++){
        string titolo = "Distribuzione Theta_" + to_string(i) + " misurati";
        string nome = "Theta_" + to_string(i);
        
        cout << nome << endl;
        cout << "\tValor medio: " << H[i].GetMean() << " [rad]" << endl;
        cout << "\tDeviazione standard: " << H[i].GetRMS() << " [rad]" << endl << endl;
        
        c1.cd(i+1);
        
        H[i].SetTitle(titolo.c_str());
        H[i].SetName(nome.c_str());
        titolo = "Theta_" + to_string(i) + " misurati [rad]";
        H[i].GetXaxis()->SetTitle(titolo.c_str());
        H[i].GetYaxis()->SetTitle("Frequenza assoluta");
        H[i].Draw();
    }
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    
    
    
    
    
    //grafici relativi agli angoli di deviazione minima
    
    tit = "Angoli di deviazione minima:";
    cout << tit << endl;
    TCanvas c2("c2", tit.c_str(), 1400, 500);
    c2.Divide(3, 1, 0.01, 0.05);
    
    for(int i=3 ; i<5 ; i++){
        string titolo = "Distribuzione Delta_m" + to_string(i-2) + " misurati";
        string nome = "Delta_m" + to_string(i-2);
        
        cout << nome << endl;
        cout << "\tValor medio: " << H[i].GetMean() << " [rad]" << endl;
        cout << "\tDeviazione standard: " << H[i].GetRMS() << " [rad]" << endl << endl;
        
        c2.cd(i-2);
        
        H[i].SetTitle(titolo.c_str());
        H[i].SetName(nome.c_str());
        titolo = "Errore su Delta_m" + to_string(i-2) + " misurati [rad]";
        H[i].GetXaxis()->SetTitle(titolo.c_str());
        H[i].GetYaxis()->SetTitle("Frequenza assoluta");
        H[i].Draw();
    }
    
    c2.cd(3);
    
    B[0].SetTitle("Residui 2D Delta_m1, Delta_m2");
    B[0].SetName("Correlazione");
    B[0].GetXaxis()->SetTitle("Errore su Delta_m1 misurati [rad]");
    B[0].GetYaxis()->SetTitle("Errore su Delta_m2 misurati [rad]");
    B[0].Draw();
    
    cout << "Coefficiente di correlazione (Delta_m1, Delta_m2): " << C[0] << endl << endl;
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    
    
    
    
    
    //grafici relativi agli indici di rifrazione
    
    tit = "Coefficienti di rifrazione:";
    cout << tit << endl;
    TCanvas c3("c3", tit.c_str(), 1400, 500);
    c3.Divide(3, 1, 0.01, 0.05);
    
    for(int i=5 ; i<7 ; i++) {
        string titolo = "Distribuzione n_" + to_string(i-4) + " misurati";
        string nome = "n_" + to_string(i-4);
        
        cout << nome << endl;
        cout << "\tValor medio: " << H[i].GetMean() << endl;
        cout << "\tDeviazione standard: " << H[i].GetRMS() << endl << endl;
        
        c3.cd(i-4);
        
        H[i].SetTitle(titolo.c_str());
        H[i].SetName(nome.c_str());
        titolo = "Errore su n_" + to_string(i-4) + " misurati";
        H[i].GetXaxis()->SetTitle(titolo.c_str());
        H[i].GetYaxis()->SetTitle("Frequenza assoluta");
        H[i].Draw();
    }
    
    c3.cd(3);
    
    B[1].SetTitle("Residui 2D n_1, n_2");
    B[1].SetName("Correlazione");
    B[1].GetXaxis()->SetTitle("Errore su n_1 misurati");
    B[1].GetYaxis()->SetTitle("Errore su n_2 misurati");
    B[1].Draw();
    
    cout << "Coefficiente di correlazione (n_1, n_2): " << C[1] << endl << endl;
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    
    
    
    
    
    //grafici relativi ai coefficienti della legge di Cauchy
    
    tit = "Coefficienti della legge di Cauchy:";
    cout << tit << endl;
    TCanvas c4("c4", tit.c_str(), 1400, 500);
    c4.Divide(3, 1, 0.01, 0.05);
    
    
    string titolo = "Distribuzione A misurati";
    string nome = "A";
    
    cout << nome << endl;
    cout << "\tValor medio: " << H[7].GetMean() << endl;
    cout << "\tDeviazione standard: " << H[7].GetRMS() << endl << endl;
    
    c4.cd(1);
    
    H[7].SetTitle(titolo.c_str());
    H[7].SetName(nome.c_str());
    titolo = "Errore su A misurati";
    H[7].GetXaxis()->SetTitle(titolo.c_str());
    H[7].GetYaxis()->SetTitle("Frequenza assoluta");
    H[7].Draw();
    
    
    titolo = "Distribuzione B misurati";
    nome = "B";
    
    cout << nome << endl;
    cout << "\tValor medio: " << H[8].GetMean() << " [nm^2]" << endl;
    cout << "\tDeviazione standard: " << H[8].GetRMS() << " [nm^2]" << endl << endl;
    
    c4.cd(2);
    
    H[8].SetTitle(titolo.c_str());
    H[8].SetName(nome.c_str());
    titolo = "Errore su B misurati [nm^2]";
    H[8].GetXaxis()->SetTitle(titolo.c_str());
    H[8].GetYaxis()->SetTitle("Frequenza assoluta");
    H[8].Draw();
    
    c4.cd(3);
    
    B[2].SetTitle("Residui 2D A, B");
    B[2].SetName("Correlazione");
    B[2].GetXaxis()->SetTitle("Errore su A misurati");
    B[2].GetYaxis()->SetTitle("Errore su B misurati [nm^2]");
    B[2].Draw();
    
    cout << "Coefficiente di correlazione (A, B): " << C[2] << endl << endl;
    
    
  
    
    
    app.Run();
    
    return 0;
}
