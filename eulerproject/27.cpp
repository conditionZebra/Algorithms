#include <iostream>
#include "../lib/eulerlib.h"

int countResult(int n, int a, int b)
{
  return ((n*n) + (a * n) + b);
}

int main()
{
  bool resultIsPrime = true;
  int primeCounter;
  int maxPrimeNumber = 0;
  int result = 0;

  for(int a = -1000; a < 1000; a++)
  //for(int a = -79; a <= -79; a++)
  {
    for(int b = -1000; b <= 1000; b++)
    //for(int b = 258; b <= 1601; b++)
    {
      primeCounter = 0;
      resultIsPrime = true;
//      std::cout << a << " " << b << std::endl;
      for(int n = 1; resultIsPrime; n++)
      {
        if(eulerlib::isPrime(countResult(n,a,b)))
        {
          primeCounter++;
          if(primeCounter > maxPrimeNumber)
          {
            maxPrimeNumber = primeCounter;
            result = a * b;
            std::cout << "a: " << a << " b: " << b << " n: " << n << std::endl;
          }
        }
        else
        {
          resultIsPrime = false;
        }
      }
    }
  }
  std::cout << result << std::endl;
  return 0;
}
