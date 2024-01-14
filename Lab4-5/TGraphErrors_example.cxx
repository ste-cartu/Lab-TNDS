#include "TCanvas.h"
#include "TApplication.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TAxis.h"
#include "TLegend.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char**argv)
{
  
  TApplication app("App",0,0);

  // construisco il grafico

  TGraphErrors * g = new TGraphErrors() ;
  
  // riempio il vettore con dei punti costruiti artificialmente
  
  for (int i = 0; i < 20; i++){   
    double x = 0.5 * i;
    double y = 10.*sin( x+0.2 );      
    double erry = 0.1* i ;
    g->SetPoint(i, x , y);
    g->SetPointError(i,0, erry);
  }
    
  // Disegnare il grafico (N.B.: viene creato automaticamente un TCanvas di nome c1)
  
  TCanvas *mygraph = new TCanvas("mygraph","Grafico") ;
  g->Draw("AL*");   // A = Disegna gli assi
                    // L = Congiunge i punti con una linea spezzata
                    // * = Segna i punti con un *
  

  TF1 *f1 = new TF1("f1","[0]*sin([1]*x+[2])",0.,10.);

  f1->SetParameter(0,10.);     // Definire il parametro [0] a 10.
  f1->SetParameters(5.,1.,0.1);   // Definire [0] -> 10. e [1] a 5.

  g->Fit(f1);
  cout << "Parametro 0 del fit : " << f1->GetParameter(0) << endl;
  cout << "Parametro 1 del fit : " << f1->GetParameter(1) << endl;
  cout << "Parametro 2 del fit : " << f1->GetParameter(2) << endl;

  // Cambiare il tipo di punto
  
  TCanvas *mygraph1 = new TCanvas("mygraph1","Grafico") ;
  g->SetMarkerStyle(21);
  g->SetMarkerColor(9);
  g->GetXaxis()->SetTitle("Asse x [um]");
  g->GetYaxis()->SetTitle("Asse y [um]");
  g->SetTitle("Grafico");
  g->Draw("ALP");   // P = Segna i punti con il punto corrente
 

  // Sovrapporre un altro grafico
  
  TGraphErrors *h = new TGraphErrors();
  for (int i = 0; i < 20; i++){   
    double x = 0.5 * i;
    double y = 6.*sin( x+0.4 );      
    double erry = 0.1* i ;
    h->SetPoint(i, x , y);
    h->SetPointError(i,0, erry);
  }
  h->SetMarkerStyle(20);
  h->SetMarkerColor(3);
  h->Draw("CP");    // C = Congiunge i punti con una linea continua  
  
  TLegend leg (0.3,0.7, 0.55, 0.85) ;
  leg.AddEntry(g,"data1","p");
  leg.AddEntry(h,"data2","p");
  leg.AddEntry(f1,"fit","l");

  leg.Draw("same");

  app.Run();

  return 0;

}
