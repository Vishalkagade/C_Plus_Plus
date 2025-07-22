#include <iostream>
#include <variant>

int main() {
  using vari = std::variant<int, float>;
  vari v1 = 12;

  std::cout << std::get<int>(v1) << std::endl;

  vari v2{3.14f};

  std::cout << std::get<float>(v2) << std::endl;

  v2 = v1;
  std::cout << std::get<int>(v2) << std::endl;
  return 0;
}