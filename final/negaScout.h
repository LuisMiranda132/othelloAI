#include "othello_cut.h"
#include "utils.h"
#include <stdio.h>

int negaScout(state_t pos,bool color, int depth, int alpha, int beta){
	
	if((depth == 0) || (pos.terminal())) return (color ? pos.value() : -pos.value());

	int score = -MAXVALUE;
	std::vector<int> succ(pos.getChildren(color));

	int i;
	for(i=0; i<succ.size(); i++){
		state_t s = pos.move(color,succ[i]);
		
		if (i > 0) {
			score = -negaScout(s, !color, depth-1, -alpha-1, -alpha); //null window search
			if (alpha < score && score < beta) {
				score = -negaScout(s, !color, depth-1, -beta, -score); 
			}
		}
		else {
		    score = -negaScout(s, !color, depth-1, -beta, -alpha); //evaluacion de la rama izquierda
		}
		
		alpha = Utils::max(score,alpha);
		
		if(alpha >= beta) return alpha; //poda
	}
	
	return alpha;
}
