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

    //TODO: remover leaf e usar apenas isFull (?)
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
    if (!this->contains(t)) {
        throw std::invalid_argument("T does not exist in NaryTree");
    }

    Node<T> *ancestor = nullptr;
    Node<T> *tmp = root;

    int indexOfChild;

    while (!tmp->holds(t)) {
        ancestor = tmp;
        tmp = tmp->next(t);
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
    } else {
        unsigned int targetIndex = tmp->indexOfInfo(t);

        if (tmp->existsChildAt(targetIndex)) {
            // o maior dos menores será o substituto
            Node<T> *smallInfoNode = tmp->childAt(targetIndex);

            T greaterNodeinformation(smallInfoNode->getBiggestInfo());
            this->remove(greaterNodeinformation);
            tmp->setInfo(targetIndex, greaterNodeinformation);
        }
        else if (tmp->existsChildAt(targetIndex + 1)) {
            // o menor dos maiores será o substituto
            Node<T> *bigInfoNode = tmp->childAt(targetIndex + 1);

            T smallestNodeinformation = bigInfoNode->getSmallestInfo();
            this->remove(smallestNodeinformation);
            tmp->setInfo(targetIndex, smallestNodeinformation);
        } else {
            // não há filhos na esquerda nem na direita, "sem substitutos"
            bool term
            for (int i=0; i < this->getOrder - 1; i++) {
                if (tmp->existsChildAt(i)) {
                    // começar da qui
                }
            }


        }
    }
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const NaryTree<U> &n) {
    os << "============| N-ARY TREE INFO |===================\n";
    os << "Order: " << n.getOrder() << "\n";
    //TODO: mostrar elementos, usar percurso por nível
}
