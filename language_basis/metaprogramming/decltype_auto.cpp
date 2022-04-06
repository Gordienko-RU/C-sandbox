#include <typeinfo>
#include <iostream>

using namespace std;

template<class A>
void logTypeName(A &variable) {
  cout << typeid(variable).name() << endl;
};

class Stub {
  public:
    Stub(int) {};
};

class Test {
  public:
    static Stub val;

    Test() {};
};

template<class A>
void createNewValueBasedOnExisted(A &a) {
  decltype(A::val) value = 12;
  logTypeName(value); // 4Stub

  auto value1 = 12;
  logTypeName(value1);  // i
}

int main() {
  Test test;
  createNewValueBasedOnExisted(test);

  return 0;
};
