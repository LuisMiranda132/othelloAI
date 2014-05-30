#include "negaMax.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[]){
  if(argc != 2){
    cout << "Usage: ./negaTest -[n|ab]" << endl;
    return 0;
  }
  string arg(argv[1]);
  if(arg != "-n" and arg != "-ab"){
    cout << "Usage: ./negaTest -[n|ab]" << endl;
  }else{
    cout << "Testing " << (arg == "-n" ? "negamax" : "negamax_ab") << endl;
    for(int cur=33; cur > 0; cur -= 5){
      state_t init;
      bool curPlay = true;
      for(int i=0;i<cur;++i){
        init = init.move(curPlay,PV[i]);
        curPlay = !curPlay;
      }

      float t1 = Utils::read_time_in_seconds();
      int n = (arg == "-n" ? negamax(init,34,curPlay) : negamax_ab(init,34,-MAXVALUE,MAXVALUE,curPlay));
      float t2 = Utils::read_time_in_seconds();
      cout << "From value " << cur << ((curPlay) ? " Black ": " White ") << "Plays: " << (curPlay ? n : -n) << " in " << t2-t1 << " seconds" << endl;
    }
  }
}
