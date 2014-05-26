#include "negaMax.h"
#define STEPS 5

int main(){
  int PVsize = (sizeof(PV)/sizeof(*PV));
  int curDepth = PVsize - 1;
  curDepth = (curDepth - STEPS < 0) ? 0 : curDepth - STEPS;

  while(curDepth >= 0){
    std::cout << "Iteration after value " << curDepth-1 << "(" << PV[curDepth-1] << ")" << std::endl;
    state_t init;
    bool curPlay = false;

    for(int i=0;i<curDepth;++i){
      std::cout << PV[i] << " ";
      init = init.move(!curPlay,PV[i]);
      curPlay = !curPlay;
    }

    for(int i=curDepth;i<PVsize-1;++i){
      Node<state_t> temp(init,curPlay);
      int next = negaMax(temp,STEPS);
      //std::cout << std::endl << next << std::endl;
      std::vector<int> plays(init.getChildren(!curPlay));

      for(int j=0;j<plays.size();++j){
        if((init.move(!curPlay,plays[j])).value() == 6){
          init = init.move(!curPlay,plays[j]);
          curPlay = !curPlay;
          std::cout << plays[j] << " ";
        }
      }

    }

    std::cout << std::endl;
    if(curDepth) break;
    curDepth = (curDepth - STEPS < 0) ? 0 : curDepth - STEPS;
  }
}
