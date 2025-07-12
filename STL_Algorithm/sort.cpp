#include <iostream>
#include <array>
#include <algorithm>

using std::cout;
using std::endl;

// Helper function to print the contents of std::array<int, 5>
void Print(std::array<int,6> arr) {
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
  std::array<int, 6> s = {2, 5, 1, 9, 3,5};

  cout << "before sorting" << endl;

  Print(s);

  std::sort(s.begin(), s.end());

  cout << "after sorting" << endl;

  Print(s);

  return 0;

}