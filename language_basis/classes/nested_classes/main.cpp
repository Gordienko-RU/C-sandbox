#include <iostream>

using namespace std;

template<typename A>
class Test {
  public:
    class Nested;
};

template<typename A>
class Test<A>::Nested {
  public:
    Nested() {
      cout << "Nested class created. Template param result: " << A() << endl;
    }
};

int main() {
  Test<int>::Nested nested;

  return 0;
}
