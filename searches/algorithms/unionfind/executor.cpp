#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "ufQuick.h"
#include "ufQuickUnion.h"
#include "ufWeighted.h"
#include "result.h"
#include "executor.h"

// -std=c++0x needed to compile
#include <memory>
#include <chrono>

std::vector<unsigned long>& ufExecutor::split(const std::string &s, char delim, std::vector<unsigned long> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(atoi(item.c_str()));
    }
    return elems;
}

ufResult ufExecutor::execute(int argc, char* argv[])
{
	ufResult res;
	res.numberOfComponents = -1;
	res.executinonTime = -1;
	res.errorCode = 0;

	auto begin_time = std::chrono::high_resolution_clock::now();

	if(argc == 1)
	{
		std::cout << "Need an input file, like http://algs4.cs.princeton.edu/15uf/tinyUF.txt" << std::endl;
		res.errorCode = 1;
		return res;
	}

	std::string algorithm;
	if(argc == 3)
	{
		algorithm = argv[2];

		if(algorithm != "quick" && algorithm != "quickunion" && algorithm != "weighted")
		{
			std::cout << "Second parameter must be quick or quickunion or weighted." << std::endl;
			res.errorCode = 2;
			return res;
		}
	}
		

	std::ifstream infile(argv[1]);
	if(!infile.good())
	{
		std::cout << "Input file error." << std::endl;
		res.errorCode = 3;
		return res;
	}
		
        std::string line;
        char delimiter = ' ';

	std::vector<unsigned long> currentRow;
	std::unique_ptr<ufBase> ufb;

	std::getline(infile, line);
	split(line, delimiter, currentRow);

	if(currentRow.size() == 1)
	{
		if(algorithm == "quick")
			ufb.reset(new ufQuickUnion(currentRow[0]));
		else if(algorithm == "quickunion")
			ufb.reset(new ufQuickUnion(currentRow[0]));
		else
			ufb.reset(new ufWeighted(currentRow[0]));
	}
	else
	{
		std::cout << "First line must be the problem size." << std::endl;
		res.errorCode = 4;
		return res;
	}


        while (std::getline(infile, line))
	{
		currentRow.clear();
		split(line, delimiter, currentRow);

		if(currentRow.size() != 2)
		{
			std::cout << "Too many integers in input line!" << std::endl;
			for(uint i = 0; i < currentRow.size(); i++)
				std::cout << currentRow[i] << " ";
			std::cout << std::endl;
			res.errorCode = 5;
			return res;
		}

		if(ufb->connected(currentRow[0], currentRow[1]))
			continue;

		ufb->unite(currentRow[0], currentRow[1]);
	}
	
	auto end_time = std::chrono::high_resolution_clock::now();

	res.numberOfComponents = ufb->getSiteCount();
	res.executinonTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count();

	return res;
}
