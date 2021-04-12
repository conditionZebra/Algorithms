#include "../lib/eulerlib.h"
#include <iostream>

int main()
{
  eulerlib::divisorMap allDivisors; //eulerlib::getDivisors(600851475143); 
  eulerlib::divisorMap* currentDivisors; 
  std::map<long long int,int>::iterator currit;
  std::map<long long int, int>::iterator allit;
  bool found = false;
  int result = 1;

  for (int i = 2; i <= 20; i++)
  {
    currentDivisors = eulerlib::getDivisors(i);

    for(currit = currentDivisors->begin(); currit != currentDivisors->end(); ++currit)
    {
      found = false;
      for(allit = allDivisors.begin(); allit != allDivisors.end(); ++allit)
      {
        if(currit->first == allit->first)
        {
          if(currit->second > allit->second)
          {
            allDivisors[currit->first] = currit->second;
            continue;
          }
          found = true;
        }
      }
      if(!found)
        allDivisors[currit->first] = currit->second;
    } 
  }
  
  for(allit = allDivisors.begin(); allit != allDivisors.end(); ++allit)
    for(int i = 0; i < allit->second; i++)
      result *= allit->first;

  std::cout << result << std::endl;
  return 0;
}
