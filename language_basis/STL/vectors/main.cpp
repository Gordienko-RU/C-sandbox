#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers(2);
  numbers[0] = 2;
  numbers[1] = 1;

  for(int i = 0; i < numbers.size(); i++) {
    cout << i << " item is: " << numbers[i] << endl;
  }

  for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
    cout << "item is: " << *it << endl;
  }

  return 0;
};
