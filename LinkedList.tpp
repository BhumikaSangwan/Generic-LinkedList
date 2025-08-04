#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T> :: ~LinkedList() {
    Node<T>* node = head;
    while (node != nullptr)
    {
        Node<T>* next = node->next;
        delete node;
        node = next;
    }    
}

template <typename T>
Node<T>* LinkedList<T>::newNode(T data) {
    return new Node<T>(data);
}


template <typename T>
Node<T>* LinkedList<T>:: getNodeAddressAtIdx(int index)
{
    if (index == 0)
    {
        return head;
    }
    Node<T>* tempNode = head;
    for (int i = 0; i < index && tempNode != nullptr; i++)
    {
        tempNode = tempNode->next;
    }
    return tempNode;
}

template <typename T>
void LinkedList<T>:: prepend(T data)
{
    Node<T>* node = newNode(data);
    node->next = head;
    head = node;
}

template <typename T>
void LinkedList<T> :: insert(T data, int index)
{
    if (index == 0)
    {
        prepend(data);
        return;
    }
    Node<T>* node = newNode(data);
    Node<T>* prevNode = getNodeAddressAtIdx(index - 1);
    node->next = prevNode->next;
    prevNode->next = node;
}

template <typename T>
void LinkedList<T> :: append(T data)
{
    Node<T>* node = newNode(data);
    if (head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = tail->next;
    }
}

template <typename T>

void LinkedList<T> :: removeFromIndex(int index)
{
    Node<T>* tempNode = nullptr;
    if (index == 0)
    {
        tempNode = head;
        head = head->next;
    }
    else
    {
        Node<T>* prevNode = getNodeAddressAtIdx(index - 1);
        tempNode = prevNode->next;
        prevNode->next = prevNode->next->next;
    }
    delete tempNode;
}

template <typename T>
void LinkedList<T>::pop()
{
    if (!head) return;

    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Node<T>* node = head;
    while (node->next != tail) {
        node = node->next;
    }

    delete tail;
    tail = node;
    tail->next = nullptr;
}


template <typename T>
void LinkedList<T>::print()
{
    Node<T>* node = head;
    while (node != nullptr)
    {
        std::cout << node->data << " -> ";
        node = node->next;
    }
}