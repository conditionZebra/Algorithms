#include "../lib/eulerlib.h"
#include <iostream>
#include <chrono>
#include <list>
#include <cmath>

int main()
{
  auto start = std::chrono::steady_clock::now();

  long long int barrier = 2000000;

  std::list<bool> primes(barrier,true);
  std::list<bool>::iterator pi = primes.begin();
  std::list<bool>::iterator negator;
  long long int position = 0;
  long long int currentPrime;
  long long int result = 0;

  *pi = false;
  pi++;
  currentPrime = 2;;

  while(pi != primes.end())
  {
    if(*pi == true)
    {
      negator = primes.begin();
      std::advance(negator,(currentPrime * currentPrime) - 1);
      position = (currentPrime * currentPrime) - 1;

      while(negator != primes.end() && position < primes.size())
      {
        if( position < primes.size())
        {
          *negator = false;
          std::advance(negator,currentPrime);
        }
        position += currentPrime;
      }
    }
    currentPrime++;
    pi++;
    if(currentPrime >= sqrt(barrier))
      break;
  }

  pi = primes.begin();

  int i = 1;
  while(pi != primes.end())
  {
    if(*pi)
      result += i;
    pi++;
    i++;
  }

  std::cout << result << std::endl;

  std::cout << "Elapsed time in seconds: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count()
       << " millisec" << std::endl;

  return 0;
}
