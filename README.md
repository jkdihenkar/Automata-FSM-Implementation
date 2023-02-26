# Automata : FSM : in C++

This is a implmentation of a Finite Automata that accepts a machine defination. After accepting the machine defination the program interprets it and load the automata rules into the memory.

## 1. Input

The sample input file looks as :

```txt
2 0 1

5 A B C D E

1 D

B E
C E
C B
C E
E E
```

Here as shown above

1st line : #ipsymbols and The Input symbols of the automata

2nd line : #of states and States of automata

3rd line : #of final state and final states

Rest of Lines : Transition rules of the states.

## 2. Compiling and Running

The compile and run process assumes that you have `g++` compiler installed.

Sample compile is as :

```sh
g++ -c state.cpp
g++ -c fsm.cpp
g++ automata.cpp state.o fsm.o -o automata
```

So now you have a executable file `automata`, Run as :

```sh
./automata
```

## 3. Explanation of Files :

* `fsm.cpp` : All the Finite state machine function definations
* `automata.cpp` : The automata main code, based on the fsm library
* `fsm.h` : The header file for fsm library
* `state.cpp` : State class that resembles the states of fsm
* `state.h` : Header file for state library
