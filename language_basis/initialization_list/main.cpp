#include <iostream>

using namespace std;

class A {
  public:
  int x;

  A() {
    x = 0;
  };
};

class B {
  public:
  int y;

  B(int y) {
    this->y = y;
  };
};

class C {
  public:
  const B b;
  A &aRef;
  A a;

  C(A &a): b(2), aRef(a) {};
};

int main() {
  A a;
  a.x = 12;

  C c(a);

  cout << "A by reference value: " << c.aRef.x << endl;
  cout << "A default constructor value: " << c.a.x << endl;
  cout << "B passed value: " << c.b.y << endl;

  return 0;
}
