#include<iostream>
#include<cstdlib>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<sstream>
#include<stdlib.h>


class Expression {
 public: 
 Expression() {}; 
 virtual std::string toString() const =0;
 virtual long evaluate() const = 0;
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
  long evaluate() const {
    return number1;
  }
  ~NumExpression() {};
};

class PlusExpression : public Expression {
  private:
  std::string num1;
  std::string num2;
  long t1;
  long t2;
  Expression * _lhs;
  Expression * _rhs;
 public:
  PlusExpression(Expression * lhs, Expression *rhs)
    {
      //      t1 = std::atol(lhs->toString().c_str());
      // t2 = std::atol(lhs->toString().c_str());
      _lhs=lhs;
      _rhs=rhs;
      num1 = _lhs->toString();
      num2 = _rhs->toString();
      t1=_lhs->evaluate();
      t2=_rhs->evaluate();
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
  long evaluate() const {
    long ans=0;
    ans=t1+t2;
    return ans;
  }
  ~PlusExpression() {
    delete _lhs;
    delete _rhs;
 }
};

class MinusExpression : public Expression {
  private:
  std::string num1;
  std::string num2;
  long t1;
  long t2;
  Expression * _lhs;
  Expression * _rhs;
 public:
  MinusExpression(Expression * lhs, Expression *rhs)
    {
      // t1 = std::atol(lhs->toString().c_str());
      // t2 = std::atol(lhs->toString().c_str());
      _lhs=lhs;
      _rhs=rhs;
      num1 = _lhs->toString();
      num2 = _rhs->toString();
      t1=_lhs->evaluate();
      t2=_rhs->evaluate();		       
      // delete lhs;
      // delete rhs;
    }
  std::string toString() const {
    std::stringstream str1;
    std::string s;
    str1<<'(';
    str1<<num1;
    str1<<" ";
    str1<<"-";
    str1<<" ";
    str1<<num2;
    str1<<')';
    s = str1.str(); 
      return s;
  }
  long evaluate() const {
    long ans=0;
    ans=t1-t2;
    return ans;
  }
  ~MinusExpression() {
    delete _lhs;
    delete _rhs;
 }
};

class TimesExpression : public Expression {
  private:
  std::string num1;
  std::string num2;
  long t1;
  long t2;
   Expression * _lhs;
  Expression * _rhs;
 public:
  TimesExpression(Expression * lhs, Expression *rhs)
    {
      // t1 = std::atol(lhs->toString().c_str());
      // t2 = std::atol(lhs->toString().c_str());
      _lhs=lhs;
      _rhs=rhs; 
      num1 = _lhs->toString();
      num2 = _rhs->toString();
      t1=_lhs->evaluate();
      t2=_rhs->evaluate();
      // delete lhs;
      // delete rhs;
    }
  std::string toString() const {
    std::stringstream str1;
    std::string s;
    str1<<'(';
    str1<<num1;
    str1<<" ";
    str1<<"*";
    str1<<" ";
    str1<<num2;
    str1<<')';
    s = str1.str(); 
      return s;
  }
  long evaluate() const {
    long ans=0;
    ans=t1*t2;
    return ans;
  }
  ~TimesExpression() {
    delete _lhs;
    delete _rhs;
 }
};

class DivExpression : public Expression {
  private:
  std::string num1;
  std::string num2;
  long t1;
  long t2;
  Expression * _lhs;
  Expression * _rhs;
 public:
  DivExpression(Expression * lhs, Expression *rhs)
    {
      // t1 = std::atol(lhs->toString().c_str());
      // t2 = std::atol(lhs->toString().c_str());
      _lhs=lhs;
      _rhs=rhs;
      num1 = _lhs->toString();
      num2 = _rhs->toString();
      t1=_lhs->evaluate();
      t2=_rhs->evaluate();
      // delete lhs;
      // delete rhs;
    }
  std::string toString() const {
    std::stringstream str1;
    std::string s;
    str1<<'(';
    str1<<num1;
    str1<<" ";
    str1<<"/";
    str1<<" ";
    str1<<num2;
    str1<<')';
    s = str1.str(); 
      return s;
  }
  long evaluate() const {
    long ans=0;
    ans=t1/t2;
    return ans;
  }
  ~DivExpression() {
    delete _lhs;
    delete _rhs;
  }
};
