#include "NaryTree.h"

int main() {

    NaryTree<int> myNaryTree(4);

    myNaryTree.insert(13);
    myNaryTree.insert(54);
    myNaryTree.insert(93);
    myNaryTree.insert(3);
    myNaryTree.insert(9);
    myNaryTree.insert(22);
    myNaryTree.insert(27);
    myNaryTree.insert(50);
    myNaryTree.insert(63);
    myNaryTree.insert(71);
    myNaryTree.insert(88);
    myNaryTree.insert(100);
    myNaryTree.insert(33);
    myNaryTree.insert(44);
    myNaryTree.insert(49);
    myNaryTree.insert(35);
    myNaryTree.insert(38);
    myNaryTree.insert(43);
    myNaryTree.insert(51);
    myNaryTree.insert(52);
    myNaryTree.insert(74);
    myNaryTree.insert(77);
    myNaryTree.insert(83);

    myNaryTree.remove(100);

    std::cout << myNaryTree << std::endl;

    return 0;
}