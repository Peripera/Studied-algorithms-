#include <iostream>
#include <vector>

using namespace std;

void mySwap(int &a, int &b){
  int temp = a;
  a = b; //Tiene el valor por el que se va a cambiat ahora b sera temp
  b=temp;
}

void selectionSort(vector<int> &vec){
  int n= vec.size();
  for (int i =0; i<n;i++){
    int minVal=i;
    for (int j=i+1;j<n;j++){
      if(vec[j]<vec[minVal]){
        minVal=j;
      }
    }
    if(minVal !=i){
      mySwap(vec[i],vec[minVal]);
    }
  }
}

int main() { 
  vector<int>vec ={2,32,54,33,5};

selectionSort(vec);
  for (int num: vec){
    cout<<num<<" ,";
  }
return 0;
}