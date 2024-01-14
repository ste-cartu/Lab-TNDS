#ifndef funzioni_hpp
#define funzioni_hpp

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

#include <vector>
#include <algorithm>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"

using namespace std;




template <class T> vector<T> Leggi(const char*);

template <class T> TH1F Histo(const vector<T>&);

template <class T> void Stampa(vector<T>, const char*);

template <class T> T Mediana(vector<T>);







template <class T> vector<T> Leggi(const char* file){
    
    ifstream in(file);
    vector<T> V;
    
    if (!in){
        cerr << "file " << file << "non trovato" << endl;
        exit(0);
    }
    else {
        while(!in.eof()){
            T a;
            in >> a;
            if(in)
                V.push_back(a);
            }
        
        in.close();
        return V;
    }
}




template <class T> TH1F Histo(const vector<T>& V){
    
    TH1F h("histo", "histo", 100, -10, 100);                        //creo un istogramma monodimensionale
    h.StatOverflows(kTRUE);                                         //permetto all'istogramma di utilizzare per i calcoli delle variabili statistiche
                                                                    //anche valori non presenti nel suo range di definizione
    for(int i=0 ; i<V.size() ; i++) h.Fill(V[i]);                   //riempio l'istogramma coi dati del vector
    
    return h;
    
}




template <class T> void Stampa(vector<T> V, const char* file){
    ofstream out(file, ios::app);
    
    for(int i=0 ; i<V.size() ; i++) {out << i+1 << ")\t" << V[i] << endl;}
    
    out.close();
}




template <class T> T Mediana(vector<T> V){
    T mediana;
    ofstream out("risultati.dat");
    
    sort(V.begin(), V.end());
    out << "ecco i dati presenti nel file data.dat ordinati in senso crescente:" << endl << endl;
    Stampa(V, "risultati.dat");
    
    if(V.size() % 2 == 0)
        mediana = (V[V.size()/2 - 1] + V[V.size()/2])/2.;
    else
        mediana = V[V.size()/2];
    
    out.close();
    
    return mediana;
}





#endif /* funzioni_hpp */
