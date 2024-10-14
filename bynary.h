#ifndef BYNARY_H
#define BYNARY_H



struct Node{
  int data;
  Node* left;
  Node* right;

  Node (int value);
};

//construccion del bynary tree --> sugar sintax de *nodo.data
class Bynary{
  public:
    Node*root;

//constructor
    Bynary();
  Node* insert(Node*root, int value);
  Node* search(Node* node, int value);




};


#endif
