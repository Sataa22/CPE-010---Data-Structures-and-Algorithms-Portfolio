#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H


template<typename T>
void LinearSearchArr(int maxSize, T dataFind, T data[]){

    int i = 0;
    while(i <= maxSize){
        if(dataFind == data[i]){
            std::cout << "Searching is successfull\n";
            return;
        }
        i++;
    }
    std::cout<<"\nThe search is unsuccessful\n";
}

template<typename T>
void LinearSearchLL(Node<T>* node, T dataFind){

    //Create a loop that iterates until a the node reaches the end (null)
    while(node != nullptr){
        //Create an if condition that will compare the search item to the current node data
        if(node->data == dataFind){
            std::cout << "\nThe search was success. \n";
            return;
        }
        //Itirator or /moving of node
        node = node->next;
    } 
    //Display if unsuccessful

    std::cout << "\nThe search was unsuccessful.\n";
}

template<typename T>
void BinarySearchArr(T dataFind, T data[], int maxSize){
    int low = 0, up = maxSize-1, middle;
    while(low <= up){
        middle = (int)((low+up)/2);
        if(dataFind == data[middle]){
            std::cout << "\nSearching is success!\n";
            return;
        }
        else if(dataFind < data[middle]){
            up = middle + 1;
        }else{
            up = middle - 1;
        }
    }
    std::cout <<"\nSearch element was not found\n";
}
//Create a helper function to get the middle
template<typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    //use two pointers
    //slow moves one node at a time
    // fast moves two nodes at a time
    Node<T>* slow = start;
    Node<T>* fast = start;

    //create a loop until fast reaches the end or
    //reaches the last node of the current search range
    while(fast != last && fast->next != last){

        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<typename T>
void BinarySearchLL(Node<T>* start, T dataFind){

    Node<T>* last = nullptr;

    while(start != last){
        //middle element
        Node<T>* middle = getMiddle(start, last);

        if(middle->data == dataFind){
            std::cout << "The data was found.\n";
            return;
        }
        else if(middle->data > dataFind){
            last = middle;
        }
        else{
            start = middle->next;
        }
    }
    std::cout<<"Search element was not found.\n";
}

#endif