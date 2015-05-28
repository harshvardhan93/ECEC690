#include<iostream>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<sstream>
class Expression {
 public:
  Expression() {}; 
 virtual std::string toString() const =0;
 virtual ~Expression() {};
};

class NumExpression : public Expression { 
 private: long number1;
 public:
  NumExpression(long num) {
    number1=num;
  }
  std::string toString() const { 
    std::stringstream str1;
    str1<<number1;
    std::string str;
    str1>>str;
    return str;
  }
  ~NumExpression() {};
};

class PlusExpression : public Expression {
  private:
  std::string num1;
  std::string num2;
 public:
  PlusExpression(Expression * lhs, Expression *rhs)
    {
      num1 = lhs->toString();
      num2 = rhs->toString();
      delete lhs;
      delete rhs;
    }
  std::string toString() const {
    std::stringstream str1;
    std::string s;
    str1<<'(';
    str1<<num1;
    str1<<" ";
    str1<<"+";
    str1<<" ";
    str1<<num2;
    str1<<')';
    s = str1.str(); 
      return s;
  }

  ~PlusExpression() {
  }
};
