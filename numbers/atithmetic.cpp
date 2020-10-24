#include <iostream>

using namespace std;

void transformWeeks(long int weeks) {
  cout << "weeks " << weeks << endl;
  
  weeks *= 7;
  cout << "days " << weeks << endl;

  weeks *= 24;
  cout << "hours " << weeks << endl;

  weeks *= 60;
  cout << "minutes " << weeks << endl;

  weeks *= 60;
  cout << "seconds " << weeks << endl;

  weeks *= 1000;
  cout << "miliseconds " << weeks << endl;
}

int main() {
  // NOTE: log dot on each hundredth iteration
  for (int i = 0; i < 10000; i += 1) {
    bool hundredthIteration = (i % 100) == 0;

    if (hundredthIteration) {
      cout << '.' << flush;
    }
  }

  // NOTE: 'i' only exist in for loop
  // cout << "counter value is: " << i << endl;

  transformWeeks(7);

  return 0;
}
