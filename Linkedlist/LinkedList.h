#include <initializer_list>
using printFunc = void(*)(int);


struct Node {
    int value;
    Node *next;
};

using modifyFunc = void(*)(Node*);

class MyLinkedList {
public:
    MyLinkedList();
    ~MyLinkedList();
    void insert(std::initializer_list<int> list);
    void insert(int value);
    bool remove(int value);
    void reverse();
    void forEach(printFunc print);
    void forEach(modifyFunc modify);

private:
    Node *_head, *_tail;
    int _size;
};