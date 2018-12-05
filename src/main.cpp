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
    myNaryTree.insert(43);
    myNaryTree.insert(44);

    myNaryTree.insert(51);
    myNaryTree.insert(52);

    myNaryTree.insert(35);
    myNaryTree.insert(38);

    // deletando...

    myNaryTree.remove(33);

//    myNaryTree.remove(13);
//    myNaryTree.remove(54);
//    myNaryTree.remove(93);
//
//    myNaryTree.remove(3);
//    myNaryTree.remove(9);
//
//    myNaryTree.remove(22);
//    myNaryTree.remove(27);
//    myNaryTree.remove(50);
//
//    myNaryTree.remove(63);
//    myNaryTree.remove(71);
//    myNaryTree.remove(88);
//
//    myNaryTree.remove(100);
//
//    myNaryTree.remove(33);
//    myNaryTree.remove(44);
//    myNaryTree.remove(49);
//
//    myNaryTree.remove(35);
//    myNaryTree.remove(38);
//    myNaryTree.remove(43);
//
//    myNaryTree.remove(51);
//    myNaryTree.remove(52);
//
//    myNaryTree.remove(74);
//    myNaryTree.remove(77);
//    myNaryTree.remove(83);

//    std::cout << myNaryTree << std::endl;

    return 0;
}