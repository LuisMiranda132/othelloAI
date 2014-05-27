#include "negaMax.h"
#include <iostream>
using namespace std;

int main(){
  state_t init;
  bool curPlay = false;
  for(int i=0;i<31;++i){
    init = init.move(!curPlay,PV[i]);
    curPlay = !curPlay;
  }
  Node<state_t> i(init,curPlay);
  int n = negaMax(i,2);
  cout << n << endl;
}
