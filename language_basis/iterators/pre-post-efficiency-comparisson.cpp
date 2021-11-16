#include <iostream>
#include <list>

using namespace std;

int main() {
  // NOTE: integral type comparrison
  for (int i = 0; i < 1000000; i++) {
    int a = i;
  }

  for (int i = 0; i < 1000000; ++i) {
    int a = i;
  }

  // NOTE: iterators comparrison
  list<int> list1(1000000, 3);

  for (list<int>::iterator it = list1.begin(); it != list1.end(); it++) {
    int a = *it;
  }

  for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it) {
    int a = *it;
  }

  return 0;
}
