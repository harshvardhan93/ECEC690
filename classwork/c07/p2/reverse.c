#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void reverse(char *a)
{
  if(*a!='\n')
    {
      a++;
      reverse(a);
      a--;
      printf("%c",*a);
    }
}

int main(int argc, char **argv)
{
  char a[500];
  char *str;
  while((str = fgets(a,500,stdin))!=NULL)
    {					      
      if(str!=NULL)
	{
	  reverse(str);
	  printf("\n");
	}
    }
  return EXIT_SUCCESS;
}

	     
