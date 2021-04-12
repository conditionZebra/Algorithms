#include <iostream>

int main()
{
  int sumSqrt = 0;
  int sqrtSum = 0;

  for (int i=1; i <= 100; i++)
  {
    sumSqrt += i * i;
    sqrtSum += i;
  }

  sqrtSum *= sqrtSum;

  std::cout << sqrtSum << std::endl;
  std::cout << sumSqrt << std::endl;
  std::cout << sqrtSum - sumSqrt << std::endl;

  return 0;
}

