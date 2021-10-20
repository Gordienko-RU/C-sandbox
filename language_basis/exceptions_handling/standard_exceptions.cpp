#include <iostream>
#include <exception>

using namespace std;

void throwInvalidArgumentException() {
  bitset<4> b3("0012");
};

int main() {
  try {
    throwInvalidArgumentException();
  } catch(invalid_argument &error) {
    cout << error.what() << endl;
  }

  return 0;
};
