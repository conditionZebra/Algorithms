#include "eulerlib.h"
#include <string>
#include <sstream>      // std::istringstream
#include <fstream>
#include <iostream>

namespace eulerlib
{

	std::shared_ptr<stringVector> getAllStringFromCSV(const char* fileName)
	{
		std::shared_ptr<stringVector> returnList(new stringVector);

		std::ifstream data(fileName);

		std::string line;
		while(std::getline(data,line))
		{
			std::stringstream lineStream(line);
			std::string cell;
			while(std::getline(lineStream,cell,','))
			{
				returnList->push_back(cell);
			}
		}

		return returnList;
	}

  int getFactorial(int num)
  {
    if(num == 1 || num == 0)
      return 1;
    else
      return num * getFactorial(num - 1);
  }

	bool isPrime(long num)
	{
		if(num <= 1)
			return false;


		for(long i = 2; i <= sqrt(num); i++)
			if(num%i == 0)
				return false;

//    std::cout << num << std::endl;
		return true;
	}	

	bool isPalindrome(long num)
	{

		int length = numberOfDigits(num);

		if(length == 1)
			return true;

		int upperDigit = 0;
		int lowerDigit = 0;

		if(length % 2)
		{
			lowerDigit = length / 2;
			upperDigit = lowerDigit + 2;
		}
		else
		{
			upperDigit = length / 2 + 1;
                        lowerDigit = length / 2;
		}

		while(lowerDigit > 0)
		{
			if(getDigitFromPosition(num, upperDigit) != getDigitFromPosition(num, lowerDigit))
				return false;

			lowerDigit--;
			upperDigit++;
		}
		

		return true;
	}

	int getDigitFromPosition(long long int num, int pos)
	{
		long long int tenPower = 1;

		for(int i = 0; i < pos; i++)
			tenPower *= 10;

		num /= tenPower;

		return num % 10;		
	}

  int numberOfDigits(long num)
	{
		int result = 0;

		while(num != 0)
		{
			num /= 10;
			result++;
		}
		return result;
	}

	long long int stringToInt( const std::string& string)
	{
		long long int numb;
		std::istringstream(string) >> numb;
		return numb;
	}

	divisorMap* getDivisors(long long int num)
	{
		divisorMap* returnMap = new divisorMap;
		if(isPrime(num))
		{
			(*returnMap)[num] = 1;
			return returnMap;
		}

		int counter;

		for(long long int i = 2; i <= sqrt(num) + 1; i++)
		{
			if(num%i == 0)
			{
				counter = 0;
				while(num%i == 0)
				{
					counter++;
					num = num / i;
				}

				(*returnMap)[i] = counter;
	
				if(isPrime(num))
				{
					(*returnMap)[num] = 1;
					return returnMap;
				}
			}
		}
		return returnMap;
	}

	allDivisorList* getAllDivisors(int num)
	{
		allDivisorList* returnList = new allDivisorList;

		for(int i = 1; i <= num /2; i++)
		{
			if(num % i == 0)
				returnList->push_back(i);
		}

		return returnList;
	}

	int getNumOfDivisors(int num)
	{
		divisorMap* divisors;
		int numOfDivisors = 1;

		divisors = getDivisors(num);

		for (std::map<long long int,int>::iterator it=(*divisors).begin(); it!=(*divisors).end(); ++it)
                {
                        numOfDivisors = numOfDivisors * (it->second + 1);

                }

		delete divisors;

		return numOfDivisors;
	
	}
}
