#include <iostream>

// Prototyping :
// 1. Create a function that will take two numbers and display the sum.
int sumOfTwoNum(int fNum, int sNum);
// 2. Create a function that will return whether variable A is greater than variable B.
int isAGreaterThanB(int aNum, int bNum);
// 3. Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success.
bool logicalOperation(bool fVal, bool sVal);

int main() {
    // std::cout << "Hello World" << std::endl;

    std::cout << "The sum of the two numbers is : " << sumOfTwoNum(6, 7) << std::endl;
    std ::cout << "Is A Greater than B? : " << isAGreaterThanB(6, 7) << std::endl;
    std::cout << logicalOperation(true, false);

    return 0;
}

// Definition :
int sumOfTwoNum(int fNum, int sNum) {
    return fNum + sNum;
}

int isAGreaterThanB(int aNum, int bNum) {
    if (aNum >= bNum) {
        std::cout << "Yes! A is Greater than B.";
    } else {
        std::cout << "No!. B is NOT Greater than A.";
    };

    return 0;
};

bool logicalOperation(bool fVal, bool sVal) {
    std::cout << "\nFirst Value: " << fVal;
    std::cout << "\nFirst Value: " << fVal;
    // AND(&&), OR(||), NOT(!), XOR(^)
    std::cout << "\nAND(&&): " << (fVal && sVal);
    std::cout << "\nOR(||): " << (fVal || sVal);
    std::cout << "\nNOT(!) First Value: " << (!fVal);
    std::cout << "\nNOT(!) Second Value: " << (!sVal);
    std::cout << "\nXOR(^): " << (fVal ^ sVal);

    return true;
};