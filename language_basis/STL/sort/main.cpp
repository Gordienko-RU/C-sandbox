#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Test {
  public:
  int val;
  Test(int val): val(val) {};

  bool operator> (const Test &other) const {
    return this->val > other.val;
  }
};

void logVectorValues(vector<int> &v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << endl;
  }
}

void logVectorValues(vector<Test> &v) {
  for (vector<Test>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << it->val << endl;
  }
}

bool testComparator(const Test &a, const Test &b) {
  return a.val > b.val;
}

int main() {
  vector<Test> tests;

  tests.push_back(Test(8));  
  tests.push_back(Test(23));  
  tests.push_back(Test(-8));  
  tests.push_back(Test(1));  

  cout << "sorted tests:" << endl;
  sort(tests.begin(), tests.end(), greater<Test>());
  // sort(tests.begin(), tests.end(), testComparator);
  logVectorValues(tests);

  vector<int> numbers;

  numbers.push_back(8);  
  numbers.push_back(23);  
  numbers.push_back(-8);  
  numbers.push_back(1);  
  numbers.push_back(25);  
  numbers.push_back(90);  
  numbers.push_back(4);  

  cout << "sorted asc numbers:" << endl;
  sort(numbers.begin(), numbers.end());
  logVectorValues(numbers); // -8 1 4 8 23 25 90

  cout << "sorted desc first three items numbers:" << endl;
  sort(numbers.begin(), numbers.begin() + 3, greater<int>());
  logVectorValues(numbers); // 4 1 -8 8 23 25 90

  return 0;
}
