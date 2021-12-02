#include <iostream>

using namespace std;

class Test {
  private:
    int value;
  public:
    Test(int value): value(value) {};
    // for global function
    friend int add(Test &test1, Test &test2);
    // for particular method of another class
    // friend int WithFriendMethod::add(Test &test1, Test &test2);
    // for another class fully
    friend class WithFullAccess;
};

// class WithFriendMethod {
//   public:
//     WithFriendMethod() {};

//     int add(Test &test1, Test &test2) {
//       return test1.value + test2.value;
//     };
// };

class WithFullAccess {
  public:
    WithFullAccess() {};
    void log1(Test &test) {
      cout << "from friend class log1: " << test.value << endl;
    }
    void log2(Test &test) {
      cout << "from friend class log2: " << test.value << endl;
    }
};

int add(Test &test1, Test &test2) {
  return test1.value + test2.value;
};

int main() {
  Test test1(7);
  Test test2(3);
  // WithFriendMethod withFriendMethod;
  WithFullAccess withFullAccess;

  cout << "global function: " << add(test1, test2) << endl; // 10
  // cout << "access granted to method: " << withFriendMethod.add(test1, test2) << endl; // 10
  withFullAccess.log1(test1); // 7
  withFullAccess.log2(test2); // 3

  return 0;
};


