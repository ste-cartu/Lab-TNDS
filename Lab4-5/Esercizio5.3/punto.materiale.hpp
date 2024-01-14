#ifndef punto_materiale_hpp
#define punto_materiale_hpp

#include "particella.hpp"
#include "campo.vettoriale.hpp"

#include <iostream>
#include <cmath>

#define EPS 8.85418781762e-12
#define _USE_MATH_DEFINES





class puntomat : public particella, public posizione {

public:
    
    puntomat(const particella& p, const posizione& r): particella(p), posizione(r) {;}
    puntomat(double massa, double carica, const posizione& r): posizione(r) {
        m_massa = massa;
        m_carica = carica;
    }
    puntomat(const particella& p, double x, double y, double z): particella(p) {
        m_A = x;
        m_B = y;
        m_C = z;
    }
    puntomat(double massa, double carica, double x, double y, double z): particella(massa, carica), posizione(x, y, z) {;}
    ~puntomat() {;}

    campovett CampoElett(const posizione& r) const{
        double k = (1/(4*M_PI*EPS)) * (m_carica/pow(Dist(r), 3));
        
        double Ex = k * (r.getX() - getX());
        double Ey = k * (r.getY() - getY());
        double Ez = k * (r.getZ() - getZ());

        //cout << "posizione relativa: (" << q.getX() << ", " << q.getY() << ", " << q.getZ() << ")" << endl << endl;

        //campovett E (r, modE * sin(q.getTheta()) * cos(q.getPhi()), modE * sin(q.getTheta()) * sin(q.getPhi()), modE * cos(q.getTheta()));

        /*
        double modE = (1/(4*M_PI*EPS)) * (m_carica/pow(Dist(r), 2));
        posizione p(getX(), getY(), getZ());
        posizione q = r-p;

        double Ex;
        double Ey;
        double Ez;

        if (q.getX() == 0)
            Ex = 0;
        else
            Ex = modE * (sqrt(pow(q.getX(), 2) + pow(q.getY(), 2)) / Dist(r)) * (q.getX() / sqrt(pow(q.getX(), 2) + pow(q.getY(), 2)));
        if (q.getY() == 0)
            Ey = 0;
        else
            Ey = modE * (sqrt(pow(q.getX(), 2) + pow(q.getY(), 2)) / Dist(r)) * (q.getY() / sqrt(pow(q.getX(), 2) + pow(q.getY(), 2)));
        if (q.getZ() == 0)
            Ez = 0;
        else
            Ez = modE * (q.getZ() / Dist(r));
        */

        campovett E(r, Ex, Ey, Ez);

        return E;
    }
    
    //campovett CampoGrav(const posizione& r) const;
  

    

};


#endif
