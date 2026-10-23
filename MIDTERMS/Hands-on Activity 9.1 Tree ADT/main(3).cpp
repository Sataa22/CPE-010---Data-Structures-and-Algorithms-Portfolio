#include <iostream>
#include "BST.h"

int main(){

    // Create the root node
    BINARY_SEARCH_TREE<int> TREE(20);

    TREE.INSERT(10);
    TREE.INSERT(5);
    TREE.INSERT(70);
    TREE.INSERT(80);
    TREE.INSERT(40);
    TREE.INSERT(50);

    std::cout << "PRE ORDER: ";
    TREE.PRE_ORDER();
    std::cout << std::endl;

    std::cout << "IN ORDER: ";
    TREE.IN_ORDER();
    std::cout << std::endl;

    std::cout << "POST ORDER: ";
    TREE.POST_ORDER();
    std::cout << std::endl;

    return 0;
}