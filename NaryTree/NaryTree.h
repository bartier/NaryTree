#ifndef NARYTREE_NARYTREE_H
#define NARYTREE_NARYTREE_H

#include <iostream>
#include "Node.h"

template<class T>
class NaryTree {
public:

    explicit NaryTree<T>(unsigned int const &order) : order(order) {
        this->root = nullptr;
    }

    unsigned int getOrder() const {
        return this->order;
    }

    /**
     * Verifica se t está em algum local da árvore
     * @param t é a informação a ser buscada.
     * @return true se ela está inserida em algum nó.
     */
    bool contains(T const &t) {
        if (root->holds(t)) {
            return true;
        } else {

            if (root->isLeaf()) {
                return false;
            }

            Node<T> *tmp = root->next(t);

            while (!tmp->isLeaf()) {
                if (tmp->holds(t)) {
                    return true;
                }
                tmp = tmp->next(t);
            }

            return tmp->holds(t);
        }
    }

    void insert(T const &t) {

        //TODO: se a árvore já possuir uma chave igual, lançar exceção.
//        if (this->contains(t)) {
//            /// ...
//            /// ...
//            /// ...
//        }

        if (root == nullptr) {

            root = new Node<T>(order);

            root->setLeafState(true);
            root->setRootState(true);

            root->insertKey(t);

            return;
        }

        Node<T> *tmp = root;

        while (!tmp->isLeaf()) {
            unsigned int indexTmp = tmp->indexOfNext(t);

            // garante que percorre a árvore por subárvores
            if (!tmp->existsChildAt(indexTmp)) {
                Node<T> *child = new Node<T>(order);
                child->setLeafState(true); // verififcar
                tmp->insertChildAt(indexTmp, child);
            }
            tmp = tmp->next(t);
        }

        if (!tmp->isFull()) {
            tmp->insertKey(t);
        } else {
            Node<T> *childOfLeafNode = new Node<T>(order);
            childOfLeafNode->setLeafState(true);
            childOfLeafNode->insertKey(t);

            int indexToInsertNewChildNode = tmp->indexOfNext(t);

            tmp->insertChildAt(indexToInsertNewChildNode, childOfLeafNode);

            tmp->setLeafState(false);
        }
    }

    void remove(T const &t) {
        //TODO: método de remover um elemento da árvore é igualmente complicado ao de inserir
    }

    /**
     * overload necessário para poder printar em std::cout
     */
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const NaryTree<U> &n) {
        os << "============| N-ARY TREE INFO |===================\n";
        os << "Order: " << n.getOrder() << "\n";
        //TODO: mostrar elementos (ideal seria por nível (?), mas pode ser notação parental...ver possibilidades)
    }

private:
    Node<T> *root;

    unsigned int order;

};


#endif //NARYTREE_NARYTREE_H
