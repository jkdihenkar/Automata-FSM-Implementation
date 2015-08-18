#include<iostream>
#include<fstream>
using namespace std;

class state {

string identifier;
bool finalState;

public:
    state** transitions;
    int no_of_transitions;
    state();
  state(string iden);
  state(string iden,state** transitions);
  string name();
  void setTransitions(state** transitions);
  state** giveTransitions();
  state input(int k);
    bool isFinal();
    void setFinal(bool k);
    void dump();
}; 
