#include "othello_cut.h"
#include "utils.h"

//MAX es OR y MIN es AND

template<class T> class minimax
{
public:
    int search(T state,int depth,bool max){

	int bestValue;
		
	if((depth == 0) || (state.terminal())){
	    
	    return state.value();
	}
	
	//True es Black, False es White
	std::vector<int> children(state.getChildren(max));
	if(max){
	    bestValue = -MAXVALUE;
	    for(int i=0;i<children.size();++i){
		T s = state.move(max,children[i]);
		int val = this->search(s,depth-1,false);
		bestValue = Utils::max(val,bestValue);
	    }
	}else{
	    bestValue = MAXVALUE;
	    for(int i=0;i<children.size();++i){
		T s = state.move(max,children[i]);
		int val = this->search(s,depth-1,true);
		bestValue = Utils::min(val,bestValue);
	    }
	}
	return bestValue;
    }
    int alphabeta(T state,int depth,int alpha,int beta,bool max){
	
	if((depth == 0) || (state.terminal())) return state.value();
	//True es Black, False es White
	std::vector<int> children(state.getChildren(max));
	if(max){

	    for(int i=0;i<children.size();++i){
		T s = state.move(max,children[i]);
		int val = this->alphabeta(s,depth-1, alpha, beta,false);
		alpha = Utils::max(alpha,val);
		if(beta <= alpha)
		    break;
	    }
	    return alpha;
	    
	}else{

	    for(int i=0;i<children.size();++i){
		T s = state.move(max,children[i]);
		int val = this->alphabeta(s,depth-1, alpha, beta,true);
		beta = Utils::min(beta,val);
		if(beta <= alpha)
		    break;
	    }
	    return beta;
	    
	}
    }
};

