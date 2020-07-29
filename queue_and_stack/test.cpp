#include "queue.h"
#include "stack.h"
#include <iostream>

int main() 
{ 
  std::cout << "------ QUEUE ----------" << std::endl;

  Queue<std::string> 	stringQueue;
  Queue<int>	    intQueue;

  intQueue.enqueue(1); 
  intQueue.enqueue(2); 
  intQueue.enqueue(3); 
  intQueue.enqueue(4); 

  stringQueue.enqueue("one"); 
  stringQueue.enqueue("two"); 
  stringQueue.enqueue("three"); 
  stringQueue.enqueue("four"); 

	for(Queue<int>::iterator iter = intQueue.begin(); iter != intQueue.end(); ++iter)
  {
    std::cout << *iter << std::endl;
  }

	std::cout << "-----------------------" << std::endl;

	for(Queue<std::string>::iterator iter = stringQueue.begin(); iter != stringQueue.end(); ++iter)
  {
    std::cout << *iter << std::endl;
  }

	std::cout << "-----------------------" << std::endl;

	// safe
	while(!intQueue.isEmpty())
		std::cout << intQueue.dequeue() << std::endl;

	std::cout << "-----------------------" << std::endl;

	// not safe -> exception
  try { 
    for(int i = 0; i <= 4; i++)
      std::cout << stringQueue.dequeue() << std::endl;
  } 
  catch (char const* ex) { 
    std::cerr << "Exception: " << ex << std::endl; 
  }
  catch (...) { 
    std::cerr << "Unknown exception" << std::endl; 
  }
 
  std::cout << "------ STACK ----------" << std::endl;

  Stack<std::string> stringStack;
    
  stringStack.push("one");
  stringStack.push("two");
  stringStack.push("three");
  stringStack.push("four");
  stringStack.push("five");

  for(Stack<std::string>::iterator iter = stringStack.begin(); iter != stringStack.end(); ++iter)
  {
    std::cout << *iter << std::endl;
  }

  std::cout << "-----------------------" << std::endl;

  // safe
  try {
    while(!stringStack.isEmpty())
      std::cout << stringStack.pop() << std::endl;
  } 
  catch (char const& ex) { 
    std::cerr << "Exception: " << ex << std::endl; 
  }
  catch (...) { 
    std::cerr << "Unknown exception" << std::endl; 
  }
return 0;
}
