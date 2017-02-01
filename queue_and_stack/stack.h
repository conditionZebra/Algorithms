#ifndef CSZSTACK_H
#define CSZSTACK_H

//#include <iostream>
#include <stdexcept>

#include "element.h"

using namespace std;

template <class T>
class Stack { 
	private: 
		Element<T> *first;
		Element<T> *last;
		int size;
		void deleteLast();

	public: 
		Stack();
		~Stack();
		void push(T const&);
		T pop();
		int getSize() const;
		bool isEmpty();

		class iterator
                {
                        private:
                                typedef Element<T>* elementPointer;
                                elementPointer ptr_;
                        public:
                                iterator(elementPointer ptr) : ptr_(ptr) { }
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
                                typedef Element<T>* elementPointer;
                                elementPointer ptr_;
                        public:
                                const_iterator(elementPointer ptr) : ptr_(ptr) { }
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
Stack<T>::Stack() 
{
	first = NULL;
	last = NULL;
	size = 0;
	return;
} 

template <class T>
Stack<T>::~Stack() 
{
	while(!isEmpty())
		deleteLast();

	return;
}

template <class T>
void Stack<T>::push(T const& data) 
{ 
	Element<T> *e = new Element<T>(data,NULL,NULL);
	if(last)
	{
		last->setNext(e);
		e->setPrevious(last);
	}

	if(!first)
		first = e;	

	last = e;
	size++;

	return;
} 

template <class T>
T Stack<T>::pop () 
{ 
	if (size == 0) { 
		throw out_of_range("Stack<>::pop(): empty stack"); 
	}

	T retVal = last->getData();
	deleteLast();
	return retVal;
} 

template <class T>
int Stack<T>::getSize () const 
{ 
	return size;
}

template <class T>
void Stack<T>::deleteLast () 
{
	if(size > 1)
	{
	
		Element<T> *removableLast = last;
		last = removableLast->getPrevious();
		last->setNext(NULL);
		delete removableLast;
	}
	else
		delete last;

	size--;
	return;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return (size == 0 );
}

#endif
