#include <stdio.h>
#include <stdlib.h>

struct _point_t {
  long x;
  long y;
};

typedef struct _point_t point_t;
typedef point_t vector_t;

//start: the point to start from
//directions: the (backwards) directions (as an array)
//n: how many directions are in the array directions
void follow(vector_t * final, vector_t * v, int *n,int *i) {
  if(*n>0)
    {
      final[*i].x = (final[*i-1].x)+((-1)*v[*n-1].x);
      final[*i].y = (final[*i-1].y)+((-1)*v[*n-1].y);
      if(*n==1)
	{
	  printf("Go to (%ld,%ld)\n",final[*i].x,final[*i].y);
	  printf("Food at (%ld,%ld)\n",final[*i].x,final[*i].y);
	}
      else
	{
	  printf("Go to (%ld,%ld)\n",final[*i].x,final[*i].y);
	}
      *n = *n - 1;
      *i = *i + 1;
      follow(final,v,n,i);
    }
  
}

//given a line (e.g. ("3,4") convert it to a vector_t
/*vector_t lineToPoint(char * line) {
  vector_t temp;
  temp.x=strtol(line,&line,10);
  line++;
  temp.y=strtol(line,&line,10);
  return temp;
}*/

//given a FILE *f, read all the lines.
//v is the memory allocated to hold all the previous lines
// (as an array of vector_t)s
//n points at an int, which says how many items are already in v.
//that is *n is the length of v.
// this function will update *n whenever it reads more items,
// so that when it returns to its original caller, the int
// whose address was passed in will indicate the lenght of the
// returned array
vector_t * readVector(FILE * f, vector_t * v, int * n,int *flag) {
  long a,b;
  char *string;
  size_t numbers=100;
  string=(char *)malloc(numbers);
  if((getline(&string,&numbers,f))!=-1)
    {
      if(2!=sscanf(string,"%ld,%ld",&a,&b))
	{
	  fprintf(stderr,"Invalid input!\n");
	  *flag+=1;
	}
	vector_t temp;
	temp.x=a;
	temp.y=b;
	// temp=lineToPoint(string);
      v[*n]=temp;
      *n = *n+1;
      readVector(f,v,n,flag);
    }
  free(string);
  return v;
  }

int main(int argc, char ** argv) {
  vector_t vec[100],fin[100];
  vector_t * final=vec;
  vector_t * v=fin;
  int n=0,flag=0;
  FILE *f = fopen(argv[1],"r");
  if(f==NULL)
    {
      fprintf(stderr,"Couldnot open files\n");
      return EXIT_FAILURE;
    }
  v = readVector(f,v,&n,&flag);
  if(flag>0)
    {
      return EXIT_FAILURE;
      }
  int i=1;
  final[0].x = (-1)*(v[n-1].x);
  final[0].y = (-1)*(v[n-1].y);
  if(i==n)
    printf("Food at (%ld,%ld)\n",final[0].x,final[0].y);
  else {
  n=n-1;
  printf("Go to (%ld,%ld)\n",final[0].x,final[0].y);
  follow(final,v,&n,&i);
  }
  if(fclose(f)!=0)
    {
      fprintf(stderr,"Couldnot close the file");
      return EXIT_FAILURE;
    }
}
