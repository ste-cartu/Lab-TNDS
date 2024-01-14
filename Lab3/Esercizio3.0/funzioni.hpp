#ifndef funzioni_hpp
#define funzioni_hpp

#include <iostream>
#include <cmath>
#include <fstream>

#include "vettore.hpp"

using namespace std;



template <class T> vettore<T> Leggi(unsigned int, const char*);

template <class T> T Media(const vettore<T>&);

template <class T> T Varianza(const vettore<T>&);

template <class T> void Swap(T&, T&);

template <class T> void Ordina(vettore<T>&);

template <class T> void Stampa(vettore<T>);

template <class T> void Stampa(vettore<T>, const char*);

template <class T> T Mediana(vettore<T>);






template <class T> vettore<T> Leggi(unsigned int n, const char* file){
    
    ifstream in(file);
    
    if (!in){
        cout << "file " << file << "non trovato" << endl;
        exit(0);
    }
    else {
        vettore<T> V(n);
        T a;
        
        for (int i=0 ; i<V.GetN() ; i++){
            in >> a;
            V[i] = a;
            if (in.eof()){
              cout << "il programma ha raggiunto la fine del file " << file << " prima di aver completato la lettura!" << endl;
              cout << "exiting..." << endl;
              exit(0);
            }
        }
        
        in.close();
        return V;
    }
}




template <class T> T Media(const vettore<T>& V){
    T media = 0;
    
    for (int i=0 ; i<V.GetN() ; i++) media = T((i*media + V.Get(i))/(i+1));
    
    return media;
}




template <class T> T Varianza(const vettore<T>& V){
    T var = 0;

    T m = 0;
    T M = Media(V);
    for (int i=0 ; i<V.GetN() ; i++){
        var = (i*var + pow(V.Get(i), 2) + i*pow(m, 2))/(i+1) - pow(M, 2);
        m = M;
    }
    
    return var;
}




template <class T> void Swap(T& a, T& b){
    T c = a;
    a = b;
    b = c;
}




template <class T> void Ordina(vettore<T>& V){
    int imin;
    for(int i=0 ; i<V.GetN()-1 ; i++){
        imin = i;
        
        for(int j=i+1 ; j<V.GetN() ; j++)
            if(V[j] < V[imin])
                imin = j;
        
        Swap(V[imin], V[i]);
    }
}




template <class T> void Stampa(vettore<T> V){
    for(int i=0 ; i<V.GetN() ; i++){
      cout << i+1 << ") \t" << V[i] << endl;
    }
    cout << endl;
}




template <class T> void Stampa(vettore<T> V, const char* file){
    ofstream out(file, ios::app);
    
    for(int i=0 ; i<V.GetN() ; i++) {out << i+1 << ")\t" << V[i] << endl;}
    
    out.close();
}




 template <class T> T Mediana(vettore<T> V){
    T mediana;
    ofstream out("risultati.dat");
    
    Ordina(V);
    out << "ecco i dati presenti nel file data.dat ordinati in senso crescente:" << endl << endl;
    Stampa(V, "risultati.dat");
    
    if(V.GetN() % 2 == 0)
        mediana = (V[V.GetN()/2 - 1] + V[V.GetN()/2])/2.;
    else
        mediana = V[V.GetN()/2];
    
    out.close();
    
    return mediana;
}




#endif /* funzioni_hpp */

