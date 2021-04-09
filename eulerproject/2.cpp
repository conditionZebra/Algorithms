#include <iostream>

int main()
{
  int result = 0;
  int first = 1;
  int second = 2;
  while( second < 4000000)
  {
    if(second % 2 == 0)
      result += second;

    second += first;
    first = second - first;
  }

  std::cout << result << std::endl;

  return 0;
}

