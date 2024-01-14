#ifndef funzioni_hpp
#define funzioni_hpp

#include <cmath>

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



#endif
