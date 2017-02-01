#ifndef CSZSORTALGO_H
#define CSZSORTALGO_H

#include<vector>

using namespace std;

namespace SortingAlgorithms {

    template <class T>
        void selectionSort (std::shared_ptr<std::vector<T>> sortableVector)
        { 

            T smallest;
            int smallestPosition;

            for (unsigned int i = 0; i < sortableVector->size(); i++)
            {
                smallest = (*sortableVector)[i];
                smallestPosition = i;
                for(unsigned int j = i + 1; j < sortableVector->size(); j++)
                {
                    if((*sortableVector)[j] < smallest)
                    {
                        smallest = (*sortableVector)[j];
                        smallestPosition = j;
                    }
                }

                (*sortableVector)[smallestPosition] = (*sortableVector)[i];
                (*sortableVector)[i] = smallest;
            }
            return;
        }

    template <class T>
        void selectionSortBothWay (std::shared_ptr<std::vector<T>> sortableVector)
        { 

            T smallest, biggest;
            int smallestPosition;
            int biggestPosition;

            for (unsigned int i = 0; i < sortableVector->size() / 2 ; i++)
            {
                smallest = (*sortableVector)[i];
                biggest = (*sortableVector)[i];
                smallestPosition = i;
                biggestPosition = i;

                for(unsigned int j = i + 1; j < sortableVector->size() - i; j++)
                {
                    if((*sortableVector)[j] < smallest)
                    {
                        smallest = (*sortableVector)[j];
                        smallestPosition = j;
                    }
                    if((*sortableVector)[j] > biggest)
                    {
                        biggest = (*sortableVector)[j];
                        biggestPosition = j;
                    }
                }

                (*sortableVector)[smallestPosition] = (*sortableVector)[i];
                (*sortableVector)[i] = smallest;
                (*sortableVector)[biggestPosition] = (*sortableVector)[sortableVector->size() - i];
                (*sortableVector)[sortableVector->size() - i] = biggest;
            }
            return;
        }

}	// end namespace SortingAlgorithms
#endif //CSZSORTALGO
