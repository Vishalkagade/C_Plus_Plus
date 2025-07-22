#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc > 2) {
    cerr << "Error: Exactly 2 arguments required." << endl;
    return 1;
  }

  string file1 = argv[0];
  string file2 = argv[1];
}