#include "part.elett.hpp"
#include <iostream>

int main (){

    particella *a = new particella(1.,2.);
    elettrone  *b = new elettrone();
    particella *c = new elettrone(); // puntatore a Particella punta a un Elettrone
    
    cout << endl;
    a->Stampa(); // Meteodo Print di Particella
    b->Stampa(); // Meteodo Print di Elettrone
    c->Stampa(); // ???
    
    delete a;
    delete b;
    delete c;

    return 0;
}
