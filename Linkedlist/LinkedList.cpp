#include <iostream>
#include "LinkedList.h"

MyLinkedList::MyLinkedList() :
    _head(nullptr),
    _tail(nullptr),
    _size(0)
{
}

MyLinkedList::~MyLinkedList()
{
}

void MyLinkedList::insert(std::initializer_list<int> list)
{
    for (auto listIterator = list.begin(); listIterator != list.end(); listIterator++) {
        insert(*listIterator);
    }
}

void MyLinkedList::insert(int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (_head == nullptr) {
        _head = newNode;
        _head->value = value;
        _head->next = nullptr;
        _tail = _head;
        _size += 1;
    } else {
        _tail->next = newNode;
        _tail = newNode;
        _size += 1;
    }
}



bool MyLinkedList::remove(int value)
{

    if (_head == nullptr) {
        return false;
    }

    Node *itr = _head;
    Node *prev = nullptr;

    while(itr->next != nullptr) {
        if (itr->value == value) {
            if (itr == _head) {
            _head = _head->next;
            itr = nullptr;
            } else {
                prev->next = itr->next;
                if (itr == _tail) {
                    _tail = prev;
                }
                itr = nullptr;
            }
            _size -= 1;
            break;
        }
        prev = itr;
        itr = itr->next;
    }

    if (itr == nullptr) {
        return true;
    } else {
        return false;
    }
}

void MyLinkedList::reverse()
{
    Node *temp = _head;
    _head = _tail;
    _tail = temp;

    Node *prev = _tail;
    Node *itr = prev->next;

    while (itr) {
        temp = itr->next;
        itr->next = prev;
        prev = itr;
        itr = temp;
    }

    _tail->next = nullptr;
}

void MyLinkedList::forEach(printFunc print)
{
    Node *itr = _head;
    while (itr) {
        print(itr->value);
        itr = itr->next;
    }
}

void MyLinkedList::forEach(modifyFunc modify)
{
    Node *itr = _head;
    while (itr) {
        modify(itr);
        itr = itr->next;
    }
}