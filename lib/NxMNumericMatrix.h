#ifndef NXMNUMERICMATRIX
#define NXMNUMERICMATRIX

#include <string>
#include <vector>

class NxMNumericMatrix
{
        private:
                int rowNo;
                int columnNo;
                std::vector<int> data;
        public:
                NxMNumericMatrix(char* fileName);
                int getRowNumber() {return rowNo;};
                int getColumnNumber() {return columnNo;};
                int getElement(int r, int c);
};
#endif
