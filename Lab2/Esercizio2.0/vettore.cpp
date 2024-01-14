#include "vettore.h"



//costruttore senza argomenti
Vettore::Vettore()  {
    cout << "chiamo il costruttore di default" << endl;
    m_N = 0;
    m_v = NULL;
}



//costruttore con dimensione
Vettore::Vettore(unsigned int N) {
    cout << "chiamo il costruttore con argomento" << endl;
    m_N = N;
    m_v = new double[N];
    for (int k = 0 ; k < N ; k++) m_v[k] = 0;                         //inizializzo a 0 il vettore
}



//distruttore
Vettore::~Vettore() {
    cout << "chiamo il distruttore" << endl;
    delete[] m_v;
}



//costruttore di copia
Vettore::Vettore(const Vettore& v) {
    m_N = v.GetN();
    m_v = new double[m_N];
    for (int i=0 ; i<m_N ; i++) m_v[i] = v.Get(i);
}



//overloading dell'operatore di assegnazione
Vettore& Vettore::operator = (const Vettore& v) {
    m_N = v.GetN();
    if (m_v) delete[] m_v;
    m_v = new double [m_N];
    for (int i=0 ; i<m_N ; i++) m_v[i] = v.Get(i);
    return *this;
}



void Vettore::Set(unsigned int i, double a) {
    assert((m_N > i) && "errore: l'indice è troppo grande");

    if(i < m_N) {
        m_v[i]=a;
    }
    else {
        cerr << "errore: indice " << i << ", dimensione " << m_N << endl;
        exit (-1);
    }
}



double Vettore::Get(unsigned int i) const {
    assert((m_N > i) && "Errore : l'indice è troppo grande");

    if(i < m_N)
        return m_v[i];
    else{
        cerr << "errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
}



void Vettore::Scambia(unsigned int i, unsigned int j) {
    double a = Get(i);
    Set(i, Get(j));
    Set(j, a);
}
