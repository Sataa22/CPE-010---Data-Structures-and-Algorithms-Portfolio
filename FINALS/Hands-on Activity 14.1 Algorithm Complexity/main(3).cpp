#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <random>
#include <algorithm>
#include <thread>
#include <functional>

void bubbleSort(int array[], size_t size);
void insertionSort(int array[], size_t size);
void runBubbleSort(int array[], int size, long long &result);
void runInsertionSort(int array[], int size, long long &result);

int main() {
    int sizes[] = {100, 1000, 10000};

    for (int size : sizes) {
        std::vector<int> bestCase(size);
        std::vector<int> worstCase(size);

        for (int i = 0; i < size; i++) {
            bestCase[i] = i + 1;
            worstCase[i] = size - i;
        }

        for (int test = 0; test < 2; test++) {
            std::vector<int> bubbleArr =
                (test == 0) ? bestCase : worstCase;

            std::vector<int> insertionArr = bubbleArr;

            long long bubbleTime = 0, insertionTime = 0;

            std::thread th_bubble(
                runBubbleSort, bubbleArr.data(), size,
                std::ref(bubbleTime));

            std::thread th_insertion(
                runInsertionSort, insertionArr.data(), size,
                std::ref(insertionTime));

            th_bubble.join();
            th_insertion.join();

            if (test == 0)
                std::cout << "\n\nBest Case (" << size << ") : ";
            else
                std::cout << "\n\nWorst Case (" << size << ") : ";

            std::cout << "\nBubble Sort: " << bubbleTime << " microseconds";
            std::cout << "\nInsertion Sort: " << insertionTime << " microseconds";
        }
    }

    return 0;
}

void bubbleSort(int array[], size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

void insertionSort(int array[], size_t size) {
    for (int i = 1; i < size; i++) {
        int temp = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }
}

void runBubbleSort(int array[], int size, long long &result) {
    auto start = std::chrono::steady_clock::now();

    bubbleSort(array, size);

    auto end = std::chrono::steady_clock::now();

    result = std::chrono::duration_cast<std::chrono::microseconds>(
        end - start).count();
}

void runInsertionSort(int array[], int size, long long &result) {
    auto start = std::chrono::steady_clock::now();

    insertionSort(array, size);

    auto end = std::chrono::steady_clock::now();

    result = std::chrono::duration_cast<std::chrono::microseconds>(
        end - start).count();
}