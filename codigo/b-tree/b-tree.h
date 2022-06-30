
#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
#include <vector>
using namespace std;

// Nó da árvore B
// Ele vai armazenar um array com chaves, um array com filhos
// Vai salvar o valor de chaves que possui, e um verificador se é folha ou não
class BTreeNode {
    int *keys; // Array de inteiros com as chaves
    BTreeNode **C; // Array de ponteiros para nós filhos
    int n; // Número de chaves armazenadas
    int t; // Parâmetro que define o número máximo de chaves e filhos, no máximo 2t-1 chaves e 2t filhos
    bool leaf; // Verdadeiro se for um nó folha

 public:
    BTreeNode(int, bool);

    int findKey(int);

    void insertNonFull(int);

    void splitChild(int, BTreeNode*);

    void deletion(int);

    void removeFromLeaf(int);

    void removeFromNonLeaf(int);

    int getPredecessor(int);

    int getSuccessor(int);

    void fill(int);

    void borrowFromPrev(int);

    void borrowFromNext(int);

    void merge(int);

    friend class BTree;
};

class BTree {
  BTreeNode *root;
  int t;

 public:
    BTree(int t) {
        root = nullptr;
        this->t = t;
    }

    void insertion(int);

    void deletion(int);

    // Funções a serem implementadas

    // Função de encontrar a k menor chave na árvore  
    int k_smallest(int k);

    // Função de encontrar a maior chave na árvore
    int k_biggest(int k);

    // Funções de exibição da árvore, vocês devem utilizar comandos "cout" para exibir
    // As chaves de acordo as três ordens diferentes: inorder, preorder, postorder
    void inorder();

    void preorder();

    void postorder();

    // Função de encontra a menor chave k que seja maior do que um valor escolhido m
    int sucessor(int m);

    // Função de encontra a maior chave k que seja menor do que um valor escolhido m
    int precessor(int m);
    
    // Função que retorna a profundidade da árvore (número de níveis)
    int depth();
   
    // Função de pesquisar por todas as chaves dentro de um intervalo [x, y]
    vector<int> interval_search(int x, int y);

    // Função de encontrar as k chaves mais próximas de um valor m 
    vector<int> k_closest(int k, int m);

    //Função de encontrar as k chaves mais próximas de um intervalo (x, y)
    vector<int> k_closest_interval(int k, int x, int y);
};

#include "b-tree.hpp"

#endif
