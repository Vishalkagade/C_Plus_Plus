#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));         // Seed the random number generator
  int num = rand() % 100; // Generate number between 0 and 99
  int guess;

  // Uncomment the line below only if you want to debug:
  // cout << "DEBUG: the number is " << num << endl;

  cout << "Guess the number (between 0 and 99): ";
  cin >> guess;

  // Input validation
  while (cin.fail() || guess < 0 || guess > 99) {
    cin.clear();             // Clear the error flag
    cin.ignore(10000, '\n'); // Remove invalid input
    cout << "[WARNING] : Number must be between 0 and 99" << endl;
    cout << "Try again: ";
    cin >> guess;
  }

  // Keep asking until correct
  while (guess != num) {
    if (guess < num) {
      cout << "The given guess is smaller than the number. Try again: ";
    } else {
      cout << "The given guess is greater than the number. Try again: ";
    }

    cin >> guess;

    // Validate new input
    while (cin.fail() || guess < 0 || guess > 99) {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "[WARNING] : Number must be between 0 and 99" << endl;
      cout << "Try again: ";
      cin >> guess;
    }
  }

  // Correct guess
  cout << "You are damn correct!" << endl;

  return 0;
}
