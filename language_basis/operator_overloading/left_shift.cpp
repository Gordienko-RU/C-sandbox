#include <iostream>

using namespace std;

class Test {
  private:
    int value;

  public:
    Test(int value): value(value) {};

    friend ostream& operator<<(ostream &stream, Test &test);
};

ostream& operator<<(ostream &stream, Test &test) {
  return stream << test.value;
};

int main() {
  Test test(9);
  cout << test << 1 << endl; // 91

  return 0;
};

