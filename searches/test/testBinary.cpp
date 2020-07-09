#include <iostream>
#include "../algorithms/binarysearch/binarySearch.h"
#include "../../lib/eulerlib.h"

int main(int argc, char *argv[])
{
    using bs =  SearchAlgorithms::BinarySearch<std::string>;
    std::shared_ptr<eulerlib::stringVector> words = eulerlib::getAllStringFromCSV("./test.txt");

    int position1 = bs::search(words, std::string("geza"));
    int position2 = bs::search(words, std::string("korte"));
    int position3 = bs::search(words, std::string("alma"));
    int position4 = bs::search(words, std::string("kutya"));
    int position5 = bs::search(words, std::string("AAA"));
    int position6 = bs::search(words, std::string("zzzzzzz"));

    std::cout << position1 << " " << position2 << " " << position3 << " " << position4 << " " << position5 << " " << position6 << std::endl;
    return 0;
}
