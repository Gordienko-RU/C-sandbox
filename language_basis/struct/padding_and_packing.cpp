#include <iostream>

struct S1 {
  int a;
  int b;
  char c;
  int d;

  S1(int a, int b, char c, int d): a(a), b(b), c(c), d(d) {};
};

#pragma pack(push, 1)
struct S2 {
  int a;
  int b;
  char c;
  int d;

  S2(int a, int b, char c, int d): a(a), b(b), c(c), d(d) {};
};
#pragma pack(pop)

using namespace std;

int main() {
  S1 s1(1, 1, 's', 1);
  S2 s2(1, 1, 's', 1);

  cout << "padded: " << sizeof(s1) << endl;
  cout << "packed: " << sizeof(s2) << endl;

  return 0;
}
