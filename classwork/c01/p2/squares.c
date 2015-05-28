#include <stdio.h>
#include <stdlib.h>

int  max(int a, int b, int c)
{
  int temp=b+c;
  if(a>temp)
    return a;
  else
    return temp;
}
void newline(void)
{
  printf("\n");
}


void squares(int size1, int x_offset, int y_offset, int size2) {
  
  int w = max(size1, x_offset, size2);
  int h = max(size1, y_offset, size2);

  for(int y=0; y<h; y++)//count from 0 to h. Call the number you count with y
    {
      for(int x=0; x<w; x++)//count from 0 to w. Call the number you count with x
	{
	  if((((x>=x_offset)&&(x<(x_offset+size2))) && (y==y_offset || y==(y_offset+size2-1))) || (((y>=y_offset)&&(y<(y_offset+size2))) && ((x==x_offset) || x==(x_offset+size2-1))))
	    {
	      printf("*");
	    }
	  else if(((x< size1)&&(y==0 || y==size1-1)) || ((y<size1)&&(x==0 || x==(size1-1))))
	    {
	      printf("#");
	    }
	  else
	    printf(" ");
	}
      printf("\n");
    }
      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *

      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #

      //else print a space
    //when you finish counting x from 0 to w, 
    //print a newline

}

int main (void) {
  printf("squares(5, 2, 4, 6)\n");
  squares(6, 2, 3, 5);
  printf("squares(3, -2, -3, 5)\n");
  squares(7, -2, -1, 5);
  printf("squares(4, 4, 4, 3)\n");
  squares(4, 3, 3, 3);
}
