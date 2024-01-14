#ifndef posizione_hpp
#define posizione_hpp

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


class posizione{
    
    public:
        //costruttori
        posizione();
        posizione(double x, double y, double z);        //loro devono essere per forza le coordinate cartesiane
        
        //distruttore
        ~posizione() {};
        
        //metodi
        //coordinate cartesiane
        double getX() const;
        double getY() const;
        double getZ() const;
        //coordinate sferiche
        double getR() const;
        double getTheta() const;
        double getPhi() const;
        //coordinate cilindriche
        double getRho() const;
        
        double Dist(const posizione&) const;
        
    
    protected:
        double m_A, m_B , m_C;
    
};



#endif
