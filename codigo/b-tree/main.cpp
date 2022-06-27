#include "b-tree.h"
#include <iostream>

using std::cout;
using std::endl;

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
  t.deletion(20);
  t.deletion(8);
  t.deletion(16);
  t.deletion(11);
}