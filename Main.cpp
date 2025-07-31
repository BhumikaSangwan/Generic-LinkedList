#include <iostream>
#include "LinkedList.h"

int main()
{

    LinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);

    list.print();

    list.prepend(0);
    list.print();

    std::cout << "\nDone";
    return 0;
}
