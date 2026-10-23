#include <iostream>
#include <cmath>

float distanceBetweenTwoPoints (float x1, float y1, float x2, float y2);

int main() {
    float x1, y1, x2, y2, distance;

    std::cout << "Enter x1: ";
    std::cin >> x1;

    std::cout << "Enter y1: ";
    std::cin >> y1;

    std::cout << "Enter x2: ";
    std::cin >> x2;

    std::cout << "Enter y2: ";
    std::cin >> y2;

    std::cout << "The distance between two points is: " << distance << std::endl;
}

float distanceBetweenTwoPoints (float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
