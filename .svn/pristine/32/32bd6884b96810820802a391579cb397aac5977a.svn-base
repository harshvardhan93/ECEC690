#include "circle.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "point.h"

/*Circle::Circle(Point _p, double _r)
{
  p = _p;
  radius = _r;
  }*/

void Circle::move(double dx, double dy)
{
  p.move(dx,dy);
}

double Circle::intersectionArea(const Circle & otherCircle)
{
  Point p1=otherCircle.getpoint();
  double area;
  double x1,y1,r1,x2,y2,r2,d;
  r1=radius;
  r2=otherCircle.getradius();
  x1=p.getX();
  x2=p1.getX();
  y1=p.getY();
  y2=p1.getY();
  d=p.distanceFrom(p1);

  if(r1<0 || r2<0)
    {
      fprintf(stderr,"Negative radius not possible!");
      return 0;
    }
  else {

  if(r1>r2)
    {
      if(d>=r1+r2)
	{
	  area=0;
	  return area;
	}
      if((d+r2)<=r1)
	{
	  area= (3.14159)*(r2)*(r2);
	  return area;
	}
      if((d+r2)>r1)
	{
	  double part1 = r2*r2*acos((d*d + r2*r2 - r1*r1)/(2*d*r2));
	  double part2 = r1*r1*acos((d*d + r1*r1 - r2*r2)/(2*d*r1));
	  double part3 = 0.5*sqrt((-d+r2+r1)*(d+r2-r1)*(d-r2+r1)*(d+r1+r2));
	  area= part1+part2-part3;
	  return area;
	}
    }
 else if(r1<r2)
    {
      if(d>=r1+r2)
	{
	  area=0;
	  return area;
	}
      if((d+r1)<=r2)
	{
	  area= (3.14159)*(r1)*(r1);
	  return area;
	}
      if((d+r1)>r2)
	{
	  double part1 = r1*r1*acos((d*d + r1*r1 - r2*r2)/(2*d*r1));
	  double part2 = r2*r2*acos((d*d + r2*r2 - r1*r1)/(2*d*r2));
	  double part3 = 0.5*sqrt((-d+r1+r2)*(d+r1-r2)*(d-r1+r2)*(d+r1+r2));
	  area= part1+part2-part3;
	  return area;
	}
    }

 else
   {
     if(d>=r1+r2)
       {
	 area=0;
	 return area;
       }
     if(d>0 && d<r1+r2)
       {
	 double part1 = r1*r1*acos((d*d + r1*r1 - r2*r2)/(2*d*r1));
	  double part2 = r2*r2*acos((d*d + r2*r2 - r1*r1)/(2*d*r2));
	  double part3 = 0.5*sqrt((-d+r1+r2)*(d+r1-r2)*(d-r1+r2)*(d+r1+r2));
	  area= part1+part2-part3;
	  return area;
       }
     if(d==0){
     area=3.14159*r1*r1;
     return area;
     }
   }
  return 0;
  }
}  
