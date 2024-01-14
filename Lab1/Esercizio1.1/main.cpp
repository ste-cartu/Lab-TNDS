#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;


void Leggi(double*, int, const char*);

double Media(double*, int);

double Varianza(double*, int, double);

void Swap(double&, double&);

void Ordina(double*, int);

void Stampa(double*, int);

double Mediana(double*, int);




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
