#include <iostream>

using namespace std;

int main () {
  int capacity=5;
  int* number = new int[capacity]; //le digo a c++ que quiero 5 espacios de memoria para guardar n
  int entries=0;

  while(true){
    cout<<"numbers"<<endl;
    cin>>number[entries];

    if (cin.fail()) break;  // metodo del input para romper el bucle
    entries ++;

    if (entries==capacity){
      int* temp= new int[capacity];
      //COPIAR LOS ELEMENTOS DE TEMP AL ARREGLO DE NUMS

      for(int i=0; i < entries; i++){
        temp[i]=number[i];
      }
      delete[] number; //libera la memoria de number 
      number=temp;
    }

    if (entries > capacity){
      cout<<"warning: exceeding the limit"<<endl;
    }

  }

  for (int i=0; i<entries; i++ ){
    cout<<number[i]<<endl;
  }



  return 0;
} 
