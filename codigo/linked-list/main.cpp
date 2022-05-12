#include "linked-list.h"

int main(){
    LinkedList<int> mylist;
    mylist.Insert(2);
    mylist.Insert(1);
    mylist.Insert(3);
    mylist.Print();
    mylist.Delete(4);
    mylist.Print();
    mylist.Delete(1);
}