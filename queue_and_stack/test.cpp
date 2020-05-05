#include "queue.h"
#include "stack.h"
#include <iostream>

int main() 
{ 
    std::cout << "------ QUEUE ----------" << std::endl;

    try { 
        Queue<string> 	stringQueue;
        Queue<int>	intQueue;

        intQueue.enqueue(1); 
        intQueue.enqueue(2); 
        intQueue.enqueue(3); 
        intQueue.enqueue(4); 

        stringQueue.enqueue("egy"); 
        stringQueue.enqueue("ketto"); 
        stringQueue.enqueue("harom"); 
        stringQueue.enqueue("negy"); 

	for(Queue<int>::iterator iter = intQueue.begin(); iter != intQueue.end(); iter++)
        {
                std::cout << *iter << std::endl;
        }

	std::cout << "-----------------------" << std::endl;

	for(Queue<string>::iterator iter = stringQueue.begin(); iter != stringQueue.end(); iter++)
        {
                std::cout << *iter << std::endl;
        }

	std::cout << "-----------------------" << std::endl;

	// safe
	while(!intQueue.isEmpty())
		std::cout << intQueue.dequeue() << std::endl;

	std::cout << "-----------------------" << std::endl;

	// not safe -> exception
	for(int i = 0; i <= 4; i++)
		std::cout << stringQueue.dequeue() << std::endl;
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
    }
 
    std::cout << "------ STACK ----------" << std::endl;

    try {
        Stack<string>   stringStack;

        stringStack.push("egy");
        stringStack.push("ketto");
        stringStack.push("harom");
        stringStack.push("negy");
        stringStack.push("ot");


        for(Stack<string>::iterator iter = stringStack.begin(); iter != stringStack.end(); iter++)
        {
                std::cout << *iter << std::endl;
        }

        std::cout << "-----------------------" << std::endl;

        // safe
        while(!stringStack.isEmpty())
                std::cout << stringStack.pop() << std::endl;
    } 
    catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    }
}
