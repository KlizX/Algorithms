#include <iostream>
#include <vector>

struct Point {
  double x, y;

  Point(double _x, double _y) : x(_x), y(_y) { }
  Point() : x(0), y(0) { }
  Point operator-(Point p);
  Point& operator=(const Point& p);
  void View();
};

Point Point::operator-(Point p) {
  x -= p.x;
  y -= p.y;
  return *this;
}

Point& Point::operator=(const Point& p) {
  if (&p == this) return *this;
  x = p.x;
  y = p.y;
  return *this;
}

void Point::View() {
  std::cout << x << " " << y << '\n';
}

Point SetLowestYAtIndex0(std::vector<Point>& p) {
  double lowestY = p[0].y;
  unsigned int index = 0;
  for (unsigned int i = 1; i < p.size(); i++) {
    if (lowestY > p[i].y || (lowestY == p[i].y && p[i].x < p[index].x)) {
      lowestY = p[i].y;
      index = i;
    }
  }
  std::swap(p[0], p[index]);
  return p[0];
}

double CountDistance(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int Area(Point a, Point b, Point c) {
  double area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  if (area < 0) return -1;
  if (area > 0) return 1;
  return 0;
}

int Compare(void* _p0, const void* _p1, const void* _p2) {
  Point* p0 = (Point*)_p0;
  Point* p1 = (Point*)_p1;
  Point* p2 = (Point*)_p2;

  int area = Area(*p0, *p1, *p2);
  if (area == 0) {
    return (CountDistance(*p0, *p1) > CountDistance(*p0, *p2)) ? 1 : -1;
  }
  return (area == -1) ? 1 : -1;
}

void Graham(std::vector<Point>& p) {
  Point lowestYPoint = SetLowestYAtIndex0(p);

  qsort_s(&p[1], p.size() - 1, sizeof(Point), Compare, &p[0]);

  for (unsigned int i = 0; i < p.size() - 2; i++) {
    //std::cout << i << ": " << p[i].x << "," << p[i].y << " " << p[i + 1].x << "," << p[i + 1].y << " " << p[i + 2].x << "," << p[i + 2].y << " " << Area(p[i], p[i + 1], p[i + 2]) << std::endl;
    if (Area(p[i], p[i + 1], p[i + 2]) <= 0) {
      p.erase(p.begin() + i + 1);
      if (i > 1) i -= 2;
      else i = -1;
    }
  }
}

int main()
{
  double x, y;
  std::vector<Point> points;
  while (std::cin >> x >> y) {
    points.push_back(Point(x, y));
  }

  Graham(points);

  for (Point& p : points) {
    p.View();
  }
}