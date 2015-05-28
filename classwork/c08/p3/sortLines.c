#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
  for(int i=0;i<count;i++)
    {
      printf("%s",data[i]);
    }
   for(int i=0;i<count;i++)
	  {
	    free(data[i]);
	  }
  free(data);
  
}

int main(int argc, char ** argv) {
  char **array;
  size_t num=0;
  char *line=NULL;
  size_t n=0;
  if(argc == 1)
    {
      array=NULL;
	while((getline(&line,&num,stdin))!=-1)
	  {
	    if(*line=='\n')
	      break;
	    n++;
	    array=realloc(array,n*sizeof(*array));
	    array[n-1]=line;
	    num=0;
	  }
	sortData(array,n);
		free(line);
    }
  if(argc>1)
    {
      for(int i=1;i<argc;i++)
	{
	  FILE *f = fopen(argv[i],"r");
	  if(f!=NULL)
	    {
      num=0;
      line=NULL;
      n=0;
      array=NULL;
      while((getline(&line,&num,f))!=-1)
	  {
	
	    n++;
	    array=realloc(array,n*sizeof(*array));
	    array[n-1]=line;
	    num=0;
	  }
	sortData(array,n);
		free(line);
	    }
	  else
	    {
	      fprintf(stderr,"File couldn't open");
	      return EXIT_FAILURE;
	    }
	  if(fclose(f)!=0)
	    {
	      fprintf(stderr,"Failed to close file!");
	      return EXIT_FAILURE;
	    }
	}
    }
  if(n==0)
    {
      fprintf(stderr,"File is empty!!");
      return EXIT_FAILURE;
      }

 
  return EXIT_SUCCESS;
}
