#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
  enum ages { VALUE_1, VALUE_2 = 3, VALUE_3, VALUE_4 };

  // value is exposed on declaration level
  cout << VALUE_1 << endl; // 0
  cout << VALUE_3 << endl; // 4
  cout << ages::VALUE_4 << endl; // 5

  // both valid
  enum ages value = VALUE_1;
  int anotherValue = VALUE_1;

  return 0;
}

