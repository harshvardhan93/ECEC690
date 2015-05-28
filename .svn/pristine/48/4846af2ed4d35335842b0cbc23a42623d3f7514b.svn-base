#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include<assert.h>
#include<string>
//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify ittemplate<typename T> class Sort;

int main(int argc, char ** argv) {
  std::vector<std::string> str;
  int count=0;
  if(argc==1)
    {
      
      // vector<string> data;
      std::string s;
      // int count=0;
      while(std::getline(std::cin,s))
	  {
	if(!std::cin.good()) {
	std::cin.clear();
	std::string badinput;
	std::getline(std::cin, badinput);
	std::cout<<"oops!"<<badinput<<"wasn't a valid input\n"<<std::endl;
	}
	/*if(strlen(s)==0)
	      {
		continue;
		}*/
	    str.push_back(s);
	    count++;
	  }
      std::sort(str.begin(),str.end());
	for(int i=0;i<count;i++)
	  {
	    std::cout<<str[i]<<std::endl;
	  }
	return EXIT_SUCCESS;
    }
  if(argc>1)
    {
      for(int i=1;i<argc;i++)
	{
	  count=0;
	  // int count=0;
	  // std::vector<std::string> data;
	  std::ifstream f(argv[i]);
	  if(f.good()) {
	    std::string s;
	    while(std::getline(f,s))
	    {
     
	      str.push_back(s);
	      count++;
	      
	    }
	    std::sort(str.begin(),str.end());
	  for(int i=0;i<count;i++)
	    {
	      std:: cout<<str[i]<<std::endl;
	    }
	  str.erase(str.begin(),str.end());
	  }
	  else
	    {
	      std::cout<<"File couldn't open"<<std::endl;
	      return EXIT_FAILURE;
	    }
	  
	  f.close();
	  /* if(f.fail())
	  {
	      std::cout<<"File couldn't close!"<<std::endl;
	      return EXIT_FAILURE;
	      }*/  
	}
    }
  return EXIT_SUCCESS;

}
	  
