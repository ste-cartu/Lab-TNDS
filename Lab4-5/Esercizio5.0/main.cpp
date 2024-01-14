#include "posizione.hpp"


// Questo programma vuole com input da riga di comando le coordinate
// x, y e z di un punto e ne restituisce le coordinate sferiche
// e cilindiriche.

int main(int argc, char** argv) {

  // Controlla gli argomenti
  if ( argc!=4 ) {
    std::cerr << "Uso del programma: " << argv[0] << " <x> <y> <z>" << endl;
    return -1;
  }

  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);

  // Crea un oggetto posizione ed accede ai vari metodi

  posizione P(x,y,z);
    
    cout << endl;
    cout << "Coordinate cartesiane:" << endl;
        cout << "P: (" << P.getX() << ", " << P.getY() << ", " << P.getZ() << ")" << endl << endl;
    cout << "Coordinate cilindriche:" << endl;
        cout << "Rho: " << P.getRho() << "\tPhi: " << P.getPhi() << "\tZ: " << P.getZ() << endl << endl;
    cout << "Coordinate sferiche:" << endl;
        cout << "R: " << P.getR() << "\tPhi: " << P.getPhi() << "\tTheta: " << P.getTheta() << endl << endl;

  return 0;
}
