#include "ufQuick.h"

int ufQuick::find(int p)
{
	return idArray[p];
}

void ufQuick::unite(int p, int q)
{
	int pID = find(p);
	int qID = find(q);
	
	if(pID == qID)
		return;

	for(int i = 0; i < arraySize; i++)
		if(idArray[i] == pID)
			idArray[i] = qID;
	count--;
	return;
}
