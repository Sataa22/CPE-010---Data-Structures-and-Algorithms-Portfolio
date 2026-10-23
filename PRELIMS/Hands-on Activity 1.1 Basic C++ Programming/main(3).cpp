#include <iostream>

void swapNumbers(int &fNum, int &sNum);

int main() {

    int fNum = 67, sNum = 76;

    std::cout << "Before Swapping: First Number = " << fNum << ", Second Number = " << sNum;

    swapNumbers(fNum, sNum); // Swapping

    std::cout << "\nAfter Swapping: First Number = " << fNum << ", Second Number = " << sNum;

    return 0;
}

void swapNumbers(int &fNum, int &sNum) {
    int temp = fNum;
    fNum = sNum;
    sNum = temp;
}