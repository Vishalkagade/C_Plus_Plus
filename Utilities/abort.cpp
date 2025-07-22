#include <iostream>
#include <cstdlib> // For std::abort

int main() {
    std::cout << "Starting program..." << std::endl;

    // Simulate a critical error
    bool criticalError = true;

    if (criticalError) {
        std::cerr << "Critical error encountered! Aborting program." << std::endl;
        std::abort(); // Immediately terminates the program
    }

    std::cout << "This line will never be executed." << std::endl;
    return 0;
}