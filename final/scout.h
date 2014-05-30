#include "othello_cut.h"
#include "utils.h"
#include <stdio.h>

bool testG(state_t pos, int depth, int v, bool max)  {
	
	if((pos.terminal()) ||  (depth == 0)) {
		return (max ? (pos.value()>v) : (-pos.value()>v));
	}
	
	std::vector<int> succ(pos.getChildren(max));
	int i;
	if (max) {
		for (i = 0; i < succ.size(); ++i) { 
			if (testG(pos.move(max,succ[i]), depth-1, v, !max)) {
				return 1;
			}
		}
	return 0;
	
	}
	else {
		for (i = 0; i < succ.size(); ++i) { 
			if (!testG(pos.move(max,succ[i]), depth-1, v, !max)) {
				return 0;
			}
		}
		return 1;
	}
}

bool testG_E(state_t pos, int depth, int v, bool max)  {
	
	if (pos.terminal() || depth == 0) {
		return (max ? (pos.value()>=v) : (-pos.value()>=v));
	}
	
	std::vector<int> succ(pos.getChildren(max));
	int i;
	if (max) {
		for (i = 0; i < succ.size(); ++i) { 
			if (testG_E(pos.move(max,succ[i]), depth-1, v, !max)) {
				return 1;
			}
		}
		return 0;
	
	}
	else {
		for (i = 0; i < succ.size(); ++i) { 
			if (!testG_E(pos.move(max,succ[i]), depth-1, v, !max)) {
				return 0;
			}
		}
	return 1;
	
	}

}


int scout(state_t pos, int depth, bool max) {
	
	std::vector<int> succ(pos.getChildren(max));
	int v;
	int i;
	
	if (pos.terminal()) {
		return (max ? pos.value() : -pos.value());
	}
	
	else {
		v = scout(pos.move(max,succ[0]), depth-1, !max);
	}
	for (i = 1; i < succ.size(); ++i) {
		if (max) {
				if (testG(pos.move(max,succ[i]), depth-1, v, !max)) {
					v = scout(pos.move(max,succ[i]), depth-1, !max); //re-search
				} 
		}
		else {
				if (!testG_E(pos.move(max,succ[i]), depth-1, v, !max)) {
					v = scout(pos.move(max,succ[i]), depth-1, !max); 
				}
		}
	}
	return v;
}
