#include <vector>

using std::vector;

template<class T>
class SkipList{
    struct Node{
        T key;
        int max_level;
        vector<Node*> next; // pointer to array of nodes
        Node(int);
        Node(int, T);
    };

    Node* head;

 public:

    int max_level;    

    SkipList(int);

    bool Find(T);

    void Insert(T);

};

template<class T>
SkipList<T>::Node::Node(int max_level) {
    this->max_level = max_level;
    for (int i = 0; i < max_level; i++) {
        next.push_back(nullptr);
    }
}

template<class T>
SkipList<T>::Node::Node(int max_level, T key) {
    this->max_level = max_level;
    this->key = key;
}

template<class T>
SkipList<T>::SkipList(int max_level) {
    this->max_level = max_level;
    head = new Node(max_level);
}

template<class T>
bool SkipList<T>::Find(T x) {
    Node* current = head;

    for (int i = max_level; i > 0; i--) {
        // for each level, goes to the right while not null or bigger
        while ((current->next[i]) && (current->key < x)) {
            current = current->next[i];
        }
    }

    current = current->next[0];
    if (!current) {
        return false;
    } else {
        return true;
    }
}

template<class T>
void SkipList<T>::Insert(T x) {

}
