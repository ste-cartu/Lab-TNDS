#include "funzioni.h"



void Leggi(vettore& V, const char* file){
    
    ifstream in(file);
    
    if (!in){
        cout << "file " << file << "non trovato" << endl;
        exit(0);
    }
    else {
        double a=0;
        for (int i=0 ; i<V.GetN() ; i++){
            in >> a;
            V.Set(i, a);
            if (in.eof()){
              cout << "il programma ha raggiunto la fine del file " << file << " prima di aver completato la lettura!" << endl;
              cout << "exiting..." << endl;
              exit(0);
            }
        }
    }
    
    in.close();
}




double Media(const vettore& V){
    double media = 0;
    
    for (int i=0 ; i<V.GetN() ; i++) media = double((i*media + V.Get(i))/(i+1));
    
    return media;
}




double Varianza(const vettore& V){
    double var = 0;
    //for(int i=0 ; i<n ; i++) {var += pow(D[i]-media, 2);}
    //var = var/n;
    
    //implementazione che evita di immagazzinare somme troppo elevate
    double m = 0;
    double M = Media(V);
    for (int i=0 ; i<V.GetN() ; i++){
        var = (i*var + pow(V.Get(i), 2) + i*pow(m, 2))/(i+1) - pow(M, 2);
        m = M;
    }
    
    
    return var;
}




void Swap(double& a, double& b){
    double c = a;
    a = b;
    b = c;
}




void Ordina(vettore& V){
    int imin;
    for(int i=0 ; i<V.GetN()-1 ; i++){
        imin = i;
        
        for(int j=i+1 ; j<V.GetN() ; j++)
            if(V[j] < V[imin])
                imin = j;
        
        Swap(V[imin], V[i]);
    }
}




void Stampa(vettore V){
    for(int i=0 ; i<V.GetN() ; i++){
      cout << i+1 << ")\t" << V[i] << endl;
    }
    cout << endl;
}




void Stampa(vettore V, const char* file){
    ofstream out(file, ios::app);
    
    for(int i=0 ; i<V.GetN() ; i++) {out << i+1 << ")\t" << V[i] << endl;}
    
    out.close();
}




double Mediana(vettore V){
    double mediana;
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

