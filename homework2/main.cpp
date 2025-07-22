#include <iostream>
using std::cout;
using std::endl;

string SayHello(const string to_whom = "World") {
  return "Hello " + to_whom + "!";
}


int main() {
  cout << SayHello() << endl;

  cout << SayHello("Vishal") << endl;

  return EXIT_FAILURE;
  
}