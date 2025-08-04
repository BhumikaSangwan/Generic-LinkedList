#ifndef LinkedList_H
#define LinkedList_H

#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList {
    private: 
        Node<T>* head;
        Node<T>* tail;
        Node<T>* newNode(T data); 
        Node<T>* getNodeAddressAtIdx(int index);

    public: 
        LinkedList();
        ~LinkedList();

        void prepend(T data);
        void insert(T data, int index);
        void append(T data);
        void removeFromIndex(int index);
        void pop();
        void print();

};

#include "LinkedList.tpp"

#endif