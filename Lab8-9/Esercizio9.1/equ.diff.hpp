#ifndef equ_diff_hpp
#define equ_diff_hpp

#include "libreria.hpp"
#include <cmath>

using namespace std;



// ====================================================================
// Classe astratta, restituisce la derivata nel punto x al tempo t
// ====================================================================

class fvett {

public:
    
    virtual vector<double> Eval(double t, const vector<double>& X) const = 0;
    
};





// ====================================================================
// Caso fisico concreto
// ====================================================================

class oscar: public fvett {

public:

    oscar(double w0) {w0_ = w0;}

    vector<double> Eval(double t, const vector<double>& X) const override {
        vector<double> Y{X[1], -pow(w0_, 2)*X[0]};
        return Y;
    }

private:
    
    double w0_;
    
};





// ====================================================================
// Classe astratta per un integratore di equazioni differenziali
// ====================================================================

class integratore {
    
public:
    
    virtual vector<double> Passo(double t, const vector<double>& X, double h, const fvett& f) const = 0;
    
};





// ====================================================================
// Integratore concreto, metodo di Eulero
// ====================================================================

class eulero: public integratore {

public:

    vector<double> Passo(double t, const vector<double>& X, double h, const fvett& f) const override {
        vector<double> Y = X + h * (f.Eval(t+h, X));
        return Y;
    }
    
};


#endif
