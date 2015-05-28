#ifndef __T_ARRAY_H___
#define __T_ARRAY_H___
#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>

template<typename T>
class array {
 private:
  T * data;
  int numElements;
 public:
  array(){
    data=NULL;
    numElements=0; }
  array(int n){
   
    numElements=n;
    data=new T[numElements]; 
  }
  array(const array<T> & rhs)
    {
      numElements=rhs.numElements;
      data=new int[numElements];
      for(int i=0;i<numElements;i++)
	{
	  data[i]=rhs.data[i];
	}
 
    }
  ~array() {
    delete[] data;
  }
  array<T> & operator=(const array<T> & rhs) {
    if(this != &rhs)
      {
	delete[] data;
	numElements=rhs.numElements;
	data=new T[numElements];
	for(int i=0;i<numElements;i++)
	  {
	    data[i]=rhs.data[i];
	  }
      }
    return *this;
  }

  T & operator[](int index) {
    assert(index<numElements);
    return  data[index];   
 
  }
  const T & operator[](int index) const {
    assert(index<numElements);
    return  data[index];   
  
  }
  int size() const {
    return numElements;
  }
  bool operator==(const array<T> & rhs) const {
    int count=0;  
    if(this->numElements==rhs.numElements)
      {
	for(int i=0;i< this->numElements;i++)
	  {
	    if(data[i]==rhs.data[i])
	      {count++;
	      }
	  }
        if(count==this->numElements)
          {return 1;
          }
        else
          return 0;
      }
    else
      return 0;

  }
  bool operator!=(const array<T> & rhs) const {
    return ! ((*this) == rhs);
  }
 
}; 
template<typename T>
std::ostream & operator<<(std::ostream & s, const array<T> & rhs) {
  for(int i=0;i<rhs.size();i++)
    {
      if(i==0)
	s << "{" << rhs[i] << ", ";
      else if(i==rhs.size()-1)
	s <<rhs[i] << "}";
      else
	{
	  s << rhs[i] << ", ";
	}
    }
  return s;
}

#endif
