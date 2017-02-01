#ifndef UF_QUICK_H
#define UF_QUICK_H

#include "ufBaseClass.h"

class ufQuick : public ufBase {
		int arraySize;
	public :
		ufQuick(int size) : ufBase(size) , arraySize(size){}
		int find(int p);
		void unite(int p, int q);
};
#endif

