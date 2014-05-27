#include "negaMax.h"
#include <iostream>
using namespace std;

int main(){

  for(int cur=33; cur > 0; --cur){
    state_t init;
    bool curPlay = true;
    for(int i=0;i<cur;++i){
      init = init.move(curPlay,PV[i]);
      curPlay = !curPlay;
    }

    Node<state_t> i(init,curPlay);
    int n = negaMax(i,34);
    cout << "From value " << cur << "(Curplay is " << ((curPlay) ? "True): ": "False): ") << n << endl;
  }
}
