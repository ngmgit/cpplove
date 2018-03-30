#include <iostream>
#include "LinkedList.h"

void MyLinkedList::insert(std::initializer_list<int> list)
{
    for (const auto val : list) {
        insert(val);
    }
}

void MyLinkedList::insert(const int value)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (_head == nullptr) {
        _head = newNode;
        _tail = _head;
    } else {
        _tail->next = newNode;
        _tail = newNode;
    }
    _size += 1;
}

bool MyLinkedList::remove(const int value)
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
                delete itr;
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