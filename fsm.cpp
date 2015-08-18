#include"state.h"
#include"fsm.h"
#include<iostream>
#include<fstream>

using namespace std;

fsm::fsm(char* filename) {
    init(filename);
    readSymbols();
    readStates();
    readTransitions();
    close();
}

void fsm::init(char* filename) {
    this->readFile.open(filename);
}

void fsm::readSymbols() {
    readFile >> no_of_ip_symbols;
     inputs = new char[no_of_ip_symbols];
     for(int n=0;n<no_of_ip_symbols;n++) {
        readFile >> inputs[n];
     }
}

void fsm::dump() {
    cout << "The Details of the fsm : " << "\n\n";
    cout << "The number of input symbols are : " << this->no_of_ip_symbols << "\n";
    cout << "The input symbols are : " << "{ ";
    for(int i=0;i<this->no_of_ip_symbols;i++) {
        cout << this->inputs[i] << " ";
    } cout << " }" << "\n";
    cout << "There are "<< this->no_of_states << " states in the automata...\n";
    cout << "The states are as : { ";
    for(int i=0;i<this->no_of_states;i++) {
        cout << states[i]->name() << " ";
    } cout << "}\n";
    cout << "Initial state : " << states[0]->name() << "\n";
    cout << "Final state(s) : { ";
    for(int i=0;i<no_of_states;i++) {
        if(states[i]->isFinal()) {
            cout << states[i]->name() << " ";
        }
    }cout << "}\n";
}

void fsm::close() {
    this->readFile.close();
}

void fsm::readStates() {
    string tmp;
    state* tstate;
    readFile >> this->no_of_states;
    this->states = new state*[no_of_states];
    for(int i=0;i<this->no_of_states;i++) {
            readFile >> tmp;
        states[i] = new state(tmp);
    }
    readFile >> no_of_fstates;
    for(int i=0;i<no_of_fstates;i++) {
        readFile >> tmp;
        tstate=lookup(tmp);
        if(tstate!=NULL) {
            tstate->setFinal(true);
        }
    }
    currentState=states[0];
}

state* fsm::lookup(string name) {
    for(int i=0;i<no_of_states;i++) {
        if(states[i]->name() == name) {
            return states[i];
        }
    }
    return NULL;
}

void fsm::dumpCurrentState() {
    cout << "The current state is : " << currentState->name();
}
    state* fsm::giveCurrentState() {
    return currentState;
}

void fsm::readTransitions() {
    string tmp;
    state* tstate;

    for(int i=0;i<no_of_states;i++) {
        states[i]->transitions = new state*[no_of_ip_symbols];
        states[i]->no_of_transitions = no_of_ip_symbols;
        for(int j=0;j<no_of_ip_symbols;j++) {
            readFile >> tmp;
            tstate=lookup(tmp);
            states[i]->transitions[j]=tstate;
        }
    }
}

void fsm::dumpAllStates() {
    for(int i=0;i<no_of_states;i++) {
        states[i]->dump();
        cout <<"\n";
    }
}

void fsm::makeTransition(char k) {
    int ip = getInputId(k);
    currentState = currentState->transitions[ip];
}


int fsm::getInputId(char k) {
    for(int i=0;i<no_of_ip_symbols;i++) {
        if(inputs[i]==k) {
            return i;
        }
    }
    return -1;
}

