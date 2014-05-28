#include "negaMax.h"
#include <iostream>
using namespace std;

int main(){
  for(int cur=33; cur > 0; cur -= 5){
    state_t init;
    bool curPlay = true;
    for(int i=0;i<cur;++i){
      init = init.move(curPlay,PV[i]);
      curPlay = !curPlay;
    }

    float t1 = Utils::read_time_in_seconds(); 
    int n = negamax(init,34,curPlay);
    float t2 = Utils::read_time_in_seconds();
    //int m = negamax_ab(init,34,-MAXVALUE,MAXVALUE,curPlay);
    //float t3 = Utils::read_time_in_seconds();
    cout << "From value " << cur << ((curPlay) ? " Black ": " White ") << "Plays: " << (curPlay ? n : -n) << " in " << t2-t1 << " seconds" << endl;
    //cout << "From value " << cur << ((curPlay) ? " Black ": " White ") << "Plays: " << (curPlay ? m : -m) << " in " << t3-t2 << " seconds" << endl;
  }
}
