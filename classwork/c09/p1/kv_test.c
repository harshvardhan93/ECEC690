#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

#define NUM_LOOKUPS 5
int main(void) {
  kvarray_t * array = readKVs("test.txt");
  if(array->length==-1)
    {
      printf("Couldn't open file!");
    }
  if(array->length==-2)
    {
      printf("Couldn't close file");
    }
  printf("Printing all keys\n\n");
  printKVs(array);
  char *tests[NUM_LOOKUPS] = {"banana", "grapes", "cantaloupe", "lettuce", "orange"};
  for (int i = 0; i < NUM_LOOKUPS; i++) {
    printf("lookupValue('%s')=%s\n", tests[i], lookupValue(array,tests[i]));
  }
  freeKVs(array);
  return EXIT_SUCCESS;
}
