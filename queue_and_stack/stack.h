#ifndef CSZSTACK_H
#define CSZSTACK_H

#include <iostream>
#include <stdexcept>

#include "container.h"

template <class T>
class Stack : public Container<T>{ 

	public: 
		void push(T const&);
		T pop();
};

template <class T>
void Stack<T>::push(T const& data) 
{ 
	this->setLast(new Element<T>(data));
	return;
} 

template <class T>
T Stack<T>::pop () 
{ 
  T retVal;
  try
  {
	  retVal = this->getLast();
  }
  catch (CsZ_Container_Exception::ExceptionType e)
  {
    if (CsZ_Container_Exception::STACK_EMPTY)
      throw "Stack<>::pop(): empty stack";
    else
      throw "Stack<>::pop(): unknown exception";
  }
	return retVal;
} 

#endif
