#include <iostream>

using namespace std;

class Test {
  public:
    Test() = default;
    Test(const Test&) = default;
    ~Test() = default;
    Test & operator=(const Test &) = default;
};

void process(Test & test) {
  cout << "call by lValue" << endl;
}

void process(Test && test) {
  cout << "call by rValue" << endl;
}

int main() {
  Test test1;
  process(test1); // "call by lValue"
  process(Test{}); // "call by rValue"

  return 0;
}


