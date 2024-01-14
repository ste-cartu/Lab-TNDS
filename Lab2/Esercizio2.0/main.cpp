#include "vettore.h"



int main() {

    //il costruttore senza argomenti crea un vettore di dimenione nulla
    Vettore vnull ;
    cout << "vettore vnull: dimensione = " << vnull.GetN() << endl;
    for (unsigned int k = 0 ; k < vnull.GetN() ; k++) cout << vnull.Get(k) << "\t";
    cout << endl << endl;


    //construttore con intero : costruisco un OGGETTO di tipo vettore di lunghezza 10
    Vettore v(10);
    cout << "vettore v: dimensione = " << v.GetN() << endl;
    for (unsigned int k = 0 ; k < v.GetN() ; k++) cout << v.Get(k) << "\t";
    cout << endl << endl;


    //anche come puntatore
    Vettore * vp = new Vettore(10);
    cout << "vettore vp: dimensione = " << vp->GetN() << endl;
    for (unsigned int k = 0 ; k < vp->GetN() ; k++) cout << vp->Get(k) << "\t";
    cout << endl << endl;


    //cambio il contenuto di v
    for (unsigned int k = 0 ; k < 10 ; k++) v.Set(k,k+2);

    cout << "vettore v modificato: dimensione = " << v.GetN() << endl;
    for (unsigned int k = 0 ; k < v.GetN() ; k++) cout << v.Get(k) << "\t" ;
    cout << endl << endl;


    //visualizzo la componente 3 (i = 2)
    int comp = 2;
    cout << "componente " << comp+1 << ": " << v.Get(comp) << endl << endl;                   //posso usare v[comp] al posto di v.Get(comp) se deinisco l'operatore []


    //copy constructor
    Vettore w=v;                        //oppure la sintassi equivalente: Vettore w(v);
    
    cout << "Vettore w: dimensione = " << w.GetN() << endl;
    for (unsigned int k = 0 ; k < w.GetN() ; k++) cout << w.Get(k) << "\t";
    cout << endl << endl;

    v.Set(4, 99);

    cout << "Vettore v: dimensione = " << v.GetN() << endl;
    for (unsigned int k = 0 ; k < v.GetN() ; k++) cout << v.Get(k) << "\t" ;
    cout << endl << endl;

    cout << "Vettore w: dimensione = " << w.GetN() << endl;
    for (unsigned int k = 0 ; k < w.GetN() ; k++) cout << w.Get(k) << "\t" ;
    cout << endl << endl;
    
    Vettore z ;                         // Operatore di assegnazione: il vettore z è già stato creato
    z = w;
    cout << "Vettore z: dimensione = " << z.GetN() << endl;
    for (unsigned int k = 0 ; k < z.GetN() ; k++) cout << z.Get(k) << "\t" ;
    cout << endl << endl;

    return 0;
}
