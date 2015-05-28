#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include "point.h"
// #include "point.cpp"
class Circle {
  Point p;
  const double radius;

 public:
 Circle(Point _p, double _r): p(_p), radius(_r) {}
  double intersectionArea(const Circle & otherCircle); 
  double getradius() const {return radius; } 
  void move(double dx, double dy);
  Point getpoint() const { return p;}
};

#endif
