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
O stack vai ser uma sequência de nodes ligados.
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

// Classe stack (pilha)
template<class T>
class Stack {
    Node<T>* ptr_root;
    int size;

 public:
        /*
    Função "constructor" de um stack que inicializa sem nenhum valor.
    O que ela faz é definir o node inicial, uma "raíz".
    E o tamanho igual a 0.
    */
    Stack() {
        ptr_root = new Node<T>;
        ptr_root->next = nullptr;
        size = 0;
    }

    int GetSize() {
        return size;
    }

    // A função de inserção vai adicionar um novo elemento no
    // topo do stack, em purrando todos os elementos para "trás"
    // Então o novo nó vai ter como próximo o "próximo do root"
    // E ele o novo nó vai ser o próximo do root
    // Antes:
    //     root -> n1 -> n2 -> ... -> null
    // Após:
    //     root -> new -> n1 -> n2 -> ... -> null
    void Insert(T value) {
        Node<T> *ptr_new = new Node<T>(value);
        ptr_new->next = ptr_root->next;
        ptr_root->next = ptr_new;
        size++;
    }

    // Vai retornar o valor salvo no topo do stack
    T Top() {
        if (ptr_root->next == nullptr) return T();
        return ptr_root->next->value;
    }

    // Vai retornar o valor salvo no topo do stack
    // e remover o primeiro nó (que contém esse valor)
    // Antes:
    //     root -> n1 -> n2 -> ... -> null
    // Após:
    //     root -> n2 -> ... -> null
    T Pop() {
        if (size == 0) return T();
        T val = ptr_root->next->value;
        Node<T>* aux = ptr_root->next;
        ptr_root->next = ptr_root->next->next;
        delete aux;  // Deletando a memória alocada dinamicamente
        size--;
        return val;
    }

    void Print() {
        Node<T>* ptr_node = ptr_root;
        cout << "Stack: {";
        while (ptr_node->next != nullptr) {
            cout << ptr_node->next->value << ", ";
            ptr_node = ptr_node->next;
            // Essa sintaxe é para acessar uma função do objeto
            // que está sendo apontado.
            // Seria a mesma coisa de (*ptr_node).next;
        }
        cout << "}\n";
    }
};

int main() {
    Stack<int> my_stack;
    for (int i = 0; i < 5; i++) {
        my_stack.Insert(i);
        my_stack.Print();
    }

    cout << "Topo stack: " << my_stack.Top() << endl;
    cout << "Pop stack: " << my_stack.Pop() << endl;
    my_stack.Print();
    cout << "Pop stack: " << my_stack.Pop() << endl;
    my_stack.Print();
    return 0;
}
