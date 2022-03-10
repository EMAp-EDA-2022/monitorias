#include "binary-tree.h"

int main(){
    BinaryTree<int> tree;
    tree.Insert(27);
    tree.Insert(14);
    tree.Insert(35);
    tree.Print();
    tree.Insert(10);
    tree.Insert(19);
    tree.Print();
    tree.Insert(31);
    tree.Insert(42);
    tree.Print();
}