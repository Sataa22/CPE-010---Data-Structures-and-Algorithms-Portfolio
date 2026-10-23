#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"


int main(){

    // C P E
    DoublyList<char>* head = createNode('C');
    DoublyList<char>* second = createNode('P');
    DoublyList<char>* third = createNode('P');

    // Connecting the head node to the next.
    head->next = second;
    second->prev = head;

    //
    second->next = third;
    third->prev = second;

    // Traversal    
    std::cout << "Testing the dllTraverse Function.\n";
    dllTraverse(head);

    // Insert at Head
    std::cout << "Testing the dllInsertHead Function.\n";
    dllInsertHead('X', &head);
     dllTraverse(head);

    // Insert at End
    std::cout << "Testing the dllInsertEnd Function.\n";
    dllInsertEnd('0', head);
    dllTraverse(head);
    
    // General Insert
    std::cout << "Testing the dllGeneralInsert Function.\n";
    dllGeneralInsert('V', head->next->next);
    dllTraverse(head);

    // Delete a Node
    std::cout << "Testing the dllDeleteNode Function.\n";
    dllDeleteNode('V', &head);
    dllTraverse(head);

    return 0;
}