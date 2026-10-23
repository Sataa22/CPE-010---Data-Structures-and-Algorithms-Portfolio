#include <iostream>
#include <cstdlib>      // For generating random integers
#include <time.h>       // Will be used for our seeding function 
#include "sorting.h"

// Step 2
const int maxSize = 100;

// Step 3
void RNG(int A[], int maxSize);

// for Step 5 and 8
void Display(int A[], int maxSize);

int main(){
    
    int A[maxSize];
    int candidate[5] = {0, 0, 0, 0, 0}; // Step 6
    int winner = 0;


    RNG(A, maxSize);
    std::cout << "Unsorted Data: ";
    Display(A, maxSize);    // Step 5

    bubbleSort(A, maxSize);
    std::cout << "\n\nSorted Data: ";
    Display(A, maxSize);

    // Step 7 ( Counting the Votes )
    for(int i = 0; i < maxSize; i++){
        candidate[A[i] - 1]++;
    }

    // Step 8
    std::cout << "\n\nCounting the Votes: ";
    for(int i = 0; i < 5; i++){
        std::cout << "Candidate " << i + 1 << " : " << candidate[i] << " votes\n";
    }

    // Step 9
    for(int i = 1; i < 5; i++){
        if(candidate[i] > candidate[winner]){
            winner = i;
        }
    }

    std::cout << "\n THE WINNER ISSS CANDIDATE #" << winner + 1 << " WITH " << candidate[winner] << " VOTES!!!.";



    return 0;
}

void Display(int A[], int maxSize){
    for(int i = 0; i < maxSize; i++){
        std::cout << A[i] << "    ";
    }
}

void RNG(int A[], int maxSize){
    srand(time(0));

    for(int i = 0; i < maxSize; i++){
        int RNG_Limit = 5;    // Limit of RNG
        A[i] = rand() % RNG_Limit + 1;  // Step 4
    }
}