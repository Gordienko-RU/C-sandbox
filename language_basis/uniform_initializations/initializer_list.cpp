#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

class Test {
  public:
    // Sequence constructor
    Test(initializer_list<int> numbers) {
      for (int number: numbers) {
        cout << number << endl;
      }
    }
};

int main() {
  vector<int> numbers = { 7, 9, -3 };
  Test test = { 10 };

  return 0;
}
