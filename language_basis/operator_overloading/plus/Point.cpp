#include "./Point.h"

using namespace std;

ostream & operator<<(ostream &stream, const Point &point) {
  return stream << point.x << "|" << point.y;
};

Point & operator+(Point &point, double a) {
  point.x += a;
  point.y += a;

  return point;
};

Point & operator+(double a, Point &point) {
  point.x += a;
  point.y += a;

  return point;
};
