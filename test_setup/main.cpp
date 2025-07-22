#include <iostream>
// #include <array>

// using std::cout;
// using std::endl;

// int main() {
//   std::array<float, 3> data{1.0f, 2.0f, 3.0f};

//   for (const auto& elem : data) {
//     cout << elem << endl;
//   }
//   cout << std::boolalpha;
//   cout << "Array empty: " << data.empty() << endl;
//   cout << "Array SIze: " << data.size() << endl;
//   cout << "second element is: " << data[1]<<endl;
//     }

using std::cout;
using std::endl;

#include <vector>
#include <string>

// int main() {
//   std::vector<int> numbers = {1, 2, 3};
//   std::vector<std::string> names = {"Vishal", "Vishnu", "Kagade"};
//   names.emplace_back("Gruadute");

//   cout << std::boolalpha << "numbers are empty: " << names.empty() << endl;
//   return 0;
// }

// int main() {

//   const int N = 200;
//   std::vector<int> vec;
//   //vec.reserve(N);
//   for (int i = 0; i < N; i++) {
//     vec.emplace_back(i);
//   }
//   vec.emplace_back(201);

//   cout << vec.size() << endl;
//   cout << vec.capacity() << endl;
// }
#include <unordered_map>
#include <map>
using namespace std;
int main() {
  using PersonalInfo = std::unordered_map<int, std::string>;
  PersonalInfo m;
  m.emplace(1, "vishal");
  m.emplace(2, "Kagade");

  m[2] = "Vishnu";

  if (m.count(1) > 0) {
    cout << "present" << endl;
  }
  else {
  cout << "not presetn" << endl;
  }

  for (const auto &[id, name] : m) {
    cout << "id: " << id << "," <<"name: " << name <<endl;
  }

  cout << m.size()<<endl;

  
  return 0;
      
}
