#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<string>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

template<class T>
class BinaryTree{
    struct Node{
        T data;
        Node* left;
        Node* right;


        Node();

        Node(T);
    };

    Node* ptr_root;

    void InsertRecursion(T, Node**);

    void PrintNode(string, Node*, bool);
    
 public:    
    BinaryTree();

    void Insert(T);

    void Print();
};

template<class T>
BinaryTree<T>::Node::Node() {
    this->left = nullptr;
    this->right = nullptr;
}

template<class T>
BinaryTree<T>::Node::Node(T data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

template<class T>
BinaryTree<T>::BinaryTree() {
    ptr_root = nullptr;
}

template<class T>
void BinaryTree<T>::Insert(T data) {
    // Se for o primeiro elemento, apenas adicione como root
    if (ptr_root == nullptr){
        ptr_root = new Node(data);
        return;
    }

    if (data < ptr_root->data){
        InsertRecursion(data, &(ptr_root->left));
    } else {
        InsertRecursion(data, &(ptr_root->right));
    }
}

template<class T>
void BinaryTree<T>::InsertRecursion(T data, Node** ptr_node) {
    // Se o nó não existir, cria ele
    if ((*ptr_node) == nullptr) {
        (*ptr_node) = new Node(data);
        return;
    }

    if (data < (*ptr_node)->data){
        InsertRecursion(data, &((*ptr_node)->left));
    } else {
        InsertRecursion(data, &((*ptr_node)->right));
    }
}

template<class T>
void BinaryTree<T>::Print() {
    PrintNode("", ptr_root, false);
};

template<class T>
void BinaryTree<T>::PrintNode(string prefix, Node* ptr_node, bool isLeft) {
    if(ptr_node != nullptr ) {
        cout << prefix;
        cout << (isLeft ? "├──" : "└──" );
        cout << ptr_node->data << endl;

        // enter the next tree level - left and right branch
        PrintNode( prefix + (isLeft ? "│   " : "    "), ptr_node->left, true);
        PrintNode( prefix + (isLeft ? "│   " : "    "), ptr_node->right, false);
    }
}



#endif //BINARY_TREE_H