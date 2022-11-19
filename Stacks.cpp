//
// Created by Brandon Hargitay on 11/19/22.
//
#ifndef STACKSIMPLEMENTATION_STACKS_CPP
#define STACKSIMPLEMENTATION_STACKS_CPP

#include "Stacks.h"

template<class T>
Stacks<T>::Stacks<T>::Stacks() : LinkedList<T>() {

}

template<class T>
bool Stacks<T>::Stacks<T>::isEmpty2() {
    return LinkedList<T>::isEmpty();
}

template<class T>
void Stacks<T>::Stacks<T>::push2(T data) {
    LinkedList<T>::push_back(data);
}

template<class T>
T Stacks<T>::Stacks<T>::pop2() {
    return LinkedList<T>::pop_front();
}

template<class T>
T Stacks<T>::Stacks<T>::top2() {
    return LinkedList<T>::pop_back();
}

template<class T>
int Stacks<T>::Stacks<T>::size2() {
    return 3;
}
#endif