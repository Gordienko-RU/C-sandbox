#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Test {
  public:
    int *arr {nullptr};

    Test(): Test(0) {};

    Test(int value) {
      cout << "Constructor - " << value << endl;
      int *arr = new int[3];
      fill(arr, arr + 3, value);
      this->arr = arr;
    }

    ~Test() {
      delete [] this->arr;
    }

    Test(const Test &target) = delete;

    Test(Test &&target) {
      this->arr = target.arr;
      target.arr = nullptr;
      cout << "Move constructor" << endl;
    }

    Test &operator=(Test &&target) {
      delete [] this->arr;
      this->arr = target.arr;
      target.arr = nullptr;

      cout << "Move assignment" << endl;

      return *this;
    }
};

int main() {
  vector<Test> tests;
  tests.push_back(Test(4));

  Test test2(5);
  test2 = Test(3);

  cout << "test 1" << endl;

  for(int i = 0; i < 3; ++i) {
    cout << tests[0].arr[i] << endl;
  }

  cout << "test 2" << endl;

  for(int i = 0; i < 3; ++i) {
    cout << test2.arr[i] << endl;
  }

  return 0;
}
