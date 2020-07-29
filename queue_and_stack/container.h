#ifndef CSZCONTAINER_H
#define CSZCONTAINER_H

#include <iostream>
#include <stdexcept>

#include "element.h"

namespace CsZ_Container_Exception
{
  enum ExceptionType {QUEUE_EMPTY = 0, STACK_EMPTY};
}

template <class T>
class Container { 
  private:
    void deleteFirst();
    void deleteLast();
		Element<T> *first;
		Element<T> *last;
		int size;

	protected: 
    void setLast(Element<T> *e);
    T getLast();   // read and delete
    T getFirst();  // read and delete
    Container();
    ~Container();

	public: 
		int getSize() const;
		bool isEmpty();

		class iterator
                {
                        private:
                                Element<T>* ptr_;
                        public:
                                explicit iterator(Element<T>* ptr) : ptr_(ptr) { }
                                iterator operator++() { iterator i = *this; ptr_ = ptr_->getNext(); return i; }
                                iterator operator++(int junk) { ptr_ = ptr_->getNext(); return *this; }
                                T operator*() { return ptr_->getData(); }
                                bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
                                bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }
                };

                iterator begin()
                {
                        return iterator(first);
                }

                iterator end()
                {
                        return iterator(NULL);
                }

		class const_iterator
                {
                        private:
                                Element<T>* ptr_;
                        public:
                                explicit const_iterator(Element<T>* ptr) : ptr_(ptr) { }
                                const_iterator operator++() { iterator i = *this; ptr_ = ptr_->getNext(); return i; }
                                const_iterator operator++(int junk) { ptr_ = ptr_->getNext(); return *this; }
                                const T operator*() { return ptr_->getData(); }
                                bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
                                bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }
                };

                const_iterator begin() const
                {
                        return iterator(first);
                }

                const_iterator end() const
                {
                        return iterator(NULL);
                }
};

template <class T>
Container<T>::Container()
{
  first = NULL;
  last = NULL;
  size = 0;
  return;
}

template <class T>
Container<T>::~Container()
{
  while(!isEmpty())
    deleteFirst();

  return;
}

template <class T>
int Container<T>::getSize () const 
{ 
	return size;
}

template <class T>
bool Container<T>::isEmpty()
{
	return (size == 0 );
}

template <class T>
void Container<T>::setLast(Element<T> *e)
{
  if(last)
    last->setNext(e);

  if(!first)
    first = e;

  e->setPrevious(last);
  last = e;
  size++;
  return;
}

template <class T>
T Container<T>::getFirst()
{
  if (size == 0) {
    throw CsZ_Container_Exception::QUEUE_EMPTY;
  }

  // remove Container<T>::first in queue
  T retVal = first->getData();
  deleteFirst();
  return retVal;
}

template <class T>
void Container<T>::deleteFirst()
{
  if(size > 1)
  {
    Element<T> *removableFirst = first;
    first = Container<T>::first->getNext();
    first->setPrevious(NULL);
    delete removableFirst;
  }
  else
    delete first;

  size--;
  return;
}

template <class T>
T Container<T>::getLast()
{
  if (size == 0) {
    throw CsZ_Container_Exception::STACK_EMPTY;
  }

  T retVal = last->getData();
  deleteLast();
  return retVal;
}

template <class T>
void Container<T>::deleteLast()
{
  if(size > 1)
  {
    Element<T> *removableLast = last;
    last = Container<T>::last->getPrevious();
    last->setNext(NULL);
    delete removableLast;
  }
  else
    delete first;

  size--;
  return;
}

#endif
