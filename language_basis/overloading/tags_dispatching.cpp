#include <iostream>

using namespace std;

class Test {
  private:
    struct CreateUsingJuJuTag {};
    struct CreateUsingRuRuTag {};
  
  public:
    static const CreateUsingJuJuTag createUsingJuJuTag;
    static const CreateUsingRuRuTag createUsingRuRuTag;

    Test() {
      cout << "created using default" << endl;
    }

    Test(CreateUsingJuJuTag) {
      cout << "created using ju ju" << endl;
    }

    Test(CreateUsingRuRuTag) {
      cout << "created using ru ru" << endl;
    }
};

int main() {
  Test test1;
  Test test2(Test::createUsingJuJuTag);
  Test test3(Test::createUsingRuRuTag);

  /*
    created using default
    created using ju ju
    created using ru ru
  */

  return 0;
}
