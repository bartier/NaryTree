#ifndef NARYTREE_NODE_H
#define NARYTREE_NODE_H


#include <vector>

/**
 * Representação de um nó de uma árvore enária (árvore de ordem n).
 * @tparam T é o tipo de informação que o nó guarda.
 */
template<class T>
class Node {
public:

    /**
     * Construtor do nó que recebe a ordem da árvore que ele pertence.
     * @param order ordem da árvore que o nó pertence.
     */
    explicit Node<T>(unsigned int const &order);

    /**
     * Retorna o "sub nó" que a chave t poderia estar
     * @param t é a chave que deseja ser "buscada" ou localizada possível nó de inserção
     * @return nó que a chave poderia estar
     */
    Node<T> *next(T const &t);

    /**
     * Retorna o índice ideal para a criação do filho
     * @param t
     * @return
     */
    unsigned int indexOfNext(T const &t);

    /**
     * Verifica se existe um filho no índice indicado.
     * @param i é o índice a ser consultado.
     * @return true se existe filho (ou seja, diferente de NULL).
     */
    bool existsChildAt(unsigned int const &i);

    /**
     * Verifica se o nó possui filhos (ou seja, no mínimo 1).
     * @return true se número de filhos > 0, caso contrário false.
     */
    bool hasChilds();

    /**
     * @param c é filho a ser utilizado para consultar seu índice no vetor.
     * @return o índice que o filho passado como parâmetro está no vetor de filhos.
     * @return -1 se o filho não existe
     */
    int indexOfChild(Node<T> *c);

    /**
     * Insere no vetor de informações (também chamado de chaves) a chave como parâmetro.
     * @param t é a informação a ser inserida.
     */
    void insertKey(T const &t);

    /**
     * Remove no vetor de informações (também chamado de chaves) a chave como parâmetro.
     * @param t é a informação a ser removida.
     */
    void removeKey(T const &t);

    /**
     * Insere o filho no índice passado como parâmetro.
     * @param index índice a ser utilizado para inserção.
     * @param ch filho utilizado na inserção.
     */
    void insertChildAt(int index, Node<T> *ch); //TODO: não inserir em filhos já inseridos (?)

    /**
     * Verifica se t (informação) existe no vetor de informações do nó.
     * @param t é a informação a ser buscada.
     * @return true se ele existe no vetor de informações
     * @return false se ela NÃO existe no vetor de informações
     */
    bool holds(T const &t);

    /**
     * @return true se é um nó folha.
     */
    bool isLeaf();

    /**
     * @return true se o nó está cheio.
     */
    bool isFull();

    /**
     * Verifica se o nó está vazio.
     * @return true se ele está vazio.
     */
    bool isEmpty();

    /**
     * @return ordem do nó e consequentemente ordem da árvore que ele está.
     */
    int getOrder();

    /**
     * Seta se o nó é uma raiz.
     * @param state
     */
    void setRootState(bool state);

    /**
     * Seta se o nó é uma folha.
     * @param state
     */
    void setLeafState(bool state);

    int indexOfInfo(T const &t);

    Node<T> *childAt(unsigned int index);

    void setInfo(unsigned int index, const T &info);

    T getBiggestInfo();
    T getSmallestInfo();
    T getInfoAt(unsigned int index);
    void offset(int direction, int start, int end);

private:
    std::vector<T> keys;
    std::vector<Node<T> *> children;

    int order;

    bool root;
    bool leaf;
    bool full;

};

#include "Node.inl"

#endif //NARYTREE_NODE_H
