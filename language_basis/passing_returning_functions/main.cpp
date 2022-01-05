#include <iostream>

using namespace std;

void log(string text) {
  cout << text << endl;
}

int main() {
  // pointer call
  void (*pLog)(string) = &log;
  // the same result
  void (*pLog1)(string) = log;

  pLog("message");
  pLog1("message 1");
}
