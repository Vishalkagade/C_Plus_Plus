#include <iostream>
#include <sstream>

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        std::cout << "There should be only two input arguments" << std::endl;

        return EXIT_FAILURE;
    }

    std::stringstream filename1{argv[1]};
    std::stringstream filename2{argv[2]};

    int num1 = 0;
    int num2 = 0;

    std::string ext1;
    std::string ext2;

    filename1 >> num1 >> ext1;
    filename2 >> num2 >> ext2;

    const std::string epng = ".png";
    const std::string etxt = ".txt";

    if ((ext1 == epng) && (ext2 == epng)) {
        std::cout << (num1 + num2) << std::endl;
    } else if ((ext1 == etxt) && (ext2 == etxt)) {
        std::cout << ((num1 + num2) / 2) << std::endl;
    } else if (((ext1 == epng) && (ext2 == etxt)) ||
               ((ext1 == etxt) && (ext2 == epng))) {
        std::cout << (num1 % num2) << std::endl;
    } else {
        std::cerr << "Extensions can only be .txt or .png" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}