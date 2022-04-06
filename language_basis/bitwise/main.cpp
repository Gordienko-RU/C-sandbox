#include <iostream>

using namespace std;

int main() {
  // 00000100
  const char a = 4;

  // 00000111
  const char b = 7;

  // & - does AND on every bit of two numbers, resolved to 1, only in case if both bits are 1.

  cout << "& result" << (a & b) << endl; // 00000100

  // | - does OR on every bit of two numbers, resolved to 1, if any of both bits are 1.

  cout << "| result" << (a | b) << endl; // 00000111

  // ^ - does XOR on every bit of two numbers, resolved to 1, only in case if bits have different values.

  cout << "^ result" << (a ^ b) << endl; // 00000011

  // ~ - does NOT - it inverts all bit values of passed number.

  cout << "~ result" << (~a) << endl; // 11111011

  // << >> - do bits shifting based on provided number
  const char c = a << 2;
  cout << "<< result" << (int)c << endl; // 00010000

  const char d = b >> 2;
  cout << ">> result" << (int)d << endl; // 00000001
}
