#include "geometry.hpp"
#include <cmath>
#include <iostream>
using namespace std;

// static int declaration
int Polygon::polygonCount = 0;

// Point methods
Point::Point() {
  xVal = 0;
  yVal = 0;
}

// PointArray methods

// default constructor
PointArray::PointArray() {
  // size is updated to 0
  size = 0;
  // new Point[] initialized
  points = new Point[size];
}

// constructor using a Point[]
PointArray::PointArray(const Point pts[], const int n) {
  // size updated based on arg
  size = n;
  points = new Point[size];
  // Point[] in argument copied into
  // new Point[] pointed to by class
  for (int i = 0; i < n; ++i) {
    points[i] = pts[i];
  }
}

// default copy constructor
PointArray::PointArray(const PointArray& pv) {
  // size copied over
  size = pv.size;
  points = new Point[size];
  // Point[] copied over to new Point[]
  for (int i = 0; i < size; ++i) {
    points[i] = pv.points[i];
  }
}

void PointArray::resize(int n) {
  // determine min elements of Point[] to copy over
  int min = (size < n ? size : n);
  // size updated based on arg
  size = n;
  // rezied Point[] is created
  Point* pointsResized = new Point[size];
  // elements are copied over to resized Point[]
  for (int i = 0; i < min; ++i) {
    pointsResized[i] = points[i];
  }
  // original Point[] is deleted
  delete[] points;
  points = pointsResized;
}

void PointArray::push_back(const Point& p) {
  size += 1;
  resize(size);
  points[size - 1] = p;
}

void PointArray::insert(const int position, const Point& p) {
  size += 1;
  resize(size);
  // move each pos <= element < size from index to (index + 1)
  for (int i = size - 1; i > position; --i) {
    points[i] = points[i - 1];
  }
  // insert element in pos
  points[position] = p;
}

void PointArray::remove(const int position) {
  if (position >= 0 && size > position) {  // need to work for 0-length array
    // move each pos <= element < size from index to (index - 1)
    for (int i = position; i < (size - 2); ++i) {
      points[i] = points[i + 1];
    }
  }
  size -= 1;
  resize(size);
}

Point* PointArray::get(const int position) {
  Point* nullPtr = 0;
  // return nullPtr if position provided is not within PointArray.size
  return (position > size) ? nullPtr : (points + position);
}

const Point* PointArray::get(const int position) const {
  Point* nullPtr = 0;
  // return nullPtr if position provided is not within PointArray.size
  return (position > size) ? nullPtr : (points + position);
}

// Polygon methods
Polygon::Polygon(const Point pts[], const int length) : pointArr(pts, length) {
  ++polygonCount;
}

// snippet adapted from assignment 3
Point constructorPoints[4];

Point* updateConstructorPoints(const Point& p1, const Point& p2,
                               const Point& p3, const Point& p4 = Point(0, 0)) {
  constructorPoints[0] = p1;
  constructorPoints[1] = p2;
  constructorPoints[2] = p3;
  constructorPoints[3] = p4;
  return constructorPoints;
}

// Rectangle methods

// constuctor using 2 corner Point(s)
Rectangle::Rectangle(Point& p1, Point& p2)
    : Polygon(updateConstructorPoints(p1, Point(p1.getX(), p2.getY()), p2,
                                      Point(p2.getX(), p1.getY())),
              4) {}

// constructor using 4 ints, where the 4 ints are the
// coordinates of the 2 corner Point(s)
Rectangle::Rectangle(int p1x, int p1y, int p2x, int p2y)
    : Polygon(updateConstructorPoints(Point(p1x, p1y), Point(p1x, p2y),
                                      Point(p2x, p2y), Point(p2x, p1y)),
              4) {}

// area function to override pure virtual Polygon::area
double Rectangle::area() const {
  double length = pointArr.get(2)->getX() - pointArr.get(0)->getX();
  double width = pointArr.get(1)->getY() - pointArr.get(0)->getY();
  return abs(length * width);
}

// Triangle methods

// constructor using 3 Point(s) of triangle
Triangle::Triangle(Point& p1, Point& p2, Point& p3)
    : Polygon(updateConstructorPoints(p1, p2, p3), 3) {}

// area function to override pure virtual Polygon::area
double Triangle::area() const {
  double aSquared = pow(pointArr.get(1)->getY() - pointArr.get(0)->getY(), 2) +
                    pow(pointArr.get(1)->getX() - pointArr.get(0)->getX(), 2);
  double bSquared = pow(pointArr.get(2)->getY() - pointArr.get(1)->getY(), 2) +
                    pow(pointArr.get(2)->getX() - pointArr.get(1)->getX(), 2);
  double cSquared = pow(pointArr.get(0)->getY() - pointArr.get(2)->getY(), 2) +
                    pow(pointArr.get(0)->getX() - pointArr.get(2)->getX(), 2);
  double a = sqrt(aSquared);
  double b = sqrt(bSquared);
  double c = sqrt(cSquared);
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

void printAttributes(Polygon* poly) {
  // prints area of poly
  cout << "Area: " << poly->area() << endl;
  const PointArray* polyPointArr = poly->getPoints();
  // prints all coordinates of poly
  for (int i = 0; i < polyPointArr->getSize(); ++i) {
    cout << "(" << polyPointArr->get(i)->getX() << ", "
         << polyPointArr->get(i)->getY() << ")" << endl;
  }
}

int main() {
  cout << "Input lower-left and upper-right positions of a Rectangle as 4 "
          "space-separated ints: "
       << endl;
  int p1x, p1y, p2x, p2y;
  cin >> p1x >> p1y >> p2x >> p2y;
  Rectangle rect(p1x, p1y, p2x, p2y);

  cout << "Input point positions of a Triangle as 6 space-separated ints: "
       << endl;
  int t1x, t1y, t2x, t2y, t3x, t3y;
  cin >> t1x >> t1y >> t2x >> t2y >> t3x >> t3y;
  Point p1(t1x, t1y);
  Point p2(t2x, t2y);
  Point p3(t3x, t3y);
  Triangle tri(p1, p2, p3);

  cout << "The area and points for the Rectangle and Triangle respectively: "
       << endl;
  printAttributes(&rect);
  printAttributes(&tri);
}
