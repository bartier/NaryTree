#include <algorithm>
#include <cmath>

template<class T>
Node<T>::Node(unsigned int const &order) {
    this->keys.reserve(order - 1);
    this->children.resize(order);

    leaf = false;
    root = false;
    full = false;

    this->order = order;
}

template<class T>
Node<T> *Node<T>::next(const T &t) {
    if (t < keys[0])
        return children[0];

    for (int i = 1; i <= keys.size(); i++) {
        if (t < keys[i] && t > keys[i - 1]) {
            return children[i];
        }
    }

    return children[children.size() - 1];
}

template<class T>
unsigned int Node<T>::indexOfNext(const T &t) {
    if (t < keys[0])
        return 0;

    for (unsigned int i = 1; i <= keys.size(); i++) {
        if (t < keys[i] && t > keys[i - 1]) {
            return i;
        }
    }

    return (unsigned int) children.size() - 1;
}

template<class T>
bool Node<T>::existsChildAt(unsigned int const &i) {
    return children.at(i);
}

template<class T>
bool Node<T>::hasChilds() {
    for (int i = 0; i < children.size(); ++i) {
        if (children[i] != NULL) {
            return true;
        }
    }
    return false;
}

template<class T>
int Node<T>::indexOfChild(Node<T> *c) {
    for (int i = 0; i < children.size(); ++i) {
        if (children.at(i) == c) {
            return i;
        }
    }
    return -1; // o filho não existe no vetor de filhos
}

template<class T>
void Node<T>::insertKey(const T &t) {
    this->keys.push_back(t);
    std::sort(keys.begin(), keys.end());

    if (keys.size() == order - 1) {
        this->full = true;
    }
}

template<class T>
void Node<T>::removeKey(const T &t) {
    auto position = std::find(keys.begin(), keys.end(), t);
    if (position != keys.end()) { // keys.end() means the element was not found
        keys.erase(position);
    }
}

template<class T>
void Node<T>::insertChildAt(int index, Node<T> *ch) {
    // não insere filhos já inseridos
    //        if (std::find(children.begin(), children.end(), ch) != children.end()) {
    //            return;
    //        }
    this->children.at(index) = ch;
}

template<class T>
bool Node<T>::holds(const T &t) {
    if (std::find(keys.begin(), keys.end(), t) != keys.end()) {
        return true;
    }
    return false;
}

template<class T>
bool Node<T>::isLeaf() {
    return this->leaf;
}

template<class T>
bool Node<T>::isFull() {
    return this->full;
}

template<class T>
bool Node<T>::isEmpty() {
    return this->keys.size() == 0;
}

template<class T>
int Node<T>::getOrder() {
    return this->order;
}

template<class T>
void Node<T>::setRootState(bool state) {
    this->root = state;
}

template<class T>
void Node<T>::setLeafState(bool state) {
    this->leaf = state;
}

template<class T>
int Node<T>::indexOfInfo(const T &t) {
    for (unsigned int i = 0; i < keys.size(); i++) { // <=
        if (keys[i] == t)
            return i;
        }
}

template<class T>
Node<T> *Node<T>::childAt(unsigned int index) {
    return children[index];
}

template<class T>
void Node<T>::setInfo(unsigned int index, const T &info) {
    this->keys[index] = info;
}

template<class T>
T Node<T>::getBiggestInfo() {
    if (this->children[this->children.size() - 1] != nullptr) {
        Node<T> *x = this->children[this->children.size() - 1];
        return x->getBiggestInfo();

    }
    return this->keys[keys.size() - 1];
}

template<class T>
T Node<T>::getSmallestInfo() {
    if (this->children[0] != nullptr) {
        Node<T> *x = this->children[0];
        return x->getSmallestInfo();
    }
    return this->keys[0];
}

template<class T>
T Node<T>::getInfoAt(unsigned int index) {
    return this->keys[index];
}

template<class T>
void Node<T>::offset(int direction, int start, int end) {
    if (direction > 0) {
        for (int i = end; i >= start ; --i) {
            this->keys[i] = this->keys[i - 1];
        }
    } else {
        for (int i = end; i <= start ; ++i) {
            this->keys[i] = this->keys[i + 1];
        }
    }

}

template<typename U>
std::ostream &operator<<(std::ostream &os, const Node<U> &n) {
    for (int i = 0; i < n.keys.size(); ++i) {
        os << n.keys[i] << (i + 1 == n.keys.size() ? "" : "-");
    }
    return os;
}


