#include "./Point.h"

using namespace std;

double Point::operator[](int index) const {
  if (index == 0) {
    return this->x;
  } else if(index == 1) {
    return this->y;
  }

  return 0;
  // TODO: throw an error
};

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
