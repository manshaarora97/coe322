#include <cmath>
#include <memory> 
//practice object oriented

class Point {
private:
  float x,y;
public:
  Point(float in_x, float in_y) {
    x = in_x; y = in_y; }; //initialize values of r and phi
  /*storing all values independently is not a good idea becuase they are dependent on each other
  do not store redundant data */
  Point() = default;
  float dx(Point q) {return x-q.x;}
  float dy(Point q) {return y-q.y;}

  std::string as_string() const {
    return std::format("({}, {})", x,y);
  };
};
  
  float distance_to_origin() {
    return sqrt(x*x + y*y);
      };
  float angle() {
    return std::atan(y/x); 
  };
  float distance(float p_x, float p_y, float q_x, float q_y) {
    return sqrt((std::pow(p_x-q_x, 2), std::pow(p_x-p_y, 2)));

  };

  float distanceAns(Point q) {
    float dx = x-q.x, dy = y-q.y;
    return sqrt(dx*dx + dy*dy);

  };

  float dx(point q) {return x-q.x} 


  float halfway(Point p, Point q) {
    
};

class Point_new {
private:
  float x,y;

public:
  Point_new(float in_x, float in_y)  x(in_x), y(in_y) {
    //constructor no return type, function w name of class 
  }
}


  
int main() {
  Point p1(1.0, 1.0);
  float d = p1.distance_to_origin();
  float a = p1.angle(1.0, 1.0);
  Point p(1.0, 2.0);
  Point q(2.0, 3.0);
  Point p2(2,2);
}


#include "pointclass::hpp"

  Point Point::scale(float a) {
    Point scaledpoint(this->x*a, y*a);
    return scaledpoint;
  };




 class Rectangle {
 private:
   float x_size, y_size; 
     public:
   Rectangle(Point botleft, float width, float height) : x{width}, y{height} bottomlef{bl};
   Rectangle(Point bl, Point tr) : bottomleft{bl}, topright{tr};
   float area() {
     return (x_size*y_size);
   };

   float rightedge_x() {
     return botleft_xvalue() + width;

   };

   float point_to_rectangle() {
     
  class DynRectangle {
     private:
    float width, height;
    Shared_point bottomLeft, bottomRight; 
     public:
    DynRectangle(Shared_point<Point> bl, shared_point<Point> tr)
      : bottomleft(bl), topright(tr) {}; 

#if 0 // pre processor directive commenting out code you may need in the future but excludes from being compiled 
    float area() {
      float width = (*tr.).dx-bl.dx; //preffered is tr->getx()-bl.getx(); 
      float height =(*tr.)dy-bl.dy; 
      return width*height;
    };

    float rightedge_x() {
      return bottomleft.xvalue() + width;
    };
    #endif
  };

  int main() {

    origin = make_shared<Point>(0,0);
    fivetwo = make_shared<Point>(5,2);
    DynRectangle r(p1,p2);
    println("Area={}, r.area() );


    return 0;
  } 
	 
