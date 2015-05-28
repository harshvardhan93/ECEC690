#include "IntArray.h"
#include <assert.h>
#include <ostream>
#include <cstdlib>
IntArray::IntArray() {
  data=NULL;
  numElements=0;
  
}
IntArray::IntArray(int n) {
  data = new int[n];
  numElements=n;
}

IntArray::IntArray(const IntArray & rhs)  {
  numElements=rhs.numElements;
  data=new int[numElements];
  for(int i=0;i<numElements;i++)
    {
      data[i]=rhs.data[i];
    }
}
IntArray::~IntArray() {
  delete[] data;
}

IntArray & IntArray::operator=(const IntArray & rhs) {
  if(this != &rhs)
    {
      delete[] data;
      numElements=rhs.numElements;
      data=new int[numElements];
      for(int i=0;i<numElements;i++)
	{
	  data[i]=rhs.data[i];
	}
    }
      return *this;

}
const int & IntArray::operator[](int index) const {
  assert((index>=0 && index< numElements)!=0);
      return data[index];
  /* else
    {
      std::cout<<"Index out of bounds!"<<"\n";
      }*/
}
int & IntArray::operator[](int index) {
  assert((index>=0 && index< numElements)!=0);
      return data[index];
    
      /* else
    {
      cout<<"Index out of bounds!"<<"\n";
      }*/
}

int IntArray::size() const {
  return numElements;
}

bool IntArray::operator==(const IntArray & rhs) const {
  if(numElements==rhs.numElements)
    {
      for(int i=0;i<numElements;i++)
	{
	  if(data[i]!=rhs.data[i])
	    {
	      return false;
	    }
	}
      return true;
    }
  else
    {
      return false;
    }
}

bool IntArray::operator!=(const IntArray & rhs) const {
  return !(*this == rhs);
}

std::ostream & operator<<(std::ostream & s, const IntArray & rhs) {
  //  using namespace IntArray;
  //  IntArray intArray(rhs);
  s<<"{";
  for(int i=0;i<rhs.size();i++)
    {
      s<<rhs[i];
      if(i!=(rhs.size()-1))
	{
	  s<<", ";
	}
    }
  s<<"}";
  /* else if(i==rhs.size()-1)
	{
	  s<<" "<<rhs[i]<<"}";
	}
     else
       {
	 s<<" "<<rhs[i]<<",";
       }
       }*/
  return s;
}
