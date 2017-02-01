#include "ufWeighted.h"

ufWeighted::ufWeighted(int size)
{
        count = size;
        idArray = new int [size];
	componentSizeArray = new int [size];

        for(int i = 0; i < size; i++)
                idArray[i] = i;
        for(int i = 0; i < size; i++)
                componentSizeArray[i] = 1;
}

ufWeighted::~ufWeighted()
{
	delete [] componentSizeArray;
}

int ufWeighted::find(int p)
{
	while (p != idArray[p])
                p = idArray[p];
        return p;
}

void ufWeighted::unite(int p, int q)
{
	int i = find(p);
        int j = find(q);

        if(i == j)
                return;

	if(componentSizeArray[i] < componentSizeArray[j])
	{
		idArray[i] = j;
		componentSizeArray[j] += i;
	}
	else
	{
		idArray[j] = i;
		componentSizeArray[i] += j;
	}
        count--;
        return;
}
