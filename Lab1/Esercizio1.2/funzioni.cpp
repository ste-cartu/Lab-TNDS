#include "funzioni.h"


void Leggi(double* D, int n, const char* file){
    
    ifstream in(file);
    
    if (!in){
      cout << "file " << file << "non trovato" << endl;
      exit(0);
    } else {
      for (int i=0 ; i<n ; i++){
        in >> D[i];
        if (in.eof()){
          cout << "il programma ha raggiunto la fine del file " << file << " prima di aver completato la lettura!" << endl;
          cout << "exiting..." << endl;
          exit(0);
        }
      }
    }
    in.close();
    
}



double Media(double* D, int n){
    
    double media = 0;
    for (int i=0 ; i<n ; i++) media += D[i];
    media = media/n;
    
    return media;
}



double Varianza(double* D, int n, double media){
    
    double var = 0;
    for(int i=0 ; i<n ; i++) var += pow(D[i]-media, 2);
    var = var/n;
    
    return var;
}




void Swap(double& a, double& b){
    
    double c = a;
    a = b;
    b = c;
    
}




void Ordina(double* C, int n){
    
    for(int i=0 ; i<n-1 ; i++)
      for(int j=i+1 ; j<n ; j++)
        if(C[j] < C[i])
          Swap(C[j], C[i]);
        
}



void Stampa(double* C, int n){
    
    ofstream out("risultati.dat");
    out << "ecco i dati presenti nel file data.dat ordinari in senso crescente:" << endl << endl;
    for(int i=0 ; i<n ; i++) {out << i+1 << ")\t" << C[i] << endl;}
    
    out.close();
    
}



double Mediana(double* C, int n){
    
    double mediana;

    if(n % 2 == 0)
        mediana = (C[n/2 - 1] + C[n/2])/2.;
    else
        mediana = C[n/2];
    
    return mediana;
    
}

