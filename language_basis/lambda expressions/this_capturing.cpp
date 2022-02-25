#include <iostream>
#include <algorithm>

using namespace std;

class Test {
  public:
    int x {0};
    auto getMutator() {
      return [this]() -> void {
        ++this->x;
      };
    }
};

int main() {
  Test test;
  auto func {test.getMutator()};
  cout << "initial log " << test.x << endl; // 0
  func(); func();
  cout << "next log " << test.x << endl; // 2

  return 0;
}
