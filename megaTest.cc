#include "minimax.h"
#include <iostream>

using namespace std;

int main(){
  state_t init;
  bool curPlay = false;

// total de 33
// i es impar -> true
// i es par -> false
  int i;
  for(i=0;i<33;++i){
    init = init.move(!curPlay,PV[i]);
    curPlay = !curPlay;
  }

  bool black = i % 2 == 0;

  cout << i << ": Juega " << (black ? "Negro" : "Blanco") << endl;
  cout << init << endl;
  minimax<state_t> pruebas;
  cout << "Corriendo minimax: "<<endl;
  int n = pruebas.search(init, 34-i, black);
  cout <<"\t"<< n <<" = -4" << endl;

  cout << "Corriendo α-ß: "<<endl;
  n = pruebas.alphabeta(init, 34-i,-1000,1000, black);
  cout <<"\t"<< n <<" = -4" << endl;
  
  
}
