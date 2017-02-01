#include <iostream>
#include <vector>
#include "result.h"

class ufExecutor {
	public :
		ufResult execute(int argc, char* argv[]);
	private :
		std::vector<unsigned long> &split(const std::string &s, char delim, std::vector<unsigned long> &elems);
};
