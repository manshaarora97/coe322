class Point {
private:
  float x,y;
public:
  Point(float in_x, float in_y) {
    x = in_x; y = in_y; }; //initialize values of r and phi                                                                                                                                                      
  /*storing all values independently is not a good idea becuase they are dependent on each other                                                                                                                 
  do not store redundant data */
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



 class Rectangle {
 private:
   float x_size, y_size;
     public:
   Rectangle(Point botleft, float width, float height) : x{width}, y{height} bottomlef{bl}; //constructor 1
   Rectangle(Point bl, Point tr) : bottomleft{bl}, topright{tr}; //constructor 2 
   float area() { 
     return (x_size*y_size);
   };

   float rightedge_x() {
     return botleft_xvalue() + width;

   };

   float point_to_rectangle() {



     s Rectangle {
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



       ~
