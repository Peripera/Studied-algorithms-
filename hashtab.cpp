#include "hashtab.h"
using namespace std;

HashTable::HashTable(int size)
    : tableSize(size), elements_lp(0), elements_qp(0) {
    linearTable.assign(size, -1);    // Inicializa la tabla de Linear Probing
    quadraticTable.assign(size, -1); // Inicializa la tabla de Quadratic Probing
}

// Función hash
int HashTable::func_hash(int key) const {
    return key % tableSize;
}

// Resolución de colisiones para Linear Probing
int HashTable::lp_colisiones(int i_hash, int i) const {
    return (i_hash + i) % tableSize;
}

// Resolución de colisiones para Quadratic Probing
int HashTable::qp_colisiones(int i_hash, int i) const {
    return (i_hash + i * i) % tableSize;
}

// Rehashing para Linear Probing
void HashTable::rehashLinear() {
    std::vector<int> oldTable = linearTable; // Copiar la tabla antigua
    tableSize *= 2; // Duplicar el tamaño de la tabla
    linearTable.assign(tableSize, -1); // Inicializar la nueva tabla
    elements_lp = 0;

    for (int key : oldTable) {
        if (key != -1 && key != -2) { // Solo reinsertar claves válidas
            int i_hash = func_hash(key);
            int i = 0;

            while (true) {
                int index = lp_colisiones(i_hash, i);
                if (linearTable[index] == -1) { // Insertar en la nueva tabla
                    linearTable[index] = key;
                    elements_lp++;
                    break;
                }
                i++;
            }
        }
    }
}

// Rehashing para Quadratic Probing
void HashTable::rehashQuadratic() {
    std::vector<int> oldTable = quadraticTable; // Copiar la tabla antigua
    tableSize *= 2; // Duplicar el tamaño
    quadraticTable.assign(tableSize, -1); // Inicializar la nueva tabla
    elements_qp = 0;

    for (int key : oldTable) {
        if (key != -1 && key != -2) { // Solo reinsertar claves válidas
            int i_hash = func_hash(key);
            int i = 0;

            while (true) {
                int index = qp_colisiones(i_hash, i);
                if (quadraticTable[index] == -1) { 
                    quadraticTable[index] = key;
                    elements_qp++;
                    break;
                }
                i++;
            }
        }
    }
}


// Insertar en ambas tablas con el factor de carga 
void HashTable::insert(int key) {
    if (elements_lp >= tableSize * 0.7) {
        rehashLinear();
    }
    if (elements_qp >= tableSize * 0.7) {
        rehashQuadratic();
    }

    int i_hash = func_hash(key);

    //insertar hash lp
    int i = 0;
    while (true) {
        int index = lp_colisiones(i_hash, i);
        if (linearTable[index] == key) {
            return; 
        }
        if (linearTable[index] == -1 || linearTable[index] == -2) {
            linearTable[index] = key;
            elements_lp++;
            break;
        }
        i++;
    }

    // insert hash qp
    i = 0;
        while (true) {
        int index = qp_colisiones(i_hash, i);
        if (quadraticTable[index] == key) {
            return; 
        }
        if (quadraticTable[index] == -1 || quadraticTable[index] == -2) {
            quadraticTable[index] = key;
            elements_qp++;
            break;
        }
        i++;
    }
}



// Buscar en Linear Probing
bool HashTable::searchLinear(int key) const {
    int i_hash = func_hash(key);
    int i = 0;

    while (i < tableSize) {
        int index = lp_colisiones(i_hash, i);
        if (linearTable[index] == -1) {
            return false;
        }
        if (linearTable[index] == key) {
            return true;
        }
        i++;
    }
    return false;
}

// Buscar en Quadratic Probing
bool HashTable::searchQuadratic(int key) const {
    int i_hash = func_hash(key);
    int i = 0;

    while (i < tableSize) {
        int index = qp_colisiones(i_hash, i);
        if (quadraticTable[index] == -1) {
            return false;
        }
        if (quadraticTable[index] == key) {
            return true;
        }
        i++;
    }
    return false;
}

// Eliminar de Linear Probing
void HashTable::removeLinear(int key) {
    int i_hash = func_hash(key);
    int i = 0;

    while (i < tableSize) {
        int index = lp_colisiones(i_hash, i);
        if (linearTable[index] == -1) {
            return;
        }
        if (linearTable[index] == key) {
            linearTable[index] = -2; // Marca como eliminado
            elements_lp--;
            return;
        }
        i++;
    }
}

// Eliminar de Quadratic Probing
void HashTable::removeQuadratic(int key) {
    int i_hash = func_hash(key);
    int i = 0;

    while (i < tableSize) {
        int index = qp_colisiones(i_hash, i);
        if (quadraticTable[index] == -1) {
            return;
        }
        if (quadraticTable[index] == key) {
            quadraticTable[index] = -2; // Marca como eliminado
            elements_qp--;
            return;
        }
        i++;
    }
}

// Mostrar tablas
void HashTable::display() const {
    cout << "Índice\tLinear Probing\tQuadratic Probing\n";
    for (int i = 0; i < tableSize; ++i) {
        cout << i << "\t";
        if (linearTable[i] == -1) {
            cout << "VACIO\t\t";
        } else if (linearTable[i] == -2) {
            cout << "ELIMINADO";
        } else {
        cout << linearTable[i] << "\t\t";
        }

        if (quadraticTable[i] == -1) {
            cout << "VACIO";
        } else if (quadraticTable[i] == -2) {
            cout << "ELIMINADO";
        } else {
            cout << quadraticTable[i];
        }
        cout << "\n";
    }
}

