#include <stdio.h>
#include <stdlib.h>
#include "code.h"

int main(void) {

  int a[] = {1,2,15};
  int n=3;
  int v=10;
  f(a,n,v);
  int a1[] = {1,2,3,4};
  n=5;
  v=6;
  f(a1,n,v);
  int a2[] = {15,3,6};
  n=3;
  v=5;
  f(a2,n,v);
  int a3[]= {15,14};
  n=2;
  v=10;
  f(a3,n,v);
  int a4[]= {5,5};
  n=2;
  v=5;
  f(a4,n,v);
  int a5[] = {5};
  n=1;
  v=3;
  f(a5,n,v);
  int a6[] = {1,2,5,5};
  n=4;
  v=5;
  f(a6,n,v);
  int a7[] = {2,7,3,5,5};
  n=5;
  v=4;
  f(a7,n,v);
  //WRITE TESTS HERE FOR THE CODE


#ifdef REPORT_COVERAGE
  reportPathCoverage();
#endif
  return EXIT_SUCCESS;
}
