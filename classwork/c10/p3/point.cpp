#include "point.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Point::move(double dx,double dy)
{
  x +=dx;
  y +=dy;
}


double Point::distanceFrom(const Point &p)
{
  
  double temp;
  temp=(x-p.getX())*(x-p.getX()) + ((y-p.getY())*(y-p.getY()));
  temp=sqrt(temp);
  return temp;
}
