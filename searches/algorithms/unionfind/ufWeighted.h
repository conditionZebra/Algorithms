#ifndef UF_WEIGHTED_H
#define UF_WEIGHTED_H

#include "ufBaseClass.h"

class ufWeighted : public ufBase {
	private :
		int * componentSizeArray;
	public :
		ufWeighted(int size);
		~ufWeighted();
		int find(int p);
		void unite(int p, int q);
};
#endif

