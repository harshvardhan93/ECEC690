#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
struct _rectangle {
  int x;
  int y;
  int width;
  int height;
};

typedef struct _rectangle rectangle;

rectangle canonicalize(rectangle r) 
{
  if(r.width<0)
    {
      r.x=r.x+r.width;
      r.width=(-1)*r.width;
    }
  if(r.height<0)
    {
      r.y=r.y+r.height;
      r.height=(-1)*r.height;
    }
  return r;
    
}

rectangle intersection(rectangle r1, rectangle r2) {
  r1= canonicalize(r1);
  r2= canonicalize(r2);	                       
  rectangle temp;
  temp.x=0;
  temp.y=0;
  temp.width=0;
  temp.height=0;
  int count=0;
  for(int i=(min (r1.x,r2.x)); i<=(max ((r1.x+r1.width),(r2.x+r2.width))); i++)/* run a loop from min to max value of x for r1 and r2*/
    {
      for(int j=r1.x; j<=r1.x+r1.width; j++) /* run a loop from r1's value of x to its max value of x */
	{
	  for(int k=r2.x; k<=r2.x+r2.width; k++) /*run a loop from r2's value of x to its maximum value of x*/
	    {
	      if(i==j) /* to check whether i is a value in r1 and r2*/
		{
		  if(i==k)
		    {
		      if(count==0) 
			{
			  temp.x=i; /* to set the starting point of intersection */
			  count++;
			  break;
			}
		      else
			{
			  count++;
			  break;
			}/* we are using count to calcuate the width and the value of width will be one less than the count since we exclude the first value*/
		    }
		}
	    }
	}
    }
  
  if(count==0)
    {
      r1.x=0;
      r1.width=0;
      r1.y=0;
      r1.height=0;
      goto end;
    }
  else
    {
      r1.width=count-1;
      r1.x=temp.x;
    }
  
      count=0;

      for(int i=(min (r1.y,r2.y)); i<=(max ((r1.y+r1.height),(r2.y+r2.height))); i++) /* run a loop from min to max value of y for r1 and r2*/
    {
      for (int j=r1.y; j<=r1.y+r1.height; j++)  /* run a loop from r1's value of y to its max value of y */
	{
	  for(int k=r2.y; k<=r2.y+r2.height; k++)  /*run a loop from r2's value of y to its maximum value of y*/
	    {
	      if(i==j)  /* to check whether i is a value in r1 and r2*/
		{
		  if(i==k)
		    {
		      if(count==0)
			{
			  temp.y=i;  /* to set the starting point of intersection */
			  count++;
			  break;
			}
		      else
			{
			  count++;
			  break;
			}/* we are using count to calcuate the height and the value of height will be one less than the count since we exclude the first value*/
		    }
		}
	    }
	}
    }
       if(count>0)
	 {
	 r1.height=count-1;
	 r1.y=temp.y;
	 }
       else
	 {
	   r1.y=0;
	   r1.height=count;/* to calculate the height of the intersecting part*/
	   r1.x=0;
	   r1.width=0;
	   goto end;
	 }
       
 end: return r1;
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
