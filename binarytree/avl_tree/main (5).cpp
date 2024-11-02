#include <iostream>

#include "avl_tree.h"

using namespace std;

int main()
{
    AVLTree tree;

    // Crear algunos usuarios
    User* user1 = new User(1, "Alice", "alice@example.com", "2024-01-01");
    User* user2 = new User(2, "Bob", "bob@example.com", "2024-01-02");
    User* user3 = new User(4, "Charlie", "charlie@example.com", "2024-01-03");
    User* user4 = new User(3, "Sara", "sarita@hotamil.com", "2022-10-02");

    // Insertar usuarios en el árbol AVL
    tree.root = tree.insert(tree.root, user1);
    tree.root = tree.insert(tree.root, user2);
    tree.root = tree.insert(tree.root, user3);
    tree.root = tree.insert(tree.root, user4);

    // Mostrar los usuarios en orden
    cout << "Usuarios almacenados en el árbol AVL:" << endl;
    tree.inorder(tree.root);



    return 0;
}

//

/* El arbol AVL ordena los usuarios segun la numeracion de el ID sin importar el orden en que fueron insertados*/