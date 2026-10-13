#include <cmath>

class Point {
private:
  float x,y;
public:
  // constructor:
  // same name as the class
  // no return type
  Point(float in_x,float in_y) {
    x = in_x; y= in_y; };
  // scaling function
  // function name "scale"
  // input parameter "a"
  // return type "Point"
  Point scale( float a ) {
    Point scaledpoint(x*a,y*a);
    return scaledpoint;
  };
  // stuff from last time
  float distance_to_origin() {
    return sqrt( x*x + y*y );
  };
  float dx( Point q ) { return x-q.x; }
  float distance( Point q ) {
    float dx = x-q.x, dy = y-q.y; // or use dx function
    return sqrt( dx*dx + dy*dy );
  };
  float angle() {
    return std::atan(y/x);
  };

  float halfway(Point P, Point Q) {
    float p_x = x-P.x, Q_x = x-Q.x;
    float P_y = y-P.y, Q_y = y-Q.y;

    float half_x = (p_x + Q_x)/2;
    float half_y = (P_y + Q_y)/2;

    return (half_x, half_y); 
};

int main() {
  Point p1(1.0,1.0);
  Point p2(2,2);

  float dpq = p1.distance(p2);

  float d = p1.distance_to_origin();
  float a = p1.angle( );

  Point P (1,2.2);
  Point Q(3.2, 5.6);
  return 0;
}
