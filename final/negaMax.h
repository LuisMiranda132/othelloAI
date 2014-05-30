#include "othello_cut.h"
#include "utils.h"
#include <iostream>

int negamax(state_t n, int depth, bool color){
  if(depth == 0 || n.terminal()) return (color ? n.value() : -n.value());
  int bestValue = -MAXVALUE;
  std::vector<int> children(n.getChildren(color));
  for(int i=0; i<children.size();++i){
    int val = -negamax(n.move(color,children[i]),depth-1,!color);
    bestValue = Utils::max(bestValue,val);
  }
  return bestValue;
}

int negamax_ab(state_t n, int depth, int a, int b, bool color){
  if(depth == 0 || n.terminal()) return (color ? n.value() : -n.value());
  int bestValue = -MAXVALUE;
  std::vector<int> children(n.getChildren(color));
  for(int i=0;i<children.size();++i){
    int val = -negamax_ab(n.move(color,children[i]),depth-1,-b,-a,!color);
    bestValue = Utils::max(bestValue,val);
    a = Utils::max(a,val);
    if(a >= b) break;
  }
  return bestValue;
}
