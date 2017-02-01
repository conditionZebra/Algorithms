#include "ufQuickUnion.h"

int ufQuickUnion::find(int p)
{
	while (p != idArray[p])
		p = idArray[p];
	return p;
}

void ufQuickUnion::unite(int p, int q)
{
	int i = find(p);
	int j = find(q);
	
	if(i == j)
		return;

	idArray[i] = j;

	count--;
	return;
}
