#include <iostream>
#include "LinkedList.h"

int main()
{

    // LinkedList<int> list;
    // list.append(1);
    // list.append(2);
    // list.append(3);

    // list.print();

    // list.prepend(0);
    // list.print();

    LinkedList<std::string> list;
    list.append("Hello");
    list.append("World");
    list.print();
    list.prepend("Hi");
    list.insert("!", 2);
    list.insert("abc", 1);
    list.print();
    list.removeFromIndex(1);
    list.print();

    return 0;
}
