#ifndef CSZELEMENT_H
#define CSZELEMENT_H

using namespace std;

template <class T>
class Element { 
	private:
		T data;
		Element<T>* previous;
		Element<T>* next;
	public: 
		Element(T t, Element<T> *p = NULL, Element<T> *n = NULL);
		T getData();
//TODO: const!!!
		Element<T>* getPrevious();
		Element<T>* getNext();
		void setNext( Element<T> *e);
		void setPrevious( Element<T> *e);
};

template <class T>
Element<T>:: Element(T t, Element<T> *p, Element<T> *n) :
	data(t),
	previous(p),
	next(n)
{
	if(p)
		p->setNext(this);

	if(n)
		n->setPrevious(this);

	return;
}

template <class T>
void Element<T>:: setNext(Element<T> *e)
{
	next = e;
	return;
}

template <class T>
void Element<T>:: setPrevious(Element<T> *p)
{
	previous = p;
	return;
}
template <class T>
Element<T>* Element<T>:: getPrevious()
{
	return previous;
}

template <class T>
Element<T>*  Element<T>:: getNext()
{
	return next;
}

template <class T>
T Element<T>:: getData()
{
	return data;
}
#endif
