#include <functional>
#include <iostream>

using namespace std;

int addOne(int &numb) {
  return numb + 1;
}

class Adder {
  public:
    int operator()(int &numb) {
      return numb + 1;
    }
} adder;

int transformNumber(int numb, function<int(int&)> transformer) {
  return transformer(numb);
};

int main() {
  function<int(int&)> lambd = [](int &numb) -> int {
    return numb + 1;
  };

  cout << transformNumber(1, addOne) << endl; // 2
  cout << transformNumber(1, adder) << endl; // 2
  cout << transformNumber(1, lambd) << endl; // 2

  return 0;
}
