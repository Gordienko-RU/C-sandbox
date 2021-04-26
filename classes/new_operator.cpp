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
  void setName(string name) {
    this->name = name;
  };
  void getName() {
    cout << this->name << endl;
  };
};

// // Unefficient.
// Test createTest(string name) {
//   Test test;
//   test.setName(name);

//   return test; // Object is destroyed since scope closed, so copy of object should be created
//   // to return it.
// }
// ...
// Test inst = createTest("test 1"); // Copy constructor call.

// That function creates pointer to return address of object,
// therefor we can avoid temporary copy creation and call of copy constructor
// while assign it to variable.
Test* createTest(string name) {
  Test* test = new Test();
  test->setName(name);

  return test;
}
// ...
// Test* inst3 = createTest("test 1"); // Address returned which is cheap, and no calls of copy constructor.

// delete inst3; // Is not very clear, since memory allocation and clearance happened in different places.

int main() {
  Test inst1; // Memory will be cleared automatically, after function finished.
  Test* inst2 = new Test(); // Need to delete object explicitly, to clear memory and call destructor.

  // inst2->name // Arrow here is shorthand for (*inst2).name.

  delete inst2;

  Test* inst3 = createTest("test 1");
  inst3->getName();

  delete inst3; 

  return 0;
}
