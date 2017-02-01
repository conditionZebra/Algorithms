#ifndef CSZ_BINARY_SEARCH_ALGO_H
#define CSZ_BINARY_SEARCH_ALGO_H

#include <vector>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <memory>

using namespace std;

namespace SearchAlgorithms {

template <class T>
int binarySearch1 (std::shared_ptr<std::vector<T>> searchedVector, int lowerBound, int upperBound, T searchedItem)
{ 

 if(upperBound - lowerBound <= 1)
  {
    if((*searchedVector)[upperBound] == searchedItem)
      return upperBound;
    else if((*searchedVector)[lowerBound] == searchedItem)
      return lowerBound;
    else
      return -1; 
  }

  int middle = (lowerBound + upperBound) / 2;
  
  if((*searchedVector)[middle] == searchedItem)
    return middle;
  if((*searchedVector)[middle] < searchedItem)
    return binarySearch1(searchedVector, middle + 1, upperBound, searchedItem);
  if((*searchedVector)[middle] > searchedItem)
    return binarySearch1(searchedVector, lowerBound, middle - 1, searchedItem);
}

template <class T>
int binarySearch (std::shared_ptr<std::vector<T>> searchedVector, T searchedItem)
{ 

  int lowerBound = 0;
  int upperBound = (*searchedVector).size() - 1;
  return binarySearch1(searchedVector, lowerBound, upperBound, searchedItem);

}

}	// end namespace SearchAlgorithms 
#endif //CSZ_BINARY_SEARCH_ALGO_H
