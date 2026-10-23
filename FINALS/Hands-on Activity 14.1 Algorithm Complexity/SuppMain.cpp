#include <iostream>
#include <chrono>
#include <iterator>
#include <cstdlib>
#include <thread>
#include <algorithm>
#include <ctime>
#include "searchingAlgo.h"

void LinearExperimental(int SIZE){
  int* arr = new int[SIZE];

  for(int i = 1001; i < SIZE; i++){
    arr[i] = i;
  }
  auto start = std::chrono::high_resolution_clock::now();
  std::cout << "\nStarting Linear Search\n";
  LinearSearchArr(SIZE, 1001, arr);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
  std::cout<< "Linear Search Runtime: " << duration << " milliseconds\n";
}

void BinaryExperimental(int SIZE){
  int* arr = new int[SIZE];

  for(int i = 1; i<SIZE; i++){
    arr[i] = i;
  }
  auto start = std::chrono::high_resolution_clock::now();
  std::cout << "\nStarting Binary Search\n";
  BinarySearchArr(1001, arr, SIZE);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
  std::cout << "Binary search runtime: " << duration << " milliseconds\n";
}

int main(){
  std::thread th1(LinearExperimental, 1000);
  std::thread th2(BinaryExperimental, 0000);

  th1.join();
  th2.join();
  return 0;
}


