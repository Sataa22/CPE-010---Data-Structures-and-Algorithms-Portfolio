#include <iostream>
#include <cmath>

class Triangle{
    private:
        double sideA, sideB, sideC;
        double totalAngle, angleA, angleB, angleC;
    public: 
        // Constructor
        Triangle(double A, double B, double C, double a, double b, double c);

    // *Function inside a class is called METHODS*
    void setAngle(double A, double B, double C);
    
    // Validator
    const bool validateTriangle();

    double computeArea();
    double computePerimeter();
    void triangleType();

};

int main() {
    // Driver Code
    Triangle setl(100, 30, 50, 3, 4, 5); // Angles and Sides
    if(setl.validateTriangle()){
        std::cout << "The triange is Valid.\n";
        std::cout << "Area: " << setl.computeArea() << std::endl; 
        std::cout << "Perimeter: " << setl.computePerimeter() << std::endl; 
    }   else {
        std::cout << "The triangle is NOT valid.\n";
    }
}

Triangle::Triangle(double A, double B, double C, double a, double b, double c){
    angleA = A;
    angleB = B;
    angleC = C;

    sideA = a;
    sideB = b;
    sideC = c;
}

void Triangle::setAngle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle(){
    return (totalAngle <= 180);
}

double Triangle::computeArea(){
    double s = computePerimeter()/2;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::computePerimeter(){
    return totalAngle;
}

void Triangle::triangleType(){
    if (angleA < 90 && angleB < 90 && angleC < 90)
        std::cout << "triangleType: Acute angle";
    else if (angleA < 90 || angleB > 90 || angleC > 90)
        std::cout << "triangleType: Obtuse angle";
        else  std::cout << "triangleType: Others(Right Traingle)";
 
}