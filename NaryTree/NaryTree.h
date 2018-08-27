#ifndef NARYTREE_NARYTREE_H
#define NARYTREE_NARYTREE_H

#include <iostream>
#include "Node.h"

template<class T>
class NaryTree {
public:

    explicit NaryTree<T>(const int &order) : order(order) {
        this->root = nullptr;
    }

    int getOrder() const {
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

    //TODO: verificar se método insert está correto
    void insert(T const &t) {

        if (root == nullptr) {

            root = new Node<T>(order);

            root->setLeafState(true);
            root->setRootState(true);

            root->insertKey(t);

            return;
        }

        //Node<T> *ancestor = nullptr;
        Node<T> *tmp = root;
        //int index = 0;

        while (!tmp->isLeaf()) {
            //ancestor = tmp;
            tmp = tmp->next(t);
            //index = ancestor->indexOfChild(tmp); // indexOfChild retorna indíce do filho
        }

        tmp->insertKey(t);
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

    int order;

};


#endif //NARYTREE_NARYTREE_H
