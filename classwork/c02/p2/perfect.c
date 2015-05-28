#include<stdio.h>
#include<stdlib.h>


int isPerfect(int x)
{
  int count=0;
  for(int i=1;i<x;i++)
    {
      if(x%i==0)
	{
	  count=count+i;
	}
    }
  return count;
}

int main(void)
{
  int number,check;
 
  for(number=1;number<10000;number++)
    {
      
      check=isPerfect(number);
      if(number==check)
	{
	  printf("%d is perfect!\n",number);
	}
    }
return EXIT_SUCCESS;
}
  
