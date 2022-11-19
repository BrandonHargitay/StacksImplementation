//
// Created by Brandon Hargitay on 11/1/22.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "Node.h"
#include <iostream>

template <class T>
class LinkedList{
public:
    LinkedList();
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void insertAfter(T thisData, T afterThisData);
    void insertBefore(T thisData, T beforeThisData);
    void remove(T data);
    //void printLinkedList();
    template <class S>
    friend std::ostream& operator <<(std::ostream& outs, const LinkedList<S> &list);
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
    Node<T> *getPrev(T data);
    Node<T> *search(T data);
    void addFirstNode(T data);
    bool isEmpty();
};

#include "LinkedList.cpp"


#endif //LINKEDLIST_LINKEDLIST_H
