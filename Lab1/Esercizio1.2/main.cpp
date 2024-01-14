#include <iostream>
#include <cmath>
#include <fstream>

#include "funzioni.h"

using namespace std;




int main(int argc, char** argv){

  if (argc < 3){
    cout << "Attenzione! Per eseguire il programma servono: " << argv[0] << " <numero_dati> <nome_file> " << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  double* D = new double[n];
  char* file = argv[2];



//leggo n numeri dal file 
    Leggi(D, n, file);



//stampo i primi 10 numeri per controllare
  cout << "i primi 10 numeri del file " << file << " sono:" << endl;
  for(int i=0 ; i<10 ; i++){
    cout << i+1 << ") \t" << D[i] << endl;
  }
  cout << endl;



//calcolo la media dei dati 
    double media = Media(D, n);
  
  cout << "la media è: " << media << endl;
  cout << endl;



//calcolo la varianza dei dati
    double var = Varianza(D, n, media);
  
  cout << "la varianza è: " << var << endl;
  cout << endl;



//creo una copia dell'array di dati, poi la ordino in ordine crescente
  double* C = new double[n];
  for(int i=0 ; i<n ; i++) C[i] = D[i];

    Ordina(C, n);
  
    


//stampo i primi 10 numeri dell'array riordinato per controllare
  cout << "i primi 10 numeri del file " << file << " riordinato sono:" << endl;
  for(int i=0 ; i<10 ; i++){
    cout << i+1 << ") \t" << C[i] << endl;
  }
  cout << endl << endl;
    
    
    
//stampo sul file risultati.dat i dati ordinati in senso crescente
    Stampa(C, n);
    

    
  
//calcolo la mediana dei dati riordinati
    cout << "la mediana è: " << Mediana(C, n) << endl;



  delete[] D;
  D = NULL;
  
  file = NULL;
    
  delete[] C;
  C = NULL;

  return 0;
    
}
