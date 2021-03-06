#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  
  kvarray_t *kva=malloc(sizeof(*kva));
  kva->length=0;
  kva->array=NULL;
  char *line=NULL;
  size_t num=0;
      FILE *f = fopen(fname,"r");
      if(f==NULL)
      {
	kva->length=-1;
	return kva;
      }
      line=NULL;
      while((getline(&line,&num,f))!=-1)
	{
	 kva->length++; 
	 num=0;
	 free(line);
	}
      kva->array=malloc(kva->length*sizeof(kvpair_t));
      free(line);
      line=NULL;
      rewind(f);
      int count=0;
      char *temp,*temp1;
	  while((getline(&line,&num,f))!=-1)
	    {
     
	      if(*line=='\n')
		break;
	      temp=strchr(line,'=');
	      *temp='\0';
	      temp++;
	      temp1=strchr(temp,'\n');
	      *temp1='\0';
	      /* kva->array[i].key=malloc((strlen(temp)+1)*sizeof(char *));
	      kva->array[i].value=malloc((strlen(temp1)+1)*sizeof(char *));
	      */
	      kva->array[count].key=strdup(line);
	      kva->array[count].value=strdup(temp);
	      count++;
	      num=0;
	      temp--;
	      *temp='=';
	      *temp1='\n';
	      temp=NULL;
	      temp1=NULL;
	      free(line);
	    }
	  // free(temp);
	  // free(temp1);
	  //	  line=NULL;
	  free(line);
      if(fclose(f)!=0)
	{
	  kva->length=-2;
	  return kva;
	}
      return kva;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0;i<pairs->length;i++)
    {
      free(pairs->array[i].key);
      free(pairs->array[i].value);
    }
  free(pairs->array);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  int len;
  len=pairs->length;
  for(int i=0;i<len;i++)
    {
      printf("key = '%s' value = '%s'\n",pairs->array[i].key,pairs->array[i].value);
      
    }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  int len=pairs->length;
  for(int i=0;i<len;i++)
    {
      if(strcmp(pairs->array[i].key,key)==0)
	{
	  return pairs->array[i].value;
	    }
 
    }
  return NULL;
}
  
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  //WRITE ME                                                                                                                                                                         

  kvarray_t *kva=malloc(sizeof(*kva));
  kva->length=0;
  kva->array=NULL;
  char *line=NULL;
  size_t num=0;
  FILE *f = fopen(fname,"r");
  while((getline(&line,&num,f))!=-1)
    {
      kva->length++;
      num=0;
    }
  kva->array=malloc(kva->length*sizeof(kvpair_t));
  free(line);
  line=NULL;
  int count=0;
  rewind(f);
  while((getline(&line,&num,f))!=-1)
    {

      if(strlen(line)==0)
	break;
      char *temp=strchr(line,'\0');
      *temp='\0';
      temp++;
      char *temp1=strchr(temp,'\n');
      *temp1='\0';

      int len1=strlen(line);
      int len2=strlen(temp);
      kva->array[count].key=malloc((len1+1)*sizeof(char));
      kva->array[count].value=malloc((len2+1)*sizeof(char));

      strcpy(kva->array[count].key,line);
      strcpy(kva->array[count].value,temp);
      kva->array[count].key[len1]='\0';
      kva->array[count].value[len2]='\0';
      count++;
      temp--;
      *temp='=';
      *temp1='\n';
      num=0;
    }
  line=NULL;
  free(line);
*/
