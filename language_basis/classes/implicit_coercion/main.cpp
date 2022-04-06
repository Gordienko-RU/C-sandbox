#include <iostream>

using namespace std;

class Test0 {
  public:
    Test0(string) {};
};

class Test1 {
  public:
    explicit Test1(int) {};
};

void testHandler(Test0 test) {
  cout << "triggered for Test0" << endl;
};

void testHandler(Test1 test) {
  cout << "triggered for Test1" << endl;
};

int main() {
  string value = "string";
  testHandler(value);
  // testHandler(32); // error - no way to coerce int to Test1

  return 0;
};
