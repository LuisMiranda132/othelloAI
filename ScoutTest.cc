#include "scout.h"
#include <iostream>
#include <time.h>
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

	time_t start, end;
	time (&start);
    int n = scout(init, 34-i, curPlay);
    time(&end);
	double dif = difftime (end,start);
	cout << "El costo es " << n << " para i=" << i << " y duro " << dif << " segundos" << endl;

  //}
}
