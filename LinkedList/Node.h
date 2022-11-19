//
// Created by Brandon Hargitay on 11/1/22.
//

#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

#include <iostream>

template <class T>
struct Node{
    T data;
    Node<T> *next = nullptr;

    Node(){
        this->next = nullptr;
    }
    Node(T d){
        this->data = d;
        this->next = nullptr;
    }
};





#endif //LINKEDLIST_NODE_H
