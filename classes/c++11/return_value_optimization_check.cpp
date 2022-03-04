#include <iostream>

using namespace std;

class Test {
  public:
  Test() { cout << "Constructor" << endl; }
  Test(const Test &) { cout << "Copy constructor" << endl; }
  ~Test() { cout << "Destructor" << endl; }
};

Test getTest() {
  Test test0;

  return test0;
}

int main() {
  Test test1 = getTest();
  /*
    with return value optimization:

    Constructor
    Destructor

    without return value optimization:

    Constructor
    Copy constructor
    Destructor
    Copy constructor
    Destructor
    Destructor
  */

  return 0;
}
