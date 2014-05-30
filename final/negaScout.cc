#include "negaScout.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(){
	int i;
	int j;
	for (j = 33; j>=0; --j) {
		state_t init;
		bool curPlay = true;

		for(i=0;i<j;++i){
			init = init.move(curPlay,PV[i]);
			curPlay = !curPlay;
		}

		time_t start, end;
		time (&start);
		int n = negaScout(init, curPlay, 34-i, -MAXVALUE, MAXVALUE);
		time(&end);
		double dif = difftime (end,start);
		cout << "NEGASCOUT: Para " << 34-i << " estados(" << "estado: " << i << ") duro " << dif << " segundos" << endl;
	}
}