#include <iostream>
#include <string.h>

using namespace std;

class A {
  public:
    void virtual log() {
      cout << "Base class A" << endl;
    };
};

class C: public A {
  public:
    void log() {
      cout << "Derived class C" << endl;
    }
};

void log(A a) {
  a.log();
};

int main() {
  // .log() from base class will be called in all cases below
  A a = C();
  a.log();

  C c;
  log(c);

  A arr[] = { c };
  arr[0].log();

  return 0;
}
