#ifndef HASHTAB_H
#define HASHTAB_H

#include <iostream>
#include <vector>
using namespace std;


enum CollisionResolutionMethod {
    LINEAR,
    QUADRATIC
};

class HashTable {
private:
    vector<int> linearTable;    // Tabla para LP
    vector<int> quadraticTable; // Tabla para qp
    int tableSize;                   
    int elements_lp;           
    int elements_qp;       

    // Función de hash
    int func_hash(int key) const;

    // Resolución de colisiones
    int lp_colisiones(int hashIndex, int i) const;
    int qp_colisiones(int hashIndex, int i) const;

    // Rehashing
    void rehashLinear();
    void rehashQuadratic();

public:
    // Constructor
    HashTable(int size);
    void insert(int key);        
    bool searchLinear(int key) const;  
    bool searchQuadratic(int key) const; 
    void removeLinear(int key);  
    void removeQuadratic(int key);  
    void display() const;       
};

#endif
