#ifndef _random_hpp_
#define _random_hpp_

#include <cmath>

#include "libreria.hpp"


class randomgen{

public:
    
    randomgen(unsigned int s) {
        seed_ = s;
        ni_ = seed_;
    }
    randomgen(unsigned int s, unsigned int a, unsigned int b, unsigned int m) {
        seed_ = s;
        ni_ = seed_;
        a_ = a;
        b_ = b;
        m_ = m;
    }

    void SetA(unsigned int a) {a_ = a;}
    void SetB(unsigned int b) {b_ = b;}
    void SetM(unsigned int m) {m_ = m;}
    void Reset() {ni_ = seed_;}

    long double Rand() {
        ni_ = (ni_*a_ + b_) % m_;
        return (long double) ni_/m_;
    }
    
    long double Unif(float xmin, float xmax) {return (long double) xmin + ((xmax-xmin) * Rand());}
    
    long double Exp(double k) {return (long double) -(1/k) * log(1 - Rand());}
    
    double GaussBM(double m, double s) {
        double p = Rand();
        double q = Rand();
        long double x = sqrt(-2. * log(1.-p)) * cos(2.*M_PI*q);
        long double y = sqrt(-2. * log(1.-p)) * sin(2.*M_PI*q);
        return m + x*s;
    }
    
    /*
    std::vector<long double> GaussBM(double m, double s) {
        double p = Rand();
        double q = Rand();
        long double x = sqrt(-2. * log(1.-p)) * cos(2.*M_PI*q);
        long double y = sqrt(-2. * log(1.-p)) * sin(2.*M_PI*q);
        std::vector<long double> A {m + x*s, m + y*s};
        return A;
    }
    */
    
    long double GaussAR(double m, double s){
        gaussiana g(m, s);
        double max = g(m);
        
        double x = Unif(m - 5*s, m + 5*s);
        double y = Rand()*max;
        
        while(y >= g(x)){
            x = Unif(m - 5*s, m + 5*s);
            y = Rand()*max;
        }
        
        return x;
    }

private:
    
    unsigned int a_ = 1664525, b_ = 1013904223, m_ = 1 << 31; //pow(2, 31)
    unsigned int seed_, ni_;
    
};

#endif
