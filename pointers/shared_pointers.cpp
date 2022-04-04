#include <iostream>

using namespace std;

class Test {
  public:
    int val {6};

    Test() {
      cout << "Test created" << endl;
    }

    ~Test() {
      cout << "Test destroied" << endl;
    }
};

class Wrapper {
  public:
    shared_ptr<Test> test{nullptr};
    void setTest(shared_ptr<Test> test) {
      this->test = test;
    }

    Wrapper() {
      cout << "Wrapper created" << endl;
    }

    ~Wrapper() {
      cout << "Wrapper destroyed" << endl;
    }
};

int main() {
  Wrapper *pWrapper1 = new Wrapper();
  Wrapper *pWrapper2 = new Wrapper();

  {
    shared_ptr<Test> test(new Test);

    pWrapper1->setTest(test);
    pWrapper2->setTest(test);
  }

  delete pWrapper1;
  delete pWrapper2;

  cout << "end" << endl;

  /*
  Wrapper created
  Wrapper created
  Test created
  Wrapper destroyed
  Wrapper destroyed
  Test destroied
  end
  */

  return 0;
};
