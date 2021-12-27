#include "../lib/eulerlib.h"
#include <iostream>

int main()
{
  eulerlib::divisorMap* currentDivisors; 
  std::map<long long int,int>::iterator currit;
  bool found = false;
  int result = 1;
  int counter = 1;
  int numOfDivisors = 0;

  while(!found)
  {
    numOfDivisors = 1;
    currentDivisors = eulerlib::getDivisors(result);

    for(currit = currentDivisors->begin(); currit != currentDivisors->end(); ++currit)
    {
      numOfDivisors *= (currit->second + 1);
    }

    if(numOfDivisors >= 500)
    {
      std::cout << result << std::endl;
      found = true;
    }
    counter++;
    result += counter;;
  }

  return 0;
}
