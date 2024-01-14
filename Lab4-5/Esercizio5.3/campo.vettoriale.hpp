#ifndef campo_vettoriale_hpp
#define campo_vettoriale_hpp

#include <iostream>
#include <cmath>




class campovett: public posizione{
    
public:
    campovett(const posizione& r): posizione(r){
        m_Fx = 0;
        m_Fy = 0;
        m_Fz = 0;
    }
    campovett(const posizione& r, double Fx, double Fy, double Fz): posizione(r){
        m_Fx = Fx;
        m_Fy = Fy;
        m_Fz = Fz;
    }
    campovett(double x, double y, double z, double Fx, double Fy, double Fz): posizione(x,y,z){
        m_Fx = Fx;
        m_Fy = Fy;
        m_Fz = Fz;
    }
    ~campovett() {;}
    
    
    double getFx() const {return m_Fx;}
    double getFy() const {return m_Fy;}
    double getFz() const {return m_Fz;}
    
    
    campovett operator + (const campovett& V) const{
        campovett S(V);
        
        if (S.getX() == V.getX() && S.getY() == V.getY() && S.getZ() == V.getZ()){
            S.m_Fx += getFx();
            S.m_Fy += getFy();
            S.m_Fz += getFz();
        }
        else{
            cerr << "Somma tra campi vettoriali:" << endl;
            cerr << "posizione primo vettore:\t(" << V.getFx() << ", " << V.getFy() << ", " << V.getFz() << ")" << endl;
            cerr << "posizione secondo vettore:\t(" << S.getFx() << ", " << S.getFy() << ", " << S.getFz() << ")" << endl;
        }
            
        return S;
    }
    
    
    campovett& operator += (const campovett& V){
        return *this = *this + V;
    }
    
    
    double Mod() const{
        return sqrt( pow(m_Fx, 2) + pow(m_Fy, 2) + pow(m_Fz, 2));
    }
    
    
    void Stampa() const{
        cout << "\tPosizione:\t(" << m_A << ", " << m_B << ", " << m_C << ")" << endl;
        cout << "\tModulo:\t\t" << Mod() << endl;
        cout << "\tCampo:\t\t(" << m_Fx << ", " << m_Fy << ", " << m_Fz << ")" << endl << endl;
    }

    
protected:
    
    double m_Fx, m_Fy, m_Fz;
    
};





#endif
