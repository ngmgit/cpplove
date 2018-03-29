#include "LinkedList.h"
#include <initializer_list>
#include <iostream>

void print(int N) { std::cout << N << ' '; }
void multiplyBy10(Node *node) { node->value = node->value * 10;}

int main(int argc, char *argv[])
{
    MyLinkedList l;
    l.insert(10);
    l.insert(20);
    l.insert(30);

    l.remove(12);
    l.remove(20);

    //advanced
    l.insert({10, 20});
    l.forEach(print);
    l.forEach(multiplyBy10);
    l.forEach(print);
    l.reverse();
    l.forEach(print);
}