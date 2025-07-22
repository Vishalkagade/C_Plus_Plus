#include <array>
#include <iostream>
// #include <numeric>

int main() {
    int memory_allocated = 0;

    while (true) {
        memory_allocated += 100;
        unsigned int siz = (1024 * memory_allocated) / sizeof(double);
        double arr[siz];
        (void)arr;
        std::cerr << memory_allocated << "[KiB] Allocated in the stack"
                  << std::endl;
    }
    return 0;
}