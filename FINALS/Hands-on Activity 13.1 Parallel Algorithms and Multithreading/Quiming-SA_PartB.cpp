// Supplementary Activity Part B
#include <iostream>
#include <thread>

// Global Integer
int globalInt = 0;

// Create an add function that will take an integer parameter and add that value to the global variable 
void add(int value) {
    globalInt += value;
}

int main() {
    // Use multi-threading techniques to create 3 threads; individually pass the add function to the threads.
    std::thread t1(add, 10);
    std::thread t2(add, 20);
    std::thread t3(add, 30);

    // Display the value of global variable at different combinations of using the join() per thread.
    std::cout << "Display: " << globalInt << std::endl;
    t1.join();

    std::cout << "Display: " << globalInt << std::endl;
    t2.join();

    std::cout << "Display: " << globalInt << std::endl;
    t3.join();

    return 0;
}
