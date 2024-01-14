#ifndef prisma_hpp
#define prisma_hpp

#include <cmath>

#include "random.hpp"

using namespace std;



class prisma{
    
public:
    prisma(unsigned int seed, double t0) : gen_(seed) {
        l1_ = 579.1E-9;
        l2_ = 404.7E-9;
        alpha_ = M_PI/3.;
        sigma_ = 0.3E-3;
        A_ = 2.7;
        B_ = 60000E-18;
        
        // calcolo degli indici di rifrazione
        n1_ = sqrt(A_ + B_/pow(l1_,2));
        n2_ = sqrt(A_ + B_/pow(l2_,2));
        
        //come theta_0 (t0_) scelgo M_PI/2
        t0_ = t0;
        
        // determino theta1 (t1_) e theta2 (t2_)
        dt1_ = 2. * asin( n1_*sin(alpha_/2.) ) - alpha_;
        dt2_ = 2. * asin( n2_*sin(alpha_/2.) ) - alpha_;
        
        t1_ = t0_ + dt1_;
        t2_ = t0_ + dt2_;
    }
        
    ~prisma() {;}
    
    double GetA() {return A_;}          double GetAMis() {return Am_;}
    double GetB() {return B_;}          double GetBMis() {return Bm_;}
    double Getn1() {return n1_;}        double Getn1Mis() {return n1m_;}
    double Getn2() {return n2_;}        double Getn2Mis() {return n2m_;}
    double Getdt1() {return dt1_;}      double Getdt1Mis() {return dt1m_;}
    double Getdt2() {return dt2_;}      double Getdt2Mis() {return dt2m_;}
    double Gett0() {return t0_;}        double Gett0Mis() {return t0m_;}
    double Gett1() {return t1_;}        double Gett1Mis() {return t1m_;}
    double Gett2() {return t2_;}        double Gett2Mis() {return t2m_;}
    
    void Misura() {
        t0m_ = gen_.GaussBM(t0_, sigma_);
        t1m_ = gen_.GaussBM(t1_, sigma_);
        t2m_ = gen_.GaussBM(t2_, sigma_);
    }
    
    void Analisi() {
        dt1m_ = t1m_ - t0m_;
        dt2m_ = t2m_ - t0m_;
        
        n1m_ = sin( (dt1m_ + alpha_)/2. ) / sin(alpha_/2.);
        n2m_ = sin( (dt2m_ + alpha_)/2. ) / sin(alpha_/2.);
        
        Am_ = ((l2_*l2_ * n2m_*n2m_) - (l1_*l1_ * n1m_*n1m_)) / (l2_*l2_ - l1_*l1_);
        Bm_ = (n2m_*n2m_ - n1m_*n1m_) / (1/(l2_*l2_) - 1/(l1_*l1_));
    }
    
private:
    randomgen gen_;
    
    double l1_, l2_, alpha_, sigma_;
    
    double A_, Am_;
    double B_, Bm_;
    double n1_, n1m_;
    double n2_, n2m_;
    double dt1_, dt1m_;
    double dt2_, dt2m_;
    double t0_, t0m_;
    double t1_, t1m_;
    double t2_, t2m_;
    
};





#endif
