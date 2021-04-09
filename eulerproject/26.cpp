#include <iostream>
#include <map>

int main()
{
  std::map<int,int> remainAndItsPosition;
  std::map<int,int>::iterator rpIter;
  int maxLength = 0;
  int result = 0;
  int x = 1;
  int j = 0;
  bool repeat = true;

  for(int i = 2; i <= 1000; i++)
  {
    j = 1;
    x = 1;
    repeat = true;
    remainAndItsPosition.clear();
    while(repeat)  
    {
      x %= i;
      if(x == 0)
      {
        repeat = false;
      }
      else{
        rpIter = remainAndItsPosition.find(x);
        if(rpIter == remainAndItsPosition.end())
        {
          remainAndItsPosition[x] = j;
          j++;
          x *= 10;
        }
        else
        {
          if(j - rpIter->second > maxLength)
          {
            maxLength = j - rpIter->second;
            result = i;
          }
          repeat = false;
        }
      }
    }

  }

  std::cout << result << std::endl;
  return 0;
}
