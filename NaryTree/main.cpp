#include <iostream>
#include "NaryTree.h"

int main() {

    NaryTree<int> myNaryTree(3);

    myNaryTree.insert(1);
    myNaryTree.insert(2);
    myNaryTree.insert(3);
    myNaryTree.insert(4);
    myNaryTree.insert(5);
    myNaryTree.insert(6);
    myNaryTree.insert(7);
    myNaryTree.insert(8);
    myNaryTree.insert(9);
    myNaryTree.insert(10);

    return 0;
}