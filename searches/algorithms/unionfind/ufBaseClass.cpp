#include "ufBaseClass.h"

ufBase::ufBase(int size)
{
	count = size;
	idArray = new int [size];

	for(int i = 0; i < size; i++)
		idArray[i] = i;	
}
