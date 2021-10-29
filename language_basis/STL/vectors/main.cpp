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

  int capacity = numbers.capacity();
  cout << "initial capacity is: " << capacity << endl;
  
  for(int i = 0; i < 100; i++) {
    numbers.push_back(0);

    if (numbers.capacity() != capacity) {
      capacity = numbers.capacity();
      cout << "capacity is: " << capacity << endl;
    }
  }
  /*
    capacity is: 4
    capacity is: 8
    capacity is: 16
    capacity is: 32
    capacity is: 64
    capacity is: 128
  */

  return 0;
};
