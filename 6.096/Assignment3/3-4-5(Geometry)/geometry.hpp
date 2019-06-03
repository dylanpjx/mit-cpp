class Point {
 private:
  int xVal, yVal;

 public:
  // Point constructors
  Point();
  Point(int x, int y) : xVal(x), yVal(y) {}

  // Point methods
  int getX() const { return xVal; }
  int getY() const { return yVal; }
  void setX(const int new_x) { xVal = new_x; }
  void setY(const int new_y) { yVal = new_y; }
};

class PointArray {
 private:
  int size;
  Point* points;

  void resize(int n);

 public:
  // PointArray constructors
  PointArray();
  PointArray(const Point pts[], const int n);
  PointArray(const PointArray& pv);

  // PointArray methods
  ~PointArray() { delete[] points; }
  void push_back(const Point& p);
  void insert(const int position, const Point& p);
  void remove(const int position);
  const int getSize() const { return size; }
  void clear() { resize(0); }
  Point* get(const int position);
  const Point* get(const int position) const;
};

class Polygon {
 protected:
  static int polygonCount;
  PointArray pointArr;

 public:
  Polygon(const Point pts[], const int length);
  Polygon(const PointArray& pts) : pointArr(pts) { ++polygonCount; }
  ~Polygon() { --polygonCount; }
  virtual double area() const = 0;  // Pure virtual
                                    // No definition given, obtain area from
                                    // subclass methods
  static int getNumPolygons() { return polygonCount; }
  int getNumSides() const { return pointArr.getSize(); }
  const PointArray* getPoints() const { return &pointArr; }
};

class Rectangle : public Polygon {  // Rectangle inherits from Polygon
 public:
  Rectangle(Point& p1, Point& p2);
  Rectangle(int p1x, int p1y, int p2x, int p2y);
  double area() const;
};

class Triangle : public Polygon {  // Triangle inherits from Polygon
 public:
  Triangle(Point& p1, Point& p2, Point& p3);
  double area() const;
};
