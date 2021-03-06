#include <stdio.h>
#include <stdlib.h>

int checkprime(int n)
{
  int temp=1;
  for(int i=2;i<n;i++)
    {
      if(n%i==0)
	{
	  temp=0;
	  break;
	}
      else
	temp=1;
    }
  return temp;
}
     
void printFactors(int n) {
  int i,bool;
  if(n<1)
    {
      printf("Factoristion not possible\n");
    }
  else if (n==1)
    {
      printf("\n");
    }
  else
    {
      while(n>1)
	{
	  for(i=2;i<=n;i++)
	    {
	      bool=checkprime(i);
	      if(bool==1 && n%i==0)
		{
		  n=(n/i);
		  printf("%d",i);
		  if(n>1)
		    printf(" * ");
		  break;
		}
	    }
	  
	}
      printf("\n");
    }
}

int main(void) {
  printf("Factorization of 1:\n");
  printFactors(1);
  printf("Factorization of 60:\n");
  printFactors(60);
  printf("Factorization of 132:\n");
  printFactors(132);
  printf("Factorization of 11726:\n");
  printFactors(11726);
  printf("Factorization of 2169720:\n");
  printFactors(2169720);
  printf("Factorization of 1789220887:\n");
  printFactors(1789220887);
  return EXIT_SUCCESS;
}
