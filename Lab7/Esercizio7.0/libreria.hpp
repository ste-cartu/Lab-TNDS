#ifndef libreria_hpp
#define libreria_hpp

#include <iostream>
#include <cmath>
#include <fstream>

#define _USE_MATH_DEFINES

using namespace std;



// funzione sgn utile negli algoritmi di ricerca zeri
int sgn(double x) {return (x==0 ? 0 : (x>0 ? 1 : -1)); }



void StampaIntervallo(int n, ofstream& out){
    if(n == 0) {out << "[0, 𝛑/2]";}
    if(n == 1) {out << "[𝛑, 3𝛑/2]";}
    else if(n != 0 && n != 1) {out << "[" << n << "𝛑, " << (2*n)+1 << "𝛑/2]";}
}


double Max(double x, double y) {return x > y ? x : y;}



double Min(double x, double y) {return x < y ? x : y;}



#endif
