#include <iostream>

using namespace std;

// first solution
/*
  time - O(n)
  space - O(n)
*/
int fun1(int n) {
  if (n > 1) {
    return n + fun1(n - 1);
  }

  return 1;
}

// tail call optimized
/*
  time - O(n)
  space - O(1) - should be transformed to simple lop by compiler
*/
int fun2(int n, int sum = 0) {
   if (n == 0) {
     return sum;
   }

   return fun2(n - 1, sum + n);
}

// loop
/*
  time - O(n)
  space - O(1)
*/
int fun3(int n) {
  int sum = 0;

   for(int i = 1; i <= n; ++i) {
     sum += i;
   }

   return sum;
}

int main() {
  cout << fun1(5) << endl;
  cout << fun2(5) << endl;
  cout << fun3(5) << endl;

  return 0;
}
