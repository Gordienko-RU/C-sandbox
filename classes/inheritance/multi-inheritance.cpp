#include <iostream>

using namespace std;

class A {
  private:
    int x;
  public:
    A(int x): x(x) { cout << "A call" << endl; };
    int getX() const { return this->x; };
};

class B {
  private:
    int y;
  public:
    B(int y): y(y) { cout << "B call" << endl; };
    int getY() const { return this->y; };
};

class C {
  private:
    int z;
  public:
    C(int z): z(z) { cout << "C call" << endl; };
    int getZ() const { return this->z; };
};

class D: public C, public B, public A {
  public:
    D(int x, int y, int z): A(x), B(y), C(z) { cout << "D call" << endl; };
};

int main() {
  D d(1, 2, 3);
  cout << d.getX() << endl;
  cout << d.getY() << endl;
  cout << d.getZ() << endl;

  /*
    C call
    B call
    A call
    D call
    1
    2
    3
  */

  return 0;
};
