#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

int getRand(int range)
{
	return (rand() % range + 1);
}

int main(int argc, char* argv[]) 
{

	srand(time(NULL));

	std::ofstream ufTestFile;

	if(argc < 3)
	{
		std::cout << "Kell ket argumentum, minimum.\n 1: nodeszam 2: kapcsolatok szama 3: adatfileok szama (1)" << std::endl;
		return 1;
	}

	int numOfNodes = atoi(argv[1]);
	int numOfConnections = atoi(argv[2]);
	int numOfDataFiles = 1;

	if(argc == 4)
	{
		numOfDataFiles = atoi(argv[3]);
	}

	int a, b;
	for(int i = 0; i < numOfDataFiles; i++)
	{
		char fullpath [9];
		char filename [3];
		strcpy (fullpath,"data/");
		sprintf(filename,"%d",i);
		strcat (fullpath,filename);
		ufTestFile.open (fullpath);

		ufTestFile << numOfNodes << std::endl;
		for(int j = 0; j < numOfConnections; j++)
		{
			a = getRand(numOfNodes);
			b = getRand(numOfNodes);
	
			ufTestFile <<  a << " " << b << std::endl;
		}
		ufTestFile.close();
	}

	return 0;
} 
