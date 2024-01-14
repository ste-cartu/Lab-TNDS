#include "funzioni.hpp"




int main(int argc, char** argv){

    if (argc != 2){
        cerr << "Attenzione! Per eseguire il programma servono: " << argv[0] << " <nome_file>" << endl;
        return -1;
    }
    
    char* file = argv[1];
    
//creo un processo app che lascia il programma attivo per vedere gli outputs grafici
    TApplication app("app", 0, 0);

    

//leggo i dati dal file e li immagazzino in un vettore
    vector<double> V = Leggi<double>(file);

    
    
//creo un istogramma monodimensionale
    TH1F histo = Histo(V);
    

    
//prendo la media dei dati dell'stogramma
    cout << "La media è: " << histo.GetMean() << endl;
    cout << "La varianza è: " << pow(histo.GetRMS(), 2) << endl;
    cout << "La deviazione standard è: " << histo.GetStdDev() << endl << endl;
    
    
    
//riordino i dati, li stampo sul file risultati.dat e ne calcolo la mediana
    //cout << "la mediana è: " << Mediana<double>(V) << endl;
    
    
    
//eseguo il fit dell'istogramma con una gaussiana
    histo.Fit("gaus");
    
    
    
//disegno l'istogramma
    TCanvas mycanva ("histo", "histo");
    histo.Draw();
    histo.GetXaxis() -> SetTitle("misure");
    
    
    
//salvo il grafico in un file .pdf per poterlo visualizzare su Replit
    //mycanva.Print("Histo.pdf");
    
    
   
    file = NULL;
    
    app.Run();

    return 0;
    
}


