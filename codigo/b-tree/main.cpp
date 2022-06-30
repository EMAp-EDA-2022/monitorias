#include "b-tree.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
  BTree t(3);
  t.insertion(8);
  t.insertion(9);
  t.insertion(10);
  t.insertion(11);
  t.insertion(15);
  t.insertion(16);
  t.insertion(17);
  t.insertion(18);
  t.insertion(20);
  t.insertion(23);

  cout << "\nThe inorder B-tree is: ";
  t.inorder();
  cout << "\nThe preorder B-tree is: ";
  t.preorder();
  cout << "\nThe postorder B-tree is: ";
  t.postorder();

  t.deletion(20);

  cout << "\nThe inorder B-tree is: ";
  t.inorder();
  cout << "\nThe preorder B-tree is: ";
  t.preorder();
  cout << "\nThe postorder B-tree is: ";
  t.postorder();

  cout << "\nThe depth of the tree is:" << t.depth();

  cout << "\n1-smallest element: " << t.k_smallest(1);

  cout << "\n4-smallest element: " << t.k_smallest(4); 

  cout << "\n3-biggest element: " << t.k_biggest(3); 

  int search = 19;
  cout << "\nSucessor of " << search << " : " << t.sucessor(search);
  
  search = 12;
  cout << "\nPrecessor of " << search << " : " << t.precessor(search);
  
  vector<int> response;
  response = t.interval_search(11, 22);
  cout << "\nSearch inside interval (11, 22): ";
  for(int i = 0; i < response.size(); i++) cout << response[i] << " ";

  response = t.k_closest(5, 14);
  cout << "\nSearch for 5 closest of 14: ";
  for(int i = 0; i < response.size(); i++) cout << response[i] << " ";

  response = t.k_closest_interval(4, 10, 17);
  cout << "\nSearch for 4 closest of interval (10, 17): ";
  for(int i = 0; i < response.size(); i++) cout << response[i] << " ";

}
