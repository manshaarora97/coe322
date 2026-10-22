#include <cmath>
#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::println;

class Point {
private:
  float x,y;
public:
  Point(float in_x, float in_y) {
    x = in_x; y = in_y; };
  Point() = default;
  float dx(Point q) {return x-q.x;}
  float dy(Point q) {return y-q.y;}
  void shift(float sx, float sy) { x += sx; y += sy; }
  float distance_to_origin() {
    return sqrt(x*x + y*y);
  };
  float angle() {
    return std::atan(y/x);
  };
  float distanceAns(Point q) {
    float dx = x-q.x, dy = y-q.y;
    return sqrt(dx*dx + dy*dy);
  };
  std::string as_string() const {
    return std::format("({}, {})", x,y);
  };
};

class DynRectangle {
private:
  shared_ptr<Point> bottomLeft, topRight;
public:
  DynRectangle(shared_ptr<Point> bl, shared_ptr<Point> tr)
    : bottomLeft(bl), topRight(tr) {};
  float area() {
    float width  = topRight->dx(*bottomLeft);
    float height = topRight->dy(*bottomLeft);
    return width*height;
  };
};

int main() {

  auto p1 = make_shared<Point>(1.0, 1.0);    // P
  auto p2 = make_shared<Point>(5.0, 7.0);    // Q (shared corner)
  auto p3 = make_shared<Point>(10.0, 12.0);  // R

  DynRectangle r1(p1, p2);   // Q is top-right of r1
  DynRectangle r2(p2, p3);   // Q is bottom-left of r2

  println("Before: r1 area={}, r2 area={}", r1.area(), r2.area());

  // shift the shared middle point
  p2->shift(1, 2);

  println("After:  r1 area={}, r2 area={}", r1.area(), r2.area());

  return 0;
}
