#include "minimax.h"
#include <iostream>

using namespace std;

int main(){
  state_t init;
  bool curPlay = false;

  vector<state_t> lista;
  
// total de 33
// i es impar -> true
// i es par -> false

  float t2, t1;
  
  int i;
  for(i=0;i<33;++i){
      init = init.move(!curPlay,PV[i]);
      curPlay = !curPlay;
      lista.insert(lista.begin(),init);
  }
  
  for(i=0;i<33;++i){
      // cout << i << endl;
      // cout << lista[i] << endl;
      
      bool black = i % 2 != 0;
      
      cout << 33-i << ": Juega " << (black ? "Negro" : "Blanco")<< endl;
//      cout << lista[i] << endl;
      minimax<state_t> pruebas;


      cout << "Corriendo minimax: "<<endl;
      t2 = Utils::read_time_in_seconds();
      int n = pruebas.search(lista[i], 34, black);
      t1 = Utils::read_time_in_seconds();
      cout <<"\t"<< n <<" = -4\tt "<<t1-t2<<"\n" << endl;
      
      cout << "Corriendo α-ß: "<<endl;
      t2 = Utils::read_time_in_seconds();
      n = pruebas.alphabeta(lista[i], 34,-1000,1000, black);
      t1 = Utils::read_time_in_seconds();
      cout <<"\t"<< n <<" = -4\tt "<<t1-t2<<"\n" << endl;
  }

  // bool black = i % 2 == 0;

  // cout << i << ": Juega " << (black ? "Negro" : "Blanco") << endl;
  // cout << init << endl;
  // minimax<state_t> pruebas;
  // cout << "Corriendo minimax: "<<endl;
  // int n = pruebas.search(init, 34-i, black);
  // cout <<"\t"<< n <<" = -4" << endl;

  // cout << "Corriendo α-ß: "<<endl;
  // n = pruebas.alphabeta(init, 34-i,-1000,1000, black);
  // cout <<"\t"<< n <<" = -4" << endl;
  
  
}
