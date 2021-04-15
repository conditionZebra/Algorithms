#include <iostream>
#include <chrono>
#include <list>
#include <cmath>

int main()
{
  auto start = std::chrono::steady_clock::now();

  int barrier = 2000000;

  std::list<bool> primes(barrier,true);
  std::list<bool>::iterator primeIterator = primes.begin();
  int currentNumber = 0;
  long long int result = 0;

  std::list<bool>::iterator negator;
  int position = 0;   // to prevent overshoot primes with advancing negator

  *primeIterator = false;
  primeIterator++;
  currentNumber = 2;

  while( currentNumber < sqrt(barrier))
  {
    if(*primeIterator == true)
    {
      negator = primes.begin();
      std::advance(negator,(currentNumber * currentNumber) - 1);
      position = (currentNumber * currentNumber) - 1;

      while(position < primes.size())
      {
        *negator = false;
        std::advance(negator,currentNumber);
        position += currentNumber;
      }
    }
    currentNumber++;
    primeIterator++;
  }

  primeIterator = primes.begin();

  int i = 1;
  while(primeIterator != primes.end())
  {
    if(*primeIterator)
      result += i;
    primeIterator++;
    i++;
  }

  std::cout << result << std::endl;
  std::cout << "Elapsed time in seconds: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count()
       << " millisec" << std::endl;

      negator = primes.begin();
      std::advance(negator,(currentNumber * currentNumber) - 1);

  std::cout << "Elapsed time in seconds: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count()
       << " millisec" << std::endl;

  return 0;
}
