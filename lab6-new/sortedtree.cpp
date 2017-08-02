#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree<int> binarySearchTree;

void addValues(){
    for (int i = 1; i<=21; i++){
        int random = rand() % 100 + 1;
        std::cout << i << " : " << random << std::endl;
        binarySearchTree.add(random);

    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    addValues();
    return 0;
}