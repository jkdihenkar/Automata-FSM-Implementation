#include<iostream>

#include<fstream>

#include"state.h"

#include"fsm.h"

using namespace std;


int main()
{
     fsm* machine;
     machine = new fsm("input");
     char k[99];
     cout << "Your automata is read successfully! :)";
     cout << "\nNow enter your input string : ";
     cin >> k;
     for(int i=0;k[i]!='\0';i++) {
        machine->makeTransition(k[i]);
     }
     if(machine->giveCurrentState()->isFinal()==true) {
        cout << "The machine is in the acceptance state!";
     }
        cout <<"\nThe Halting state is : " << machine->giveCurrentState()->name();
     return 0;

}
