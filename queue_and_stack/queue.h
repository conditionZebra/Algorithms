#ifndef CSZQUEUE_H
#define CSZQUEUE_H

//#include <iostream>
#include <stdexcept>

#include "element.h"

using namespace std;

template <class T>
class Queue { 
	private: 
		Element<T> *first;
		Element<T> *last;
		int size;
		void deleteFirst();

	public: 
		Queue();
		~Queue();
		void enqueue(T const&);
		T dequeue();
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
Queue<T>::Queue() 
{
	first = NULL;
	last = NULL;
	size = 0;
	return;
} 

template <class T>
Queue<T>::~Queue() 
{
	while(!isEmpty())
		deleteFirst();

	return;
}

template <class T>
void Queue<T>::enqueue(T const& data) 
{ 
    // append copy of passed element 
	Element<T> *e = new Element<T>(data,NULL,NULL);
	if(last)
		last->setNext(e);

	if(!first)
		first = e;	

	last = e;
	size++;

	return;
} 

template <class T>
T Queue<T>::dequeue () 
{ 
	if (size == 0) { 
		throw out_of_range("Queue<>::dequeue(): empty queue"); 
	}

	// remove first in queue 
	T retVal = first->getData();
	deleteFirst();
	return retVal;
} 

template <class T>
int Queue<T>::getSize () const 
{ 
	return size;
}

template <class T>
void Queue<T>::deleteFirst () 
{
	if(size > 1)
	{
		Element<T> *removableFirst = first;
		first = first->getNext();
		first->setPrevious(NULL);
		delete removableFirst;
	}
	else
		delete first;

	size--;
	return;
}

template <class T>
bool Queue<T>::isEmpty()
{
	return (size == 0 );
}

#endif
