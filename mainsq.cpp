#include <iostream>
#include "queue.h"

using namespace std;


int main(){
  Queue q(5);

  q.enqueue(3);
  q.enqueue(2);
  q.enqueue(1);
  
  q.dequeue();
  q.dequeue();  

  cout<<"Front element: "<<q.frontElement()<<endl;
  return 0;
}