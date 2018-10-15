#include "NxMNumericMatrix.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <stdlib.h> 

int NxMNumericMatrix::getElement(int r, int c)
{
        // TODO check boundaries
        return data[r * rowNo + c];
} 

NxMNumericMatrix::NxMNumericMatrix(char* inputFile)
{
        std::ifstream infile(inputFile);
        std::string line;
        char delimiter = ' ';
        rowNo = 0;
        columnNo = 0;
        while (std::getline(infile, line))
        {
                rowNo++;
        }

        infile.clear();
        infile.seekg(0);
        int position = 0;
        std::string hackTemp;   // becouse newlines are not spaces
        int newLinePosition = 0;
        while (std::getline(infile, line, delimiter))
        {
                newLinePosition = line.find("\n");
                // newline handling
                // if it's between two numbers, split it and put the two numbers into the vector
                // if it's at the end, push only the one existing number into
                if(newLinePosition != std::string::npos && newLinePosition != line.size() - 1)
                {
                        hackTemp = line.substr(0, newLinePosition);
                        data.push_back(atoi(hackTemp.c_str()));
                        hackTemp = line.substr(newLinePosition + 1, line.size());
                        data.push_back(atoi(hackTemp.c_str()));
                }
                else
                        data.push_back(atoi(line.c_str()));
        }

        columnNo = data.size() / rowNo;
}
