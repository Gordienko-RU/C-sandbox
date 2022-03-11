#include <iostream>

using namespace std;

class Test {
  private:
    int x {3};
    int y {4};

  public:
    void apply() {
      cout << this->x << endl;
      cout << this->y << endl;
    };
};

int main() {
  char value = 4;
  Test *pTest = (Test*)&value;

  // no matching conversion for C-style cast from 'char' to 'Test' error
  // Test test1 = (Test)value;

  // pointer of bigger type pointing to smaller value - compiled, but cause unexpected behavior
  pTest->apply(); // 4 716554240 - for x 'value' was used, and for y it's just a garbage value
  
  // can not compile, error generated
  // int *staticPT = static_cast<Test*>(&value);

  return 0;
};

