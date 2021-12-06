#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <execution>

using namespace std;

void logDuration(chrono::time_point<chrono::high_resolution_clock> start, chrono::time_point<chrono::high_resolution_clock> stop) {
  cout << (chrono::duration_cast<chrono::microseconds>(stop - start)).count() << endl;
}

int main() {
  vector<int> numbers;
  vector<int> numbers1;

  const int AMOUNT = 1000000;

  for (int i = 0; i < AMOUNT; ++i) {
    const int randomNumber = rand();

    numbers.push_back(randomNumber);
    numbers1.push_back(randomNumber);
  }

  chrono::time_point<chrono::high_resolution_clock> t1, t2, t3, t4;
  
  t1 = chrono::high_resolution_clock::now();
  sort(numbers.begin(), numbers.end());
  t2 = chrono::high_resolution_clock::now();

  cout << "without mt: " << logDuration(t1, t2) << endl;

  t3 = chrono::high_resolution_clock::now();
  sort(execution::par, numbers.begin(), numbers.end());
  t4 = chrono::high_resolution_clock::now();

  cout << "with mt: " << logDuration(t3, t4) << endl;

  return 0;
}
