#include "../lib/eulerlib.h"
#include <iostream>

int main()
{
  eulerlib::divisorMap* dm = eulerlib::getDivisors(600851475143); 

  if(!dm->empty())
    std::cout << (--dm->end())->first <<  std::endl;

  return 0;
}
