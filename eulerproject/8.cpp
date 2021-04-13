#include "../lib/eulerlib.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::string theNumber;
  std::ifstream dataFile("8_data.txt");
  long long int currentEight = 0;
  long long int result = 0;
  long long int temp = 1;

  if (dataFile.is_open())
  {
    if(!getline(dataFile,theNumber))
    {
      std::cout << "File empty?" << std::endl;
      dataFile.close();
      return 1;
    }
    dataFile.close();
  }
  else
  {
    std::cout << "Unable to open file" << std::endl;
    return 2;
  }

  for(int i = 0 ; i <= 983; i++)
  {
    currentEight = eulerlib::stringToInt(theNumber.substr(i,13));
    if(currentEight > 999999999999)
    {
      for(int j = 0; j < 13; j++)
        temp *= eulerlib::getDigitFromPosition(currentEight,j);

      if(temp > result)
        result = temp;

      temp = 1;
    }
  }

  std::cout << result << std::endl;

  return 0;
}
