#include <iostream>
#include <exception>

using namespace std;

class CustomError: public exception {
  public:
  const char* message;

  CustomError(): message("custom error happened") {};

  ~CustomError() throw() {
    delete [] this->message;
  }

  const char* what() const throw() {
    return this->message;
  }
};

void func1() {
  throw CustomError();
}

int main() {
  try {
    func1();
  } catch(CustomError &error) {
    cout << error.what() << endl;
  }

  return 0;
};
