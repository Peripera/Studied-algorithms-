#include <iostream>
#include "bynary.h"
using namespace std;


int main(){

Bynary tree;
  tree.root=tree.insert(tree.root,5);
  tree.root=tree.insert(tree.root,2);
  tree.root=tree.insert(tree.root,7);
  int valueToSearch=7;
  Node*result=tree.search(tree.root,valueToSearch);
  cout<<result->data;
  return 0;
}

