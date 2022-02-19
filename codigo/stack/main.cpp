#include<iostream>

using namespace std;

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
    Node(T x){
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
// 
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
        Stack(){
            pRoot = new Node<T>;
            pRoot->next = nullptr;
            size = 0;
        }

        int GetSize(){
            return size;
        }

        void Insert(T value){
            Node<T>* pNode = pRoot;
            while(pNode->next != nullptr){
                pNode = pNode->next; 
                // Essa sintaxe é para acessar uma função do objeto
                // que está sendo apontado. Seria a mesma coisa de (*pNode).next;
            }
            Node<T> *pNew = new Node<T>(value);
            pNode->next = pNew;
            size++;
        }

        void Print(){
            Node<T>* pNode = pRoot;
            cout << "Stack: {";
            while(pNode->next != nullptr){
                cout << pNode->next->value << ", ";
                pNode = pNode->next; 
                // Essa sintaxe é para acessar uma função do objeto
                // que está sendo apontado. Seria a mesma coisa de (*pNode).next;
            }
            cout << "}\n";
        }
};

int main(){
    Stack<int> fila;
    cout << "Tamanho fila: " << fila.GetSize() << endl;
    fila.Insert(1);
    cout << "Tamanho fila: " << fila.GetSize() << endl;
    fila.Insert(2);
    fila.Print();
    return 0;
}