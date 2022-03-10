#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>
#include<stdexcept>

using std::cout;
using std::endl;

template<class T>
class LinkedList{
    struct Node{
        T data;
        Node *next;

        Node(); 

        Node(T);
    };

    Node* ptr_root;

 public:
    LinkedList();

    void Insert(T);

    void Delete(T);

    void Print();

};

template<class T>
LinkedList<T>::Node::Node(){
    this->next = nullptr;
}

template<class T>
LinkedList<T>::Node::Node(T data){
    this->data = data;
    this->next = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(){
    this->ptr_root = new Node();
    
}

template<class T>
void LinkedList<T>::Insert(T data){
    Node* ptr_cur = ptr_root;
    // Primeiro encontrar a posição que o nó que vai ser adicionado
    while ((ptr_cur->next != nullptr) && (ptr_cur->next->data < data)) {
        ptr_cur = ptr_cur->next;
    }

    Node* ptr_new = new Node(data);
    ptr_new->next = ptr_cur->next;
    ptr_cur->next = ptr_new;
}

template<class T>
void LinkedList<T>::Delete(T data){
    Node* ptr_cur = ptr_root;
    // Primeiro encontrar a posição que do nó anterior ao que vai ser removido
    while ((ptr_cur->next != nullptr) && (ptr_cur->next->data < data)) {
        ptr_cur = ptr_cur->next;
    }

    // Se for o último joga um erro ou se o dado for diferente
    if ((ptr_cur->next == nullptr) || (ptr_cur->next->data != data)) {
        throw std::runtime_error("Value to remove not in list.");
    }

    Node* aux = ptr_cur->next;
    ptr_cur->next = ptr_cur->next->next;
    delete aux;
}

template<class T>
void LinkedList<T>::Print(){
    Node* ptr_cur = ptr_root;
    cout << "[";
    while (ptr_cur->next != nullptr) {
        cout << ptr_cur->next->data << " ";
        ptr_cur = ptr_cur->next;
    }
    cout << "]" << endl;
}





#endif //LINKED_LIST_H