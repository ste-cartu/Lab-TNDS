#include "particella.hpp"
#include <iostream> 



int main() {

    particella *a   = new particella(1.,1.6E-19);
    elettrone *e    = new elettrone();

    // Metodi della classe base
    cout << endl;
    cout << "particella " << a->getMassa() << "," << a->getCarica() << endl << endl;
    a->Print();

    // Metodi della classe derivata
    cout << endl;
    cout << "elettrone " << e->getMassa() << "," << e->getCarica() << endl << endl;
    e->Print();
    cout << endl;

    particella b(*a) ;  // costruisco una Particella a partire da una Particella
    particella d(*e);   // costruisco una Particella a partire da un Elettrone
    //elettrone f(d);   costruisco un Elettrone a partire da una Particella => ERRORE

    return 0;

}


