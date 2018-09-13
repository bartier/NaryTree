template<class T>
NaryTree<T>::NaryTree(unsigned int const &order) : order(order) {
    this->root = nullptr;
}

template<class T>
unsigned int NaryTree<T>::getOrder() const {
    return this->order;
}

template<class T>
bool NaryTree<T>::contains(const T &t) {
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

template<class T>
void NaryTree<T>::insert(const T &t) {
    //TODO: se a árvore já possuir uma chave igual, lançar exceção.

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

template<class T>
void NaryTree<T>::remove(const T &t) {
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
    //////////////////////////////////////
    //////////////////////////////////////
    //////////////////////////////////////
    //////////////////////////////////////
    // caso não tenha substitutos...
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const NaryTree<U> &n) {
    os << "============| N-ARY TREE INFO |===================\n";
    os << "Order: " << n.getOrder() << "\n";
    //TODO: mostrar elementos, usar percurso por nível
}