#ifndef POINT
#define POINT

#include <iostream>

using namespace std;

class Point {
  private:
    double x;
    double y;

  public:
    Point(): x(0), y(0) {};
    Point(double x, double y): x(x), y(y) {};

    friend ostream & operator<<(ostream &stream, const Point &point);
    friend Point & operator+(Point &point, double a);
    friend Point & operator+(double a, Point &point);
};

#endif // !POINT