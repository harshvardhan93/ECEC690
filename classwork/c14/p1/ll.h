#ifndef _LL_H_
#define _LL_H_
#include <cstdlib>
#include <exception>
#include <assert.h>
#include <stdio.h>
#include <iostream>
//YOUR CODE GOES HERE
template<typename T>
class LinkedList {
 private:
  class Node {
  public:
    T data;
    Node * next;
    Node * previous;
  Node(const T & d) : data(d), next(NULL), previous(NULL) {}
  };
  Node *head;
  Node *tail;
 public:

  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  LinkedList(const LinkedList & item) {
    head=NULL;
    tail=NULL;
    for(int i=0;i<item.getSize();i++) {
      addBack(item[i]);
    }
  }
  
  void addFront(const T &item) {
    if(head == NULL) {
	Node *temp = new Node (item);
	head = temp;
	tail = temp;
	temp->next=NULL;
	temp->previous=NULL;
    }
    if(head !=NULL) {
	Node ** curr = &head;
	Node *temp = new Node(item);
	temp->next = *curr;
	temp->previous = NULL;
	(*curr)->previous = temp;
	*curr = temp;
      }
  }
  
  void addBack(const T &item) {
    if(tail == NULL){
      Node *temp = new Node(item);
      tail = temp;
      head = temp;
      temp->next = NULL;
      temp->previous = NULL;
    }
    if(tail != NULL) {
      Node ** curr = &tail;
      Node *temp = new Node(item);
      (*curr)->next = temp;
      temp->previous = *curr;
      *curr = temp;
      temp->previous=NULL;
    }
  }

  int getSize() const{
    Node *temp =head;
    int i=1;
    if(head==NULL)
      {
	i=0;
      }
    else{
      while(temp->next!=NULL) {
	temp =temp->next;
	i++;
      }
    }
    return i;
  }

  bool remove(const T &item) {
   
    if(head==NULL)
      return false;

    Node ** curr = &head;
    while(*curr != NULL && (*curr)->data != item) {
      curr = &((*curr)->next);
     }
    if((*curr)->data!=item) {
      return false;
    }
    if((*curr)->previous == NULL) {
	  Node *temp = *curr;
	  *curr = (*curr)->next;
	  (*curr)->previous = temp->previous;
	  delete temp;
	  return true;
	}
      else if((*curr)->next == NULL) {
	Node *temp = *curr;
	*curr = (*curr)->previous;
	delete temp;
	return true;
      }
      else {
	Node *temp=*curr;
	*curr = (*curr)->next;
	(*curr)->previous=temp;
	delete temp;
	return true;
	}
}
    
 
  T& operator[](int index) {
    int count = this->getSize();
   assert(index>=0 &&  index<count); 
   Node * curr = head;
   int i=0;
    while(curr!=NULL && i!=index) {
	curr = curr->next;
	i++;
      }
      return curr->data;
  }

  const T& operator[](int index) const {
   int count = this->getSize();
   assert(index>=0 &&  index<count); 
   Node * curr = head;
   int i=0;
    while(curr!=NULL && i!=index) {
	curr = curr->next;
	i++;
      }
      return (curr->data);
 }

  int find(const T &item) {
    Node ** curr = &head;
    int index=0;

    while(*curr!=NULL && (*curr)->data!=item) {
      curr = &(*curr)->next;
      index++;
     }
    
    if(*curr == NULL) {
      index=-1;
    }
    return index;
  }

  
  ~LinkedList() {
      if(this->getSize() != 0) {
    destroy(head);
     }
      }
 
 void destroy (Node *n)
  {
    if(n!=NULL)
      {
	destroy(n->next);
	  delete n;
      }
  }
  

};
#endif
