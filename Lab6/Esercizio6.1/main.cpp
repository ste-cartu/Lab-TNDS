#include "funz.par.hpp"

#include <iostream>

using namespace std;


int main(int argc, char** argv){
    
    if(argc != 4){
        cerr << "Attenzione!" << endl;
        cerr << "Per eseguire il programma scrivere: " << argv[0] << " <a> <b> <c>" << endl;
        exit(0);
    }
    
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    
    parabola p(a, b, c);
    
    cout << endl;
    cout << "l'equazione della parabola inserita è: y = " << a << "X^2 + " << b << "X + " << c << endl << endl;
    cout << "il vertice della parabola è: x = " << -b/(2*a) << endl << endl;
    cout << "il valore della parabola nel vertice è: y = " << p.Eval(-b/(2*a)) << endl << endl;
    
    
    return 0;
    
}
