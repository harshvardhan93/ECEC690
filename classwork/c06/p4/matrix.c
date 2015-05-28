#include<stdio.h>
#include<stdlib.h>

void rotatematrix(char matrix[10][10])
{
  for(int j=0;j<10;j++)
    {
      for(int i=9;i>=0;i--)
	{
	  fprintf(stdout,"%c",matrix[i][j]);
	}
      fprintf(stdout,"\n");
    }
}


void getmatrix(FILE *f,char matrix[10][10])
{ 
  char c;
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<=10;j++)
      {
	  if((c = fgetc(f))!='\n') 
	    {
	    matrix[i][j]=c;
	  }
	}
    }
 
  rotatematrix(matrix);
}


int main(int argc, char ** argv)
{
  char matrix[10][10];
  FILE *f=fopen(argv[1],"r");
  if(f == NULL)
    {
      fprintf(stderr,"Could not open file");
      return EXIT_FAILURE;
    }

  getmatrix(f, matrix);

  if(fclose(f)!=0)
    {
      fprintf(stderr,"Failed to close file!");
      return EXIT_FAILURE;
    }
  return EXIT_SUCCESS;
}
      
    
