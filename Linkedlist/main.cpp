#include "LinkedList.h"
#include <initializer_list>
#include <iostream>

void print(int N) { std::cout << N << ' '; }

int main(int argc, char *argv[])
{
    MyLinkedList l;
    l.insert(10);
    l.insert(20);
    l.insert(30);

    l.remove(12);
    l.remove(20);

    //advanced
    l.insert({10, 20, 30});
    l.forEach(print);
}