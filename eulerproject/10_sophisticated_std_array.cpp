#include <iostream>
#include <chrono>
#include <cmath>
#include <array>

int main()
{
  auto start = std::chrono::steady_clock::now();

  const int barrier = 2000000;

  std::array<bool, barrier> primes;
  bool* negatorPtr;
  for(int i = 0; i < barrier; i++)
    primes[i] = true;

  int currentNumber = 0;
  int currentPosition = 0;
  long long int result = 0;

  primes[0] = false;
  currentNumber = 1;

  while(currentNumber < sqrt(barrier))
  {
    if(primes[currentNumber - 1] == true)
    {
      currentPosition = currentNumber * currentNumber - 1;
      negatorPtr = &primes[0 + currentPosition];
      while(currentPosition < barrier)
      {
        *negatorPtr = false;
        currentPosition += currentNumber;
      negatorPtr += currentNumber;
      }
    }
    currentNumber++;
  }

  for(int i = 0; i < barrier; i++)
  {
    if(primes[i])
      result += i+1;
  }
  std::cout << result << std::endl;
  std::cout << "Elapsed time in seconds: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count()
       << " millisec" << std::endl;

  return 0;
}
