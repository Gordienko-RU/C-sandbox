#include <iostream>

using namespace std;

void log(double itemToLog) {
  cout << "logged from different logger value is: " << itemToLog << endl;
};

template<class T>
void log(T itemToLog) {
  cout << "logged value is: " << itemToLog << endl;
};

template<class T>
struct Point {
    T x;
    T y;
    Point(T x, T y): x(x), y(y) {};
};

int main() {
  log<int>(9);
  log<string>("value to log");
  Point<double> point(2.3, 5.7);
  log<double>(point.x); // template version call
  log<>(point.x); // template version call
  log(point.y); // dedicated version call

  return 0;
};
