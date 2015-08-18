#include<iostream>
#include<fstream>
using namespace std;

class fsm {

int no_of_ip_symbols;
char* inputs;
int no_of_states;
int no_of_fstates;
ifstream readFile;
state** states;
state* currentState;


public :
    fsm(char* filename);
    void init(char* filename);
    void readSymbols();
    void dump();
    void close();
    void readStates();
    state* lookup(string name);
    void dumpCurrentState();
    state* giveCurrentState();
    void readTransitions();
    void dumpAllStates();
    void makeTransition(char k);
    int getInputId(char k);
}; 
