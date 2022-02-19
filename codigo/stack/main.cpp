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
    Node(T x) {
        value = x;
        next = nullptr;
    }

    /*
    Criando um segunco "constructor" para quando for criar um node vazio.
    */
    Node(){
        next = nullptr;
    }
};

// Classe stack (pilha)
template<class T>
class Stack {
        Node<T>* pRoot;
        int size;

    public:
         /*
        Função "constructor" de um stack que inicializa sem nenhum valor.
        O que ela faz é definir o node inicial, uma "raíz".
        E o tamanho igual a 0.
        */
        Stack() {
            pRoot = new Node<T>;
            pRoot->next = nullptr;
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
            Node<T> *pNew = new Node<T>(value);
            pNew->next = pRoot->next;
            pRoot->next = pNew;
            size++;
        }

        // Vai retornar o valor salvo no topo do stack
        T Top() {
            if (pRoot->next == nullptr) return T();
            return pRoot->next->value;
        }

        // Vai retornar o valor salvo no topo do stack
        // e remover o primeiro nó (que contém esse valor)
        // Antes:
        //     root -> n1 -> n2 -> ... -> null
        // Após:
        //     root -> n2 -> ... -> null
        T Pop() {
            if (size == 0) return T();
            T val = pRoot->next->value;
            Node<T>* aux = pRoot->next;
            pRoot->next = pRoot->next->next;
            delete aux;  // Deletando a memória alocada dinamicamente
            size--;
            return val;
        }

        void Print() {
            Node<T>* pNode = pRoot;
            cout << "Stack: {";
            while (pNode->next != nullptr) {
                cout << pNode->next->value << ", ";
                pNode = pNode->next;
                // Essa sintaxe é para acessar uma função do objeto
                // que está sendo apontado. 
                // Seria a mesma coisa de (*pNode).next;
            }
            cout << "}\n";
        }
};

int main() {
    Stack<int> fila;
    for (int i = 0; i < 5; i++) {
        fila.Insert(i);
        fila.Print();
    }

    cout << "Topo stack: " << fila.Top() << endl;
    cout << "Pop stack: " << fila.Pop() << endl;
    fila.Print();
    cout << "Pop stack: " << fila.Pop() << endl;
    fila.Print();
    return 0;
}
