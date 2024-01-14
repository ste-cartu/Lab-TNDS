#include "funzioni.hpp"




int main(int argc, char** argv){

    if (argc != 3){
        cerr << "Attenzione! Per eseguire il programma servono: " << argv[0] << "<numero_dati> <nome_file>" << endl;
        return -1;
    }
    
    
    char* file = argv[2];


//leggo i dati dal file e li immagazzino in un vettore
    vector<double> V = Leggi<double>(file);
    //vector<double> V = Leggi<double>(atoi(argv[1]), file);



//stampo i dati per controllare
    cout << "i dati presenti nel file " << file << " sono:" << endl << endl;
    Stampa(V);
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;



//calcolo la media dei dati
    double media = Media<double>(V);
  
    cout << "la media è: " << media << endl;
    cout << endl;



//calcolo la varianza dei dati
    double var = Varianza<double>(V);
  
    cout << "la varianza è: " << var << endl;
    cout << endl;

    
  
//riordino i dati, li stampo sul file risultati.dat e ne calcolo la mediana
    cout << "la mediana è: " << Mediana<double>(V) << endl;

    
   
    file = NULL;

    return 0;
    
}


