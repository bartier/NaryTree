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

    myNaryTree.insert(51);
    myNaryTree.insert(52);

    myNaryTree.insert(74);
    myNaryTree.insert(77);
    myNaryTree.insert(83);

    myNaryTree.insert(35);
    myNaryTree.insert(38);
    myNaryTree.insert(43);

    std::cout << myNaryTree << std::endl;
    // deletando...

    myNaryTree.remove(13); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(54); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(93); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(3); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(9); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(22); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(27); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(50); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(63); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(71); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(88); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(100); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(33); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(44); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(49); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(51); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(52); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(74); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(77); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(83); std::cout << myNaryTree << std::endl;

    myNaryTree.remove(35); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(38); std::cout << myNaryTree << std::endl;
    myNaryTree.remove(43); std::cout << myNaryTree << std::endl;

    std::cout << myNaryTree << std::endl;

    return 0;
}