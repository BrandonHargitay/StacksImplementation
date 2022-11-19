//
// Created by Brandon Hargitay on 11/1/22.
//



#ifndef LINKEDLIST_LINKEDLIST_CPP
#define LINKEDLIST_LINKEDLIST_CPP

#include "LinkedList.h"
template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
void LinkedList<T>::push_back(T data) {
    Node<T> *newNode = new Node<T>(data);

    if(isEmpty()){
        addFirstNode(data);
        //this->head = newNode;
        //this->tail = newNode;
        //this->head->next = tail;

    }else{
        tail->next = newNode;
        this->tail = newNode;
        //this->tail->next = newNode;
        //this->tail = newNode;
        //this->size++;
        this->size++;
    }
}

template<class T>
void LinkedList<T>::addFirstNode(T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->next = nullptr;
    this->head = newNode;
    this->tail = newNode;
    this->size++;
}

template<class T>
void LinkedList<T>::push_front(T data) {
    Node<T> *newNode = new Node<T>(data);

    if(isEmpty()){
        addFirstNode(data);
    }else{
        newNode->next = head;
        head = newNode;
        this->size++;
    }
}
template<class T>
bool LinkedList<T>::isEmpty() {
    return head == nullptr;
}

template< class S >
std::ostream& operator <<(std::ostream& outs, const LinkedList<S> &list){
    const Node<S> *walker = list.head;

    while(walker->next != nullptr){
        outs<<walker->data << " --> ";
        walker = walker->next;
    }
    outs<<walker->data << "-->" << walker->next;
    outs << std::endl << "Size: "  << list.size;
    return outs;
}

template<class T>
void LinkedList<T>::pop_back() {
    if(isEmpty()) return;
    Node<T> *temp = head;

    if(temp->next == nullptr){
        delete temp;
        head = nullptr;
        tail = nullptr;
        this->size--;
        return;
    }
    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    tail = temp;
    delete temp->next;
    temp->next = nullptr;
    this->size--;
}

template<class T>
void LinkedList<T>::pop_front() {
    if(isEmpty()) return;
    Node<T> *temp = head;
    if(temp->next == nullptr){
        delete temp;
        head = nullptr;
        tail = nullptr;
        this->size--;
        return;
    }
    head = head->next;
    delete temp;
    this->size--;
}

template<class T>
Node<T> *LinkedList<T>::search(T key) {
    Node<T> *walker = head;
    while(walker != nullptr){
        if(walker->data == key){
            return walker;
        }
        walker = walker->next;
    }
    std::cout << "Element not found";
    return nullptr;
}

template<class T>
void LinkedList<T>::insertAfter(T thisData, T afterThisData) {
    Node<T> *temp = search(afterThisData);
    Node<T> *newNode = new Node<T>(thisData);

    if(temp->next == nullptr){
        tail->next = newNode;
        this->tail = newNode;
        this->size++;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    this->size++;
}

template<class T>
void LinkedList<T>::remove(T data) {
    Node<T> *prev = getPrev(data);
    Node<T> *curr = search(data);

    if(curr == head){
        pop_front();
        return;
    }
    if(curr == tail){
        pop_back();
        return;
    }

    prev->next = curr->next;
    delete curr;
    this->size--;
}

template<class T>
Node<T> *LinkedList<T>::getPrev(T data) {
    Node<T> *walker = head;
    Node<T> *prev = nullptr;
    //if(head->next == nullptr) return nullptr;
    while(walker->next != nullptr && walker->data != data)
    {
        prev = walker;
        walker = walker->next;
    }
    return prev;
}

template<class T>
void LinkedList<T>::insertBefore(T thisData, T beforeThisData) {
    //std::cout<<"RAN";
    Node<T> *prev = getPrev(beforeThisData);
    Node<T> *newNode = new Node<T>(thisData);

    if(prev == nullptr){
        newNode->next = head;
        head = newNode;
        this->size++;
        return;
    }
    newNode->next = prev->next;
    prev->next = newNode;
    this->size++;
}


//template<class T>
//void LinkedList<T>::printLinkedList(){
//    Node<T> *tempNode = this->head;
//
//    while(tempNode->next != nullptr){
//        std::cout<<tempNode->data << std::endl;
//        tempNode = tempNode->next;
//    }
//    std::cout<<tempNode->data << std::endl;
//}

#endif //LINKEDLIST_LINKEDLIST_CPP
