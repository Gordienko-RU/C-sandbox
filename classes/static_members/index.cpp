#include <iostream>

#include "./Test/Test.h"

using namespace std;
using namespace sandbox;

int main() {
  cout << "Static constant is: " << Test::TEST_CONSTANT << endl;
  // cout << "Instance count is: " << Test::getInstanceCount() << endl;
  Test test1;
  cout << test1.getId() << endl; // 1

  return 0;
};
