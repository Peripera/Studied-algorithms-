#include "queue.h"
#include <iostream>

using namespace std; 

Queue::Queue(int capacity){
  front= -1;
  rear= -1;
  size= capacity;
  queue= new int(size);
}

bool Queue::isEmpty(){
  return front==-1;
}
bool Queue::isFull(){
  return rear== size -1;
}

void Queue::enqueue(int value){
  if (isFull()){
    cout<<"Queue is full"<<endl;
    return;
  }

  if (front==-1){
    front=0;
  }
  queue[++rear]=value;
  cout<<value<<"enque to queue"<<endl;

}

void Queue::dequeue(){
  if(isEmpty()){
    cout<<"Queue is empty"<<endl;
    return;
  }
  cout<<queue[front]<<"dequeue from queue"<<endl;
  front++;

  if (front>rear){
    front=-1;
    rear=-1;
  }
}

  int Queue::frontElement() {
      if (isEmpty()) {
          cout << "Queue is empty" << endl;
          return -1;  // si la cola está vacía
      }
      return queue[front];  
  }

Queue:: ~Queue(){
  delete[] queue;
}

