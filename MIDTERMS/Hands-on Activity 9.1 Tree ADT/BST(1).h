#include <iostream>
#ifndef BST_H
#define BST_H

template <typename T>
class BINARY_SEARCH_TREE{
    private:

    T KEY;

    // Pointers
    BINARY_SEARCH_TREE<T>* LEFT;
    BINARY_SEARCH_TREE<T>* RIGHT;


    public:

    // Constructor
    BINARY_SEARCH_TREE<T>(T VALUE);

    // Inserting
    void INSERT(T VALUE);

    // Traverse
    void PRE_ORDER();
    void IN_ORDER();
    void POST_ORDER();

};

template <typename T>
BINARY_SEARCH_TREE<T>::BINARY_SEARCH_TREE(T VALUE){
    KEY = VALUE;
    LEFT = nullptr;
    RIGHT = nullptr;
};

template <typename T>
void BINARY_SEARCH_TREE<T>::INSERT(T VALUE){
    if(VALUE < KEY){
        if(LEFT == nullptr){
            LEFT = new BINARY_SEARCH_TREE<T>(VALUE);
        }else{
            LEFT->INSERT(VALUE);
        }      
    }
    else if(VALUE > KEY){
        if(RIGHT == nullptr){
            RIGHT = new BINARY_SEARCH_TREE<T>(VALUE);
        }else{
            RIGHT->INSERT(VALUE);
        }
    }
};

template <typename T>
void BINARY_SEARCH_TREE<T>::PRE_ORDER(){
    std::cout << KEY << "   ";
    if(LEFT != nullptr){
        LEFT -> PRE_ORDER();
    }

    if(RIGHT != nullptr){
        RIGHT -> PRE_ORDER();
    }
}

template <typename T>
void BINARY_SEARCH_TREE<T>::IN_ORDER(){
    if(LEFT != nullptr){
        LEFT -> IN_ORDER();
    }

    std::cout << KEY << "   ";

    if(RIGHT != nullptr){
        RIGHT -> IN_ORDER();
    }
}

template <typename T>
void BINARY_SEARCH_TREE<T>::POST_ORDER(){
    if(LEFT != nullptr){
        LEFT -> POST_ORDER();
    }


    if(RIGHT != nullptr){
        RIGHT -> POST_ORDER();
    }

    std::cout << KEY << "   ";
}


#endif 

