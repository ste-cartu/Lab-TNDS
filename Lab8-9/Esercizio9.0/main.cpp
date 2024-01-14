#include <vector>
#include <iostream>

#include "libreria.hpp"

using namespace std;

int main() {
    
    cout << endl;
    
    vector<double> v1{3., 4., 6.};
    Stampa(v1, "v1");
    
    vector<double> v2{4., 5., 6.};
    Stampa(v2, "v2");

    double para = 2.;

    // provare la somma e prodotto per scalare

    vector<double> v3 = v1 + v2;
    Stampa(v3, "v3");
    
    vector<double> v4 = v2/para;
    Stampa(v4, "v4 = v2/2");
    
    vector<double> v5 = v1 - v2;
    Stampa(v5, "v5 = v1 - v2");
    
    vector<double> v6 = v1 * 3.;
    Stampa(v6, "v6 = v1 * 3");
    
    double p = v3 * v2;
    cout << "v3 * v2 = " << p << endl << endl;
    
    double q = v1 * v2;
    cout << "v1 * v2 = " << q << endl;
    
    cout << endl;
    
    return 0;

}

