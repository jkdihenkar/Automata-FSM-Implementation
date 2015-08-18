#include<iostream>

#include<fstream>

#include"state.h"

#include"fsm.h"

using namespace std;
   
   state::state() {}

    state::state(string iden) {
    this->identifier=iden;
    transitions=NULL;
  }

  state::state(string iden,state** transitions) {
    this->identifier=iden;
    this->transitions=transitions;
  }

  string state::name() {
    return identifier;
  }

  void state::setTransitions(state** transitions) {
    this->transitions=transitions;
  }

  state** state::giveTransitions() {
    return transitions;
  }

  state state::input(int k) {
    return *transitions[k];
  }

  bool state::isFinal() {
    return finalState;
  }

  void state::setFinal(bool k) {
    finalState=k;
  }

  void state::dump() {
    cout << "Name of State : " << name() << "\n";
    cout << "The transitions of the states are : ";
    for(int i=0;i<no_of_transitions;i++) {
        cout << "\n\t(for " << i+1 << "th input): " << transitions[i]->name();
    }
    cout << "\nFinal state? : " << ((finalState)?("Yes"):("No"));
  }
 
