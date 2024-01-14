 #include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char** argv){

  if (argc < 3){
    cout << "Attenzione! Per eseguire il programma servono: " << argv[0] << " <numero_dati> <nome_file> " << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  double* D = new double[n];
  char* file = argv[2];

  ifstream in(file);



//leggo n numeri dal file 
  if (!in){
    cout << "file " << file << "non trovato" << endl;
    exit(0);
  } else {
    for (int i=0 ; i<n ; i++){
      in >> D[i];
      if (in.eof()){
        cout << "Il programma ha raggiunto la fine del file " << file << " prima di aver completato la lettura!" << endl;
        cout << "exiting..." << endl;
        exit(0);
      }
    }
  }



//stampo i primi 10 numeri per controllare
  cout << "I primi 10 numeri del file " << file << " sono:" << endl;
  for(int i=0 ; i<10 ; i++){
    cout << i+1 << ") \t" << D[i] << endl;
  }
  cout << endl;



//calcolo la media dei dati 
  double media = 0;
  for (int i=0 ; i<n ; i++) media += D[i];
  media = media/n;
  
  cout << "La media è: " << media << endl;
  cout << endl;



//calcolo la varianza dei dati
  double var = 0;
  for(int i=0 ; i<n ; i++) var += pow(D[i]-media, 2);
  var = var/n;

  cout << "La varianza è: " << var << endl;
  cout << endl;



//creo una copia dell'array di dati, poi la ordino in ordine crescente
  double* C = new double[n];
  for(int i=0 ; i<n ; i++) C[i] = D[i];

  for(int i=0 ; i<n-1 ; i++)
    for(int j=i+1 ; j<n ; j++)
      if(C[j] < C[i]){
        double b = C[j];
        C[j] = C[i];
        C[i] = b;
      }
    


//stampo i primi 10 numeri dell'array riordinato per controllare
  cout << "I primi 10 numeri del file " << file << " riordinato sono:" << endl;
  for(int i=0 ; i<10 ; i++){
    cout << i+1 << ") \t" << C[i] << endl;
  }
  cout << endl << endl;
    
    
    
//stampo sul file risultati.dat i dati ordinati in senso crescente
    ofstream out("risultati.dat");
    out << "Ecco i dati presenti nel file data.dat ordinari in senso crescente:" << endl << endl;
    for(int i=0 ; i<n ; i++) {out << i+1 << ")\t" << C[i] << endl;}
    
    
    
//calcolo la mediana dei dati riordinati
  double mediana;
  cout << "La mediana è: ";
  if(n % 2 == 0)
      mediana = (C[n/2 - 1] + C[n/2])/2.;
  else
      mediana = C[n/2];
  cout << mediana << endl;


    
    
    
    in.close();
    out.close();


  delete[] D;
  D = NULL;
  
  file = NULL;
    
  delete[] C;
  C = NULL;

  return 0;
}
