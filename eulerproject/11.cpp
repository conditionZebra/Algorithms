#include "../lib/eulerlib.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
  int result= 0;
  int tempResult = 0;
  int i = 0;
  std::shared_ptr<eulerlib::stringVector> data;
  data = eulerlib::getAllStringFromCSV("11_data.txt");

  //vertical
  for(i = 0; i<340; i++)
  {
    tempResult =  eulerlib::stringToInt((*data)[i]) * 
                  eulerlib::stringToInt((*data)[i + 20]) * 
                  eulerlib::stringToInt((*data)[i + 40]) * 
                  eulerlib::stringToInt((*data)[i + 60]);

    if(tempResult > result)
      result = tempResult;

  }

  //horizontal
  for(i = 0; i<=397; i++)
  {
    tempResult =  eulerlib::stringToInt((*data)[i]) * 
                  eulerlib::stringToInt((*data)[i + 1]) * 
                  eulerlib::stringToInt((*data)[i + 2]) * 
                  eulerlib::stringToInt((*data)[i + 3]);

    if(tempResult > result)
      result = tempResult;

    if(i % 20 == 16)
      i += 3;
  }

  //diagonal left to right
  for(i = 0; i<=336; i++)
  {
    tempResult =  eulerlib::stringToInt((*data)[i]) * 
                  eulerlib::stringToInt((*data)[i + 21]) * 
                  eulerlib::stringToInt((*data)[i + 42]) * 
                  eulerlib::stringToInt((*data)[i + 63]);

    if(tempResult > result)
      result = tempResult;

    if(i % 20 == 16)
      i += 3;
  }

  //diagonal right to left
  for(i = 3; i<=339; i++)
  {
    tempResult =  eulerlib::stringToInt((*data)[i]) * 
                  eulerlib::stringToInt((*data)[i + 19]) * 
                  eulerlib::stringToInt((*data)[i + 38]) * 
                  eulerlib::stringToInt((*data)[i + 57]);

    if(tempResult > result)
      result = tempResult;

    if(i % 20 == 0)
      i += 3;

  }

  std::cout << result <<std::endl;
  return 0;
}
