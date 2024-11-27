#include "hashtab.h"
#include <iostream>
using namespace std;
void menu() {
    cout << "\n Selecciona: \n";
    cout << "1. Insertar claves\n";
    cout << "2. Buscar clave\n";
    cout << "3. Eliminar clave\n";
    cout << "4. Salir\n";
    cout << "Elige una opcion: ";
}

int main() {
    int tableSize;
    cout << "Ingrese el size inicial del hash: ";
    cin >> tableSize;

    HashTable hashTable(tableSize);

    int option, key, numKeys;
    do {
        menu();
        cin >> option;

        switch (option) {
        case 1: // Insertar claves
            cout << "Numero de claves a insertar:  ";
            cin >> numKeys;
            for (int i = 0; i < numKeys; ++i) {
                cout << "Ingrese la clave " << i + 1 << ": ";
                cin >> key;
                hashTable.insert(key);
            }
            hashTable.display();
            break;
        case 2: // Buscar clave
            cout << "Ingrese la clave a buscar: ";
            cin >> key;
            cout << "Linear Probing: " << (hashTable.searchLinear(key) ? "Encontrado" : "No encontrado") << "\n";
            cout << "Quadratic Probing: " << (hashTable.searchQuadratic(key) ? "Encontrado" : "No encontrado") << "\n";
            hashTable.display();
            break;
        case 3: // Eliminar clave
         cout << "Ingrese la clave a eliminar: ";
            cin >> key;
            if (hashTable.searchLinear(key)) {
                hashTable.removeLinear(key);
                cout << "Clave eliminada de LP\n";
            } else {
                cout << "Ese valor no existe\n";
            }

            if (hashTable.searchQuadratic(key)) {
                hashTable.removeQuadratic(key);
                cout << "Clave eliminada de QP\n";
            } else {
                cout << "Ese valor no existe\n";
            }
            break;
        case 4: 
            break;
        default:
            cout << "Opcion no válida invalida\n";
            break;
        }
    } while (option != 4);

    return 0;
}

