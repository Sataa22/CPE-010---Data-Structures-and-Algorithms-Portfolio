#include <iostream>
#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

// Double List Node
template <typename T>
class DoublyList{
    public:
        T data;
        DoublyList<T>* next;
        DoublyList<T>* prev;
};

// Creating a node function
template <typename T>
DoublyList<T>* createNode(T newData){
    // Dynamic memory allocation for a new node.
    DoublyList<T>* newNode = new DoublyList<T>;
    newNode->data = newData;
    // Point it to the next node.
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

template <typename T>
void dllTraverse(DoublyList<T>* currentNode){
    // Check if list is empty
    if(currentNode == nullptr){
        std::cout << "The list is empty.";
        return;
    }
    DoublyList<T>* tail = nullptr; // tail not declared fix
    // Forward
    std::cout << "FORWARD: \n";
    while(currentNode != nullptr){
        // PRINT data OF n
        std::cout << currentNode->data<< "  ";
        tail = currentNode;
        // GO TO NEXT NODE
        currentNode = currentNode->next;       
    }
    
    // Reverse
    std::cout << "\nREVERSE: \n";
    while (tail != nullptr){
        std::cout << tail->data << "  ";
        tail = tail->prev;
    }
    std::cout << "\n";

}

// Inserting a node to the head
template <typename T>
void dllInsertHead(T newData, DoublyList<T>** currentNode){
    // Create a new node:
    DoublyList<T> *newNode = createNode(newData);
    // Point the newNode to the currentNode(head)
    newNode->next = *currentNode;
    // Point the currentNode(head) to the newNode
    (*currentNode)->prev = newNode;
    // Updating the header pointer
    *currentNode = newNode;

}

template <typename T>
void dllInsertEnd(T newData, DoublyList<T> *currentHead){
    // Create a new node
    DoublyList<T> *newNode = createNode(newData);
    // Traverse the new node back to the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }
    // Connect the new node back to the last node
    newNode->prev = currentHead;
    // Connect the new node back to the new node
    currentHead->next = newNode;

}

template <typename T>
void dllGeneralInsert(T newData, DoublyList<T>* prevNode){
    // Check if it is the head node
    if(prevNode == nullptr){
        std::cout << "Current Node is Null.\n"; return;
    }
    // Node creation
    DoublyList<T> *newNode = new DoublyList<T>;
    newNode->data = newData;
    // Connecting the new node to the head
    newNode->next = prevNode->next;
    // Points the currentNode to the newNode.
    newNode->prev = prevNode;                
    if(newNode->next != nullptr){                 
        newNode->next->prev = newNode;
    }

    // Makes the new node the newHead    
    prevNode->next = newNode;
}

template <typename T>
void dllDeleteNode(T findData, DoublyList<T>** head){
    if(*head == nullptr) return;

    DoublyList<T>* currNode = *head;

    // Search for the data
    while(currNode != nullptr && currNode->data !=findData){
        currNode = currNode->next;
    }

    // Data found.
    if(currNode == *head){
        *head = currNode->next;
    } else{
        currNode->prev->next = currNode->next;
    }

    if(currNode->next != nullptr){
        currNode->next->prev = currNode->prev;
    }

    delete currNode;
}

#endif