#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <assert.h>
#include "array.h"
template <typename T>
class Matrix {
 private:
  int numRows;
  int numColumns;
  array<T> ** rows;
 public:
  Matrix(){
    numRows=0;
    numColumns=0;
    rows=NULL; 

  } 
  Matrix(int r, int c) {
    numRows = r;
    numColumns = c;
    rows = new array<T>*[numRows];
    for (int i = 0; i < numRows; i++) {
      rows[i] = new array<T>(numColumns);
    }
  }
  Matrix(const Matrix & rhs) {
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    rows = new array<T>*[numRows];
    for (int i = 0; i < numRows; i++) {
      rows[i] = new array<T>(numColumns);
     

    }
    for(int i=0;i<numRows;i++)
      {
	*rows[i]=*rhs.rows[i];
    
      }
  }
  ~Matrix() {
    for (int i = 0; i < numRows; i++) {
      delete rows[i];
    } 
    delete[] rows;
  }
  Matrix<T> & operator=(const Matrix<T> & rhs) {
    for (int i = 0; i < numRows; i++) {
      delete rows[i];
    } 
    delete[] rows;
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    rows = new array<T>*[numRows];
    for (int i = 0; i < numRows; i++) {
      rows[i] = new array<T>(numColumns);
    }
    for(int i=0;i<numRows;i++)
      {
	*rows[i]=*rhs.rows[i];
    
      } 
    
    return *this;
  }
  int getRows() const {
    return numRows;
  }
  int getColumns() const {
    return numColumns;
  }
  const array<T> & operator[](int index) const {
    assert(index<numRows&& index>=0);
    return *rows[index];
  }
  array<T> & operator[](int index) {
    assert(index<numRows&& index>=0);
    return *rows[index];
  }
  bool operator==(const Matrix<T> & rhs) const {
    int count=0;  
    if(numRows==rhs.numRows)
      {
	if(numColumns==rhs.numColumns)
	  {
	    for(int i=0;i<numRows;i++)
	      {
		if((*rows[i])==rhs[i])
		  {
		    count++; 
		  }
	      }
	    if(count==numRows)
	      {
		return 1;
	      }
	    else
	      return 0;
	  }
	else
	  return 0;
      }
    else
      return 0;

  }
  Matrix<T> operator+(const Matrix<T> & rhs) const {
    assert ((numRows == rhs.numRows) && (numColumns == rhs.numColumns));
    Matrix<T> sum(rhs);
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numColumns; j++) {
	sum[i][j] = (*rows[i])[j]+ rhs[i][j]; 
      }
    }
    return sum       ;
  }
};

template<typename T>
std::ostream & operator<<(std::ostream & s, const Matrix<T> & rhs){
  s << "[ ";  
  for(int i=0;i<rhs.getRows();i++)
    {
      if(i==rhs.getRows()-1)
	{
	  s <<rhs[i];
	}
      else{
	s <<rhs[i]<<",\n";
      } 
    }
  s<<" ]";
  return s;
}

#endif
