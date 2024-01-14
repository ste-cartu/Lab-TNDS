#ifndef tangente_hpp
#define tangente_hpp

#include "funzione.hpp"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

//ax = btan(cx)
//bsin(cx) - axcos(cx) = 0




void Intervallo(int n, ofstream& out){
    if(n == 0) {out << "[0, 𝛑/2]";}
    if(n == 1) {out << "[𝛑, 3𝛑/2]";}
    else if(n != 0 && n != 1) {out << "[" << n << "𝛑, " << (2*n)+1 << "𝛑/2]";}
}




class tangente : public funzione {

public:

    tangente() {m_a=0.; m_b=0.; m_c=0.;}
    tangente(double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
    ~tangente() {;}
    double Eval (double x) const override {return m_b*sin(m_c*x) - m_a*x*cos(m_c*x);}
    void SetA (double a) {m_a=a;}
    double GetA () const {return m_a;}
    void SetB (double b) {m_b=b;}
    double GetB () const {return m_b;}
    void SetC (double c) {m_c=c;};
    double GetC () const {return m_c;}
    
    void StampaZeri(vector<double> Z, double p){
        //cifre significative
        int cifre = -log10(p);
        
        ofstream out("zeri.dat");
        
        if(m_a == 1 && m_b == 1 && m_c == 1) {out << "Gli zeri della funzione x = tan(x) sono:" << endl << endl;}
        else {out << "Gli zeri della funzione " << GetA() << "x = " << GetB() << "tan(" << GetC() << "x) sono:" << endl << endl;}
        
        for(int i=0 ; i<Z.size() ; i++) {
            out << fixed;
            out << setprecision(cifre) << i+1 << ")\t" << Z[i] << " ± " << p << "   ∈   ";
            Intervallo(i, out);
            out << endl;
        }
        out.close();
    }


private:

    double m_a, m_b, m_c;

};


#endif 
