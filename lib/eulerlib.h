#ifndef EULERLIB_H
#define EULERLIB_H

#include <cmath>
#include<map>
#include<list>
#include<vector>
#include<string>
#include <memory>

namespace eulerlib
{
	bool isPrime(long num);
	bool isPalindrome(long num);
	int numberOfDigits(long num);
  /*
   *  getDigitFromPosition(456, 0) ==> 6
   *  getDigitFromPosition(456, 1) ==> 5
   *  getDigitFromPosition(456, 2) ==> 4
   */
  int getDigitFromPosition(long long int num, int pos);
	long long int stringToInt(const std::string& string);

	// first int is the diviasor the second
	// is which power the divisor is.
	// I hope it's clear... :)
	typedef std::map<long long int,int> divisorMap;
	divisorMap* getDivisors(long long int num); 

	typedef std::list<int> allDivisorList;
	allDivisorList* getAllDivisors(int num); 

	int getNumOfDivisors(int num);

	int getFactorial(int num);

	typedef std::vector<std::string> stringVector;
	std::shared_ptr<stringVector> getAllStringFromCSV(const char* fileName); 
}

#endif
