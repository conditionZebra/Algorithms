#ifndef UF_QUICK_UNION_H
#define UF_QUICK_UNION_H

#include "ufBaseClass.h"

class ufQuickUnion : public ufBase {
	public :
		ufQuickUnion(int size) : ufBase(size) {}
		int find(int p);
		void unite(int p, int q);
};
#endif

