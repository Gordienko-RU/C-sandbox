#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class ConnectionError {
  public:
  char* type;
  ConnectionError() {
    this->type = "Connection error";
  };
};

class ResponseStructureError {
  public:
  char* type;
  ResponseStructureError() {
    this->type = "Response structure error";
  };
};

void func1() {
  const char errorIndicator = (rand() % 2) + 1;

  switch (errorIndicator) {
    case 1: {
      throw ConnectionError();
    }
    case 2: {
      throw ResponseStructureError();
    }
  }
}

void func2() {
  try {
    func1();
  } catch(ConnectionError &error) {
    cout << error.type << " happened. func2 handler." << endl;

    throw error;
  }
}

int main() {
  srand(time(NULL));

  try {
    func2();
  } catch(ConnectionError &error) {
    cout << error.type << " happened. Main handler." << endl;
  } catch(ResponseStructureError &error) {
    cout << error.type << " happened. Main handler." << endl;
  }

  return 0;
};
