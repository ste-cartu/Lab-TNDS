#ifndef __vettore_hpp__
#define __vettore_hpp__

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

//#define NDEBUG

#include <assert.h>


using namespace std;



template <typename T> class vettore {
    
    public:
    
        vettore();
    
        vettore(unsigned int);
    
        ~vettore();
        
        vettore(const vettore&);
        
        vettore& operator = (const vettore&);
        
        unsigned int GetN() const;
        
        void Set(unsigned int, double);
        
        T Get(unsigned int) const;
     
        void Scambia(unsigned int, unsigned int);
     
        T& operator [] (unsigned int);
	

    private:

        unsigned int m_N;
        
        T* m_V;

};





template <class T> vettore<T>::vettore() {
    m_N = 0;
    m_V = NULL;
}



template <class T> vettore<T>::vettore(unsigned int N) {
    m_N = N;
    m_V = new T[N];
    for (int k = 0 ; k < N ; k++) m_V[k] = 0;
}



template <class T> vettore<T>::~vettore() {
    delete[] m_V;
}



template <class T> vettore<T>::vettore(const vettore& V) {
    m_N = V.GetN();
    m_V = new T[m_N];
    for (int i=0 ; i<m_N ; i++) m_V[i] = V.Get(i);
}



template <class T> vettore<T>& vettore<T>::operator = (const vettore& V) {
    m_N = V.GetN();
    if (m_V) delete[] m_V;
    m_V = new T[m_N];
    for (int i=0 ; i<m_N ; i++) m_V[i] = V.Get(i);
    return *this;
}



template <class T> unsigned int vettore<T>::GetN() const {
    return m_N;
}



template <class T> void vettore<T>::Set(unsigned int i, double a) {
    assert((m_N > i) && "errore: l'indice è troppo grande");

    if(i < m_N) {
        m_V[i]=a;
    }
    else {
        cerr << "errore: indice " << i << ", dimensione " << m_N << endl;
        exit (-1);
    }
}



template <class T> T vettore<T>::Get(unsigned int i) const {
    assert((m_N > i) && "Errore : l'indice è troppo grande");

    if(i < m_N)
        return m_V[i];
    else{
        cerr << "errore: indice " << i << ", dimensione " << m_N << endl;
        exit(-1);
    }
}



template <class T> void vettore<T>::Scambia(unsigned int i, unsigned int j) {
    T a = Get(i);
    Set(i, Get(j));
    Set(j, a);
}



template <class T> T& vettore<T>::operator [] (unsigned int i){
    assert((m_N > i) && "Errore : l'indice è troppo grande");
    if(i < m_N)
        return m_V[i];
    else{
        cerr << "errore: indice " << i << " dimensione " << m_N << endl;
        exit(-1);
    }
}




#endif // __vettore_hpp__
