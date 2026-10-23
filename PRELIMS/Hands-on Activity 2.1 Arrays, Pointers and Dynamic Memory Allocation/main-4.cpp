#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;

    public:
    // Constructor
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor was called.\n";
    }

    // Deconstructor
    ~Student(){
        std::cout << "Destructor was called.\n";
    }

    // Copy Constructor
    Student(const Student &copyStudent){
        std::cout << "Copy Constructor  was called.\n";
        studentName = copyStudent.studentName; 
        studentAge = copyStudent.studentAge;
    }

    // Display Attribute
    void printDetails(){
        std::cout << this->studentName << " " << this->studentAge << std::endl;
    }

    // Copy Assignment Operator


};

int main() {

    const size_t j = 5;

    Student studentList[j] = {};
    std::string nameList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
    int ageList[j] = {15, 16, 18, 19, 16};

    // Loop A
    for(int i = 0; i < j; i++){
        Student *ptr = new Student(nameList[i], ageList[i]);
        studentList[i] = *ptr;
        delete ptr;
        ptr = nullptr;
    }

    //Loop B
    for(int i = 0; i < j; i++){
        studentList[i].printDetails();
    }
    return 0;
}