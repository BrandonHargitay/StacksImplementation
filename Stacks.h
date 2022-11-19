//
// Created by Brandon Hargitay on 11/19/22.
//

#ifndef STACKSIMPLEMENTATION_STACKS_H
#define STACKSIMPLEMENTATION_STACKS_H
#include "LinkedList/LinkedList.h"


template <class T>
class Stacks : public LinkedList<T>{
public:
    Stacks();

    void push2(T data);
    T pop2();
    T top2();
    int size2();
    bool isEmpty2();
private:

};

#include "Stacks.cpp"


#endif //STACKSIMPLEMENTATION_STACKS_H
