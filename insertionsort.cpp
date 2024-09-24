#include <iostream>
#include <vector>

using namespace std;


bool primos(int arr){
  if (arr<=1){
    return false;
  }
  for (int i= 2; i*i<=arr;i++){
    if (arr % i==0){
      return false;
          }
      }
      return true;
  }

void InsertionSort(vector<int> &arr){
  int n = arr.size();

  for(int i=1;i<n;i++){
    int key = arr[i];
    int j = i-1;

    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j--;
      
    }
    arr[j+1]=key;
  
  }
}



int main() { 
  vector<int>arr ={12, 5, 3, 7, 11, 4, 8, 13};
  
  vector<int>primosfiltro;

  InsertionSort(arr);
  for (int num:arr){
    if (primos(num)){
      cout<<num<<", ";
    }
  }
return 0;
}