#ifndef funzioni_hpp
#define funzioni_hpp

#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



class funzione {

public:
    
    funzione() {m_a = 0;}
    virtual double Eval(double) const = 0;
    double operator()(double x) {return Eval(x);}
    virtual ~funzione() {;}

protected:
    
    double m_a;
    
};



class gaussiana: public funzione{
    
public:
    gaussiana(double m, double s) {media_ = m; devst_ = s;}
    ~gaussiana() {;}
    
    double Eval (double x) const override {return (1 / sqrt(2*M_PI*pow(devst_, 2))) * pow(M_E, -(pow(x-media_, 2)) / 2*pow(devst_, 2));}
    
    void SetMedia (double m) {media_ = m;}
    double GetMedia() const {return media_;}
    void SetDevst (double s) {devst_ = s;}
    double GetDevst () const {return devst_;}
    
private:
    double media_, devst_;
        
};



//y = a*sin(b*x) + c
class seno : public funzione {

public:

    seno() {a_=1; b_=1.; c_=0.;}
    seno(double a, double b, double c) {a_=a; b_=b; c_=c;}
    ~seno() {;}
    double Eval (double x) const override {return a_*sin(b_*x) + c_;}
    void SetA (double a) {a_=a;}
    double GetA () const {return a_;}
    void SetB (double b) {b_=b;}
    double GetB () const {return b_;}
    void SetC (double c) {c_=c;};
    double GetC () const {return c_;}

private:

    double a_, b_, c_;

};



long double Media(const vector<long double>& V){
    long double media = 0;
    
    for (int i=0 ; i<V.size() ; i++) media = (i*media + V[i])/(i+1);
    
    return media;
}



long double Varianza(const vector<long double>& V){
    long double var = 0;

    long double m, M=0;
    for (int i=0 ; i<V.size() ; i++){
        m = M;
        M = Media(V);
        
        var = (i*var + pow(V[i], 2) + i*pow(m, 2))/(i+1) - pow(M, 2);
    }
    
    return var;
}



#endif
