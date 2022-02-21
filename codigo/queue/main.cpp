// Copyright (c) 2022 Giovani Valdrighi

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.

#include<iostream>

using std::cout;
using std::endl;

/*
Struct que vai representar um node. 
A queue vai ser uma sequência de nodes ligados.
O node vai armazenar um valor do tipo T e um ponteiro para o próximo node.
*/
template<class T>
struct Node {
    T value;
    Node* next;

    /*
    Função "constructor". Ela é opcional, porém é bastante útil.
    Definimos uma função que será executada quando nós criarmos um novo objeto.
    Ela não precisa ter o tipo que retorna.
    No caso, o constructor irá criar um node com um valor já definido.
    E o ponteiro para o próximo igual a nulo.
    */
    explicit Node(T x) {
        value = x;
        next = nullptr;
    }

    /*
    Criando um segunco "constructor" para quando for criar um node vazio.
    Comando "explicit" impede que o compilador faça 
    conversões de tipo "implicitas" (infere que é necessário a conversão).
    */
    Node(){
        next = nullptr;
    }
};

// Classe queue (fila)
template<class T>
class Queue {
    Node<T>* ptr_root;
    Node<T>* ptr_end;
    int size;

 public:
        /*
    Função "constructor" de um queue que inicializa sem nenhum valor.
    O que ela faz é definir o node inicial, uma "raíz".
    E o tamanho igual a 0.
    */
    Queue() {
        ptr_root = nullptr;
        ptr_end = nullptr;
        size = 0;
    }

    int GetSize() {
        return size;
    }

    // A função de inserção vai adicionar um novo elemento no
    // final da fila, sem mudar os demais. Vai atualizar 
    // o ponteiro que marca o último.
    // Antes:
    //                             end v
    //     root -> n1 -> n2 -> ... -> nk -> null
    //                           
    // Após:
    //                                           end v
    //     root -> new -> n1 -> n2 -> ... -> nk -> new -> null
    //                                         
    void Insert(T value) {
        Node<T> *ptr_new = new Node<T>(value);
        size++;
        if (ptr_root == nullptr) {
            ptr_root = ptr_new;
            ptr_end = ptr_new;
        } 
        ptr_end->next = ptr_new;
        ptr_end = ptr_new;
    }

    // Vai retornar o primeiro valor da queue
    // e remover o primeiro nó (que contém esse valor)
    // Antes:
    //   (root)             (end)
    //     n1 -> n2 -> ... -> nk -> null
    // Após:
    //   (root)        (end)
    //      n2 -> ... -> nk -> null
    T PopFront() {
        if (size == 0) return T();
        T val = ptr_root->value;
        Node<T>* aux = ptr_root;
        ptr_root = ptr_root->next;
        if (ptr_root == nullptr) ptr_end = nullptr;
        size--;
        delete aux;  // Deletando a memória alocada dinamicamente
        return val;
    }

    // Vai retornar o primeiro valor adicionado na queue
    T First() {
        if (size == 0) return T();
        return ptr_root->value;
    }

    // Vai retornar o último valor adiciona na queue
    T Last() {
        if (size == 0) return T();
        return ptr_end->value;
    }

    void Print() {
        Node<T>* ptr_node = ptr_root;
        cout << "Stack: {";
        while (ptr_node != nullptr) {
            cout << ptr_node->value << ", ";
            ptr_node = ptr_node->next;
        }
        cout << "}\n";
    }
};

int main() {
    Queue<int> my_queue;
    for (int i = 0; i < 5; i++){
        my_queue.Insert(i);
    }
    my_queue.Print();

    for (int i = 0; i < 3; i++){
        my_queue.PopFront();
    }
    my_queue.Print();
    return 0;
}
