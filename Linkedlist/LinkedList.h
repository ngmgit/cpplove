
struct Node {
    int value;
    Node *next;
};

class MyLinkedList {
public:
    MyLinkedList();
    ~MyLinkedList();
    void insert(int value);
    bool remove(int value);

private:
    Node *_head, *_tail;
    int _size;
};