#include "negaScout.h"
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]){
  int i;
  int j;
  //for (j = 0; j<33; ++j) {
  state_t init;
  bool curPlay = true;

	for(i=0;i<atoi(argv[1]);++i){
      init = init.move(curPlay,PV[i]);
      curPlay = !curPlay;
    }

	
    int n = negaScout(init,curPlay, 34-i, -MAXVALUE, MAXVALUE);
    printf("el n es %d para i %d \n", n, i);
  //}
}
