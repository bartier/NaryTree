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

    /**
     * Insere na árvore a informação (chave) passada como parâmetro.
     * @param t é a informação a ser inserida.
     */
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

        Node<T> *ancestor = nullptr;
        Node<T> *tmp = root;

        int indexOfChild;

        while (!tmp->holds(t)) {
            ancestor = tmp;
            tmp = tmp->next(t);

            if (tmp == nullptr) {
                // informação não existe, lançar excessão...
                throw -666; // temporário
            }
        }

        if (!tmp->hasChilds()) {
            tmp->removeKey(t);

            if (tmp->isEmpty()) {

                if (ancestor != nullptr) {
                    indexOfChild = ancestor->indexOfChild(tmp);
                    ancestor->insertChildAt(indexOfChild, NULL);
                } else {
                    this->root = nullptr;
                }
                delete tmp;
            }
        }

        // Caso em que o nó tem filhos
        // subir um substituto
        // se tiver na esquerda, subir o maior
        // se tiver na direita, subir o menor

        // caso não tenha substitutos...

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
