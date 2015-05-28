#include <stdio.h>
#include <stdlib.h>

int maxSeq(int * array, int n) {
  if(n>0)
    {
      int count, temp_count;
      count=1;
      temp_count=1;
      for(int i=0; i<n-1; i++)
	{
	  if(array[i+1]>array[i])
	    {
	      temp_count++;
	      if(count<temp_count)
		{
		  count=temp_count;
		}
	    }
	  else
	    {
	      temp_count=1;
	    }
	}
      return count;
    }
  else
  return 0;
}

void doTest(int * array, int n) {
  printf("maxSeq(");
  if (array == NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (int i =0; i < n; i++) {
      printf("%d", array[i]);
      if (i < n -1) {
	printf(", ");
      }
    }
    printf("}");
  }
  printf(", %d) is \n", n);
  int ans = maxSeq (array, n);
  printf("%d\n", ans);
}

int main(void) {
  int array1[] = { 1, 2, 3, 2, 4, 6, 9, 11, 13, 13, 15, 1, 2, 3, 2, 1};
  int array2[] = { -100, -99, -98, -97, -96, -95, -94};
  int array3[] = { 1, 1, 2, 3, 5, 8, 13, 8, 5, 4, 1, 2, 3,9};
  int array4[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};

  doTest (array1, 16);
  doTest (array2, 7);
  doTest (array3, 14);
  doTest (array4, 9);
  doTest (NULL, 0);
  doTest (array1, 0);
  
  return EXIT_SUCCESS;
}
