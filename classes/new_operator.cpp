#include <iostream>

using namespace std;

class Test {
private:
  string name;
public:
  Test() {};
  ~Test() {};
  void setName(string name) {
    this->name = name;
  };
  void getName() const {
    cout << this->name << endl;
  };
};

// OBJECT RETURNING FROM FUNCTION EXAMPLES:
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
// Test* createTest(string name) {
//   Test* test = new Test();
//   test->setName(name);

//   return test;
// }
// ...
// Test* inst3 = createTest("test 1"); // Address returned which is cheap, and no calls of copy constructor.

// delete inst3; // Is not very clear, since memory allocation and clearance happened in different places.

int main() {
  // PLAYING WITH NEW OPERATOR
  // Test inst1; // Memory will be cleared automatically, after function finished.
  // Test* inst2 = new Test(); // Need to delete object explicitly, to clear memory and call destructor.

  // inst2->name // Arrow here is shorthand for (*inst2).name.

  // delete inst2;

  // Test* inst3 = createTest("test 1");
  // inst3->getName();

  // delete inst3; 

  // Test* tests = new Test[10]; // Create array of several instances.

  // delete [] tests;  // Culry brackets needed to tell that we want to delete the whole array,
  // // not only first element.

  // int* integerArrAllocated = new int[100]; // Memory can be allocated with new for primitives as well.

  // delete [] integerArrAllocated;

  // TEST TASK FROM COURSE
  const int ASCII_INDENT = 65;
  const int CHARACTERS_IN_ALPABET_COUNT = 26;

  Test tests[CHARACTERS_IN_ALPABET_COUNT];

  for(int i = 0; i < CHARACTERS_IN_ALPABET_COUNT; i++) {
    const int charCode = i + ASCII_INDENT;
    const string alphabetCharacter = string(1, charCode);

    Test& testRef = tests[i];
    testRef.setName(alphabetCharacter);
    testRef.getName();
  };

  return 0;
}
