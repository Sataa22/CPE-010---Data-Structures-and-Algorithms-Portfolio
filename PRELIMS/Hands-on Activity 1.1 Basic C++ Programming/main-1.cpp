#include <iostream>

float kelvinToFahrenheit(float kelvin);

int main() {
    float temp;

    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> temp;
    std::cout << "Temperature in Fahrenheit: " << kelvinToFahrenheit(temp)<< "F" << std::endl;
    return 0; 
}

float kelvinToFahrenheit(float kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}
