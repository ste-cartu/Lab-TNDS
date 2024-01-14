#ifndef posizione_hpp
#define posizione_hpp

#include <iostream>
#include <cmath>

using namespace std;




class posizione{
    
public:

    posizione(){
        m_A = 0;
        m_B = 0;
        m_C = 0;
    }
    posizione(double x, double y, double z){
        m_A = x;
        m_B = y;
        m_C = z;
    }
    ~posizione() {};
    

//coordinate cartesiane
    double getX() const {return m_A;}
    double getY() const {return m_B;}
    double getZ() const {return m_C;}
    
    void setX(double x) {m_A = x;}
    void setY(double y) {m_B = y;}
    void setZ(double z) {m_C = z;}
    
//coordinate sferiche
    double getR() const{
        return sqrt( pow(m_A, 2) + pow(m_B, 2) + pow(m_C, 2) );
    }
    double getTheta() const{
        return acos(m_C/getR());
    }
    double getPhi() const{
        return atan2(m_B, m_A);
    }
    
//coordinate cilindriche
    double getRho() const{
        return sqrt( pow(m_A, 2) + pow(m_B, 2));
    }
    
    
    double Dist(const posizione& p) const{
        return sqrt( pow(getX() - p.getX(), 2) + pow(getY() - p.getY(), 2) + pow(getZ() - p.getZ(), 2));
    }
    
    posizione operator + (const posizione& p) const{
        posizione q(getX() + p.getX(), getY() + p.getY(), getZ() + p.getZ());
        
        return q;
    }
    
    posizione operator - (const posizione& p) const{
        posizione q(getX() - p.getX(), getY() - p.getY(), getZ() - p.getZ());
        
        return q;
    }

protected:
    double m_A, m_B , m_C;

};




#endif
