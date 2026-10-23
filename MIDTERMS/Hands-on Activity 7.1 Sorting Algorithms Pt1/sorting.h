#ifndef DATASET_H
#define DATASET_H
#include <iostream>

template<typename T>
void bubbleSort(T A[], int maxSize){

    for(int i = 0; i < maxSize; i++)
        for(int j = 0; j < maxSize - i - 1; j++){
            // Compares 2 adjacent element
            if(A[j] > A[j + 1]){
                std::swap(A[j], A[j + 1]);
            }
        }
}


#endif