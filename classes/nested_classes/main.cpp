#include <iostream>

using namespace std;

class Test {
  public:
    class Nested;
};

class Test::Nested {
  public:
    Nested() {
      cout << "Nested class created." << endl;
    }
};

int main() {
  Test::Nested nested;

  return 0;
}
