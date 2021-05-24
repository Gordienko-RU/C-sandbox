#include <iostream>

using namespace std;

class Test {
  public:
    static const int TEST_CONSTANT = 99;
    static int getInstanceCount() {
      return instanceCount;
    }
  private:
    static int instanceCount;
    int id;
  public:
    Test() {
      this->id = ++instanceCount;
    }

    int getId() const {
      return this->id;
    };
};

int Test::instanceCount = 0;

int main() {
  cout << "Static constant is: " << Test::TEST_CONSTANT << endl;
  cout << "Instance count is: " << Test::getInstanceCount() << endl;
  Test test1;
  cout << test1.getId() << endl; // 1

  return 0;
};
