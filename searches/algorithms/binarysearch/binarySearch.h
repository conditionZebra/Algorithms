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
  class BinarySearch {
    private:
      BinarySearch();
      static int worker (std::shared_ptr<std::vector<T>> , int, int, T);
    
    public:
      static int search (std::shared_ptr<std::vector<T>>, T);

  };

template <class T>
int BinarySearch<T>::worker (std::shared_ptr<std::vector<T>> searchedVector, int lowerBound, int upperBound, T searchedItem)
{
  if((*searchedVector)[upperBound] == searchedItem)
    return upperBound;
  else if((*searchedVector)[lowerBound] == searchedItem)
    return lowerBound;

  if(upperBound - lowerBound <= 1)
	  return -1;
    
  int middle = (lowerBound + upperBound) / 2;
  
  if((*searchedVector)[middle] == searchedItem)
    return middle;

  if((*searchedVector)[middle] < searchedItem)
    return worker(searchedVector, middle + 1, upperBound, searchedItem);
  if((*searchedVector)[middle] > searchedItem)
    return worker(searchedVector, lowerBound, middle - 1, searchedItem);

  return -1;
};

template <class T>
int BinarySearch<T>::search (std::shared_ptr<std::vector<T>> searchedVector, T searchedItem)
{ 

  int lowerBound = 0;
  int upperBound = (*searchedVector).size() - 1;
  return BinarySearch<T>::worker(searchedVector, lowerBound, upperBound, searchedItem);

}

}	// end namespace SearchAlgorithms 
#endif //CSZ_BINARY_SEARCH_ALGO_H
