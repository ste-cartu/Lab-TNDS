#include "tangente.hpp"
#include "bisezione.hpp"

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//il programma calcola lo zero della funzione x = tan(x) [sin(x) - xcos(x) = 0], dati da linea di comando il numero di intervalli (k𝛑, k𝛑 + 𝛑/2) in cui cercare le soluzioni, la precizione e il numero massimo di iterazioni da eseguire


int main(int argc, char** argv){
    cout << endl;
    /*
    double a = nan("NaN");
    vector<double> V;
    V.push_back(a);
    cout << V[0];
    */
    
    if(argc != 4){
        cerr << "Attenzione!" << endl;
        cerr << "Per usare il programma servono: " << argv[0] << " <nintervalli> <precisione> <nmax iterazioni>" << endl << endl;
        exit(0);
    }
    
    unsigned int n = atoi(argv[1]);
    double p = atof(argv[2]);
    unsigned int nmax = atoi(argv[3]);
    
    tangente T(1,1,1);
    
    bisezione B;
    vector<double> Z = B.CercaZeri(n, T, p, nmax);

    T.StampaZeri(Z, p);
    
    return 0;
    
}
