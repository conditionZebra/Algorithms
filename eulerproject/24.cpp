#include "../lib/eulerlib.h"
#include <iostream>
#include <vector>

int main()
{
  int portion = 0;
  int currentDigitPosition = 0;

  int missingPart = 1000000 - 1;  // 0 is the first permutation, and that counts also
  std::vector<int> elements;
  for (int i = 0; i < 10 ; i++)
    elements.push_back(i);

  while(elements.size() > 0)
  {
    portion = eulerlib::getFactorial(elements.size() - 1); 
    currentDigitPosition = (missingPart / portion);
    std::cout << elements[currentDigitPosition];
    elements.erase(elements.begin() + currentDigitPosition);
    missingPart -= currentDigitPosition * portion;
  }

  std::cout << std::endl;

  return 0;
}
