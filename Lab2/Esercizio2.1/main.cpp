#include "vettore.h"
#include "funzioni.h"




int main(int argc, char** argv){

    if (argc != 3){
        cout << "Attenzione! Per eseguire il programma servono: " << argv[0] << "<numero_dati> <nome_file> " << endl;
        return -1;
    }
    
    vettore V(atoi(argv[1]));
    
    char* file = argv[2];



//leggo i dati dal file
    Leggi(V, file);



//stampo i dati per controllare
    cout << "I dati presenti nel file " << file << " sono:" << endl << endl;
    Stampa(V);
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;



//calcolo la media dei dati
    double media = Media(V);
  
    cout << "La media è: " << media << endl;
    cout << endl;



//calcolo la varianza dei dati
    double var = Varianza(V);
  
    cout << "La varianza è: " << var << endl;
    cout << endl;

    
  
//riordino i dati, li stampo sul file risultati.dat e ne calcolo la mediana
    cout << "La mediana è: " << Mediana(V) << endl;

 
   
    file = NULL;

    return 0;
    
}


