#include "funzioni.h"




int main(int argc, char** argv){

    if (argc != 3){
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
    Stampa(D, 10);



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
    cout << "i primi 10 dati del file " << file << " riordinato in senso crescente sono:" << endl;
    Stampa(C, 10);
    
    
    
//stampo sul file risultati.dat i dati ordinati in senso crescente
    ofstream out("risultati.dat");
    Stampa(C, n, "risultati.dat");
    out.close();

    
  
//calcolo la mediana dei dati riordinati
    cout << "la mediana è: " << Mediana(C, n) << endl;



    delete[] D;
    D = NULL;

    file = NULL;

    delete[] C;
    C = NULL;

    return 0;
    
}
