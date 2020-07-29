#ifndef CSZQUEUE_H
#define CSZQUEUE_H

//#include <iostream>
#include <stdexcept>

#include "container.h"

template <class T>
class Queue : public Container<T>{ 

	public: 
		void enqueue(T const&);
		T dequeue();
};

template <class T>
void Queue<T>::enqueue(T const& data) 
{ 
  this->setLast(new Element<T>(data));
	return;
} 

template <class T>
T Queue<T>::dequeue () 
{ 
  T retVal;
  try
    {
      retVal = this->getFirst();
    }
    catch (CsZ_Container_Exception::ExceptionType e)
    {
      if (e == CsZ_Container_Exception::QUEUE_EMPTY)
        throw "Queue<>::dequeue(): empty queue";
      else
        throw "Queue<>::dequeue(): unknown exception";
    }

	return retVal;
} 

#endif
