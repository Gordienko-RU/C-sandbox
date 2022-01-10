#include <iostream>
#include <vector>

using namespace std;

class Point {
  public:
    double x;
    double y;
    Point(double x, double y): x(x), y(y) {};
};

const int SQUARE_SIDE = 10;

bool isPointOutOfDimension(Point &point) {
  return point.x > SQUARE_SIDE || point.y > SQUARE_SIDE;
};

vector<Point> * getOutOfDimensionPoints(vector<Point> &points, bool (*checker)(Point &)) {
  vector<Point> * outOfDimensionPoints = new vector<Point>;

  for (vector<Point>::iterator it = points.begin(); it != points.end(); ++it) {
    if (checker(*it)) {
      outOfDimensionPoints->push_back(*it);
    }
  }

  return outOfDimensionPoints;
};

int main() {
  vector<Point> points;

  points.push_back(Point(2.2, 3.1));
  points.push_back(Point(1.2, 20.1));
  points.push_back(Point(0.2, 3.1));
  points.push_back(Point(10.2, 3.1));

  vector<Point> * outOfDimensionPoints = getOutOfDimensionPoints(points, isPointOutOfDimension);
  cout << outOfDimensionPoints->size() << endl;

  delete outOfDimensionPoints;

  return 0;
};
