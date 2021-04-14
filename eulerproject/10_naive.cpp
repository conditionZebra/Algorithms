#include "../lib/eulerlib.h"
#include <iostream>
#include <chrono>

int main()
{
  auto start = std::chrono::steady_clock::now();

  long long int result = 2;
  for(int i = 3; i < 2000000; i += 2)
  {
    if(eulerlib::isPrime(i))
        result += i;
  }

  std::cout << result <<  std::endl;

  std::cout << "Elapsed time in seconds: "
       << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count()
       << " millisec" << std::endl;

  return 0;
}
