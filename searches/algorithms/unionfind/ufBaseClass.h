#ifndef UF_BASE_H
#define UF_BASE_H

#include <iostream>

class ufBase {
	protected :
		int count;
		int * idArray;
	public :
		ufBase(){};
		ufBase(int size);
		virtual ~ufBase() { delete [] idArray; };
		int getSiteCount() { return count; } ;
		bool connected(int p, int q) { return find(p) == find(q); } ;
		virtual int find(int p) = 0;
		virtual void unite(int p, int q) = 0;
};
#endif

