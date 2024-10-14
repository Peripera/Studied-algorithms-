#include <iostream>

using namespace std; //generalmente se especifica

struct Node{
  int data;
  Node* next;
};

void addNode(Node* &head, int value){
  Node* newnode= new Node(); //crea nuevo nofo
  newnode -> data=value; //la flecita es el sugar sintax, accedes al   new+data va a ser asignado al valor a la estrutura accedes al data
  newnode -> next=nullptr;

  if(head==nullptr){
    head=newnode;//si la lista esta vacia el nuevo nodo es la head
  }else{
      Node* temp=head;//variable temp que almacena el current head
    
      while(temp->next!=nullptr){//recorres la lista hasta el ultimo n
        temp=temp->next;
      }
    temp->next=newnode;//enlazamos
  }
}

void showlist(Node* head){
  Node* temp=head;
  while(temp!=nullptr){
    cout<<temp->data<<"->";
    temp=temp->next;  
  }
}

int main() { 
  Node* list=nullptr;
  addNode(list,5);
  addNode(list,49);
  addNode(list,23);
  addNode(list, 3);

  cout<<"Lista de valores: "<<endl;
  showlist(list);

  return 0;
}