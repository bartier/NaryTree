#ifndef NARYTREE_NODE_H
#define NARYTREE_NODE_H


#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

template<class T>
class Node {
public:

    explicit Node<T>(unsigned int const &order) : order(order) {

        this->keys.reserve(order - 1);
        this->children.resize(order);

        leaf = false;
        root = false;
        full = false;
    }

    /**
     * Retorna o "sub nó" que a chave t poderia estar
     * @param t é a chave que deseja ser "buscada" ou localizada possível nó de inserção
     * @return nó que a chave poderia estar
     */
    Node<T> *next(T const &t) {

        if (t < keys[0])
            return children[0];

        for (int i = 1; i <= keys.size(); i++) {
            if (t < keys[i] && t > keys[i - 1]) {
                return children[i];
            }
        }

        return children[children.size() - 1];
    }

    /**
     * Retorna o índice ideal para a criação do filho
     * @param t
     * @return
     */
    unsigned int indexOfNext(T const &t) {
        if (t < keys[0])
            return 0;

        for (int i = 1; i <= keys.size(); i++) {
            if (t < keys[i] && t > keys[i - 1]) {
                return i;
            }
        }

        return children.size() - 1;
    }

    bool existsChildAt(unsigned int const &i) {
        return children.at(i);
    }

    /**
     * @param c
     * @return o índice que o filho está no vetor de filhos
     * @return -1 se o filho não existe
     */
//    int indexOfChild(Node<T> *c) {
//        for (int i = 0; i < children.size(); ++i) {
//            if (children.at(i) == c) {
//                return i;
//            }
//        }
//        return -1; // o filho não existe no vetor de filhos
//    }

    /**
     * Insere no vetor de informações a chave como parâmetro.
     * @param t
     */
    void insertKey(T const &t) {
        this->keys.push_back(t);
        std::sort(keys.begin(), keys.end());

        if (keys.size() == order - 1) {
            this->full = true;
        }
    }

    //TODO: não inserir em filhos já inseridos (?)
    void insertChildAt(int index, Node<T> *ch) {
        // não insere filhos já inseridos
//        if (std::find(children.begin(), children.end(), ch) != children.end()) {
//            return;
//        }
        this->children.at(index) = ch;
    }
//
//    Node<T> *childAt(int const &i) {
//        return this->children.at(i);
//    }

    /**
     * Verifica se t (informação) existe no vetor de informações do nó.
     * @param t é a informação a ser buscada.
     * @return true se ele existe no vetor de informações
     * @return false se ela NÃO existe no vetor de informações
     */
    bool holds(T const &t) {
        if (std::find(keys.begin(), keys.end(), t) != keys.end()) {
            return true;
        }
        return false;
    }

    /**
     * Retorna a informação (chave) do índice i passado como parâmetro
     * @param i
     * @return a informação contida no índice i do vetor de informações
     */
//    T at(int const &i) {
//        return this->keys.at(i);
//    }

//    void removeKeyAt(int const &i) {
//        this->keys.erase(keys.begin() + i);
//    }

//    void removeChildAt(int const &i) {
//        this->children.erase(children.begin() + i);
//    }

    /**
     * @return true se é um nó folha.
     */
    bool isLeaf() {
        return this->leaf;
    }

    /**
     * @return true se o nó está cheio.
     */
    bool isFull() {
        return this->full;
    }

    /**
     * @return ordem do nó e consequentemente ordem da árvore que ele está.
     */
    int getOrder() {
        return this->order;
    }

//    int getSizeOfKeys() {
//        return this->keys.size();
//    }

//    int getSizeOfChildren() {
//        return this->children.size();
//    }

    /**
     * @return endereço do pai (que aponta) em this
     */
//    Node<T> *getAncestor() {
//        return ancestor;
//    }

    /**
     * Seta se o nó é uma raiz.
     * @param state
     */
    void setRootState(bool state) {
        this->root = state;
    }

    /**
     * Seta se o nó é uma folha.
     * @param state
     */
    void setLeafState(bool state) {
        this->leaf = state;
    }

    /**
     * Pai (que aponta) o nó atual.
     * @param a
     */
//    void setAncestor(Node<T> *a) {
//        ancestor = a;
//    }

private:
    std::vector<T> keys;
    std::vector<Node<T> *> children;

    //Node<T> *ancestor;

    int order;

    bool root;
    bool leaf;
    bool full;

};

#endif //NARYTREE_NODE_H
