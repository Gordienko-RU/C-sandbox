#include <iostream>
#include <string.h>

using namespace std;

int multiply(int x, int y) {
  return x * y;
}

string multiply(string x, int y) {
  string rez;

  for (int i = 0; i < y; i++) {
    rez += x;
  }

  return rez;
}

class ShoppingCard {
  public:
    double totalCost;
    ShoppingCard(double initial): totalCost(initial) {};
    void operator+ (const double value) {
      this->totalCost += value;
    };
};

int main() {
  cout << multiply(2, 3) << endl; // 6
  cout << multiply("2", 3) << endl; // 222

  ShoppingCard shoppingCard(12.41);
  shoppingCard + 3.47;

  cout << shoppingCard.totalCost << endl; // 15.88

  return 0;
}

