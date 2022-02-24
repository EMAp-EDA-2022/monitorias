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

#include "queue.h"
#include <iostream>

/*
Função "constructor". Ela é opcional, porém é bastante útil.
Definimos uma função que será executada quando nós criarmos um novo objeto.
Ela não precisa ter o tipo que retorna pois nunca retorna nada.
No caso, o constructor irá criar um node com um valor já definido.
E o ponteiro para o próximo igual a nulo.
*/
template<class T>
Node<T>::Node(T x) {
    value = x;
    next = nullptr;
}

/*
Função "constructor" de um queue que inicializa sem nenhum valor.
O que ela faz é definir o node inicial, uma "raíz".
E o tamanho igual a 0.
*/
template<class T>
Queue<T>::Queue() {
    ptr_start = nullptr;
    ptr_end = nullptr;
}

/*
A função de inserção vai adicionar um novo elemento no
final da fila, sem mudar os demais. Vai atualizar 
o ponteiro que marca o último.
Antes:
   start                end 
   n1 -> n2 -> ... -> nk -> null
                           
Após:
  start                     end 
  n1 -> n2 -> ... -> nk -> new -> null
*/
template<class T>                  
void Queue<T>::Enqueue(T x) {
    Node<T>* ptr_new = new Node<T>(x);
    if (ptr_start == nullptr) {
        ptr_start = ptr_new;
        ptr_end = ptr_new;
    }else{
        ptr_end->next = ptr_new;
        ptr_end = ptr_new;
    }
}


// Vai retornar o primeiro valor da queue
// e remover o primeiro nó (que contém esse valor)
// Antes:
//   (start)             (end)
//     n1 -> n2 -> ... -> nk -> null
// Após:
//   (root)        (end)
//      n2 -> ... -> nk -> null
template<class T>
T Queue<T>::Dequeue() {
    if (ptr_start == nullptr) return T();

    T value = ptr_start->value;

    Node<T>* aux = ptr_start;
    ptr_start = ptr_start->next;
    if (ptr_start == nullptr) ptr_end = nullptr; 
    delete aux;

    return value;
}

template<class T>
void Queue<T>::Print() {
    Node<T>* ptr_cur = ptr_start;
    std::cout << "Fila: ";
    while (ptr_cur != nullptr) {
        std::cout << ptr_cur->value << ", ";
        ptr_cur = ptr_cur->next;
    }
    std::cout << std::endl;
}
