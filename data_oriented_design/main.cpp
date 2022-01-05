#include <iostream>
#include <vector>

using namespace std;

// OOP
class Point {
  double x;
  double y;
  void draw();
  Point();
}

// DO
class Points {
  vector<double> x;
  vector<double> y;
  void draw();
  Points();
}

int main() {
  Points points();
  vector<Point> points();

  return 0;
};
