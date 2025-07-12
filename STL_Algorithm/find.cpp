#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

int main() {

  const int n = 10;
  std::vector<int> vec{1, 2, 3, 4, 5};

  auto result= std::find(vec.begin(), vec.end(), n);

  if (result != std::end(vec)) {
    cout << "V contains: "<< n << endl;
  }
  else {
  cout << "v does not contain" << endl;
  }

  return 0;
}