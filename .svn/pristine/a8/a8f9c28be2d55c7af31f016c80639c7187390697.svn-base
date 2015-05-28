#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  
  counts_t *c = createCounts();
  FILE *f = fopen(filename,"r");
  if(f==NULL)
    {
      fprintf(stderr,"Couldn't open File!");
      return NULL;
    }
  char *line=NULL;
    char *value=NULL;
    size_t num=0;
    char *temp=NULL;
  while(getline(&line,&num,f)!=-1)
    {
      temp=strchr(line,'\n');
      *temp='\0';
      value=lookupValue(kvPairs,line);
      addCount(c,value);
      free(line);
      value=NULL;
      temp=NULL;
      //      free(temp);
      num=0;
    }
  // free(value);
  free(line);   
  if(fclose(f)!=0)
    {
      fprintf(stderr,"Couldn't close file!");
    return NULL;
    }
  return c;
}

int main(int argc, char ** argv) {
  int i;
  if(argc<=2)
    {
      fprintf(stderr,"The no. of inputs are less");
      return EXIT_FAILURE;
    }
  kvarray_t *kv=readKVs(argv[1]);
  if(kv->length==-1)
    {
      printf("Couldn't open file!");
      return EXIT_FAILURE;
    }
  if(kv->length==-2)
    {
      printf("Couldn't close file");
      return EXIT_FAILURE;
    }

  //WRITE ME (plus add appropriate error checking!)
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  for(i=2;i<argc;i++) {
    counts_t *c=countFile(argv[i],kv); //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    char *outName = computeOutputFileName(argv[i]);//compute the output file name from argv[i] (call this outName)
    FILE *f = fopen(outName,"w");//open the file named by outName (call that f)
    printCounts(c,f);//print the counts from c into the FILE f
    if(fclose(f)!=0)
      {
	fprintf(stderr,"Couldn't close file!");
	return EXIT_FAILURE;
      }//close f
    free(outName);
    freeCounts(c); //free the memory for outName and c
    }
  freeKVs(kv); //free the memory for kv
  return EXIT_SUCCESS;
}
