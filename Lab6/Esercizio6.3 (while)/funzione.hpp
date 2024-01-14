#ifndef funzione_hpp
#define funzione_hpp


// funzione sgn utile negli algoritmi di ricerca zeri
int sgn(double x) {return (x==0 ? 0 : (x>0 ? 1 : -1)); }


class funzione {
    
public:

    virtual double Eval(double) const = 0;
    virtual ~funzione() {;}
    
};



#endif
