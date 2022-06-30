#include <iostream>
#include <map>

using namespace std;

map<int, int> cache;

int calcFactorial(int n) {
  if (n < 1) {
    cache[n] = 1;

    return 1;
  }

  const int stepRezult = n * calcFactorial(n - 1);

  if (cache.find(n) == cache.end()) {
    cache[n] = stepRezult;
  }

  return stepRezult;
}


int getUniqCombinationsAmount(int n, int r) {
  const int diff = n - r;
  const int nFactorial = calcFactorial(n);

  return nFactorial / (cache[r] * cache[diff]);
}

int main() {
  cout << getUniqCombinationsAmount(5, 3) << endl;

  return 0;
}
