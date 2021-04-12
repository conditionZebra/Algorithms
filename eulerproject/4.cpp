#include "../lib/eulerlib.h"
#include <iostream>

int main()
{
  int lowerLimit = 0;
  int biggestPalindrome = 0;
  long temp = 0;

  for(int i = 999; i > lowerLimit; i--)
    for(int j = i ; j > 0; j--)
    {
      temp = i * j;
      if (eulerlib::isPalindrome(temp))
          {
            if(temp > biggestPalindrome)
              biggestPalindrome = temp;
            lowerLimit = j;
            continue;
          }
    }

    std::cout << biggestPalindrome <<  std::endl;

  return 0;
}
