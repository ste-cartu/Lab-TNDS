#include "posizione.hpp"
#include "campo.vettoriale.hpp"
#include "punto.materiale.hpp"

#include <iostream>
#include <iomanip>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TF1.h"
#include "TAxis.h"

#include "TArrow.h"
#include "TEllipse.h"
#include "TText.h"
#include "TPaveText.h"

#define d 1.E-10


using namespace std;



//questo programma richiede da linea di comando una posizione in coordinate cartesiane e restituisce in output il valore del campo elettrico di un dipolo protone-elettrone in quel punto



int main(int argc, char** argv){
    
    if(argc != 4){
        cerr << "Attenzione! Uso del programma: " << argv[0] << " <x> <y> <z>" << endl;
        exit(-1);
    }
    
    
    double x = atof(argv[1]);
    double y = atof(argv[2]);
    double z = atof(argv[3]);
    posizione r(x,y,z);
    
    
    puntomat elettrone(Me, -el, 0., 0., d/2.);
    puntomat protone(Mp, el, 0., 0., -d/2.);
    

    campovett E = elettrone.CampoElett(r) + protone.CampoElett(r);
    
    cout << "Campo Elettrico:" << endl;
    E.Stampa();
    
  
    //calcolo l'andamento del campo tramite la legge di potenza
    posizione r1(0, 0, 100*d);
    posizione r2(0, 0, 1000*d);
    campovett E1 = elettrone.CampoElett(r1) + protone.CampoElett(r1);
    campovett E2 = elettrone.CampoElett(r2) + protone.CampoElett(r2);
    double a = (log(E2.Mod()/E1.Mod())/log(10.));
    cout << "Il campo ha un andamento asintotico a R^(" << setprecision(0) << a << ")" << endl;
    cout << "E = kR^(" << a << ")" << endl;
    
    
    
    //grafico l'andamento del campo sull'asse del dipolo
    TApplication app("app", 0, 0);
    TCanvas c1 ("c", "Grafico");
    TGraph grafico;
    
    for(int i=100 ; i<1000 ; i++){
        double x = i*d;
        posizione z(x, 0., 0.);
        campovett F = elettrone.CampoElett(z) + protone.CampoElett(z);
        double y = F.Mod();
        grafico.SetPoint(i-99, x, y);
    }
    
    grafico.GetXaxis() -> SetTitle("z [m]");
    grafico.GetYaxis() -> SetTitle("E [N/C]");
    
    grafico.Draw("AP");
    
    
    //rappresento il campo con TArrows
    posizione P(0.,0.,0.);

    double maxind = 10;

    TCanvas c2("plot","Plot", 600, 600) ;
    c2.cd();
    c2.DrawFrame (-maxind*d,-maxind*d,maxind*d,maxind*d, "Campo di due cariche puntiformi; y[m]; z[m]");
    
    for ( int k = -int(maxind) ; k <= int(maxind) ; k++ ) {
      for ( int j = -int(maxind) ; j <= int(maxind) ; j++ ) {
        if ( sqrt( k*k + j*j  ) < 4  ) continue ;
        double pz = k*d ;
        double py = j*d ;
        P.setZ(pz) ;
        P.setY(py) ;
        campovett C = elettrone.CampoElett(P) + protone.CampoElett(P);
        double scale = 30E-21;
        TArrow* field = new TArrow(py , pz  , py + C.getFy()*scale, pz + C.getFz()*scale, 0.01 ,">") ;
        field -> Draw(">same");
      }
    }
    
    
    TEllipse * Elettrone = new TEllipse(0,d/2, d/3) ;
    TEllipse * Protone = new TEllipse(0,-d/2, d/3) ;
    TText *lab1 = new TText( 0  , d/2, "-") ;
    lab1->SetTextAlign(22);
    lab1->SetTextSize(0.03);
    TText *lab2 = new TText( 0  , -d/2, "+") ;
    lab2->SetTextAlign(22);
    lab2->SetTextSize(0.03);

    Elettrone->SetFillColor(4);
    Protone->SetFillColor(2);
    Elettrone->Draw("same");
    Protone->Draw("same");
    lab1->Draw("same");
    lab2->Draw("same");
    
    
    app.Run();
        
    
    
    
    return 0;
}
