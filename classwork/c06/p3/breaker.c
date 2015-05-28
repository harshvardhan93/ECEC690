#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void decrypt(FILE *f)
{
  int c,n, key,a, array[26],temp,count;
  a=0;
count=0;
  for (int i=0; i<26; i++)
    {
      array[i]=0;
    }
  while ((c = fgetc(f)) != EOF) {
    if(isalpha(c)) {
      count++;
      c= tolower(c);
      n= c-97;
      array[n]++;
    }
  }
  temp=array[0]; 
    for (int k=1;k<26;k++)
      {
	if(array[k]>temp){
	  temp=array[k];
	  a=k;
	}
      }

    key=0;
    a=a+97;
    /*
      c=a;
      c= c - 'a';
      c= c%26;
      key=c-'a'-'e';
    */
   key=a - 'e' ;
   if(key>=0) 
    printf("%d\n",key);
   if(key<0)
     {
       key=key+26;
       printf("%d\n",key);
     }
}
    
    
    
      
int main(int argc, char ** argv) {
  //  printf("Inside main\n");

  FILE * f = fopen(argv[1], "r");
  int count;
  count=0;
  if (f == NULL) {
    fprintf(stderr,"Could not open file");
    return EXIT_FAILURE;
  }

  fseek(f,0,SEEK_END);
  if(ftell(f)==0)
    {
      fprintf(stderr,"File is empty!\n");
      return EXIT_FAILURE;
    }
  
  fseek(f,0,SEEK_SET);

  /*while((c = fgetc(f))!= EOF)
    {
      if(isalpha(c))
	count++;
    }
  if(count==0)
    {
      fprintf(stderr,"No alphabets in the File!\n");
      return EXIT_FAILURE;
    }
  fseek(f,0,SEEK_SET);*/
  decrypt(f);
  if(fclose(f)!=0) {
    fprintf(stderr,"Failed to close the input file!");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
