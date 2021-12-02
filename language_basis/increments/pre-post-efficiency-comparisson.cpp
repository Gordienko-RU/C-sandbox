#include <iostream>
#include <list>
#include <chrono>

using namespace std;

void logDuration(chrono::time_point<chrono::high_resolution_clock> start, chrono::time_point<chrono::high_resolution_clock> stop) {
  cout << (chrono::duration_cast<chrono::microseconds>(stop - start)).count() << endl;
}

int main() {
  chrono::time_point<chrono::high_resolution_clock> t1, t2, t3, t4, t5;

  t1 = chrono::high_resolution_clock::now();

  // NOTE: integral type comparrison
  for (int i = 0; i < 1000000; i++) {
    int a = i;
  }

  t2 = chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000000; ++i) {
    int a = i;
  }

  t3 = chrono::high_resolution_clock::now();

  // NOTE: iterators comparrison
  list<int> list1(1000000, 3);

  for (list<int>::iterator it = list1.begin(); it != list1.end(); it++) {
    int a = *it;
  }

  t4 = chrono::high_resolution_clock::now();

  for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it) {
    int a = *it;
  }

  t5 = chrono::high_resolution_clock::now();

  cout << "intregral post-inc. takes: "<< endl;
  logDuration(t1, t2);
  cout << "intregral pre-inc. takes: " << endl;
  logDuration(t2, t3);
  cout << "iterator post-inc. takes: " << endl;
  logDuration(t3, t4);
  cout << "iterator pre-inc. takes: " << endl;
  logDuration(t4, t5);

  // NOTE: pre-inc is always faster

  return 0;
}
