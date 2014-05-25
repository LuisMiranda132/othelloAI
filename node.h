template<class T> class Node{

  public:
    T state;
    //And == true, Or == false
    bool type;
    Node* parent;
    int action;

    Node(T& s, bool t) : state(s), type(t), parent(), action(36){}
    Node(Node* n, T& s, int a) : state(s), type(!(n->type)), parent(n), action(a){}
    

    int value(){ return state.value(); }
    bool terminal() { return state.terminal(); }

};
