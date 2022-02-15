#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void log(const int &val) {
  cout << val << endl;
}

int main() {
  vector<int> numbers {1, 2, 3, 4};

  // same result
  for_each(numbers.begin(), numbers.end(), log);
  cout << endl;
  for_each(numbers.begin(), numbers.end(), [](const int &val) -> void { cout << val << endl; } );

  return 0;
}
