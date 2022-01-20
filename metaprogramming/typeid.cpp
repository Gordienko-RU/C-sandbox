#include <typeinfo>
#include <iostream>

using namespace std;

class Test {
  public:
    int val;

    Test(): val(5) {};
};

template<class A>
void logTypeName(A &variable) {
  cout << typeid(variable).name() << endl;
};

void testF() {};

int main() {
  char ch = '3';
  Test test;
  string str = "asdf";

  logTypeName(ch); // c
  logTypeName(test); // 4Test
  logTypeName(str); // NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE
  logTypeName(testF); // FvvE

  return 0;
};
