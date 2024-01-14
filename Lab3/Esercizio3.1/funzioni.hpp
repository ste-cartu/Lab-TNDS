#ifndef funzioni_hpp
#define funzioni_hpp

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

#include <vector>                               //vettori di STL
#include <algorithm>                            //funzioni di STL

using namespace std;



template <class T> vector<T> Leggi(const char*);

template <class T> vector<T> Leggi(unsigned int, const char*);

template <class T> T Media(const vector<T>&);

template <class T> T Varianza(const vector<T>&);

template <class T> void Stampa(vector<T>);

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




template <class T> vector<T> Leggi(unsigned int n, const char* file){
    
    ifstream in(file);
    
    if (!in){
        cerr << "file " << file << "non trovato" << endl;
        exit(0);
    }
    else {
        vector<T> V(n);
        T a;
        
        for (int i=0 ; i<V.size() ; i++){
            in >> a;
            V[i] = a;
            if (in.eof()){
                  cerr << "il programma ha raggiunto la fine del file " << file << " prima di aver completato la lettura!" << endl;
                  cerr << "exiting..." << endl;
                  exit(0);
            }
        }
        
        in.close();
        return V;
    }
}




template <class T> T Media(const vector<T>& V){
    T media = 0;
    
    for (int i=0 ; i<V.size() ; i++) media = T((i*media + V[i])/(i+1));
    
    return media;
}

    


template <class T> T Varianza(const vector<T>& V){
    T var = 0;

    T m, M=0;
    for (int i=0 ; i<V.size() ; i++){
        m = M;
        M = Media<double>(V);
        
        var = (i*var + pow(V[i], 2) + i*pow(m, 2))/(i+1) - pow(M, 2);
    }
    
    return var;
}




template <class T> void Stampa(vector<T> V){
    for(int i=0 ; i<V.size() ; i++){
      cout << i+1 << ") \t" << V[i] << endl;
    }
    cout << endl;
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

