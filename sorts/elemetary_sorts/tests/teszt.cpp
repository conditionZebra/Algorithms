#include <memory>
#include <chrono>
#include <vector>
#include <iostream>
#include "../elementarySorts.h"	

#include <QApplication>
#include "simple_function_x_y_mw.h"

#define PROBLEMSIZE 15000

int getRand(int steps)
{
    return rand() % steps;
}

int main(int argc, char *argv[]) {

    std::shared_ptr<std::vector<int>> numberList(new std::vector<int>);
    std::vector<double> *x = new std::vector<double>;
    std::vector<double> *y = new std::vector<double>;

    x->push_back(0);
    y->push_back(0);

    int longestRunTime = 0;

    for(int steps = 2000; steps <= PROBLEMSIZE; steps += 2000)
    {
        std::cout << steps  << std::endl;
        // Fill the list...
        for (int i = 0; i < steps; i++)
            numberList->push_back(i + 1);

        srand(time(NULL));

        // ...shuffle it...
        int a, b, temp;
        for (int i = 0; i < steps; i++)
        {
            a = getRand(steps);
            b = getRand(steps);
            temp = (*numberList)[a];
            (*numberList)[a] = (*numberList)[b];
            (*numberList)[b] = temp;
        }

        // ...then sort and measure sorting time.
        auto begin_time = std::chrono::high_resolution_clock::now();
        SortingAlgorithms::selectionSortBothWay(numberList);
        //SortingAlgorithms::selectionSort(numberList);
        auto end_time = std::chrono::high_resolution_clock::now();

        // ... and store current problem size, execution time.
        x->push_back(steps);
        y->push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count());
        // ... update longest run time for correct graph Y axis size
        longestRunTime = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - begin_time).count();

        // Clear the vector to the next run.
        numberList->clear();
    }

    // Printout the result
    for(unsigned int i = 0; i < x->size(); i++)
    {
        std::cout << (*x)[i] << " " << (*y)[i] << std::endl;
    }

    // Dislpay the result.
    QApplication qapp(argc, argv);
    MainWindow w(x, y, PROBLEMSIZE, longestRunTime);
    w.show();
    return qapp.exec();
} 
