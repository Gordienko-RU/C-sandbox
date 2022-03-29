#include <iostream>
#include <functional>
#include <sstream>

using namespace std;
using namespace placeholders;

class Test1 {
  public:
    int val1 {3};

    void log(int val) {
      cout << this->val1 + val << endl;
    }
};

int main() {
  Test1 test;
  auto logger = bind(&Test1::log, test, 3);
  logger(); // 6

  return 0;
}

