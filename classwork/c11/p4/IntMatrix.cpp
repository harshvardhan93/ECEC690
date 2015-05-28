#include "IntMatrix.h"
IntMatrix::IntMatrix(){
  numRows=0;
  numColumns=0;
  rows=NULL;
  // *rows=NULL;
}
IntMatrix::IntMatrix(int r, int c) {
  numRows=r;
  numColumns=c;
  rows = new IntArray*[r];
  for(int i=0;i<numRows;i++)
    {
      rows[i]=new IntArray(numColumns);
    }
}
IntMatrix::IntMatrix(const IntMatrix & rhs)  {
  numRows=rhs.numRows;
  numColumns=rhs.numColumns;
  rows = new IntArray*[numRows];
  for(int i=0;i<numRows;i++)
    {
      rows[i]=new IntArray(numColumns);
      (*this)[i]=rhs[i];
    }
  /* for(int i=0;i<numRows;i++)
    {
      for(int j=0;j<numColumns;j++)
	{
	  (*rows[i])[j]= rhs[i][j];
	}
	}*/
}
IntMatrix::~IntMatrix() {
  for(int i=0;i<numRows;i++)
    {
      delete rows[i];
      }
  delete[] rows;
}
IntMatrix &IntMatrix::operator=(const IntMatrix & rhs) {
  if(this!=&rhs){
    for(int i=0;i<numRows;i++)
      {
	delete[] rows[i];
      }
    delete[] rows;
    numRows=rhs.numRows;
    numColumns=rhs.numColumns;
    rows = new IntArray*[numRows];
    for(int i=0;i<numRows;i++)
    {
      rows[i]=new IntArray(numColumns);
      (*this)[i]= rhs[i];
    }
    /* for(int i=0;i<numRows;i++)
    {
      for(int j=0;j<numColumns;j++)
	{
	  (*rows[i])[j] = rhs[i][j];
	}
	}*/
  }
  return *this;
}
int IntMatrix::getRows() const {
  return numRows;
}
int IntMatrix::getColumns() const {
  return numColumns;
}
const IntArray & IntMatrix::operator[](int index) const {
  assert((index>=0 && index<numRows)!=0);
  return *(rows[index]);
}
IntArray & IntMatrix::operator[](int index){
  assert((index>=0 && index<numRows)!=0);
  return *(rows[index]);
}



bool IntMatrix::operator==(const IntMatrix & rhs) const {
  if(numRows==rhs.numRows)
    {
      if(numColumns==rhs.numColumns)
	{
	  for(int i=0;i<numRows;i++)
	    {
	      if(*rows[i]==rhs[i])
	      continue;

	      else
		return 0;
	    }
	  return 1;
	}
      else
	return 0;
    }
  else
    return 0;
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {
  assert(((numRows==rhs.numRows) && (numColumns==rhs.numColumns))!=0);
  IntMatrix temp(numRows,numColumns);// = rhs;
  for(int i=0;i<temp.numRows;i++)
    {
      for(int j=0;j<temp.numColumns;j++)
	{
	  temp[i][j] = rhs[i][j] + (*this)[i][j];
	}
    }
  return temp;
}

std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
  s<<"[ ";
  for(int i=0;i<rhs.getRows();i++)
    {
      if(i<rhs.getRows()-1)
	s<<rhs[i]<<","<<"\n";
      else
	s<<rhs[i];
    }
  s<<" ]";
  return s;
}
