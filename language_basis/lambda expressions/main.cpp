#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void log(const int &val) {
  cout << val << endl;
}

template<typename A>
auto sumAndLogFactory(A baseValue) {
  return [baseValue](A value) {
    cout << baseValue + value << endl;
  };
}

int main() {
  vector<int> numbers {1, 2, 3, 4};

  // same result
  for_each(numbers.begin(), numbers.end(), log);
  cout << endl;
  for_each(numbers.begin(), numbers.end(), [](const int &val) -> void { cout << val << endl; } );
  
  // capture clause
  cout << endl;
  int a = 23;

  [&a]() {
    cout << a << endl;
  }();

  // function creation
  auto f = sumAndLogFactory(12);
  f(5); // 17

  return 0;
}
