#include <iostream>
#include <exception>

using namespace std;

void throwInvalidArgumentException() {
  bitset<4> b3("0012");
};

void throwPureException() {
 throw exception();
}

int main() {
  try {
    throwInvalidArgumentException();
  } catch(exception &error) {
    cout << "exception: " << error.what() << endl; // will be called
  } catch(invalid_argument &error) {
    cout << "invalid argument: " << error.what() << endl; // ignored
  }

  return 0;
};
