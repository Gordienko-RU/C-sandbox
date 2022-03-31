#include <iostream>

using namespace std;

class Test {
  public:
    int val {6};

    Test() {
      cout << "created" << endl;
    }

    ~Test() {
      cout << "destroied" << endl;
    }
};

// class Wrapper {
//   public:
//     Test * tests;
//     Wrapper(): tests{new Test[2]} {};
// };
class Wrapper {
  public:
    unique_ptr<Test[]> tests;
    Wrapper(): tests(new Test[2]) {};
};

int main() {
  {
    unique_ptr<Test> test(new Test()); // created
    cout << test->val << endl; // 6
    // destroied
  }

  {
    unique_ptr<Test[]> tests(new Test[2]);
    /*
      created
      created
      destroied
      destroied
    */
  }

  {
    Wrapper wrapper;
    /*
      created
      created
      destroied
      destroied
    */
  }

  cout << "end" << endl;

  return 0;
};
