#include <iostream>
#include "bynary.h"
using namespace std;

Node::Node(int value){
  data=value;
  left= nullptr;
  right=nullptr;
}

Bynary::Bynary(){
  root=nullptr;
}


Node*Bynary::insert(Node *node,int value){
  if (node==nullptr){
    return new Node(value);
  }
  if (value<node->data){
    node->left=insert(node->left,value);
  }else{
      node->right=insert(node->right,value);
  }
  return node;
}

Node *Bynary::search(Node *node, int value){
  if (node==nullptr || node->data==value){
    return node;
  }
  if(value<node->data){
    return search(node->left,value);
  }
  return search(node->right,value);
}