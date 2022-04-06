#include <iostream>

using namespace std;

class A {
  public:
    int x;
    A(int x, int y, int z): x(x), y(y), z(z) {};
  protected:
    int y;
  private:
    int z;
};

class B: public A {
  public:
  B(int x, int y, int z): A(x, y, z) {};

  void log() {
    cout << "B instance method log: " << endl;
    cout << "x - " << this->x << endl;
    cout << "y - " << this->y << endl;
    // cout << "z - " << this->z << endl; // fail
  };
};

class C: protected A {
  public:
  C(int x, int y, int z): A(x, y, z) {};

  void log() {
    cout << "C instance method log: " << endl;
    cout << "x - " << this->x << endl;
    cout << "y - " << this->y << endl;
    // cout << "z - " << this->z << endl; // fail
  };
};

class D: private A {
  public:
  D(int x, int y, int z): A(x, y, z) {};

  void log() {
    cout << "D instance method log: " << endl;
    cout << "x - " << this->x << endl;
    cout << "y - " << this->y << endl;
    // cout << "z - " << this->z << endl; // fail
  };
};

int main() {
  B b(1, 2, 3);
  C c(1, 2, 3);
  D d(1, 2, 3);

  b.log();
  cout << "B instance out of scope log: " << endl;
  cout << "x - " << b.x << endl;
  // cout << "y - " << b.y << endl; // fail
  // cout << "z - " << b.z << endl; // fail

  c.log();
  cout << "C instance out of scope log: " << endl;
  // cout << "x - " << c.x << endl; // fail
  // cout << "y - " << b.y << endl; // fail
  // cout << "z - " << c.z << endl; // fail

  d.log();
  cout << "D instance out of scope log: " << endl;
  // cout << "x - " << d.x << endl; // fail
  // cout << "y - " << d.y << endl; // fail
  // cout << "y - " << d.z << endl; // fail

  return 0;
};

