#include <iostream>

int main()
{
  int a = 0;
  for (int c = 499; c > 0 ; c--)
  {
    for(int b = c - 1; b >= c/2 ; b--)
    {
      a = 1000 - (b + c);
      if((c * c) == (b * b) + (a * a))
      {
        std::cout << c * b * a << std::endl;
        return 0;
      }
    }
  }

  return 1;
}

