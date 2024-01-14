#ifndef pos_campo_hpp
#define pos_campo_hpp

#define Epsilon 8.85418781762e-12
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;



//questo programma richiede da linea di comando una posizione in coordinate cartesiane e restituisce in output il valore del campo elettrico di un dipolo protone-elettrone in quel punto


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
    double getX() const{
        return m_A;
    }
    double getY() const{
        return m_B;
    }
    double getZ() const{
        return m_C;
    }
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








#endif /* pos_campo_hpp */
