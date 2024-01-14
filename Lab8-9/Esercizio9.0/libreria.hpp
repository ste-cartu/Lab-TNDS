// ===============================================================================
//
// A library defining possible operations among std::vector 
//
// ===============================================================================

#ifndef libreria_hpp
#define libreria_hpp

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>    // se se vogliono usare algoritmi STL
#include <numeric>      // per inner_product

//using namespace std;





// ===============================================================================               
// somma di due vettori : somma componente per componente
// ===============================================================================                                                                                               
template <typename T> std::vector<T> operator +(const std::vector<T> &a, const std::vector<T> &b) {

    // assert(a.size() == b.size());
    //  if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;
    if (a.size() != b.size()) {
        std::cerr << "Errore! Somma di due vettori di dimensioni differenti!" << std::endl;
        std::cerr << "Exiting..." << std::endl;
        exit(-1);
    }

    std::vector<T> result(a.size());

    //for (int i = 0 ; i < static_cast<int>(a.size()) ; i++) {result[i] = a[i] + b[i];}

    // Alternativamente si puo' usare l'algoritmo transform della STL
    std::transform(a.begin(), a.end(), b.begin(), result.begin() , std::plus<T>());

    return result;
  
}





// =====================================================================================================
// differenza di due vettori componente per componente
// [ preferisco re-implementarlo perche' si fanno meno operazioni rispetto result = a + (-1.*b) ]
// =====================================================================================================

template <typename T> std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b) {
  
    // assert(a.size() == b.size());
    // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size";

    if (a.size() != b.size()) {
        std::cerr << "Errore! Differenza di due vettori di dimensioni differenti!" << std::endl;
        std::cerr << "Exiting..." << std::endl;
        exit(-1);
    }

    std::vector<T> result(a.size());

    //for (int i = 0; i < static_cast<int>(a.size()); i++) {result[i] = a[i] - b[i];}

    // Alternativamente si puo' usare l'algoritmo transform della STL
    std::transform(a.begin(), a.end(), b.begin(), result.begin() , std::minus<T>());

    return result;

}





// ===============================================================================  
// prodotto scalare tra due vettori 
// ===============================================================================

template <typename T> T operator * (const std::vector<T> &a, const std::vector<T> &b) {

    // assert(a.size() == b.size());
    // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size";
    
    if (a.size() != b.size()) {
        std::cerr << "Errore! Prodotto scalare di due vettori di dimensioni differenti!" << std::endl;
        std::cerr << "Exiting..." << std::endl;
        exit(-1);
    }

    T p = 0;
    
    for (int i = 0; i < static_cast<int>(a.size()); i++) {p += a[i] * b[i];}

    // Alternativamente si puo' usare l'algoritmo inner_product della STL
    //p = std::inner_product(std::begin(a), std::end(a), std::begin(b), 1.0);

    return p;
  
}





// ===============================================================================
// prodotto tra uno scalare e un vettore
// ===============================================================================

template <typename T> std::vector<T> operator * (T c , const std::vector<T> &a) {
  
    std::vector<T> result(a.size());

    //for (int i = 0; i < static_cast<int>(a.size()); i++) {result[i] = c * a[i];}

    // Alternativamente si puo' usare l'algoritmo inner product
    std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T x){return x * c;});
    
    //std::transform(a.begin(), a.end(), result.begin(), [&c](T x){return x * c;})

    return result;
  
}





// ===============================================================================
// prodotto tra un vettore e uno scalare 
// ===============================================================================

template <typename T> std::vector<T> operator * (const std::vector<T> &a , T c) {
  
    std::vector<T> result(a.size());

    for (int i = 0; i < static_cast<int>(a.size()); i++) {result[i] = c * a[i];}

    // oppure il ciclo for puo' essere sostituito da ( ~ stesso numero di operazioni con il
    // move constructor del vector altrimenti sarebbe meno efficiente )
    // result = c * a ;

    // Alternativamente si puo' usare l'algoritmo transform della STL con una lambda function
    //std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T x){return x * c;});

    return result;

}





// ===============================================================================
// divisione tra un vettore e uno scalare 
// ===============================================================================

template <typename T> std::vector<T> operator / (const std::vector<T> &a , T c) {
  
    std::vector<T> result(a.size());

    //for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] / c ;

    // oppure il ciclo for puo' essere sostituito da

    double fact = 1./c;
    result = a * fact;

    // Alternativamente si puo' usare l'algoritmo transform della STL con una lambda function
    //std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T x){return x / c;});

    return result;
  
}





// ===============================================================================
// somma ad a un vettore b e il risultato viene messo in a
// ===============================================================================

template <typename T> std::vector<T>& operator += (std::vector<T>& a, const std::vector<T>& b) {

    // assert(a.size() == b.size());
    // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;
    
    if ( a.size() != b.size() ) {
        std::cerr << "Errore! Somma di due vettori di dimensioni differenti!" << std::endl;
        std::cerr << "Exiting..." << std::endl;
        exit(-1);
    }

    //for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] += b[i];

    // Alternativamente si puo' usare l'algoritmo transform della STL
    std::transform(a.begin(), a.end(), b.begin(), a.begin() , std::plus<T>());

    return a;
    
}





// ===============================================================================
// sottrai ad a un vettore b e il risultato viene messo in a
// ===============================================================================

template <typename T> std::vector<T>& operator-=(std::vector<T>& a, const std::vector<T>& b) {

    // assert(a.size() == b.size());
    // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;
    
    if ( a.size() != b.size() ) {
        std::cerr << "Errore! Differenza di due vettori di dimensioni differenti!" << std::endl;
        std::cerr << "Exiting..." << std::endl;
        exit(-1);
    }

    //for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] -= b[i];

    // Alternativamente si puo' usare l'algoritmo transform della STL
    std::transform(a.begin(), a.end(), b.begin(), a.begin() , std::minus<T>());

    return a;
    
}





// ===============================================================================
// Possiamo usare funzioni generiche che agiscono sui vettori
// ===============================================================================
  
// metodo comodo per stampare il vettore
template <typename T> void Stampa(const std::vector<T> &v, const char* vettore) {
  
    std::cout << vettore << ":" << std::endl;
    std::cout << "(";
    for (auto it = v.begin() ; it != v.end() ; it++) {std::cout << *it << ", " ;}
    std::cout << "\b\b)" << std::endl << std::endl;
    //std::cout << "End of printing vector" << std::endl;

}




/*
template <typename T> class linearVector : public std::vector<T> {
  
public :

    linearVector<T> ( ) : std::vector<T>(){} ;
    linearVector<T> ( int size ) : std::vector<T>(size){} ;

    linearVector<T> operator+( const linearVector<T> &a ) {

    assert(a.size() == this->size());

    linearVector<T> result(a.size()) ;
    for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] + (*this)[i];

    return result;
    
  }
  
};
*/



#endif
