#include <iostream>
#include "../algorithms/binarysearch/binarySearch.h"
#include "../../lib/eulerlib.h"

int main(int argc, char *argv[])
{
    std::shared_ptr<eulerlib::stringVector> words = eulerlib::getAllStringFromCSV("./test.txt");

    int position1 = SearchAlgorithms::binarySearch(words, std::string("geza"));
    int position2 = SearchAlgorithms::binarySearch(words, std::string("korte"));
    int position3 = SearchAlgorithms::binarySearch(words, std::string("geza"));
    int position4 = SearchAlgorithms::binarySearch(words, std::string("kutya"));
    int position5 = SearchAlgorithms::binarySearch(words, std::string("AAA"));
    int position6 = SearchAlgorithms::binarySearch(words, std::string("zzzzzzz"));

    std::cout << position1 << " " << position2 << " " << position3 << " " << position4 << " " << position5 << " " << position6 << std::endl;
    return 0;
}
