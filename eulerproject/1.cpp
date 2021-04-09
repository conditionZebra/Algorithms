#include <iostream>

int main()
{
  int result = 0;
  for (int i=1; i < 1000; i++)
  {
    if(i % 3 == 0)
    {
      result += i;
      continue;
    }
    if(i % 5 == 0)
    {
      result += i;
      continue;
    }
  }

  std::cout << result << std::endl;

  return 0;
}

