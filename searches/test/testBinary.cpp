#include <iostream>
#include "../algorithms/binarySearch.h"
#include "../../../euler/lib/eulerlib.h"

int main(int argc, char *argv[])
{
    std::shared_ptr<eulerlib::stringVector> words = eulerlib::getAllStringFromCSV("./szom.txt");

    int position1 = SearchAlgorithms::binarySearch(words, std::string("accreditation"));
    int position2 = SearchAlgorithms::binarySearch(words, std::string("accretion"));
    int position3 = SearchAlgorithms::binarySearch(words, std::string("9th"));
    int position4 = SearchAlgorithms::binarySearch(words, std::string("a"));
    int position5 = SearchAlgorithms::binarySearch(words, std::string("AAA"));
    int position6 = SearchAlgorithms::binarySearch(words, std::string("zzzzzzz"));

    std::cout << position1 << " " << position2 << " " << position3 << " " << position4 << " " << position5 << " " << position6 << std::endl;
    return 0;
}
