#include <iostream>
#include <vector>

int main()
{
  std::vector<int> prevElement;
  std::vector<int> currentElement;
  int counter = 2;
  int actualSumm = 0;
  int i = 0;
  int vectorSize = 0;

  prevElement.push_back(1);
  currentElement.push_back(1);

  while(currentElement.size() != 1000)
  {
    vectorSize = currentElement.size();

    for(i = 0; i < vectorSize; i++)
    {
      actualSumm = currentElement[i] + prevElement[i] + actualSumm;
      prevElement[i] = currentElement[i];
      if(actualSumm > 9)
      {
        currentElement[i] = actualSumm - 10;
        if(i == currentElement.size() - 1)
        {
          currentElement.push_back(1);
          prevElement.push_back(0);
          actualSumm = 0;
        }
        else
          actualSumm = 1;
      }
      else
      {
        currentElement[i] = actualSumm;
        actualSumm = 0;
      }
    }
    counter++;
  }

  std::cout << counter << std::endl;
  return 0;
}
