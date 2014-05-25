#include "othello_cut.h"
#include "node.h"
#include "utils.h"
#include <iostream>

int negaMax(Node<state_t>& n, int depth){
  if(depth == 0 || n.terminal()) return n.value();
  int a = -MAXVALUE;
  std::vector<int> children(n.state.getChildren(n.type));
  for(int i=0;i<children.size();++i){
    state_t s;
    s = n.state.move(n.type,children[i]);
    Node<state_t> temp(&n,s,children[i]);
    a = Utils::max(a,-negaMax(temp,depth-1));
  }
  return a;
}
