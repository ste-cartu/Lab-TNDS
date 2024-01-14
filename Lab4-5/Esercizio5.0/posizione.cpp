#include "posizione.hpp"




//costruttori
posizione::posizione(){
    m_A = 0;
    m_B = 0;
    m_C = 0;
}



posizione::posizione(double x, double y, double z){
    m_A = x;
    m_B = y;
    m_C = z;
}


//metodi
//coordinate cartesiane
double posizione::getX() const{
    return m_A;
}



double posizione::getY() const{
    return m_B;
}



double posizione::getZ() const{
    return m_C;
}




//coordinate sferiche
double posizione::getR() const{
    return sqrt( pow(m_A, 2) + pow(m_B, 2) + pow(m_C, 2) );
}



double posizione::getTheta() const{
    return acos(m_C/getR());
}



double posizione::getPhi() const{
    return atan2(m_B, m_A);
}

//coordinate cilindriche
double posizione::getRho() const{
    return sqrt( pow(m_A, 2) + pow(m_B, 2));
}

double posizione::Dist(const posizione& p) const{
    return sqrt( pow(getX() - p.getX(), 2) + pow(getY() - p.getY(), 2) + pow(getZ() - p.getZ(), 2));
}
