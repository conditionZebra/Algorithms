#include "../lib/eulerlib.h"
#include <iostream>

int main()
{
  int counter = 1;
  int currentNumber = 3;
  while(true)
  {
    if(eulerlib::isPrime(currentNumber))
    {
      counter++;
      if(counter == 10001)
      {
        std::cout << currentNumber << std::endl;
        return 0;
      }
    }
    currentNumber += 2;
  }
  return 0;
}
