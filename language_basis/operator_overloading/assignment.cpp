#include <iostream>

using namespace std;

class Test {
  private:
    int value;

  public:
    Test(int value): value(value) {};

    Test(const Test &target) {
      cout << "copy constructor called" << endl;
      this->value = target.value;
    };

    int getValue() {
      return this->value;
    }

    const Test& operator=(const Test &target) {
      cout << "assignment operator called" << endl;
      this->value = target.value;

      return *this;
    }
};

int main() {
  Test test1(1);
  Test test2(2);
  Test test3(3);

  test1 = test2 = test3; // assignment chain

  cout << endl;
  cout << "test1 value: " << test1.getValue() << endl;
  cout << "test2 value: " << test2.getValue() << endl;
  cout << "test3 value: " << test3.getValue() << endl;

  cout << endl;

  Test test4(test2); // copy constructor call
  cout << "test4 value: " << test4.getValue() << endl;

  return 0;
};
