#ifndef NARYTREE_NARYTREE_H
#define NARYTREE_NARYTREE_H

#include <iostream>
#include "Node.h"

/**
 * Representação de uma árvore de ordem n (árvore enária).
 * @see https://en.wikipedia.org/wiki/K-ary_tree
 * @tparam T
 */
template<class T>
class NaryTree {
public:
//TODO: tratar exceções (inserir elemento igual ou deletar inexistente...)
    /**
     * Construtor da arvore enária.
     * @param order ordem da árvore.
     */
    explicit NaryTree<T>(unsigned int const &order);

    /**
     * Retorna a ordem da árvore enária.
     * @return a ordem da árvore enária.
     */
    unsigned int getOrder() const;

    /**
     * Verifica se t está em algum local da árvore
     * @param t é a informação a ser buscada.
     * @return true se ela está inserida em algum nó.
     */
    bool contains(T const &t);

    /**
     * Insere na árvore a informação (chave) passada como parâmetro.
     * @param t é a informação a ser inserida.
     */
    void insert(T const &t);

    /**
     * Remove na árvore a informação (chave) passada como parâmetro.
     * @param t  é a informaçaõ a ser removida.
     */
    void remove(T const &t);

    /**
     * overload necessário para poder printar em std::cout
     */
    template<typename U>
    friend std::ostream &operator<<(std::ostream &os, const NaryTree<U> &n);

private:
    Node<T> *root;
    unsigned int order;

};

#include "NaryTree.cpp"

#endif //NARYTREE_NARYTREE_H
