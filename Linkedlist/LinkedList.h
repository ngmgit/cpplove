#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <initializer_list>
using printFunc = void(*)(int);


struct Node {
    int value = 0;
    Node *next = nullptr;
};

using modifyFunc = void(*)(Node*);

class MyLinkedList {
public:
    MyLinkedList() = default;
    ~MyLinkedList() = default;
    void insert(std::initializer_list<int> list);
    void insert(const int value);
    bool remove(const int value);
    void reverse();
    void forEach(printFunc print);
    void forEach(modifyFunc modify);

private:
    Node *_head {nullptr};
    Node *_tail {nullptr};
    unsigned int _size {0};
};

#endif // MYLINKEDLIST_H