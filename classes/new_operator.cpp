#include <iostream>

using namespace std;

class Test {
private:
  string name;
public:
  Test() {
    cout << "Object created." << endl;
  };
  ~Test() {
    cout << "Object deleted." << endl;
  };
};

int main() {
  Test inst1; // Memory will be cleared automatically, after function finished.
  Test* inst2 = new Test(); // Need to delete object explicitly, to clear memory and call destructor.

  // inst2->name // Arrow here is shorthand for (*inst2).name.

  delete inst2;

  return 0;
}

