#include <iostream>
#include <random>

int main() {
    std::cout << "Welcome to Guessing Game" << std::endl;

    bool win = false;

    const int min = 0;
    const int max = 99;

    std::random_device rd;
    std::uniform_int_distribution<int> distrib(min, max);

    int usr_guess = 0;
    int game_num = 0;

    game_num = distrib(rd);

    while (!win) {
        std::cout << "Please guess the number :";
        std::cin >> usr_guess;

        if (std::cin.fail()) {
            std::cerr << "Error encountered, exiting..." << std::endl;
            std::cout << game_num << std::endl;
            return EXIT_FAILURE;
        }

        if (usr_guess <= min || usr_guess >= max) {
            std::cerr << "[WARNING] : Number must be between 0 and 99"
                      << std::endl;
            std::cout << game_num << std::endl;

        } else if (usr_guess > game_num) {
            std::cerr << "Number must be smaller than current guess"
                      << std::endl;
            std::cout << game_num << std::endl;
            return EXIT_FAILURE;

        } else if (usr_guess < game_num) {
            std::cout << "Number is smaller than the target number"
                      << std::endl;
            std::cout << game_num << std::endl;
        }

        else {
            std::cout << "SUCCESS" << std::endl;
            std::cout << game_num << std::endl;
            win = true;
        }
    }

    return EXIT_SUCCESS;
}
