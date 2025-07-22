#include <iostream>
#include <utility>

int main() {
  auto a = 5;
  auto b = 10;

  std::cout << a << " and " << b << "\n";

  std::swap(a, b);

  std::cout << a << " and " << b;

  return 0;
  
}